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
void xoan(int b[], int x[][100], int c, int d)
{
    int t=0;
    int d1=0;
    int d2=d;
    int c1=0;
    int c2=c;
    while(d1<d2&&c1<c2)
    {
    	for(int i=c1;i<c2;i++)
    	{
        	x[d1][i]=b[t];
        	++t;
   	 	}
    	++d1;
    	for(int i=d1;i<d2;i++)
    	{
        	x[i][c2-1]=b[t];
        	++t;
    	}
    	--c2;
    	if(d1<d2)
    	{
        	for(int i=c2-1;i>=c1;i--)
        	{
            	x[d2-1][i]=b[t];
            	++t;
        	}
    	--d2;
    	}
    	if(c1<c2)
    	{
        	for(int i=d2-1;i>=d1;i--)
        	{
            	x[i][c1]=b[t];
            	++t;
        	}
    	++c1;
    	}
	}	
}
int main()
{
    int a[100][100],x[100][100],b[100];
    int c,d,k;
    cout<<"Nhap dong";cin>>d;
    cout<<"Nhap cot";cin>>c;
    nhapmatran(a,c,d);
    biendoi2s1(a,b,d,c,k);
    SapXepTang(b,k);
    xoan(b,x,c,d);
    xuatmatran(x,c,d);
}
