#include<iostream>
using namespace std;
class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		double GetReal();
		double GetImaginary();
};
double Cmycomplex::GetReal()
{
	return r;
}
double Cmycomplex::GetImaginary()
{
	return i;
}
Cmycomplex::Cmycomplex(double x,double y)//Àà£º£ºº¯Êý 
{
	r=x;
	i=y;
}
//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
cout<<z1.GetReal()<<"\n";
cout<<z2.GetImaginary()<<"\n";
cout<<z3.GetReal()<<"\n";

}
//StudybarCommentEnd 
