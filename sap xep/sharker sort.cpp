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
void shark (int a[], int n)
{
	int left=0, right=n-1, k=0;
	while (left<right)
	{
		for(int i=left; i<right; i++)
		{
			if(a[i]>a[i+1])
			{
				int temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
					k=i;
			}
		}
		right=k;
		for(int i=right; i>left; i--)
		{
			if(a[i]<a[i-1])
			{
				int tem=a[i];
					a[i]=a[i-1];
					a[i-1]=tem;
					k=i;
			}
		}
		left=k;
	}
}
int main ()
{
	int a[100],n;
	nhapmang(a,n);
	shark(a,n);
	xuatmang(a,n);
}
