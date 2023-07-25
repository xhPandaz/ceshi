//��6-18 ��̬������
#include <iostream>
#include <cassert>
using namespace std;

class Point {
	public:
		Point() : x(0), y(0) {
			cout << endl << "Default Constructor called." ;
		}
		Point(int x, int y) : x(x), y(y) {
			cout << endl << "Constructor called." ;
		}
		~Point() {
			cout << endl << "Destructor called." ;
		}
		int getX() const {
			return x;
		}
		int getY() const {
			return y;
		}
		void move(int newX, int newY) {
			x = newX;
			y = newY;
		}
	private:
		int x, y;
};

class ArrayOfPoints { //��̬������
	public:
		ArrayOfPoints(int size) : size(size) {
			points = new Point[size];
		}
		~ArrayOfPoints() {
			cout << endl << "Deleting..." ;
			size = 0;
			delete[] points;
		}
		Point &element(int index) {//����Ԫ��
			return points[size];
		}
	private:
		Point  *points; //ָ��̬�����׵�ַ
		int size; //�����С
};


int main() {
	int count;
	cout << "Please enter the number of points: ";
	cin >> count;
	ArrayOfPoints points(count); //�����������
	points.element(0).move(5, 0); //��������Ԫ�صĳ�Ա
	points.element(1).move(15, 20); //��������Ԫ�صĳ�Ա
	return 0;
}
