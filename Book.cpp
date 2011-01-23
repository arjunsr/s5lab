#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Book
{
  char bookname[20];
  char author[20];
  char publisher[20];
  int stock;
  float price;
  friend int add_book();
  friend int buy_book();
 public:
  Book();
  Book(int i)
  {
  }
  int get_details();
};

int Book::get_details()
{
  cout<<"\n"<<bookname<<"   "<<author<<"   "<<publisher<<"   "<<stock<<"  ";
  cout<<price<<"\n";
}

Book::Book()
{
  char c;
  fflush(stdin);
  cout<<"\nInput the book name : ";
  c=getchar();
  cin.getline(bookname,20,'\n');
  cout<<"\nInput the author : ";
  c=getchar();
  cin.getline(author,20,'\n');
  cout<<"\nInput the publisher : ";
  cin.getline(publisher,20,'\n');
  cout<<"\nInput the number of copies available : ";
  cin>>stock;
  cout<<"\nInput the price : ";
  cin>>price;
}

int add_book()
{
  int choice=0;
  ofstream fout;
  fout.open("/home/us/s07/s0730/LIBR",ios::app | ios::out | ios::binary);
  do
    {
      Book temp;
      fout.write((char *)&temp,sizeof(temp));
      cout<<"\nDo you want to add more books(1/0)";
      cin>>choice;
    }
  while(choice==1);
  fout.close();
  return(0);
}


int buy_book()
{
  int ch=0,no_copy;
  char name[20],author[20];
  fflush(stdin);
  cout<<"\nInput the book name : ";
  getchar();
  cin.getline(name,20,'\n');
  cout<<"\nInput the author name : ";
  getchar();
  cin.getline(author,20,'\n');
  Book buk(1);
  fstream fin,newfin;
  fin.open("/home/us/s07/s0730/LIBR",ios::in |ios::ate | ios::binary);
   if(fin.fail())
    {
      cout<<"\nCannot open the file";
      return(1);
    }
   fin.seekg(ios::beg);
   newfin.open("/home/us/s07/s0730/newlib",ios::out|ios::binary);
   fin.read((char *)&buk,sizeof(buk));
   while(!fin.eof())
     {   
       //  fin.read((char *)&buk,sizeof(buk));
       if((strcmp(name,buk.bookname)==0)&&(strcmp(author,buk.author)==0)&&ch==0)
	 {
	   buk.get_details();
	   cout<<"\nInput the number of copies you need : ";
	   cin>>no_copy;	
	   if(no_copy > buk.stock)
	     {
	      cout<<"\nSorry not enough copies available... ";
	      return(0);
	     }
	   cout<<"\nTotal price is Rs:"<<no_copy*buk.price;
	  cout<<"\nPress 1 to confirm:";
	  cin>>ch;
	  if(ch==1)
	    {	
	      /*
		buk.stock=buk.stock - no_copy;
		fin.seekp(-1*sizeof(buk),ios::cur);
		fin.write((char *)&buk,sizeof(buk));
	      */
	      buk.stock= buk.stock-no_copy ;
	      newfin.write((char *)&buk,sizeof(buk));
	    }
	  else
	    {
	      newfin.write((char *)&buk,sizeof(buk));
	    }
	 }
       else
	 {
	   newfin.write((char *)&buk,sizeof(buk));
	 }
       fin.read((char *)&buk,sizeof(buk));
	 }
   if(ch==0 && fin.eof())
     cout<<"\n The book not found\n";
   fin.close();
   newfin.close();
   system("rm /home/us/s07/s0730/LIBR");
   system("mv /home/us/s07/s0730/newlib /home/us/s07/s0730/LIBR");
  
  return(1);
}


int main()
{
  int choice;
  do
    {
      cout<<"\nBOOK SHOP MENU";
      cout<<"\n1.Buy a book";
      cout<<"\n2.Add books";
      cout<<"\n3.Exit";
      cout<<"\nEnter your choice : ";
      fflush(stdin);
      cin>>choice;
      switch(choice)
	{
	case 1: 
	  buy_book();
	  break;
	case 2:
	  add_book(); 
	  break;
	case 3:
	  exit(0);
	default:
	  cout<<"\nInvalid choice:";
	}
    }while(1);
}
