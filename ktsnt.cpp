#include <iostream>
using namespace std;

bool KTSNT(int x)
{
	if(x<2)
		return false;
	for(int i=2; i<=x/2; i++)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	int n;
	cout<<"Nhap vao so nguyen duong n: ";
	cin>>n;
	if(KTSNT(n)==true)
		cout<< n << " la so nguyen to!";
	else
		cout<< n <<" khong la so nguyen to!";
	cout<<endl;
}

