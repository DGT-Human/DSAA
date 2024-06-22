#include <iostream>
using namespace std;
int quick(int a[], int l, int r)
{
    int x=a[l], i=l+1, j=r;
    do
    {
        while (i<=j&&(a[i]<=x))
        i++;
        while (i<=j&&(a[j]>x))
        j--;
        if(i<j)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++; //phan tu trai da xet, tang len
            j--; //phan tu phai da xet, giam xuong
        }
    }while (i<=j);
    int tem=a[l];
    a[l]=a[j];
    a[j]=tem;
    return j;
}
void quicksort(int a[], int l, int r)
{
    int k;
    if (l<r)
    {
        k=quick(a,l,r);
        quicksort(a,l,k-1);
        quicksort(a,k+1,r);
    }
}
void nhapmang(int a[], int &n)
{
	cout << "nhap n: ";
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
  
int main()
{
    int a[100],n;
    nhapmang(a,n);
    quicksort(a, 0, n-1);
    xuatmang(a, n);
  
}
