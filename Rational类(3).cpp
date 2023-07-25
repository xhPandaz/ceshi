#include <iostream>
#include <iomanip>
#include<cmath>
//分子  numerator
//分母  denominator
using namespace std;

class Rational {
	private:
		int numerator, denominator;
	public:
		Rational(int fz = 0, int fm = 1); //构造函数  以简化的形式保存分数
		Rational add(Rational z1, Rational z2); //加
		Rational minus(Rational z1, Rational z2);//减
		Rational multi(Rational z1, Rational z2);//乘
		Rational divide(Rational z1, Rational z2);//除
		void printBoth(); //以 浮点数 的形式输出
		void printFormal(); //以 a/b 的形式输出
		void huajian() {
			if (numerator * denominator >= 0) {
				for (int i = 2; i <= abs(denominator); i++) {
					if (numerator % i == 0 && denominator % i == 0) {
						numerator = abs(numerator / i);
						denominator = abs(denominator / i);
						i = 2;
					}
				}
			} else {
				for (int i = 2; i <= abs(denominator); i++) {
					if (numerator % i == 0 && denominator % i == 0) {
						numerator = -abs(numerator / i);
						denominator = abs(denominator / i);
						i = 2;
					}
				}
			}
		}
};

Rational::Rational(int fz, int fm) {
	numerator = fz;
	denominator = fm;
	huajian();

}

Rational Rational::add(Rational z1, Rational z2) { //加
//t.换成this->      z2.换成z2.  没有的换成z1.
	this-> denominator = z1.denominator * z2.denominator;
	this-> numerator = z1.numerator * z2.denominator + z1.denominator * z2.numerator;
	huajian();
	return *this;
}

Rational Rational::minus(Rational z1, Rational z2) { //减
	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.denominator - z1.denominator * z2.numerator  ;
//	cout << this->numerator << '/' << this->denominator << endl;

	huajian();
	return *this;
}

Rational Rational::multi(Rational z1, Rational z2) { //乘

	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.numerator;
	huajian();
	return *this;
}

Rational Rational::divide(Rational z1, Rational z2) { //除

	this->denominator = z1.denominator * z2.numerator;
	this->numerator = z1.numerator * z2.denominator;
	huajian();
	return *this;
}

void Rational::printBoth() {
	double fenshu;
	fenshu = (double)numerator / denominator;
	cout << "the Formal format of the rational is : ";
	printFormal();
	cout << "the Fixed format of the first rational is : ";
	cout << fixed << setprecision(2) << fenshu << endl;
}

void Rational::printFormal() {
	cout << numerator << "/" << denominator << endl;
}



//StudybarCommentBegin
int main() {
	int firstN, firstD, secondN, secondD;
	char op;

//    cout<<"Please input the numerator of first Rational: ";
	cin >> firstN;
//    cout<<"Please input the denominator of first Rational: ";
	cin >> firstD;
//    cout<<"Please input the numerator of second Rational: ";
	cin >> secondN;
//    cout<<"Please input the denominator of second Rational: ";
	cin >> secondD;


	Rational r1(firstN, firstD), r2(secondN, secondD), r3;


	cin >> op;

	cout << "the Formal format of the first rational is : ";
	r1.printFormal();
	cout << "the Formal format of the second rational is : ";
	r2.printFormal();
	cout << endl;

	switch (op) {
		case '+' :
			r3.add(r1, r2);
			r3.printBoth();
			break;
		case '-' :
			r3.minus(r1, r2);
			r3.printBoth();
			break;
		case '*':
			r3.multi(r1, r2);
			r3.printBoth();
			break;
		case '/':
			r3.divide(r1, r2);
			r3.printBoth();
			break;
		default:
			cout << "Invalid operator!";
	}

	return 0;
}
//StudybarCommentEnd
