#include<iostream>
using namespace std;
class Date{
	private:
		int year,month,day;
	public:
		Date(int m,int d,int y);//���캯�� �� �� �� 
		//��������ú����ͻ�ȡ����
		void setYear(int y);
		int getYear();
		//���µ����ú����ͻ�ȡ����
		void setMonth(int m);
		int getMonth();
		//���յ����ú����ͻ�ȡ����
		void setDay(int d);
		int getDay();
		
		void displayDate();//��Ա���� ��ʾ����б�ߣ�/���ָ����¡��պ����ֵ
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
