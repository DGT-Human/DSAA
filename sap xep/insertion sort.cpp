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
void sapchen(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int t = a[i];
		while (t < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = t;
	}
}
int main()
{
	int a[100], n;
	nhapmang(a, n);
	sapchen(a, n);
	xuatmang(a, n);
}
