#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char a[100];
	cout<<"nhap ho ten: ";
	fflush(stdin);
	gets(a);
	
	for (int i = 0; i < strlen(a) - 1;i++ ) {
		if ( a[i] == ' ' && a[i+1] == ' '){
			strcpy(&a[i] , &a[i+1]);
			--i;
		}
	}
	for (int i = 0; i < strlen(a);i++){
		cout << a[i];
	}
}
