#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
struct queue
{
    NODE *front;
    NODE *rear;
};
typedef struct queue QUEUE;
void khoitaoqueue(QUEUE &q)
{
    q.front=NULL; 
    q.rear=NULL;
}
NODE *khoitaonode(int n)
{
    NODE *p=new NODE;
    p->data=n;
    p->next=NULL;
    return p;
}
bool empty(QUEUE q)
{
    if(q.front==NULL)
        return true;
    return false;
}
bool enqueue(QUEUE &q, NODE *p)
{
    if(p==NULL)
    {
        return false ;
    }
    if(empty(q)==true)
        q.front=q.rear=p;
    else
    {
        q.rear->next=p;
        q.rear=p;
    }
    return true;
}
bool dequeue(QUEUE &q, int &x)
{
    if(empty(q)==true)
        return false;
    else
    {
       NODE *p=q.front;
        x=p->data;
        q.front=q.front->next;
        delete p;   
    }
    return true;
}
bool front(QUEUE &q, int &x)
{
    if(empty(q)==true)
    {
        return false;
    }
    x=q.front->data;
    return true;
}
void nhap(QUEUE &q, NODE *p)
{
    int n;
    cout<<"Nhap so luong node can them:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cout<<"Nhap gia tri so nguyen: ";
        cin>>x;
        p=khoitaonode(x);
        enqueue(q,p);   
    }
}
void xuat(QUEUE p)
{
	for(NODE *k=p.front; k!=NULL; k=k->next)
	{
		cout<<k->data<<" ";
	}
}
void menu(QUEUE &q)
{
	NODE *p;
    int x;
    int luachon;
	while (true)
	{
		cout<<"\n\n\t\t======menu======";
		cout<<"\n1. nhap danh sach";
		cout<<"\n2. xuat danh sach";
		cout<<"\n3. hien thi phan tu vi tri dau";
		cout<<"\n4. xoa phan tu o vi tri dau dau";
        cout<<"\n\n\t\t======END======";
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
            nhap(q,p);
		}
		else if (luachon==2)
		{
			cout<<"Cac phan tu trong queue la : ";
			xuat(q);
		}
		else if (luachon==3)
		{
			if(front(q,x)==true)
            cout<<"Phan tu dau la "<<x;
            else 
            cout<<"khong co phan tu nao";
        }
		else if (luachon==4)
		{
			if(dequeue(q,x)==true)
			cout<<"da xoa phan tu "<<x<<" ra khoi danh sach"<<endl;
			else
			cout<<"khong con phan tu nao"<<endl;
		}
    }
}
int main ()
{
	QUEUE q;
	khoitaoqueue(q);
    menu(q);
	system("pause");
	return 0;
}
