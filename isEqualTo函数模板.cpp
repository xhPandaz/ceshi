#include <iostream>
using namespace std;

// 模板函数：判断两个同类型的参数是否相等
template<typename T>

bool isEqualTo(const T &a, const T &b) {
	return a == b;
}

// SomeClass类：含有两个数据成员
class SomeClass {
	public:
		SomeClass(int a = 0, double b = 0.0) : m_a(a), m_b(b) {}
		friend istream &operator>>(istream &in, SomeClass &obj) {
			in >> obj.m_a >> obj.m_b;
			return in;
		}
		friend ostream &operator<<(ostream &out, const SomeClass &obj) {
			out << "(" << obj.m_a << "," << obj.m_b << ")";
			return out;
		}
		// 判断两个SomeClass对象是否相等
		bool isEqualTo(const SomeClass &other) const {
			return m_a == other.m_a && m_b == other.m_b;
		}
	private:
		int m_a;
		double m_b;
};

int main() {
	int a, b;
	cin >> a >> b;
	cout << a << " and " << b << " are "
	     << (isEqualTo(a, b) ? "equal" : "not equal") << endl;

	char c, d;
	cin >> c >> d;
	cout << c << " and " << d << " are "
	     << (isEqualTo(c, d) ? "equal" : "not equal") << endl;

	double e, f;
	cin >> e >> f;
	cout << e << " and " << f << " are "
	     << (isEqualTo(e, f) ? "equal" : "not equal") << endl;

	SomeClass g(1, 1.1), h;
	cin >> h;
	cout << "The class objects " << g << " and " << h << " are "
	     << (g.isEqualTo(h) ? "equal" : "not equal") << endl;

	return 0;
}
