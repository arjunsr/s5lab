#include<iostream>
using namespace std;
class point
{
protected:
  float x,y;
public:
  point(float x_inp,float y_inp){x=x_inp;y=y_inp;}
  virtual char type_ret()=0;
};
class rectangle:public point
{
protected:
  float len,breadth;
public:
  rectangle(float x_inp,float y_inp,float len_inp,float breadth_inp):point(x_inp,y_inp)
  {
    len=len_inp;
    breadth=breadth_inp;
  }
  char type_ret(){return 'r';}
};
class circle:public point
{
protected:
  float radius;
public:
  circle(float x_inp,float y_inp,float rad_inp):point(x_inp,y_inp)
  {
    radius=rad_inp;
  }
  char type_ret(){return 'c';}
};
class shape_comparator
{
public:
  static int both;
  shape_comparator(point *first,point *second)
  {
    if(first->type_ret()==second->type_ret())
      both++;
  }
};
int shape_comparator::both;
int main()
{
  shape_comparator::both=0;
  point *arr1[25];
  point *arr2[25];
  int N;
  do{
    cout<<"\nEnter number of objects to be inserted (MAX 25) : ";
    cin>>N;
    if((N>25)||(N<0))
      {
	cout<<"\nWrong number of objects...";
	cout<<"\nPlease enter again...";
      }
  }while((N<0)||(N>25));
  char shape_type;
  float x_inp,y_inp,val1,val2;
  for(int i=0;i<N;i++)
    {
      cout<<"\nCircle or Rectangle at position "<<i+1<<" of first array?(c/r) : ";
      cin>>shape_type;
      switch(shape_type)
	{
	case 'r':
	case 'R':
	  cout<<"Enter values for Top-Left cordinates of rectangle : ";
	  cin>>x_inp>>y_inp;
	  cout<<"\nEnter length and breadth : ";
	  cin>>val1>>val2;
	  arr1[i]=new rectangle(x_inp,y_inp,val1,val2);
	  break;
	case 'c':
	case 'C':
	  cout<<"\nEnter the values for centre of the circle : ";
	  cin>>x_inp>>y_inp;
	  cout<<"\nEnter value for radius : ";
	  cin>>val1;
	  arr1[i]=new circle(x_inp,y_inp,val1);
	  break;
	default:
	  cout<<"\nWrong value entered ";
	  i--;
	}
    }
  for(int i=0;i<N;i++)
    {
      cout<<"\nCircle or Rectangle at position "<<i+1<<" of second array?(c/r) : ";
      cin>>shape_type;
      switch(shape_type)
	{
	case 'r':
	case 'R':
	  cout<<"Enter values for Top-Left cordinates of rectangle : ";
	  cin>>x_inp>>y_inp;
	  cout<<"\nEnter length and breadth : ";
	  cin>>val1>>val2;
	  arr2[i]=new rectangle(x_inp,y_inp,val1,val2);
	  break;
	case 'c':
	case 'C':
	  cout<<"\nEnter the values for centre of the circle : ";
	  cin>>x_inp>>y_inp;
	  cout<<"\nEnter value for radius : ";
	  cin>>val1;
	  arr2[i]=new circle(x_inp,y_inp,val1);
	  break;
	default:
	  cout<<"\nWrong value entered ";
	  i--;
	}
    }
  for(int i=0;i<N;i++)
    {
      shape_comparator dummy(arr1[i],arr2[i]);
    }
  cout<<"\nThe number of shapes equal at corresponding positions are : "<<shape_comparator::both;
  cout<<"\n";
  return 0;
}
