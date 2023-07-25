#include<iostream>
using namespace std;

class Cmycomplex{
	private:
		double r,i;
	public:
		Cmycomplex(double x=0,double y=0);
		void Set(double r,double i);
		bool operator ==(Cmycomplex &z);
		bool operator !=(Cmycomplex &z);
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

bool Cmycomplex::operator ==(Cmycomplex &z)
{
	if(r==z.r&&i==z.i)
	{
		return true;
	}
	else
	{
		return 0;
	}
}
bool Cmycomplex::operator !=(Cmycomplex &z)
{
	if(r!=z.r&&i!=z.i)
	{
		return true;
	}
	else
	{
		return 0;
	}
}


//StudybarCommentBegin
int main()
{
Cmycomplex  z1(3,4),z2(7),z3;
double  x,y;
cin>>x>>y;
z1.Set(x,y);
cin>>x>>y;
z2.Set(x,y);

if(z1==z2)
cout<<"y\n";
else
cout<<"n\n";
if(z1!=z2)
cout<<"y\n";
else
cout<<"n\n";

}
//StudybarCommentEnd
