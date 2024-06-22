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
int main ()
{
	int a[100],n;
	nhapmang(a,n);
	selectionSort(a,n);
	xuatmang(a,n);
}
