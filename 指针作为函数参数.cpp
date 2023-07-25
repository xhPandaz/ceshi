//StudybarCommentBegin
#include <iostream>
using namespace std;
 void swap(int *,int *);
int main( )
{ 
     int i,j;
	 cin >> i >>j ;
     swap(&i,&j);
     cout<<i<<" "<<j<<endl;
     return 0;
}
//StudybarCommentEnd
void swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
