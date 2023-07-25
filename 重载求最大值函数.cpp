#include<iostream>
using namespace std;


	int maxinum(const int a1,const int a2,const int a3);//整数 
	float maxinum(const float & b1,const float & b2,const float & b3);//小数 
	char maxinum(const char & c1,const char & c2,const char & c3);//字符 


int maxinum(const int a1,const int a2,const int a3)//整数 
		{
			int max;
			if(a1>a2)
			{
				max=a1;
			}
			else
				max=a2;
			if(a3>max)
			{
				max=a3;
			}
			return max;
		}

float maxinum(const float & b1,const float & b2,const float & b3)//小数 
		{
			float max;
			if(b1>b2)
			{
				max=b1;
			}
			else
				max=b2;
			if(b3>max)
			{
				max=b3;
			}
			return max;
		}

char maxinum(const char & c1,const char & c2,const char & c3)//字符 
		{
			float max;
			if(c1>c2)
			{
				max=c1;
			}
			else
				max=c2;
			if(c3>max)
			{
				max=c3;
			}
			return max;
		}

//StudybarCommentBegin
int main()
{
    int b1, b2, b3;
	float c1, c2, c3;
	char a1, a2, a3;
	cin >> b1 >> b2 >> b3 >> c1 >> c2 >> c3>> a1 >> a2 >> a3;
	cout << maxinum(b1, b2, b3) << ' ' << maxinum(c1, c2, c3) << ' ' << maxinum(a1, a2, a3);
	return 0;
}
//StudybarCommentEnd
