#include <iostream>

#include <cmath>

using namespace std;

class Point { //Point�ඨ��
public: //�ⲿ�ӿ�
const Point(int newx = 0, int newy = 0,int times=0, int size=sizeof(Point)) { x=newx; y=newy; TimesofGetMysize=times; Mysize=size; }
int getX() { return x; }
int getY() { return y; }
int getMysize() const { TimesofGetMysize++; return Mysize;}
int getTimesofGetMysize() { return TimesofGetMysize;}

friend float dist(const Point &p1,const Point &p2);
friend float dist( Point &p1, const Point &p2);
private: //˽�����ݳ�Ա�����ݳ�Ա�Ķ���û�д�
int x, y;
int TimesofGetMysize;
const int Mysize;

};

void TestFun( Point &p)
{
cout<<"TestFun is "<<p.getX();
}


float dist( const Point &p1, const Point &p2) {
double x = p1.x - p2.x;
double y = p1.y - p2.y;
p2.x++;
return static_cast<float>(sqrt(x*x+y*y));
}

float dist( Point &p1, const Point &p2) {
double x = p1.x - p2.x;
double y = p1.y - p2.y;
p1.x++;
return static_cast<float>(sqrt(x*x+y*y));
}



//StudybarCommentBegin
int main() {  //������

       const Point myp1(1, 1), myp2(4, 5);    
       Point myp3;
      
       cout<<"myp1.getY() "<< myp1.getY() <<endl;    
	              
       cout<<"myp3.getX() "<<myp3.getY() <<endl;       
       cout << "dist(myp1, myp3) " << dist(myp1, myp3) << endl;       
       cout <<"myp3.getX() "<< myp3.getX() <<endl;
       
       cout<<"myp3.getMysize() "<<myp3.getMysize()<<endl;
       cout <<"myp3.getTimesofGetMysize "<< myp3.getTimesofGetMysize() <<endl;
	   
       cout << "dist(myp3, myp1) " << dist(myp3,myp1) << endl;
	   
       cout <<"myp3.getX() "<< myp3.getX() <<endl;
	   
       TestFun(Point(1,1));
	   
       return 0;

}
//StudybarCommentEnd





