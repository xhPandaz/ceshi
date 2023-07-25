//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
 using std::cout;
 using std::endl;
 using std::setfill;
 using std::setw;
//StudybarCommentEnd
using namespace std;
class Time{
	private:
		int hour,minute,second;
	public:
		Time(int hour=0,int minute=0,int second=0);
		void printTime() const;
		void setTime(int h,int m,int s);
		//前置单目运算符重载  ++t
		Time & operator++();
		//后置单目运算符重载 t++
		Time operator++(int);
		friend Time operator+(int,Time);
	
	
};

Time::Time(int hour,int minute,int second)
{
	if(0<=hour&&hour<24&&0<=minute&&minute<60&&0<=second&&second<60)
	{
		this->hour=hour;
		this->minute=minute;
		this->second=second;
	}
	else
	{
		cout<<"Time error!"<<endl;
	}
}
void Time::setTime(int h,int m,int s)
{
	hour=h;
	minute=m;
	second=s;
}

void Time::printTime() const
{
 cout<<setfill('0')<<setw(2)<<hour
  <<":"<<setw(2)<<minute<<":"
  <<setw(2)<<second<<endl;
}

Time & Time::operator++()
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
		}
	}
	return *this;
}
Time Time::operator++(int)
{
	Time old=*this;
	++(*this);
	return old;
}
Time operator+(int z, Time x ) 
{
	Time t;
	int m, n;//进位 

	m =  (x.second + z) / 60;
	t.second =  (x.second + z) % 60;

	n = (x.minute + m) / 60;
	t.minute = (x.minute + m) % 60;

	t.hour = (x.hour + n) % 24;

	return t;
}

//StudybarCommentBegin
int main()
{
	int hour,minute,second;
	int increase;
	Time t1(23,45,0),t2,t3(t1);
	cin>>hour>>minute>>second>>increase;
	t1.setTime(hour,minute,second);
	t1.printTime();
	t2=++t1;
	t2.printTime();
	t3=increase+t1;
	t3.printTime();
        return 0;
}
//StudybarCommentEnd
