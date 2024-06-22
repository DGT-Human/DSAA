#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
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
		l.plast=p;
		l.plast->next=l.phead; 
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
		if(cur->next==l.phead)
		{
			cur->next=q;
			l.plast=q;
			l.plast->next=l.phead; 
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
	l.phead=q;
	l.plast->next=l.phead; 
	
}
void xoadau(LIST &l)
{
	NODE *p=l.phead;
	l.phead=l.phead->next;
	p->next=NULL;
	delete p;
	l.plast->next=l.phead; 
	return;
}
void xoacuoi(LIST &l)
{
	NODE *cur=l.phead;
	NODE *prev;
	while (cur->next!=l.phead)
	{
		prev=cur;
		cur=cur->next;
	}
	delete cur;
	l.plast=prev; 
	prev->next=l.phead;
	return;
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
	for (NODE *k=l.phead; k->next!=l.phead; k=k->next)
	{
		if (k->data==x)
		{
			g->next=k->next;
			delete k;
			return;
		}
	g=k;
	}
} 
void dao(LIST &l)
{
	NODE *cur=l.phead;
	NODE *prev=l.phead, *next=l.phead;
	do
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}while(cur!=l.phead);
	l.phead->next=prev;
	l.phead=prev;
}
int timphantu (LIST &l, int x)
{
	int k=0;
	NODE *q=l.phead;
	do{
		if(q->data==x)
		k++;
		q=q->next; 
	}while(q!=l.phead);
	return k;
}
void xoalist(LIST &l)
{ 
	NODE *cur=l.phead;
	cout<<"da xoa danh sach"; 
    do
	{
		NODE *p=l.phead;
        l.phead=l.phead->next;
        delete p;
        cur=cur->next; 
    }
    while(cur!=l.phead); 
    l.phead=NULL; 
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
            if(l2.phead==NULL)
            {
                l2.plast = temp;
                l2.phead = temp;
                l2.plast->next = l2.phead;
            }
            else 
            {
                l2.plast->next=temp;
                l2.plast=temp;
                l2.plast->next=l2.phead;
            }
            cur= cur->next;
        }  
        while (cur!=l.phead);       
    }
}
int sosanh(LIST l, LIST l3)
{   
    NODE *temp=l.phead;
    NODE *temp2=l3.phead;
    int dem1=1, dem2=1;
    do 
    {
        if(temp->data!=temp2->data)
            return -1;
        temp=temp->next;
        if(temp!=l.phead)
        	dem1++;
        temp2=temp2->next;
        if(temp2!=l3.phead)
        	dem2++;
    }while(temp!=l.phead||temp2!=l3.phead);
    if(dem1!=dem2)
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
    } while (cur!=l.phead);  
        cout<<endl;
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
			xuatdslk(l);
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
			xuatdslk(l2);	
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

