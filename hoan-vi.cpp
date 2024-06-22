#include <iostream >
using namespace std; 
int main ()
{
	int a,b,temp;
	cout<<"nhap a= "; cin>>a;
	cout<<"nhap b= "; cin>>b;
	temp=a;
	a=b;
	b=temp;
	cout<<"a= "<<a<<endl; 
	cout<<"b= "<<b<<endl;
 } 
