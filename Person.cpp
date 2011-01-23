#include<cstdlib>
#include<cstdio>
#define MAX 50
#include<iostream>
using namespace std;

class Person
{
protected:
  char name[20];
  unsigned short int code;
};
class Admin: public virtual Person
{
protected:
  unsigned short int experience;
};

class Account:public virtual Person
{
protected:
   double pay;
};
class Master: public Admin, public Account
{
public:
  void ReadData(int id)
  { 
    fflush(stdin);
    cout<<"\nEnter the name of the Person : "; 
    getchar();
    cin.getline(name,20);
    cout<<"\nThe automatically generated ID of the Person is : "<<id;
    code=id;
    //    getchar();
    cout<<"\nEnter the experience of the person : "; 
    cin>>experience;
    cout<<"\nEnter the Pay amount of person : ";
    cin>>pay;
    
  }
  void Update()
  {
    char ans;
    system("clear");
    cout<<"The Name and Code ID of the person cannot be edited...\n ";
    cout<<"\nEDIT MENU";
    cout<<"\n1.Edit experience attribute";
    cout<<"\n2.Edit Pay attribute";
    cout<<"\n3.Exit";
    cout<<"\nPlease Enter your Choice : ";
    cin>>ans;
    switch(ans)
      {
      case '1': 
	unsigned short int newexp;
	cout<<"Current Experience value is : "<<experience;
	cout<<"\nEnter the new value for experience : ";
	cin>>newexp;
	experience=newexp;
	break;
      case '2':
	cout<<"\nYour current value for pay is : "<<pay;
	cout<<"\nEnter the new value for pay : ";
	cin>>pay;
	break;
      case '3':
	cout<<"Quitting...";
	break;
      default:
	cout<<"Entered value is Invalid!";
	cout<<"\nPlease Enter Again\n";
	break;
      }
  }
  void Display()
  {
    cout<<"The details of individuals : ";
    cout<<"\nNAME       :"<<name;
    cout<<"\nCODE       :"<<code;
    cout<<"\nPAY        :"<<pay;
    cout<<"\nEXPERIENCE :"<<experience;
  }
  
};

int main()
{
  Master record[MAX];
  unsigned short int id=1;
  unsigned short int choice;
  do{
    cout<<"\nCREATION MENU\n";
    cout<<"1.Create Person Database\n";
    cout<<"2.Update the Person Database\n";
    cout<<"3.Display the Person Database\n";
    cout<<"4.Exit from the Program\n";
    cout<<"Please Enter your choice : ";
    cin>>choice;
    switch(choice)
      {
      case 1:
	int n;
	cout<<"\nEnter the number of records you want to enter (MAX 50) : ";
	cin>>n;
	if(n>50)
	  {
	    cout<<"Maximum number of records is 50...\n";
	    exit(1);
	  }
	else
	  { 
	    for(int i=0; i<n ; i++,id++)
	      {
		record[i].ReadData(id);
	      }
	  }
	break;

      case 2: 
	unsigned short edit_code ;
	cout<<"Enter the Code of the person to be Updated : ";
	cin>>edit_code;
	if(edit_code>id)
	  cout<<"Invalid Code Number!";
	  else
	    record[edit_code-1].Update();
	break;

      case 3:
	unsigned int display_code;
	cout<<"Enter the Code ID of the Person whose information is to be displayed : ";
	cin>>display_code;
	if(display_code>=id)
	  {
	    cout<<"Person with CODE ID = "<<display_code;
	    cout<<" does not exist";
	  }
	else
	  record[display_code-1].Display();
	break;

      case 4:
	cout<<"The Program is Quitting\n";
	exit(0);
      default:
	cout<<"Invalid Choice !!!";
	break;	
      }
  }while(choice!=4);
}
