#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Rectangle{
	private:
		double length,width;
	public:
		Rectangle(double l,double w);//构造函数
		Rectangle(); 
		double perimeter();//计算周长的成员函数
		double area();//计算面积的成员函数
		//长度对应的设置和获取函数
		void setLength(double l);
		double getLength();
		//宽度对应的设置和获取函数
		void setWidth(double w);
		double getWidth();
		
};
Rectangle::Rectangle()
{
	
}
Rectangle::Rectangle(double l,double w)
{
	length=l;
	width=w;
}
void Rectangle::setLength(double l)
{
	if(l<=0.0||l>=20.0)
	{
		length=1;
	}
	else
		length=l;
}
double Rectangle::getLength()
{
	return length;
}
void Rectangle::setWidth(double w)
{
	if(w<=0.0||w>=20.0)
	{
		width=1;
	}
	else
		width=w;
}
double Rectangle::getWidth()
{
	return width;
}

double Rectangle::perimeter()
{
	double per;
	per=(length+width)*2;
	return per;
}
double Rectangle::area()
{
	double a;
	a=length*width;
	return a;
}


//StudybarCommentBegin
int main()
{
    Rectangle r;
    double length,width;
    
//    cout<<"please input the length of Rectangle:";
    cin>>length;
//    cout<<"please input the width of Rectangle:";
    cin>>width;
    r.setLength(length);
    r.setWidth(width);
    cout<<"the perimeter is:"<<setprecision(2)<<fixed<<r.perimeter()<<endl;
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;
    return 0;
    
}
//StudybarCommentEnd
