#include<iostream>
using namespace std;
int front=0;
int rear=-1;
void enqueue(int queue[], int val)
{
    if(rear==100-1)
        cout<<"STACK da day khong the them";
    else
    {
        rear++;
        queue[rear]=val;
	}
}
int dequeue(int queue[])
{
    if(front>rear)
    {   
        return -1;
    }
    else
    {
        int x=queue[front];
        front++;
        return x;
    }
}
int frontt(int queue[])
{
	if(front>rear)
		return -1;
    return queue[front];
}
void xuat(int queue[], int n) 
{
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
}
void menu(int queue[], int &n)
{
    int x;
    int luachon;
	while (true)
	{
		cout<<"\n\n\t\t======menu======";
		cout<<"\n1. nhap danh sach";
		cout<<"\n2. xuat danh sach";
		cout<<"\n3. hien thi phan dung dau hang doi";
		cout<<"\n4. xoa phan tu dau";
        cout<<"\n\n\t\t======END======";
		cout<<"\nnhap lua chon: ";
		cin>>luachon;
		if(luachon==1)
		{
            cout<<"Nhap so luong phan tu:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"Them vao queue "<<i<<" : ";
                cin>>x;
                enqueue(queue,x);
            }
        
		}
		else if (luachon==2)
		{
			cout<<"Cac phan tu trong queue la : ";
			xuat(queue,n);
		}
		else if (luachon==3)
		{
			if(frontt(queue)==-1)
			cout<<"khong co phan tu";
			else
            cout<<"Phan tu dau la "<<frontt(queue);
        }
		else if (luachon==4)
		{
			if(dequeue(queue)==-1)
			cout<<"queue rong"<<endl;
			else
			{
            cout<<"Da xoa phan tu dau ra khoi queue \n";
            xuat(queue,n);
        	}
		}
    }
}
int main ()
{
    int queue[100];
    int n;
    menu(queue,n);
	system("pause");
	return 0;
}
