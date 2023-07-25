//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using namespace std;

class Cmycomplex {
	private:
		double r, i;
	public:
		Cmycomplex(double x = 0, double y = 0);
		Cmycomplex operator +(Cmycomplex &z);
		Cmycomplex operator -(Cmycomplex &z);
		Cmycomplex operator *(Cmycomplex &z);
		friend Cmycomplex operator *(int n, Cmycomplex &z);
		Cmycomplex operator /(Cmycomplex &z);
		friend Cmycomplex operator /(double n, Cmycomplex &z);
		void Show();

};

Cmycomplex Cmycomplex::operator -(Cmycomplex &z) {
	Cmycomplex t;
	t.r = r - z.r;
	t.i = i - z.i;
	return t;
}

Cmycomplex Cmycomplex::operator *(Cmycomplex &z) {
	Cmycomplex t;
	t.r = r * z.r - i * z.i;
	t.i = r * z.i + i * z.r;
	return t;
}

Cmycomplex operator *(int n, Cmycomplex &z) {
	Cmycomplex t;
	t.r = n * z.r;
	t.i = n * z.i;
	return t;
}

Cmycomplex Cmycomplex::operator /(Cmycomplex &z) {
	Cmycomplex t;
	t.r = (r * z.r + i * z.i) / (z.r * z.r + z.i * z.i);
	t.i = (i * z.r - r * z.i) / (z.r * z.r + z.i * z.i);
	return t;
}

Cmycomplex operator /(int n, Cmycomplex &z) {
	Cmycomplex t;
	t.r = z.r / n;
	t.i = z.i / n;
	return t;
}

Cmycomplex Cmycomplex::operator +(Cmycomplex &z) {
	Cmycomplex t;
	t.r = r + z.r;
	t.i = i + z.i;
	return t;
}

Cmycomplex::Cmycomplex(double x, double y) {
	r = x;
	i = y;
}

void Cmycomplex::Show() {
	if (i > 0) {
		cout << setiosflags(ios::fixed);   //具体显示几位小数的设置
		cout << "(" << setprecision(2) << r << "+" << setprecision(2) << i << "i)";
	} else if (i < 0) {
		cout << setiosflags(ios::fixed);   //具体显示几位小数的设置
		cout << "(" << setprecision(2) << r << setprecision(2) << i << "i)";
	} else {
		cout << setiosflags(ios::fixed);   //具体显示几位小数的设置
		cout << "(" << setprecision(2) << r << "i)";
	}
}



int main() {
	double x1, x2, x3, y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	Cmycomplex a(x1, y1), b(x2, y2), c(x3, y3), z, t1, t2;

	z = b * b - 4 * a * c;

	t1 = ((-1) * b + z.sqrt()) / (2 * a); //z.sqrt()为求复数z的平方根，这里的2*a涉及操作符重载，且友元重载。
	t2 = ((-1) * b - z.sqrt()) / 2.0 / a; //这里涉及到除法的重载

	if (t1.gety() > t2.gety()) { //gety()为得到虚部值
		t1.Show();
		t2.Show();
	} else {
		t2.Show();
		t1.Show();
	}
	return 0;
}
//StudybarCommentEnd
