#include <iostream>
using namespace std;
void nhapmang(int a[], int &n)
{
	cout << "nhap n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout <<a[i]<< " ";
}
void bubble (int a[], int n)
{
	int i,j;
	for (i=0; i<n-1; i++)
	{
		for (j=n-1; j>i; j--)
		{
			if(a[j]<a[j-1])
			{
				int temp=a[j-1];
				    a[j-1]=a[j];
				    a[j]=temp;
				    
			}
		}
	}
}
int main ()
{
	int a[100], n;
	nhapmang(a,n);
	bubble(a,n);
	xuatmang(a,n);
}
