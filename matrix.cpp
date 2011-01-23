#include<iostream>
using namespace std;
class matrix
{
  
  int A[20][20];
  int m,n;
public:
  matrix()
  {
    int i,j;
    for(i=0;i<10;i++)
      {
	for(j=0;j<10;j++)
	  {
	    A[i][j]=0;
	  }
      }
  }
  void read()
  {
    int i,j;
    cout<<"Enter matrix  row and colomn  : ";
    cin>>m>>n;
    cout<<"\nEnter matrix  : \n";
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    cout<<"Enter element "<<i+1<<" "<<j+1<<" : ";
	    cin>>A[i][j];
	  }
      }
    
  }
  void show()
  {
    
    int i,j;
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    cout<<"\t"<<A[i][j];
	  }
	cout<<"\n";
      }
  }
  matrix add(matrix a)
  {
    
    matrix temp;
    int i,j;
    if(m!=a.m||n!=a.n)
      {
	cout<<"Cannot add   :";
	exit(0);
      }
    else
      {
	temp.m=m;
	temp.n=n;
	for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	      {
		temp.A[i][j]=A[i][j]+a.A[i][j];
	      }
	  }
	
        
	return(temp);
      }
  }
  
  matrix sub(matrix a)
  {
    
    matrix temp;
    int i,j;
    if(m!=a.m||n!=a.n)
      {
	cout<<"Cannot sub   :";
	exit(0);
      }
    else
      {
	temp.m=m;
	temp.n=n;
	for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	      {
		temp.A[i][j]=A[i][j]-a.A[i][j];
	      }
	  }
	
        
	return(temp);
      }
  }
  matrix mul(matrix a)
  {
    int i,j,k,l,sum=0;
    matrix temp;
    if(n!=a.m)
      {
	cout<<"\nCannot multiply  ";
	exit(0);
      }
    else
      {
	temp.m=m;
	temp.n=a.n;
	for(k=0;k<m;k++)
	  {
	    for(l=0;l<a.n;l++)
	      {
		for(j=0;j<n;j++)
		  {
		    sum=sum+A[k][j]*a.A[j][l];
		  }
		temp.A[k][l]=sum;
		sum=0;
	      }
	  }
	
	
	return(temp);
	
      }
  }
  
  matrix trans()
  {
    matrix temp;
    temp.m=m;
    temp.n=n;
    
    int i,j;
    for(i=0;i<m;i++)
      {
	for(j=0;j<n;j++)
	  {
	    temp.A[j][i]=A[i][j];
	  }
      }
    return(temp);
    
  }
  
};
int main()
{
  matrix h1,h2,h3;
  int c;
  cout<<"\nMENU ";
  cout<<"\n1.Add";
  cout<<"\n2.Substract";
  cout<<"\n3.Multiply";
  cout<<"\n4.Transpose";
  cout<<"\nAny other for exit...";
  cout<<"\nEnter the choice : ";
  cin>>c;
  if(c==1)
    {
      h1.read();
      h2.read();
      cout<<"\nSum\n";
      h3=h1.add(h2);
      h3.show();
    }
  if(c==2)
    {
      h1.read();
      h2.read();
      cout<<"\nDifference\n";
      h3=h1.sub(h2);
      h3.show();
    }
  if(c==3)
    {
      h1.read();
      h2.read();
      cout<<"\nProduct \n ";
      h3=h1.mul(h2);
      h3.show();
    }
  if(c==4)
    {
      h1.read();
      cout<<"\nTranspose \n";
      h2=h1.trans();
      h2.show();
    }
  return(0);
}
