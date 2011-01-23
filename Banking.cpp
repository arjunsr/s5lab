#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
const float MIN=200;
const float PEN=50;
const float RATE=12;
class account
{
protected:
  char name[25];
public:
  int ac_no;
  char ac_type;
  float bal;
  void display_bal();
  void withdraw();
  void deposit();
  void check_balance();
  void withdraw_check();
  void inp_account(char *inp, int in_no){strcpy(name,inp);ac_no=in_no;bal=MIN;}
};
void account::display_bal()
{
  printf("\nThe currrent balance is : %f",bal);
}

void account::withdraw()
{
  if(bal<=PEN)
  {
    printf("\nBalance too low...");
    return;
  }
  float with=0;
  while(1)
  {
    printf("\nEnter the amount to be withdrawn : ");
    scanf("%f",&with);
    if(with>=(bal-PEN))
    {
      printf("\nNot enough balance to withdraw the amount...");
      printf("\nEnter the amount again(0 to withdraw nothing)...");
      continue;
    }
    break;
  }
  bal-=with;
  check_balance();
}
void account::deposit()
{
  printf("\nEnter the amount to be deposited : ");
  float dep;
  scanf("%f",&dep);
  bal+=dep;
}
void account::check_balance()
{
  if((bal<MIN)&&(ac_type=='C'))
  {
    printf("\nThe minimum balance is less than %f...",MIN);
    printf("\nImposing penalty of %f...",PEN);
    bal-=PEN;//Add to the account of the bank this amount
  }
}
void account::withdraw_check()
{
  if(ac_type!='C')
  {
    printf("\nAccount is not a current account");
    printf("\nWithdrawing by cheque is not possible..");
    return;
  }
  withdraw();
}
class sav_acct:public account
{
  float interest;
public:
  void calc_interest();
  void inp_sav_account(char *inp, int in_no)
  {
    inp_account(inp,in_no);
    ac_type='S';
  }
};
  
void sav_acct::calc_interest()
{
  float months;
  printf("\nThe current monthly rate is : %f",RATE);
  printf("\nEnter the number of months the interest needs to be calculated : ");
  scanf("%f",&months);
  months/=12.0;
  float newbal=bal*pow((1+ (RATE/100)),months);
  float inter=newbal-bal;
  printf("\nThe interest is %f",inter);
  bal=newbal;
  printf("\nAdded to the account...");
}
class cur_acct:public account
{
public:
  void inp_cur_account(char *inp, int in_no)
  {
    inp_account(inp,in_no);
    ac_type='C';
  }
};
cur_acct cur_list[25];
sav_acct sav_list[25];
int cur_accts,sav_accts;
void sav();
void cur();
int main()
{
  int choice;
  cur_accts=-1;
  sav_accts=-1;
  do{
    printf("\nMENU");
    printf("\n1.Manage Current Accounts");
    printf("\n2.Manage Savings Accounts");
    printf("\n3.Exit");
    printf("\nEnter your choice...");
    scanf("%d",&choice);
    switch(choice)
      {
      case 1:
	cur();
	break;
      case 2:
	sav();
	break;
      case 3:
	break;
      default:
	printf("\nWrong value entered...");
	printf("\nPlease enter again");
      }
  }while(choice!=3);
  return 0;
}
void cur()
{
  int choice,i,taken,ac_no;
  char name[25];
  do{
    printf("\nMENU");
    printf("\n1.Enter new current account to the system");
    printf("\n2.Display the balance of a current account");
    printf("\n3.Deposit to a current account");
    printf("\n4.Withdraw an amount in cash");
    printf("\n5.Wihdraw an amount in cheque");
    printf("\n6.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
      {
      case 1:
	if(cur_accts>=24)
	  {
	    printf("\nSystem can hold only 25 current accounts at a time");
	    printf("\nAll spaces are full. Sorry cant process");
	    break;
	  }
	while(1)
	  {	
	    printf("\nEnter acount number : ");
	    scanf("%d",&ac_no);
	    taken=0;
	    for(i=0;i<=cur_accts;i++)
	      {
		if(cur_list[i].ac_no==ac_no)
		  {
		    printf("\nAccount number already taken...");
		    printf("\nPlease enter again...");
		    getchar();
		    taken=1;
		    break;
		  }
	      }
	    if(!taken)
	      break;
	  }
	getchar();
	printf("\nEnter name : ");
	gets(name);
	//getchar();
	cur_accts++;
	cur_list[i].inp_cur_account(name,ac_no);
	break;
      case 2:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=cur_accts;i++)
	  {
	    if(cur_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>cur_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    cur_list[i].display_bal();
	  }
	break;
      case 3:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=cur_accts;i++)
	  {
	    if(cur_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>cur_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    cur_list[i].deposit();
	  }
	break;
      case 4:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=cur_accts;i++)
	  {
	    if(cur_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>cur_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    cur_list[i].withdraw();
	  }
	break;
      case 5:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=cur_accts;i++)
	  {
	    if(cur_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>cur_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    cur_list[i].withdraw_check();
	  }
	break;
      case 6:
	break;
      default:
	printf("\nWrong choice...");
	printf("\nPlease enter again...");
      }
  }while(choice!=6);
}
void sav()
{
  int choice,i,taken,ac_no;
  char name[25];
  do{
    printf("\nMENU");
    printf("\n1.Enter new savings account to the system");
    printf("\n2.Display the balance of a savings account");
    printf("\n3.Deposit to a savings account");
    printf("\n4.Withdraw an amount in cash");
    printf("\n5.Wihdraw an amount in cheque");
    printf("\n6.Calculate the interest");
    printf("\n7.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
      {
      case 1:
	if(sav_accts>=24)
	  {
	    printf("\nSystem can hold only 25 savings accounts at a time");
	    printf("\nAll spaces are full. Sorry cant process");
	    break;
	  }
	while(1)
	  {	
	    printf("\nEnter acount number : ");
	    scanf("%d",&ac_no);
	    taken=0;
	    for(i=0;i<=sav_accts;i++)
	      {
		if(sav_list[i].ac_no==ac_no)
		  {
		    printf("\nAccount number already taken...");
		    printf("\nPlease enter again...");
		    getchar();
		    taken=1;
		    break;
		  }
	      }
	    if(!taken)
	      break;
	  }
	getchar();
	printf("\nEnter name : ");
	gets(name);
	//getchar();
	sav_accts++;
	sav_list[i].inp_sav_account(name,ac_no);
	break;
      case 2:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=sav_accts;i++)
	  {
	    if(sav_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>sav_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    sav_list[i].display_bal();
	  }
	break;
      case 3:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=sav_accts;i++)
	  {
	    if(sav_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>sav_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    sav_list[i].deposit();
	  }
	break;
      case 4:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=sav_accts;i++)
	  {
	    if(sav_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>sav_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    sav_list[i].withdraw();
	  }
	break;
      case 5:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=sav_accts;i++)
	  {
	    if(sav_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>sav_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    sav_list[i].withdraw_check();
	  }
	break;
      case 6:
	printf("\nEnter account number : ");
	scanf("%d",&ac_no);
	for(i=0;i<=sav_accts;i++)
	  {
	    if(sav_list[i].ac_no==ac_no)
	      break;
	  }
	if(i>sav_accts)
	  {
	    printf("\nAccount does not exist...");
	    break;
	  }
	else
	  {
	    sav_list[i].calc_interest();
	  }
	break;
      case 7:
	break;
      default:
	printf("\nWrong choice...");
	printf("\nPlease enter again...");
      }
  }while(choice!=7);
}
