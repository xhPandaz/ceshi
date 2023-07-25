#include<iostream>
using namespace std;
class Cmytime{
	private:
		int hour,min,sec;
	public:
		int Set(int h,int m,int s)
	{
		if(h<0 || h>23 || m<0 ||m>59 || s<0 || s>59)
			return 0;
		hour=h;
		min=m;
		sec=s;
		return 1;
	}
	void Show(){
		cout<<hour<<":"<<min<<":"<<sec;
	}
	void AddOneSecond()
	{ 
		if(sec<59&&sec>=0)
		{
			sec=sec+1;
		}
		if(sec>=59&&min<59)
		{
			min=min+1;
			sec=0;
		}
		if(sec>=59&&min>=59&&hour<23)
		{
			hour=hour+1;
			min=0;
			sec=0;
		}
	}
	int AddNSeconds(int n)
	{
		sec=sec+n;
		int t=0;
		if(sec>=60)
		{
			min+=sec/60;
			sec=sec%60;
		}
		if(min>=60)
		{
			hour+=min/60;
			min=min%60;
		}
		if(hour>=24)
		{
			t+=hour/24;
			hour=hour%24;
		}
		return t;
	}
};
	
//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;

   Cmytime t1;
   t1.Set(h,m,s);
   t1.Show();
   cout<<endl<<t1.Set(24,0,0)<<"\n";
   t1.Show();

   t1.AddNSeconds(1);
   cout<<endl;
   t1.Show();
   cout<<endl<<t1.AddNSeconds(3600*25);
  
    return 0;
}

//StudybarCommentEnd
