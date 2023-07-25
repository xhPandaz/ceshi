#include <iostream>
#include <iomanip>
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
};

Rational::Rational(int fz, int fm) {
	for (int i = 2; i <= fm; i++) {
		if (fz % i == 0 && fm % i == 0) {
			fz = fz / i;
			fm = fm / i;
			i = 2;
		}
	}
	numerator = fz;
	denominator = fm;
}

Rational Rational::add(Rational z1, Rational z2) { //加
//t.换成this->      z2.换成z2.  没有的换成z1.
	this-> denominator = z1.denominator * z2.denominator;
	this-> numerator = z1.numerator * z2.denominator + z1.denominator * z2.numerator;
	for (int i = 2; i <= this->denominator; i++) {
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			this->numerator = this->numerator / i;
			this->denominator = this->denominator / i;
			i = 2;
		}
	}
	return *this;
}

Rational Rational::minus(Rational z1, Rational z2) { //减
	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.denominator - z1.denominator * z2.numerator  ;
//	cout << this->numerator << '/' << this->denominator << endl;
	if (this->numerator > 0) {
		for (int i = 2; i <= this->denominator; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				this->numerator = this->numerator / i;
				this->denominator = this->denominator / i;
				i = 2;
			}
		}
	} else {
		for (int i = -2; i <= -(this->denominator); i--) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				this->numerator = this->numerator / -i;
				this->denominator = this->denominator / -i;
				i = 2;
			}
		}
	}
	return *this;
}

Rational Rational::multi(Rational z1, Rational z2) { //乘

	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.numerator;
	for (int i = 2; i <= this->denominator; i++) {
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			this->numerator = this->numerator / i;
			this->denominator = this->denominator / i;
			i = 2;
		}
	}
	return *this;
}

Rational Rational::divide(Rational z1, Rational z2) { //除

	this->denominator = z1.denominator * z2.numerator;
	this->numerator = z1.numerator * z2.denominator;
	for (int i = 2; i <= this->denominator; i++) {
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			this->numerator = this->numerator / i;
			this->denominator = this->denominator / i;
			i = 2;
		}
	}
	return *this;
}

void Rational::printBoth() {
	double fenshu;
	fenshu = (double)numerator / denominator;
	cout << "the Formal format of the rational is : ";
	printFormal();
	cout << "the Fixed format of the rational is : ";
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
