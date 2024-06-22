#include<iostream>
using  namespace std;
struct NODE
{
    int data;
    NODE *next;
};
struct STACK
{
    NODE *top;
};
void khoitaostack(STACK &s)
{
    s.top=NULL; //stack chua co phan tu
}
bool kiemtrarong(STACK s)
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
bool push(STACK &s, NODE *p)
{
    if(p==NULL)
    {
        return false ;
    }
    if(kiemtrarong(s)==true)
        s.top=p;
    else
    {
        p->next=s.top;
        s.top=p;
    }
    return true;
}
bool pop(STACK &s, int &x)
{
    if(kiemtrarong(s)==true)
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
    if(kiemtrarong(s)==true)
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
        cout<<cur->data<<" ";
        cur=cur->next;
    } 
        cout<<endl;
}
void chuyensangnhiphan(STACK &s,int thapphan)
{
    while(thapphan!=0)
    {
        int x=thapphan%2;
        NODE *p=khoitaonode(x);
        push(s,p);
        thapphan=thapphan/2;
    }
}
int main()
{
    int thapphan;
    STACK s;
    khoitaostack(s);
    cout<<"Nhap so thap phan can chuyen doi: ";
    cin>>thapphan;
    chuyensangnhiphan(s,thapphan);
    cout<<"So thap phan sau khi chuyen sang nhi phan la: ";
    xuat(s);
}
