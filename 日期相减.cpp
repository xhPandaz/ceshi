#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class date {
	public:
		date(int year = 1, int month = 1, int day = 1) { //���캯��
			if (year > 0 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month)) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "error!" << endl;
			}
		}

		bool operator==(const date &d) const {
			return Year == d.Year &&
			       Month == d.Month &&
			       Day == d.Day;
		}
		bool operator!=(const date &d) const {
			return !(*this == d);
		}
		bool operator>(const date &d) {
			return ((Year > d.Year) ||
			        (Year == d.Year && Month > d.Month) ||
			        (Year == d.Year && Month == d.Month && Day > d.Day));
		}
		bool operator>=(const date &d) {
			return (*this > d) || (*this == d);
		}
		bool operator<(const date &d) {
			return !(*this >= d);
		}
		bool operator<=(const date &d) {
			return !(*this > d);
		}
//ǰ��++��--����++��--
		date &operator++() {
			*this += 1;
			return *this;
		}
		date operator++(int) {
			date temp = (*this);
			*this += 1;
			return temp;
		}


//����һ�������
		int GetMonthDay(int year, int month) {
			static int GetMonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			//�����ƽ�꣬2����29��
			if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
				return 29;
			}
			return GetMonthDay[month];
		}

//���ں������ļӼ�
		date operator+(int day) {
			date temp(*this);
			temp += day;
			return temp;
		}
		date operator-(int day) {
			date temp(*this);
			temp -= day;
			return temp;
		}
		date &operator+=(int day) {
			if (day < 0) {
				return *this -= -day;
			}
			Day += day;
			while (Day > GetMonthDay(Year, Month)) {
				Day -= GetMonthDay(Year, Month);
				Month++;
				if (Month > 12) {
					Year++;
					Month = 1;
				}
			}
			return *this;
		}
		date &operator -= (int day) {
			if (day < 0) {
				return *this += (-day);
			}
			Day -= day;
			while (Day <= 0) {
				Month--;
				if (Month == 0) {
					Year--;
					Month = 12;
				}
				Day += GetMonthDay(Year, Month);
			}
			return *this;
		}
//����-����
		int operator-(const date &d) {
			int flag = 1;
			int day = 0;
			date max = *this;
			date min = d;
			if (*this < d) {
				max = d;
				min = *this;
				flag = -1;
			}
			//С������һֱ++���ӵ��ʹ������һ��ʱ�����˶�����Ͳ���ٴ�
			while (min != max) {
				min++;
				day++;
			}
			return day * flag;
		}
		void Test() {
			cout << Year << "--" << Month << "--" << Day << endl;
		}
		short year() {
			return Year;
		}
		short month() {
			return Month;
		}
		short day() {
			return Day;
		}
	private:
		int Year;
		int Month;
		int Day;
};

//StudybarCommentBegin
int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	date D1, D2;
	int year;
	int month;
	int day;
	cin >> year >> month >> day; //shu ru di yi ge ri qi
	D1 = date(year, month, day);
	cin >> year >> month >> day; //shu ru di er ge ri qi
	D2 = date(year, month, day);
	cout << D2 - D1 << endl;
	cin >> day; //shu ru yao jia jian de tian shu,
	D1 += day;
	D2 -= day;
	cout << D1.year() << " " << D1.month() << " " << D1.day() << endl;
	cout << D2.year() << " " << D2.month() << " " << D2.day() << endl;
	return 0;
}

//StudybarCommentEnd