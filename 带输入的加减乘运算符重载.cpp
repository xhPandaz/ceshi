#include<iostream>
using namespace std;
class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		Cmycomplex operator +(Cmycomplex &z);
		Cmycomplex operator -(Cmycomplex &z);
		Cmycomplex operator *(Cmycomplex &z);
		void Show();
		void Set(double r,double i); 
};

Cmycomplex::Cmycomplex(double x,double y)
{
	r=x;
	i=y;
}
Cmycomplex Cmycomplex::operator +(Cmycomplex &z)
{
	Cmycomplex t;
	t.r=r+z.r;
	t.i=i+z.i;
	return t;
} 
Cmycomplex Cmycomplex::operator -(Cmycomplex &z)
{
	Cmycomplex t;
	t.r=r-z.r;
	t.i=i-z.i;
	return t;
}
Cmycomplex Cmycomplex::operator *(Cmycomplex &z)
{
	Cmycomplex t;
	t.r=r*z.r-i*z.i;
	t.i=r*z.i+i*z.r;
	return t;
}
void Cmycomplex::Show()
{
	if(i>0)
	{
		cout<<"("<<r<<"+"<<i<<"i)";
	}
	else if(i<0)
	{
		cout<<"("<<r<<i<<"i)";
	}
	else
	{
		cout<<"("<<r<<"i)";
	}
}
void Cmycomplex::Set(double r,double i)
{
	this->r=r;
	this->i=i;
}

//StudybarCommentBegin
int main()
{
Cmycomplex  z1(3,4),z2(7),z3;
double  x,y;
cin>>x>>y;
z2.Set(x,y);
z3=z1+z2;
cout<<"\n";
z3.Show();
z3=z1-z2;
cout<<"\n";
z3.Show();
z3=z1*z2;
cout<<"\n";
z3.Show();

}
//StudybarCommentEnd
