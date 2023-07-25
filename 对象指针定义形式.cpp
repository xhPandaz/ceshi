//6_12.cpp
#include <iostream>
using namespace std;

class Point {
	public:
		Point(int x = 0, int y = 0) : x(x), y(y) { }
		int getX() const {
			return this->x;
		}
		int getY() const {
			return  y;
		}
	private:
		int x, y;
};

int main() {
	Point a(4, 5);
	Point  *p1  = &a; //�������ָ�룬��a�ĵ�ַ��ʼ��
	cout <<  p1->getX() << endl; //��ָ����ʶ����Ա
	cout << a.getY() << endl; //�ö��������ʶ����Ա
	return 0;
}