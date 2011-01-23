#include<iostream>
using namespace std;
class complex
{
  float real,imag;
public:
  complex & operator+(complex num2);
  complex & operator-(complex num2);
  int operator==(complex num2);
  int operator!=(complex num2);
  complex(complex &num){real=num.real;imag=num.imag;}
  complex(){real=0;imag=0;}
  complex(float r,float i){real=r;imag=i;}
  friend void check_equal_friend(complex num1,complex num2);
  friend void check_unequal_friend(complex num1,complex num2);
  friend complex & add(complex num1,complex num2);
  friend complex & sub(complex num1,complex num2);
  friend void sum_overload(complex num1,complex num2);
  friend void diff_overload(complex num1,complex num2);
  friend void sum_friend(complex num1,complex num2);
  friend void diff_friend(complex num1,complex num2);
  friend void real_mult(complex num,float real_num);
};
complex dummy;
complex &res_ref=dummy;
int complex::operator==(complex num2)
{
  if((real==num2.real)&&(imag==num2.imag))
    return 1;
  else
    return 0;
}
int complex::operator!=(complex num2)
{
  if((real==num2.real)&&(imag==num2.imag))
    return 0;
  else
    return 1;
}
complex & complex::operator+(complex num2)
{
  complex res;
  res.real=real+num2.real;
  res.imag=imag+num2.imag;
  res_ref=res;
  return res_ref;
}
complex & complex::operator-(complex num2)
{
  complex res;
  res.real=real-num2.real;
  res.imag=imag-num2.imag;
  res_ref=res;
  return res_ref;
}
complex & add(complex num1,complex num2)
{
  complex res;
  res.real=num1.real+num2.real;
  res.imag=num1.imag+num2.imag;
  res_ref=res;
  return res_ref;
}
complex & sub(complex num1,complex num2)
{
  complex res;
  res.real=num1.real-num2.real;
  res.imag=num1.imag-num2.imag;
  res_ref=res;
  return res_ref;
}
void check_equal_overload(complex num1,complex num2)
{
  if(num1==num2)
    printf("\nThe complex numbers are equal...\n");
  else
    printf("\nThe complex numbers are not equal...\n");
}
void check_unequal_overload(complex num1,complex num2)
{
  if(num1!=num2)
    printf("\nThe complex numbers are not equal...");
  else
    printf("\nThe complex numbers are equal...");
}
void check_equal_friend(complex num1,complex num2)
{
  if((num1.real==num2.real)&&(num1.imag==num2.imag))
    printf("\nThe complex numbers are equal...\n");
  else
    printf("\nThe complex numbers are not equal...\n");
}
void check_unequal_friend(complex num1,complex num2)
{
  if((num1.real!=num2.real)||(num1.imag!=num2.imag))
    printf("\nThe complex numbers are not equal...\n");
  else
    printf("\nThe complex numbers are equal...\n");
}
void real_mult(complex num,float real_num)
{
  complex num2;
  num2.real=num.real*real_num;
  num2.imag=num.imag*real_num;
  cout<<"The result of the multiplication is : ";
  cout<<"\n"<<num.real<<"+"<<num.imag<<"i"<<"\t*\t"<<real_num<<"\t=\t"<<num2.real<<"+"<<num2.imag<<"i";
}
void getnumber(complex &number);
void getnumbers(complex &number1,complex &number2);
void sum_overload(complex num1,complex num2);
void diff_overload(complex num1,complex num2);
void sum_friend(complex num1,complex num2);
void diff_friend(complex num1,complex num2);
int main()
{
  
  int choice;
  complex num1,num2;
  do{
    cout<<"\nMENU";
    cout<<"\n1.Add the numbers by operator overloading";
    cout<<"\n2.Substract the numbers by operator overloding";
    cout<<"\n3.Add the numbers by friend function";
    cout<<"\n4.Substract the numbers by friend function";
    cout<<"\n5.Check equality by overloading";
    cout<<"\n6.Check inequality by overloading";
    cout<<"\n7.Check equality by friend function";
    cout<<"\n8.Check inequlaity by friend function";
    cout<<"\n9.Multiply a real number to a complex number";
    cout<<"\n10.Exit";
    cout<<"\nPlease enter the choice...";
    cin>>choice;
    switch(choice)
      {
      case 1:
	getnumbers(num1,num2);
	sum_overload(num1,num2);
	break;
      case 2:
	getnumbers(num1,num2);
	diff_overload(num1,num2);
	break;
      case 3:
	getnumbers(num1,num2);
	sum_friend(num1,num2);
	break;
      case 4:
	getnumbers(num1,num2);
	diff_overload(num1,num2);
	break;
      case 5:
	getnumbers(num1,num2);
	check_equal_overload(num1,num2);
	break;
      case 6:
	getnumbers(num1,num2);
	check_unequal_overload(num1,num2);
	break;
      case 7:
	getnumbers(num1,num2);
	check_equal_friend(num1,num2);
	break;
      case 8:
	getnumbers(num1,num2);
	check_unequal_friend(num1,num2);
	break;
      case 9:
	getnumber(num1);
	cout<<"\nEnter the real number : ";
	float real_num;
	cin>>real_num;
	real_mult(num1,real_num);
	break;
      case 10:
	break;
      default:
	cout<<"\nWrong choice!!!";
	cout<<"\nPlease enter again";
      }

  }while(choice!=10);
    return 0;
}
void getnumbers(complex &number1,complex &number2)
{
  float r,i;  
  cout<<"\nEnter the real and imaginary parts of first complex number : ";
  cin>>r>>i;
  complex num1(r,i);
  cout<<"\nEnter the real and imaginary parts of the second complex number : ";
  cin>>r>>i;
  complex num2(r,i);
  number1=num1;
  number2=num2;
}
void getnumber(complex &number)
{
  float r,i;
  cout<<"\nEnter the real and imaginary parts of the complex number : ";
  cin>>r>>i;
  complex num1(r,i);
  number=num1;
}
void sum_overload(complex num1,complex num2)
{
  complex sum=num1+num2;
  cout<<"\nSum by operator overloading : ";
  cout<<num1.real<<"+"<<num1.imag<<"i"<<"\t+\t"<<num2.real<<"+"<<num2.imag<<"i"<<"\t=\t"<<sum.real<<"+"<<sum.imag<<"i";
}
void diff_overload(complex num1,complex num2)
{
  complex diff;
  diff=num1-num2;
  cout<<"\nDifference by operator overloading : ";
  cout<<num1.real<<"+"<<num1.imag<<"i"<<"\t+\t"<<num2.real<<"+"<<num2.imag<<"i"<<"\t=\t"<<diff.real<<"+"<<diff.imag<<"i";
}
void sum_friend(complex num1,complex num2)
{
  complex sum;
  sum=add(num1,num2);
  cout<<"\nSum by operator overloading : ";
  cout<<num1.real<<"+"<<num1.imag<<"i"<<"\t+\t"<<num2.real<<"+"<<num2.imag<<"i"<<"\t=\t"<<sum.real<<"+"<<sum.imag<<"i";
}
void diff_friend(complex num1,complex num2)
{
  complex diff=sub(num1,num2);
  cout<<"\nDifference by operator overloading : ";
  cout<<num1.real<<"+"<<num1.imag<<"i"<<"\t+\t"<<num2.real<<"+"<<num2.imag<<"i"<<"\t=\t"<<diff.real<<"+"<<diff.imag<<"i";
}
