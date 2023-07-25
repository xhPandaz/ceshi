#include<iostream>
using namespace std;
class Date{
	private:
		int year,month,day;
	public:
		Date(int m,int d,int y);//构造函数 月 日 年 
		//对年的设置函数和获取函数
		void setYear(int y);
		int getYear();
		//对月的设置函数和获取函数
		void setMonth(int m);
		int getMonth();
		//对日的设置函数和获取函数
		void setDay(int d);
		int getDay();
		
		void displayDate();//成员函数 显示用正斜线（/）分隔的月、日和年的值
};
Date::Date(int m,int d,int y)
{
	month=m;
	day=d;
	year=y;
} 
void Date::setYear(int y)
{
	year=y;
}
int Date::getYear()
{
	return year;
}
void Date::setMonth(int m)
{
	if(m<1||m>12)
	{
		month=1;
	}
	else
		month=m;
}
int Date::getMonth()
{
	return month;
}
void Date::setDay(int d)
{
	day=d;
}
int Date::getDay()
{
	return day;
}

void Date::displayDate()
{
	cout<<month<<"/"<<day<<"/"<<year<<endl;
}



//StudybarCommentBegin
// function main begins program execution
int main()
{
    Date date( 5, 6, 1981 ); // create a Date object for May 6, 1981
    
    // display the values of the three Date data members
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;
    
    cout << "\nOriginal date:" << endl;
    date.displayDate(); // output the Date as 5/6/1981
    
    // modify the Date
    date.setMonth( 13 ); // invalid month
    date.setDay( 1 );
    date.setYear( 2005 );
    
    cout << "\nNew date:" << endl;
    date.displayDate(); // output the modified date (1/1/2005)
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
