#include<iostream>
using namespace std;
class functions
{
 public:
  void repeat_char(char ch);
  void repeat_char(char ch,int num);
  void repeat_char();
  void repeat_char(int num);
};
void functions::repeat_char(char ch)
{
  int i;
  cout<<"\n";
  for(i=0;i<20;i++)
    cout<<ch;
}
void functions::repeat_char()
{
  int i;
  cout<<"\n";
  for(i=0;i<20;i++)
    cout<<"*";
}
void functions::repeat_char(char ch,int num)
{
  int i;
  cout<<"\n";
  for(i=0;i<num;i++)
    cout<<ch;
}
void functions::repeat_char(int num)
{
  cout<<"    "<<num-2;
  cout<<"\n  "<<num-2<<" "<<num-1<<" "<<num-2;
  cout<<"\n"<<num-2<<" "<<num-1<<" "<<num<<" "<<num-1<<" "<<num-2;
  cout<<"\n  "<<num-2<<" "<<num-1<<" "<<num-2;
  cout<<"\n    "<<num-2;
}
int main()
{
  functions dummy;
  char ch;
  int num;
  int choice;
  do{
    cout<<"\nMENU";
    cout<<"\n1.Print now";
    cout<<"\n2.Enter a character";
    cout<<"\n3.Enter a character and number";
    cout<<"\n4.Enter a number";
    cout<<"\n5.Exit";
    cout<<"\nPlease enter your choice : ";
    cin>>choice;
    switch(choice)
      {
      case 1:
	dummy.repeat_char();
	break;
      case 2:
	cout<<"\nEnter the character : ";
	cin>>ch;
	dummy.repeat_char(ch);
	break;
      case 3:
	cout<<"\nEnter the character : ";
	cin>>ch;
	cout<<"\nEnter the number : ";
	cin>>num;
	dummy.repeat_char(ch,num);
	break;
      case 4:
	cout<<"\nEnter the number : ";
	cin>>num;
	dummy.repeat_char(num);
	break;
      case 5:
	break;
      default:
	cout<<"\nWrong choice entered...";
	cout<<"\nPlease eter again...";
	break;
      }
  }while(choice!=5);
  return 0;
}
