#include <iostream>
#include <iomanip>
#include<cmath>
//����  numerator
//��ĸ  denominator
using namespace std;

class Rational {
	private:
		int numerator, denominator;
	public:
		Rational(int fz = 0, int fm = 1); //���캯��  �Լ򻯵���ʽ�������
		Rational add(Rational z1, Rational z2); //��
		Rational minus(Rational z1, Rational z2);//��
		Rational multi(Rational z1, Rational z2);//��
		Rational divide(Rational z1, Rational z2);//��
		void printBoth(); //�� ������ ����ʽ���
		void printFormal(); //�� a/b ����ʽ���
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

Rational Rational::add(Rational z1, Rational z2) { //��
//t.����this->      z2.����z2.  û�еĻ���z1.
	this-> denominator = z1.denominator * z2.denominator;
	this-> numerator = z1.numerator * z2.denominator + z1.denominator * z2.numerator;
	huajian();
	return *this;
}

Rational Rational::minus(Rational z1, Rational z2) { //��
	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.denominator - z1.denominator * z2.numerator  ;
//	cout << this->numerator << '/' << this->denominator << endl;

	huajian();
	return *this;
}

Rational Rational::multi(Rational z1, Rational z2) { //��

	this->denominator = z1.denominator * z2.denominator;
	this->numerator = z1.numerator * z2.numerator;
	huajian();
	return *this;
}

Rational Rational::divide(Rational z1, Rational z2) { //��

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
