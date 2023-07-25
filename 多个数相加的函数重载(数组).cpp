#include<iostream>
using namespace std;

int myadd(int a,int b)
{
 return a+b;
}

int myadd(int a[],int b)
{
	int sum=a[0],i;
	for(i=1;i<b;i++)
	{
		sum=a[i]+sum;
	}
	return sum;
}

int myadd(int a,int b,int c)
{
 return a+b+c;
}


//StudybarCommentBegin
main()
{
int a[20],n,i;

cin>>n;
if(n==2)
    cout<<myadd(5,3);
else if (n==3)
    cout<<myadd(5,3,9);
else if(n>3)
{
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<myadd(a,n);
}

}
//StudybarCommentEnd
