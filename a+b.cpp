#include<iostream>

using namespace std;

int add(int a,int b);
int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	int c=add(a,b);
	cout<<c;
	return 0;
}
int add(int a,int b)
{
	return a+b;
}
