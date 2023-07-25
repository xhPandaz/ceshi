#include<iostream>
using namespace std;
class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		Cmycomplex operator + (Cmycomplex z);
		void Show(); 
};
Cmycomplex Cmycomplex::operator + (Cmycomplex z)//返回数据的类型::类名    参数类型（复数类的参数）//加法重载 
{
	Cmycomplex t;
	t.r=r+z.r;
	t.i=i+z.i;
	return t;
}

void Cmycomplex::Show()
{
	if(i>0) 
		cout<<"("<<r<<"+"<<i<<"i)";
	else if(i<0)
	{
		cout<<"("<<r<<i<<"i)";
	}
	else
		cout<<"("<<r<<")";
}
Cmycomplex::Cmycomplex(double x,double y)//类：：函数 
{
	r=x;
	i=y;
} 
//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z2=z1+z3;
z2.Show();

}
//StudybarCommentEnd
