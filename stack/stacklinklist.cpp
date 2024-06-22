#include<iostream>
using  namespace std;
struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
struct stack
{
    NODE *top;
};
typedef struct stack STACK;
void khoitaostack(STACK &s)
{
    s.top=NULL; //stack chua co phan tu
}
bool empty(STACK s)
{
    if(s.top==NULL)
        return true;
    return false;
}
NODE *khoitaonode(int n)
{
    NODE *p=new NODE;
    if(p==NULL)
    {
        cout<<"Khong du bo nho";
        return NULL;
    }
    p->data=n;
    p->next=NULL;
    return p;
}
void push(STACK &s, NODE *p)
{
    if(empty(s)==true)
        s.top=p;
    else
    {
        p->next=s.top;
        s.top=p;
    }
}
bool pop(STACK &s, int &x)
{
    if(empty(s)==true)
        return false;
    else
    {
       NODE *p=s.top;
        x=p->data;
        s.top=s.top->next;
        delete p;   
    }
    return true;
}
bool peek(STACK &s, int &x)
{
    if(empty(s)==true)
    {
        return false;
    }
    x=s.top->data;
    return true;
}
void xuat(STACK s)
{   NODE *cur=s.top;
    while(cur!=NULL)
    {
        cout<<"\n"<<cur->data<<endl;
        cur=cur->next;
    } 
        cout<<endl;
}
void menu(STACK &s)
{
	NODE *p;
    int x;
    int luachon;
	while (true)
	{
		cout<<"\n\n\t\t======menu======";
		cout<<"\n1. them phan tu vao";
		cout<<"\n2. xuat phan tu";
		cout<<"\n3. hien thi phan tu dau";
		cout<<"\n4. xoa phan tu dau";
        cout<<"\n\n\t\t======END======";
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
        	cout<<"Nhap gia tri so nguyen: ";
        	cin>>x;
        	p=khoitaonode(x);
            push(s,p);
		}
		else if (luachon==2)
		{
			cout<<"Cac phan tu trong stack la: ";
			xuat(s);
		}
		else if (luachon==3)
		{
			if(peek(s,x)==true)
            cout<<"Phan tu dau la: "<<x;
            else
            cout<<"khong co phan tu ";
        }
		else if (luachon==4)
		{
			if(pop(s,x)==true)
			{
            cout<<"Da xoa phan tu "<<x<<" ra khoi danh sach"<<endl;
            xuat(s);
        	}
            else
            cout<<"khong con phan tu de xoa"<<endl;
		}
    }
}
int main ()
{
	STACK s;
	khoitaostack(s);
    menu(s);
	system("pause");
	return 0;
}
