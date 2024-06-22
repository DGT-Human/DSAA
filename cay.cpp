#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
typedef struct node NODE;
void khoitaocay (NODE* &p)
{
	p=NULL;
}
void themnodevaocay (NODE* &p, int x)
{
	if(p==NULL)
	{
		NODE *q=new NODE;
		q->data=x;
		q->left=NULL;
		q->right=NULL;
		p=q;
	}
	else 
	{
		if (p->data==x)
			return;
		if (p->data > x)
			themnodevaocay(p->left,x);
		else 
			themnodevaocay(p->right,x);
	}
}
void NLR (NODE *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		NLR(p->left);
		NLR(p->right);
	}
}
void LNR (NODE *p)
{
	if(p)
	{
		LNR(p->left);
		cout<<p->data<<" ";
		LNR(p->right);
	}
}
void LRN (NODE *p)
{
	if(p)
	{
		LRN(p->left);
		LRN(p->right);
		cout<<p->data<<" ";
	}
}
void duyet (NODE *p)
{
	while(true)
	{
		int x;
		cout<<"\n1.duyet NLR";
		cout<<"\n2.duyet LNR";
		cout<<"\n3.duyet LRN";
		cout<<"\nchon: ";
		cin>>x;
		if(x==1)
			NLR(p);
		else if(x==2)
			LNR(p);
		else if(x==3)
			LRN(p);
		break;
	}
}
NODE* searchNode(NODE *p, int x)
{
	if (p)
	{
		if (p->data == x)
		return p;
		if (p->data > x)
		return searchNode(p->left, x);
		else
		return searchNode(p->right, x);
	}
	return NULL;
}
void themnode(NODE* &p, int x)
{
	if(p)
	{
		if(p->data==x)
			return;
		if(p->data>x)
		return themnode(p->left,x);
		else 
		return themnode(p->right,x);
	}
	p=new node;
	p->data=x;
	p->left=p->right=NULL;
}
void searchstandfor (NODE* &p, NODE* &q)
{
	if(q->left)
		searchstandfor(p,q->left);
	else
	{
		p->data=q->data;
		p=q;
		q=q->right;
	}
}
void delnode (NODE* &p, int x)
{
	if(p==NULL)
		return;
	if(p->data>x)
		delnode(p->left,x);
	if(p->data<x)
		delnode(p->right,x);
	else 
	{
		NODE *temp=p;
		if(p->left==NULL)
			p=p->right;
		else
		{
			if(p->right==NULL)
				p=p->left;
			else
			{
				searchstandfor(temp,p->right);
			}
		}
		delete temp;
	}
	
}
void xoacay(NODE* &p)
{
		if(p!=NULL)
		{
			xoacay(p->left);
			xoacay(p->right);
			delete p;
		}
	return;
}
void menu (NODE* &p)
{
	while(true)
	{
		cout<<"\n\n\t\t ==========MENU==========";
		cout<<"\n1. nhap gia tri";
		cout<<"\n2. duyet gia tri cay";
		cout<<"\n3. tim kiem";
		cout<<"\n4. chen";
		cout<<"\n5. xoa bat ky";
		cout<<"\n6. xoa cay";
		cout<<"\n\n\t\t ==========END==========";
		int luachon;
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			int n;
			cout<<"gia tri: ";
			cin>>n;
			themnodevaocay(p,n);
		}
		else if(luachon==2)
		{
			duyet(p);
		}
		else if(luachon==3)
		{
			int x;
			cout<<"nhap X:";
			cin>>x;
			NODE *t=searchNode(p,x);
			if(t==NULL)
				cout<<"\nkhong ton tai "<<x<<" trong cay";
			else 
				cout<<"\nton tai "<<x<<" trong cay";
		}
		else if (luachon==4)
		{
			int x;
			cout<<"nhap x: ";
			cin>>x;
			themnode(p,x);
		}
		else if (luachon==5)
		{
			int n;
			cout<<"nhap gia tri can xoa: ";
			cin>>n;
			delnode(p,n);
		}
		else if(luachon==6)
		{
			xoacay(p);
			if(p==NULL);
			cout<<"da xoa";
		}
		
	}
}
int main ()
{
	NODE* p;
	khoitaocay(p);
	menu(p);
	return 0;
}
