#include<iostream.h>
class shape
{
public:
  virtual void getdata()=0;
  virtual void calculate_area()=0;
  virtual void display_area()=0;
};

class rectangle:public shape
{
  unsigned double length,breadth;
  unsigned  double area;
public:
  void getdata()
  {
    cout<<"Enter the value of length:";
    cin>>l;
    cout<<"Enter the value of breadth:";
    cin>>b;
  }
  void calculate_area()
  {
    area=l*b;
  }
  void display_area()
  {
    cout<<"Area of rectangle:"<<area<<"\n";
  }
};
class triangle:public shape
{
  double base,height;
  double area;
public:
  void getdata()
  {
    cout<<"Enter the value of base:";
    cin>>base;
    cout<<"Enter the value of height:";
    cin>>height;
  }
  void calculate_area()
  {
    area=.5*base*height;
  }
  void display_area()
  {
    cout<<"Area of triangle:"<<area<<"\n";
  }
};
int main()
{
  shape *p;
  rectangle ob;
  triangle obj;
  p=&ob;
  p->getdata();
  p->calculate_area();
  p->display_area();
  p=&obj;
  p->getdata();
  p->calculate_area();
  p->display_area();
  return 0;
}

