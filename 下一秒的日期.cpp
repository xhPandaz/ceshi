//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;

//StudybarCommentEnd
#include<ctime>
using namespace std;
class Time{
	private:
		int year,month,day,hour,minute,second;
	public:
		Time(int y,int mon,int d,int h=0,int m=0,int s=0);
		Time();
		void setTime(int y,int mon,int d,int h,int m,int s);
		void printTime() const;
		int getMonthday(int y,int m);
		Time &operator ++();//前置运算符
		Time operator ++(int);//后置运算符
		friend Time operator+(int z, Time x );
		int operator-(Time a);
	
};
Time::Time()
{
	
}
Time::Time(int y,int mon,int d,int h,int m,int s)
{
	if(0<=h&&h<24&&0<=m&&m<60&&0<=s&&s<60)
	{
		hour=h;
		minute=m;
		second=s;
	}
	else
	{
		cout<<"Time error!"<<endl;
	}
	year=y;
	month=mon;
	day=d;
}
void Time::setTime(int y,int mon,int d,int h,int m,int s)
{
	year=y;
	month=mon;
	day=d;
	hour=h;
	minute=m;
	second=s;
}
void Time::printTime() const
{
 cout<<year<<"/"<<month<<"/"<<day
  <<" "<<setfill('0')<<setw(2)<<hour                   
  <<":"<<setw(2)<<minute<<":"
  <<setw(2)<<second<<endl;
}  

int Time::getMonthday(int y,int m)
{
	static const int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((m==2) && ((y%4==0 && y%100!=0)||y%400==0)) 
	{
        return 29;
    }
    else
	{
        return md[m];
    }
}

Time & Time::operator++()//前置 
{
	second++;
	if(second>=60)
	{
		second=second-60;
		minute++;
		if(minute>=60)
		{
			minute=minute-60;
			hour=(hour+1)%24;
			if(hour==0)
			{
				day++;
				hour=0;
				if(day>getMonthday(year,month))
				{
					day=1;
					month++;
					if(month>12)
					{
						year++;
						month=1;
					}
				}
			}
		}
	}
	
	return *this;
}
Time Time::operator++(int)//后置 
{
	Time old=*this;
	++(*this);
	return old;
}

Time operator+(Time x,int z) 
{
	for(int i=1;i<=z;i++)
	{
		++x;
	}
	return x;
}
int Time::operator-(Time a)
{
	int miao=0;
	while (!(a.hour==0&&a.minute==0&&a.second==0))
	{
		a++;
		miao++;
	}
	while(!(a.year==year&&a.month==month&&a.day==day))
	{
		a.day++;
		miao=miao+24*60*60;
		if(a.day>getMonthday(a.year,a.month))
		{
			a.day=1;
			a.month++;
			if(a.month>12)
			{
				a.month=1;
				a.year++;
			}
		}
	}
	while (!(a.hour==hour&&a.minute==minute&&a.second==second))
	{
		a++;
		miao++;
	}
	return miao;
}










//StudybarCommentBegin
int main()
{
	
	int year,month,day;
	int hour,minute,second;
	int increase;
	int capacity=0;
	Time t1(2016,3,31,23,45,0),t2,t3(t1),t4;
	cin>>year>>month>>day>>hour>>minute>>second;
	t1.setTime(year,month,day,hour,minute,second);
	cin>>year>>month>>day>>hour>>minute>>second;
	t2.setTime(year,month,day,hour,minute,second);
	cin>>increase;
	t1.printTime();
	t2.printTime();
	t3=++t1;
	t3.printTime();
	t4=t1+increase;
	t4.printTime();
	capacity = t2-t1;
	cout<<capacity<<endl;
}
//StudybarCommentEnd
