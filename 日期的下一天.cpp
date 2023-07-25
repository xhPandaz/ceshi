//判断是否为闰年：
//  (year%4==0&&year%100!=0)||year%400==0
//闰年2月有29天
#include <iostream>
using namespace std;

class date {
	private:
		int Year, Month, Day;
	public:
		date() {}
		date(int year, int month, int day);
		date operator++(int);//后置
		date &operator ++();//前置
		friend int main(void);
		int year() {
			return Year;
		}
		int month() {
			return Month;
		}
		int day() {
			return Day;
		}
};


date::date(int year, int month, int day) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		if (month == 2) {
			if (year > 0 && month > 0 && month <= 29 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (year > 0 && month > 0 && month <= 31 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (year > 0 && month > 0 && month <= 30 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		}
	} else {
		if (month == 2) {
			if (year > 0 && month > 0 && month <= 28 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (year > 0 && month > 0 && month <= 31 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (year > 0 && month > 0 && month <= 30 && day > 0) {
				Year = year;
				Month = month;
				Day = day;
			} else {
				cout << "Error!" << endl;
			}
		}
	}
}

date &date::operator ++() { //前置
	Day++;
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) {
		if (Month == 2) {
			if (Day > 29) {
				Day = Day - 29;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}

		} else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
			if (Day > 31) {
				Day = Day - 31;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}
		} else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
			if (Day > 30) {
				Day = Day - 30;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}
		}
	} else {
		if (Month == 2) {
			if (Day > 28) {
				Day = Day - 28;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}

		} else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
			if (Day > 31) {
				Day = Day - 31;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}
		} else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
			if (Day > 30) {
				Day = Day - 30;
				Month++;
				if (Month >= 12) {
					Month = Month - 12;
					Year = Year + 1;
				}
			}
		}
	}
	return *this;
}

date date::operator++(int) { //后置
	date old = *this;
	++(*this);
	return old;
}

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

	D2 = D1++;

	cout << D1.year() << " " << D1.month() << " " << D1.day() << endl;
	cout << D2.year() << " " << D2.month() << " " << D2.day() << endl;
	return 0;
}

//StudybarCommentEnd
