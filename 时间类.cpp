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
};

//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;
  Cmytime t1;
t1.Set(h,m,s);
t1.Show();
    return 0;
}

//StudybarCommentEnd

