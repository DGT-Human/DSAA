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
void merge(int a[], int l, int m, int r)
{
	int i=l, j=m+1, k=0, n=r-l+1;
	int *b=new int[n];
	while((i<m+1)&&(j<r+1))
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			k++;i++;
		}
		else
		{
			b[k]=a[j];
			k++;j++;
		}
	}
	while(i<m+1)
	{
		b[k]=a[i];
		k++;i++;
	}
	while(j<r+1)
	{
		b[k]=a[j];
		k++;j++;
	}
	i=l;
	for(k=0;k<n;k++)
	{
		a[i]=b[k];
		i++;
	}
	delete [] b;
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
  
        merge(arr, l, m, r);
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
    mergeSort(a, 0, n - 1);
    xuatmang(a, n);
  
}

