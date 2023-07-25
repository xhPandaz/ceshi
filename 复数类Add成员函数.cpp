#include<iostream>
using namespace std;

class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		void Add(Cmycomplex &z);
		void Show();
};
Cmycomplex::Cmycomplex(double x,double y)
{
	r=x;
	i=y;
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
void Cmycomplex::Add(Cmycomplex &z)
{
	r=r+z.r;
	i=i+z.i;
	
}
//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z1.Add(z3);
z1.Show();

}
//StudybarCommentEnd
