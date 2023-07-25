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
	void  AddOneSecond()
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

   t1.AddOneSecond();
   cout<<endl;
   t1.Show();
  
    return 0;
}

//StudybarCommentEnd
