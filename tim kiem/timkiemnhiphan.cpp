#include <iostream>
using namespace std;
int binarysearch(int a[], int size, int x)
{
	int left=0, mid;
	int right=size-1;
	while (left<right)
	{
		mid=(left+right)/2;
		if(x==a[mid])
			return mid;
		else 
			if(x<a[mid])
				right=mid+1;
			else
				left=mid+1;		
	}
	return -1;
}
void nhapmang(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
void selectionSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
    min= i;
    for (j = i+1; j < n; j++)
        if (a[j] < a[min])
        min = j;
      int temp=a[min];
      a[min]=a[i];
      a[i]=temp;
    }
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout <<a[i]<< " ";
}
int main ()
{
	int a[100];
	int n,x;
	cout<<"nhap n: ";
	cin>>n;
	nhapmang(a,n);
	selectionSort(a,n); 
	xuatmang(a,n); 
	cout<<"\nnhap gia tri can tim: ";
	cin>>x;
	if (binarysearch(a,n,x)==-1)
		cout<<"khong tim duoc";
	else 
		cout<<"phan tu "<<x<<" o vi tri: "<<binarysearch(a,n,x);
}
