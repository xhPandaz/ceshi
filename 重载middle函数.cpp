	
//StudybarCommentBegin
#include<iostream>
using namespace std;


//StudybarCommentEnd
int middle(const int a1[]);//整数
double middle(const double b[]);//双精度数
unsigned middle(const unsigned c[]);//无符号整数

int middle(const int a1[])//整数 
{
	int mid;
		if((a1[0]>a1[1]&&a1[0]<a1[2])||(a1[0]>a1[2]&&a1[0]<a1[1]))
		{
			mid=a1[0];
		}
		else if((a1[1]>a1[0]&&a1[1]<a1[2])||(a1[1]>a1[2]&&a1[1]<a1[0]))
		{
			mid=a1[1];
		}
		else if((a1[2]>a1[1]&&a1[2]<a1[0])||(a1[2]>a1[0]&&a1[2]<a1[1]))
		{
			mid=a1[2];
		}
	
	return mid;
}

double middle(const double b[])//双精度数
{
	double mid;
	if((b[0]>b[1]&&b[0]<b[2])||(b[0]>b[2]&&b[0]<b[1]))
		{
			mid=b[0];
		}
	else if((b[1]>b[0]&&b[1]<b[2])||(b[1]>b[2]&&b[1]<b[0]))
		{
			mid=b[1];
		}
	else if((b[2]>b[1]&&b[2]<b[0])||(b[2]>b[0]&&b[2]<b[1]))
		{
			mid=b[2];
		}
	return mid;
}

unsigned middle(const unsigned c[])//无符号整数
{
	unsigned mid;
	if((c[0]>c[1]&&c[0]<c[2])||(c[0]>c[2]&&c[0]<c[1]))
		{
			mid=c[0];
		}
	else if((c[1]>c[0]&&c[1]<c[2])||(c[1]>c[2]&&c[1]<c[0]))
		{
			mid=c[1];
		}
	else if((c[2]>c[1]&&c[2]<c[0])||(c[2]>c[0]&&c[2]<c[1]))
		{
			mid=c[2];
		}
	return mid;
}
//StudybarCommentBegin
int main()
{
	int iNumber[3]={45,3,89};
	double dNumber[3]={12.4,6,55.8};
	unsigned uNumber[3]={345,776,565};

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<iNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(iNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<dNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(dNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<uNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(uNumber)<<endl;

	return 0;
}
//StudybarCommentEnd
