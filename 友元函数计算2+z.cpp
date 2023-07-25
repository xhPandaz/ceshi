#include<iostream>
using namespace std;
class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		void Set(double r,double i);
		void Show();
		Cmycomplex operator +(Cmycomplex &z);
		friend Cmycomplex operator+(int a,Cmycomplex b);
		friend Cmycomplex operator+(Cmycomplex b,int a);
};

Cmycomplex::Cmycomplex(double x,double y)
{
	r=x;
	i=y;
}
void Cmycomplex::Set(double r,double i)
{
	this->r=r;
	this->i=i;
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

Cmycomplex Cmycomplex::operator +(Cmycomplex &z)
{
	Cmycomplex t;
	t.r=r+z.r;
	t.i=i+z.i;
	return t;
}
Cmycomplex operator+(int a,Cmycomplex b)
{
	Cmycomplex m;
	m.r=a+b.r;
	m.i=b.i;
	return m;
}
Cmycomplex operator+(Cmycomplex b,int a)
{
	Cmycomplex m;
	m.r=a+b.r;
	m.i=b.i;
	return m;
}

	
//StudybarCommentBegin
int main()
{
Cmycomplex z1(3,4),z2(7),z3,z4(z1);
double x,y;
cin>>x>>y;
z3.Set(x,y);
cout<<endl;
z3=z3+z2;
z3.Show();
z4=2+z4;
cout<<endl;
z4.Show();
z4=z4+2;
cout<<endl;
z4.Show();

} 
//StudybarCommentEnd
