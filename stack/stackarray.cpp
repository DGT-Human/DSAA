#include<iostream>
using namespace std;
int top=-1;
bool empty()
{
    if(top==-1)
        return true;
    else 
        return false;       
}
bool max()
{
    if(top==100-1)
        return true;
    else 
        return false;
}
void push(int stack[], int n)
{
    if(max()==true)
        cout<<"STACK da day";
    else
        top++;
        stack[top]=n;
}
void pop(int stack[])
{
    if(empty()==true)
        cout<<"da rong";
    else
    {
        cout<<"da xoa phan tu dau: "<<stack[top];
        top--;
    }
}
int peek(int stack[])
{
	if(empty()==true)
		return -1;
    return stack[top];
}
void xuat(int stack[], int n) 
{
    for (int i = top; i >-1; i--)
        cout <<"\n"<<stack[i] <<endl;
}
void menu(int stack[], int &n)
{
    int x;
    int luachon;
	while (true)
	{
		cout<<"\n\n\t\t======menu======";
		cout<<"\n1. them phan tu";
		cout<<"\n2. xuat";
		cout<<"\n3. hien thi phan tu dau";
		cout<<"\n4. xoa phan tu dau";
        cout<<"\n\n\t\t======END======";
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
            cout<<"Them vao stack:";
            cin>>x;
            push(stack,x);
        
		}
		else if (luachon==2)
		{
			cout<<"Cac phan tu trong stack la : ";
			xuat(stack,n);
		}
		else if (luachon==3)
		{
			if(peek(stack)==-1)
			cout<<"khong co phan tu nao";
			else
            cout<<"Phan tu dau la: "<<peek(stack);
        }
		else if (luachon==4)
		{
			pop(stack);
		}
    }
}
int main ()
{
    int stack[100];
    int n;
    menu(stack,n);
	system("pause");
	return 0;
}


