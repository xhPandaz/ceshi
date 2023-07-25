#include<iostream>
using namespace std;
class Cmytime{
	private:
		int hour,min,sec;
	public:
		int Set(int h,int m,int s)
		{
			if(h<0 || h>23 || m<0 ||m>59 || s<0 || s>59)
				return -1;
			hour=h;
			min=m;
			sec=s;
			return 0;
		}
		void Show(){
		cout<<hour<<":"<<min<<":"<<sec;
	}
		Cmytime(int h,int m,int s);
		Cmytime();
		Cmytime(int h);
};

Cmytime::Cmytime(int h,int m,int s)
{
	if(h<0 || h>23 || m<0 ||m>59 || s<0 || s>59)
		return ;
	hour=h;
	min=m;
	sec=s;
	return ;
}

Cmytime::Cmytime()
{
	hour=0;
	min=0;
	sec=0;
	return ;
}

Cmytime::Cmytime(int h)
{
	if(h<0 || h>23)
		return ;
	hour=h;
	min=0;
	sec=0;
	return ;
}


//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;
  Cmytime t1(3,2,1),t2,t3(5);
t1.Show();
cout<<"\n";
t1.Set(h,m,s);
t1.Show();
cout<<"\n";
t2.Show();
cout<<"\n";
t3.Show();
    return 0;
}

//StudybarCommentEnd
