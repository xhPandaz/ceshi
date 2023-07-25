#include <iostream>
#include <cstdlib>
using namespace std;
struct Student {
  int id;       //ѧ��
  float gpa;    //ƽ����
}; 
template <class T>
class Store {//��ģ�壺ʵ�ֶ������������ݽ��д�ȡ
private:
    T item; // item���ڴ���������͵�����
    bool haveValue;  // haveValue���item�Ƿ��ѱ���������
public:
    Store();
    T &getElem();   //��ȡ���ݺ���
    void putElem(const T &x);  //�������ݺ���
};

template <class T>  
Store<T>::Store(): haveValue(false) { } 
template <class T>
T &Store<T>::getElem() {
    //����ͼ��ȡδ��ʼ�������ݣ�����ֹ����
    if (!haveValue) {   
        cout << "No item present!" << endl;
        exit(1);    //ʹ������ȫ�˳������ص�����ϵͳ��
    }
    return item;        // ����item�д�ŵ����� 
}
template <class T>
void Store<T>::putElem(const T &x) {
    // ��haveValue ��Ϊtrue����ʾitem���Ѵ�����ֵ   
    haveValue = true;   
    item = x;           // ��xֵ����item
}

int main() {
    Store<int> s1, s2;  
    s1.putElem(3);  
    s2.putElem(-7);
    cout << s1.getElem() << "  " << s2.getElem() << endl;

    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putElem(g); 
    cout << "The student id is " << s3.getElem().id << endl;

    Store<double> d;
    cout << "Retrieving object D... ";
    cout << d.getElem() << endl;
   //dδ��ʼ����ִ�к���D.getElement()ʱ���³�����ֹ
    return 0;
}
