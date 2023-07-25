#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,fz,fm,i;
	cin>>a>>b>>c>>d;
	fm=b*d;
	fz=a*d+b*c;
	for(i=2;i<=fm;i++)
	{
		if(fz%i==0&&fm%i==0)
		{
			fz=fz/i;
			fm=fm/i;
			i=2;
		}
	}
	cout<<fz<<"/"<<fm;
	return 0;
}
