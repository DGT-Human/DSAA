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
void biendoi(int a[], int n)
{
	int i,j;
	int temp;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
		    }
		}
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout <<a[i]<< " ";
	}
}
int main ()
{
	int a[100],n;
	nhapmang(a, n);
	biendoi(a, n);
	xuatmang(a, n);
}
