#include<iostream>
using namespace std;
class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		void Show();
};
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
Cmycomplex::Cmycomplex(double x,double y)//Àà£º£ºº¯Êý 
{
	r=x;
	i=y;
} 
//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z1.Show();
}
//StudybarCommentEnd
