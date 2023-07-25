#include <iostream>
using namespace std;

// ģ�庯�����ж�����ͬ���͵Ĳ����Ƿ����
template<typename T>

bool isEqualTo(const T &a, const T &b) {
	return a == b;
}

// SomeClass�ࣺ�����������ݳ�Ա
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
		// �ж�����SomeClass�����Ƿ����
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
