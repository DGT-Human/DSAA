#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;
struct list
{
	 NODE *phead;
	 NODE *plast;
};
typedef struct list LIST;
void khoitao(LIST &l)
{
	l.phead=NULL;
	l.plast=NULL;
}
NODE *khoitaonode(int n)
{
	NODE *p=new NODE;
	p->data=n;
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void themnodecuoi (LIST &l, NODE *p)
{
	if(l.phead==NULL)
	{
		l.phead=l.plast=p;
	}
	else
	{
		l.plast->next=p;
		p->prev=l.plast;
		l.plast=p;
	}
	
}
void nhapdslk(LIST &list, NODE *p)
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
        themnodecuoi(list,p);   
    }
}
void addcuoi(LIST &l)
{
	int x;
	cout<<"nhap gia tri ";
	cin>>x;
	NODE *q=khoitaonode(x);
	NODE *cur=l.phead;
	while (cur)
	{
		if(cur->next==NULL)
		{
			cur->next=q;
			q->prev=cur;
			return;
		}
		cur=cur->next;
	}
}
void adddau(LIST &l)
{
	int x;
	cout<<"\nnhap gia tri ";
	cin>>x;
	NODE *q=new NODE;
	q->data=x;
	q->next=l.phead;
	l.phead->prev=q;
	l.phead=q;
	
}
void xoadau(LIST &l)
{
	NODE *p=l.phead;
	l.phead=l.phead->next;
	l.phead->prev=NULL; 
	p->next=NULL;
	delete p;
	return;
}
void xoacuoi(LIST &l)
{
		for(NODE *k=l.phead; k!=NULL; k=k->next)
	{
		if(k->next==l.plast)
		{
			delete l.plast;
			k->next=NULL;
			l.plast=k;
			return;
		}
	}
}
void xoabatky(LIST &l, int x)
{
	if (l.phead->data==x)
	{
		xoadau(l);
		return;
	}
	if (l.plast->data==x)
	{
		xoacuoi(l);
		return;
	}
	NODE *g=new NODE;
	for (NODE *k=l.phead; k->next!=NULL; k=k->next)
	{
		if (k->data==x)
		{
			g=k->prev; 
			g->next=k->next;
			k->next->prev=g;
			delete k;
			return;
		}
	}
} 
void dao(LIST &l)
{
	NODE *cur=l.phead;
	//NODE *prev=l.phead;
	NODE *temp=NULL;
	while(cur!=NULL)
	{
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		cur=cur->prev;
	}
	if(temp!=NULL)
	l.phead=temp->prev;
}
int timphantu (LIST &l, int x)
{
	int k=0;
	NODE *q=l.phead;
	do{
		if(q->data==x)
		k++;
		q=q->next; 
	}while(q!=NULL);
	return k;
}
void xoalist(LIST &l)
{ 
	while(l.phead!=NULL)
	{
		NODE *p=l.phead;
		l.phead=l.phead->next;
		p->next=NULL;
		delete p;
	}
	cout<<"da xoa danh sach"; 
}
void copy(LIST l, LIST &l2)
{
    NODE *cur=l.phead;
    if(l.phead==NULL)
        return;
    else
    {
        do 
        {
            NODE *temp = new NODE;
            temp->data = cur->data;
            temp->next=NULL;
            temp->prev=NULL;
            if(l2.phead==NULL)
            {
                l2.plast = temp;
                l2.phead = temp;
                l2.plast->next = NULL;
                l2.phead->prev=NULL;
            }
            else 
            {
                l2.plast->next=temp;
                temp->prev=l2.plast;
                l2.plast=temp;
            }
            cur= cur->next;
        }  
        while (cur!=NULL);       
    }
}
int sosanh(LIST l, LIST l3)
{  
    NODE *temp=l.phead;
    NODE *temp2=l3.phead;
    int dem1=1, dem2=1;
    while(temp!=NULL&&temp2!=NULL)
    {
        if(temp->data!=temp2->data)
            return -1;
        temp=temp->next;
        if(temp!=NULL)
        	dem1++;
        temp2=temp2->next;
        if(temp2!=NULL)
        	dem2++;
    }
    if (dem1!=dem2)
    	return -1;
    return 1;
} 
void xuatdslk(LIST l)
{   
	if(l.phead==NULL)
	return;
	NODE *cur=l.phead;
    do
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    } while (cur!=NULL);  
        cout<<endl;
}
void xuat(LIST l)
{
	for(NODE *k=l.phead; k!=NULL; k=k->next)
	{
		cout<<k->data<<" ";
	}
}
void menu(LIST &l, LIST &l2, LIST &l3)
{
	NODE *p;
	int luachon;
	while (true)
	{
		cout<<"\n\n\t\t======menu======";
		cout<<"\n1. them node vao danh sach";
		cout<<"\n2. xuat";
		cout<<"\n3. them node dau";
		cout<<"\n4. them node cuoi";
		cout<<"\n5. xoa node ";
		cout<<"\n6. dao ";
		cout<<"\n7. tim phan tu ";
		cout<<"\n8. xoa danh sach lien ket";
		cout<<"\n9. copy danh sach";
		cout<<"\n10. so sanh danh sach";
		cout<<"\n\n\t\t======END======";
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
			nhapdslk(l,p);
		}
		else if (luachon==2)
		{
			cout<<"danh sach lien ket : ";
			xuat(l);
		}
		else if (luachon==3)
		{
			adddau(l);
		}
		else if (luachon==4)
		{
			addcuoi(l);
		}
		else if (luachon==5)
		{
			int x;
			cout<<"\nnhap node can xoa: ";
			cin>>x;
			xoabatky(l,x);
		}
		else if (luachon==6)
		{
			dao(l);
		}
		else if (luachon==7)
		{
			int x;
			cout<<"nhap phan tu can tim: ";
			cin>>x;
			cout<<"so lan xuat hien cua phan tu "<<x<<" la "<<timphantu(l,x);
		}
		else if (luachon==8)
		{
			xoalist(l);
		}
		else if (luachon==9)
		{
			copy(l,l2);
			cout<<"danh sach duoc copy: ";
			xuat(l2);	
		}
		else if (luachon==10)
		{
			nhapdslk(l3,p);
			if(sosanh(l,l3)==-1)
				cout<<"khong giong nhau\n";
			else
				cout<<"2 danh sach giong nhau\n";
			xoalist(l3); 
		}
	}
}
int main ()
{
	LIST l,l2,l3;
	khoitao(l);
	khoitao(l2);
	khoitao(l3); 
	menu(l,l2,l3);
	system("pause");
	return 0;
}


