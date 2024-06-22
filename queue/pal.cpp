#include<iostream>
#include<string.h>
using namespace std;

char Peek(char A[], int top){
    return A[top];
}
void Pop(char A[], int &top){   
    top--;
}
void Dequeue(char queue[], int &front){
    front = front+1;
}
int so_sanh(char A[], int top, int front){
	int flag = 1;
    for(int i=0;i<strlen(A);i++){
        if(Peek(A, top)!=Peek(A, front)){
            flag = 0;
            break;
        }
        else{
        	Dequeue(A, front);
        	Pop(A, top);
    	}
    }
    return flag;
}
int main()
{
    char A[50];
    cout << "Nhap tu: ";
    cin.getline(A, 50);
    int top=strlen(A)-1;
    int front = 0;
    if(so_sanh(A, top, front)==0)
        cout << "Khong phai Palindromes";
    else
        cout << "La Palindromes";
}
