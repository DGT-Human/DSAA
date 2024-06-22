#include<iostream>
using namespace std;
void nhapmatran(int a[][100], int &c, int &d )
{
    for(int i=0; i<d; i++)
        for(int j=0; j<c; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
        }
}
void xuatmatran(int a[][100], int c, int d)
{
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<c; j++)
            cout<<a[i][j]<<"  ";
        cout<<endl;
    }
}
void biendoi2s1(int a[][100], int b[], int d, int c, int &k)
{
    k=0;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<c;j++)
        {
            b[k++]=a[i][j];
        }
    }
}
void SapXepTang(int a[], int n)
{ 
    int i, j;
    for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
            { 
                if (a[i] > a[j])
                {
                    int tam = a[i];
                    a[i] = a[j]; 
                    a[j]= tam;
                }
            }    
}
void tangdan(int x[][100], int b[], int c, int d)
{
	int t=0;
	for(int i=0; i<d; i++)
		for(int j=0; j<c; j++)
			x[i][j]=b[t++];
}
int main ()
{
	int c,d,k;
    int a[100][100],b[100],x[100][100];
    cout<<"Nhap dong";
    cin>>d;
    cout<<"Nhap cot";
    cin>>c;
    nhapmatran(a,c,d);
    biendoi2s1(a,b,d,c,k);
    SapXepTang(b,k);
    tangdan(x,b,c,d);
    xuatmatran(x,c,d);
}
