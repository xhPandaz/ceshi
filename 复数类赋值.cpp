#include<iostream>
using namespace std;

class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		Cmycomplex Add(Cmycomplex &z);
		void Show();
};

Cmycomplex::Cmycomplex(double x,double y)
{
	r=x;
	i=y;
}

Cmycomplex Cmycomplex::Add(Cmycomplex &z)
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

//StudybarCommentBegin
int main()
{
Cmycomplex  z1(2,3),z2,z3(3);
z2=z1.Add(z3);
z2.Show();

}
//StudybarCommentEnd
