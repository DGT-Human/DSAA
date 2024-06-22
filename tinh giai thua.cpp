#include <iostream>
using namespace std;
void giaithua (int n)
{
	int giaithua=1;
	for (int i=1; i<=n; i++)
		giaithua*=i;
	cout<<"giai thua "<<n<<" la "<<giaithua;
}
int main()
{
	int n;
	cout<<"nhap n "; cin>>n;
	giaithua(n);
	return 0;
}
