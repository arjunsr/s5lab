#include<iostream>
#include<cstdlib>
#define default_size 10
using namespace std;
template <class T>
class vector
{
  T *v;
  int size;
public:
  T mul,oldval,newval;
  vector()
  {
    v=new T[default_size];
    for(int i=0;i<default_size;i++)
      {
	v[i]=0;
      }
    size=default_size;
  }
  vector(int s)
  {
    v=new T[s];
    for(int i=0;i<s;i++)
      {
	v[i]=0;
      }
    size=s;
  }
  int modify_elem(T oldvalue,T newvalue)
  {
    int i;
    for( i=0;i<size;i++)
      {
	if(v[i]==oldvalue)
	  {
	    v[i]=newvalue;
	    break;
	  }
      }
    if(i==size)
      {
	cout<<"\n Value not found";
      }
    return(0);
  }
  void show()
  {
    cout<<"\n";
    for(int i=0;i<size;i++)
      {
	cout<<v[i]<<",";
      }
    cout<<"\b";
  }
  void operator *(T val)
  {
    for(int i=0;i<size;i++)
      {
	v[i]=val*v[i];
      }
  }
  void initialize(int mode)
  {
    if(mode==1)
      {
	for(int i=0;i<size;i++)
	  {
	    v[i]=i+4;
	  }
      }
    else
      {
	T val;
	for(int i=0;i<size;i++)
	  {
	    cout<<"\n>>";
	    cin>>val;
	    v[i]=val;
	  }
	cout<<"\nFinished";
      }
  }
};


int main()
{
  int input,i,ch,size;
  //cout<<"\nInput the type of vector \n1.Int \n2.Float \n3.Double \n4.Char";
  //cin>>ch;
 cout<<"size:";
 i=ch;
 cin>>size;
 vector<int> V(size);
 cout<<"\n Add elements to the vector:";
 V.initialize(0);
 V.show();
 cout<<"\nInput the value to be modified";
 cin>>V.oldval;
 cout<<"\nInput the new value";
 cin>>V.newval;
 V.modify_elem(V.oldval,V.newval);
 V.show();
 // if(ch!=4)
   {
     cout<<"\nInput the value to be multiplied:";
     cin>>V.mul;
     V*V.mul;
     V.show();
      }
 return(0);
}
