#include<iostream>
using namespace std;
#define COUNT 10
struct NODE
{
    int data;
    NODE *right;
    NODE *left;
};
int chieucao(NODE *&t)
{
    if(t!=NULL)
    {
        int l=chieucao(t->left)+1;
        int r=chieucao(t->right)+1;
        return l>r?l:r;
    }
    return 0;
}
int chiso(NODE *&t)
{
    int hl=chieucao(t->left);
    int hr=chieucao(t->right);
    int delta=hl-hr;
    return delta;
}
void xoayphai(NODE *&t)
{
    NODE *temp=t->left;
    t->left=temp->right;
    temp->right=t;
    t=temp;
}
void xoaytrai(NODE *&t)
{
    NODE *temp=t->right;
    t->right=temp->left;
    temp->left=t;
    t=temp;
}
void Khoitaocay(NODE *&t)
{
    t=NULL;
}
void Canbang(NODE *&t)
{
    if(t!=NULL)
    {
        if(chiso(t)==2)
        {
            if(chiso(t->left)==1||chiso(t->left)==0)
                xoayphai(t);
            else
                if(chiso(t->left)==-1)
                {
                    xoaytrai(t->left);
                    xoayphai(t);
                }
        }
        else
            if(chiso(t)==-2)
            {
                if(chiso(t->right)==1)
                {
                    xoayphai(t->right);
                    xoaytrai(t);
                }
                else 
                    if(chiso(t->right)==-1||chiso(t->right)==0)
                    {
                        xoaytrai(t);
                    }
            }
        Canbang(t->left);
        Canbang(t->right);
    }
    else
        return;    
}
void themvaocay(NODE *&t,int x)
{
    if(t==NULL)
    {
        NODE *p=new NODE;
        p->data=x;
        p->right=NULL;
        p->left=NULL;
        t=p;
    }
    else
    {
        if(t->data>x)
            themvaocay(t->left,x);
        else if(t->data<x)
            themvaocay(t->right,x);
    }   
}
void Duyet_NLR(NODE *&t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        Duyet_NLR(t->left);
        Duyet_NLR(t->right);
    }
}
void Duyet_LNR(NODE *&t)
{
    if(t!=NULL)
    {
        Duyet_LNR(t->left);
        cout<<t->data<<" ";
        Duyet_LNR(t->right);
    }
}
NODE *timkiem(NODE *&t,int x)
{
    if (t!=NULL)
    {
        if (t->data == x)
            return t;
        if (t->data > x)
            return timkiem(t->left, x);
        else
            return timkiem(t->right, x);
    }
    return NULL;
}
void NODE_the(NODE *&X, NODE *&Y)
{
    if(Y->left!=NULL)
        NODE_the(X,Y->left);
    else
    {   
        X->data=Y->data;
        X=Y->left;
        Y=Y->right;
    }   
}
void Xoa(NODE *&t, int x)
{
    if(t==NULL)
        return;
    else if(t->data>x)
        Xoa(t->left,x);
    else if(t->data<x)
        Xoa(t->right,x);
    else
    {
        NODE *X=t;
        if(t->right==NULL)
            t=t->left;
        else if(t->left==NULL)
            t=t->right;
        else
        {    
            NODE_the(X,t->right);
        }       
    delete X;
    }     
}
void Huycay(NODE *&t)
{
    if(t!=NULL)
    {
        Huycay(t->left);
        Huycay(t->right);
        delete t;
    }
}
void Menu(NODE *&t)
{
    int luachon;   
    while(true)
    {
        cout<<"\n1.Them vao cay";
        cout<<"\n2.Duyet LNR";
        cout<<"\n3.Duyet NLR";
        cout<<"\n4.Xoa bat ky";
        cout<<"\n5.Huy cay";
        cout<<"\n6.Tim kiem";
        cout<<"\n7.in node root";
        cout<<"\n\n\t\t========END========";
        cout<<"\nNhap lua chon: ";
        cin>>luachon;
        if(luachon==1)
        {   
            int x;
            cout<<"Nhap gia tri so nguyen: ";
            cin>>x;
            themvaocay(t,x);
            Canbang(t);
        }
        else if(luachon==2)
            Duyet_LNR(t);
        else if(luachon==3)
            Duyet_NLR(t);
        else if(luachon==4)
        {
            int del;
            cout<<"Nhap gia tri can xoa: ";
            cin>>del;
            Xoa(t,del);
            Canbang(t);
        }
        else if(luachon==5)
        {
          Huycay(t);
          if(t==NULL);
            cout<<"Da xoa cay";
        }
        else if(luachon==6)
        {
            int search;
            cout<<"Nhap gia tri can tim: ";
            cin>>search;
            NODE *temp=NULL;
            temp=timkiem(t,search);
            if(temp==NULL)
                cout<<"Khong co phan tu "<<search<<" trong cay";
            else
                cout<<"Co phan tu "<<search<<" trong cay";
        }
        else if(luachon==7)
        {
            cout<<"node goc: "<<t->data;
        }
        else
            break;       
    }
}
int main()
{
    NODE *t;
    Khoitaocay(t);
    Menu(t);
    system("pause");
    return 0;
}
