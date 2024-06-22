#include<iostream>
#include<math.h>
using namespace std;
int  GiaiPTB2(float a, float b, float c, float &x1, float &x2){
	float delta;
	if(a==0){
		if(b==0){
			if(c==0)
			{
				x1=999999999;
				return 1;
		    }
			else
			{
				x1=-999999999;
				return 2;
			}
		}
		else 
			x1=(-c/b);
			return 3;
	}
	else{
		delta=pow(b,2)-(4*a*c);
		if(delta>0)
		{
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			return 4;
	    }
		if(delta==0)
		{
			x1=-b/2*a;
			return 5;
		}
		if(delta<0)
		{
			x1=-999999999;
			return 6;
	    }
	}
}
int main(){
	float a, b, c,x1,x2;
	cout<<"Nhap vao a b va c"<<endl;
	cout<<"a= ";
	cin>>a;
	cout<<"b= ";
	cin>>b;
	cout<<"c= ";
	cin>>c;
	float  x=GiaiPTB2(a, b, c, x1, x2);
	if(x==1)
	cout<<"phuong trinh vo so nghiem ";
	if(x==2)
	cout<<"phuong trinh vo nghiem ";
	if(x==3)
	cout<<"phuong trinh co nghiem "<<x1;
	if(x==4)
	{
	cout<<"phuong trinh co 2 nghiem "<<endl;
	cout<<"x1= "<<x1<<endl;
	cout<<"x2= "<<x2<<endl;
	}
	if(x==5)
	cout<<"phuong trinh co nghiem kep "<<x1; 
	if(x==6)
	cout<<"phuong trinh vo nghiem";
}
