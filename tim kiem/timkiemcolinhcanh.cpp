#include <iostream>
using namespace std;
void nhap (int a[], int &x)
{
	for(int i=0; i<x; i++)
	{
		cout<<"a["<<i<<"]:";
		cin>>a[i];
	}
}
void xuat (int a[], int x)
{
	for(int i=0; i<x; i++)
	{
		cout<<a[i]<<" ";
	}
} 
int timkiem (int a[], int x, int n)
{
	int i=0;
	a[x]=n;
	while (a[i]!=n) 
	{
		i++;
	}
	return i; 
}
int main ()
{
	int a[100],x,n;
	cout<<"nhap n: ";
	cin>>x;
	nhap(a,x);
	xuat(a,x);
	cout<<"nhap gia tri can tim: ";
	cin>>n;
	if(timkiem(a,x,n)!=x)
		cout<<"gia tri can tim "<<n<<" o vi tri "<<timkiem(a,x,n);
	else
		cout<<"khong tim thay "<<n;
} 
