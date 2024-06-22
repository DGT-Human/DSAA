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
void  tim ( int a[], int n , int x )
{
    int dem = 0;
    cout << "\n nhap gia tri can tim x = ";
    cin  >> x;
    for ( int i = 0 ; i < n ; i++)
    {
        if ( a[i] == x )
        {  
            cout<< "  \nphan tu  " << x << " co o trong phan tu cua mang o vi tri " <<  i ;
           
        }
    }
}
int main()
{
	int a[100], n, x;
	nhapmang(a,n);
	xuatmang(a,n);
	tim(a,n,x);
}
