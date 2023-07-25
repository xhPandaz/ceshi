#include<iostream>
#include<cmath>
using namespace std;
class Rectangle{
	private:
		double X[4],Y[4],Width,Length;
		int isRectangle;//�Ƿ��ǳ����α�� 
	public:
		Rectangle(double rect[4][2]);
		void zuobiao(double rect[4][2]);//��������
		double length();//��ó�
		double width(); //��ÿ� 
		double perimeter();//�����ܳ�
		double area();//�������
		int square();//�ж��Ƿ�Ϊ������ 
};
Rectangle::Rectangle(double rect[4][2])
{
	Width=0;
	Length=0;
	zuobiao(rect);
}
void Rectangle::zuobiao(double rect[4][2])//����˳��Ϊ���ϣ����ϣ����£����£�����˳ʱ�뱣�� 
{
	X[0]=rect[0][0];
	X[1]=rect[1][0];
	X[2]=rect[3][0];
	X[3]=rect[2][0];
	
	Y[0]=rect[0][1];
	Y[1]=rect[1][1];
	Y[2]=rect[3][1];
	Y[3]=rect[2][1];
	//�ж��Ƿ��ڵ�һ����
	for (int i=0;i<4;i++){
            for (int j=0;j<2;j++){
                if (rect[i][j]<0||rect[i][j]>20) {
                    rect[i][j]=0;
                    if (j==0) {
                        cout<<"��"<<i+1<<"�����������ֵ��Ч,����Ϊ0"<<endl;
                    } else {
                        cout<<"��"<<i+1<<"����ĺ�����ֵ��Ч,����Ϊ0"<<endl;
                    }
                    
                }
            }
        } 
		double length1 = (X[1] - X[0]) * (X[1] - X[0]) + (Y[1]-Y[0]) * (Y[1]-Y[0]);
        double width1 = (X[1] - X[2]) * (X[1] - X[2]) + (Y[1] - Y[2]) * (Y[1] - Y[2]);
        double duijiaoxian = (X[2] - X[0]) * (X[2] - X[0]) + (Y[2] - Y[0]) * (Y[2] - Y[0]);
        //0 2 3�ڵ㹹��ֱ��������
        double width2 = (X[0] - X[3]) * (X[0] - X[3]) + (Y[0] - Y[3]) * (Y[0] - Y[3]);
        double length2 = (X[2] - X[3]) * (X[2] - X[3]) + (Y[2] - Y[3]) * (Y[2] - Y[3]);

        if (length1 == length2 && width1 == width2 && length1 + width1 == duijiaoxian)
        {
            isRectangle = 1;
            if (length1 > width1)
            {
                Length = sqrt(length1);
                Width = sqrt(width1);
            }
            else
            {
                Length = sqrt(width1);
                Width = sqrt(length1);
            }
            
        }
        else
        {
            isRectangle = 0;
            cout << "���ܹ��ɳ����Σ�\n";
        
        }
	
}
double Rectangle::length()
{
	return Length;
}
double Rectangle::width()
{
	return Width;
}
double Rectangle::perimeter()
{
	return (2*length()+2*width());
}
double Rectangle::area()
{
	return (length()*width());
}
int Rectangle::square()
{
	if(Length==Width&&Length!=0)
		return 1;
	else
		return 0;
}






//StudybarCommentBegin
int main()
{
    double rect[4][2];
    int i;
    
    for(i=0;i<4;i++)
    {
//        cout<<"�������"<<i+1<<"����ĺ������꣨����0��С��20��,�Կո�ָ���";
        cin>>rect[i][0]>>rect[i][1];
    }
    
    Rectangle myRect(rect);
    cout<<"����Ϊ��"<<myRect.length()<<endl;
    cout<<"���Ϊ��"<<myRect.width()<<endl;
    cout<<"�ܳ�Ϊ��"<<myRect.perimeter()<<endl;
    cout<<"���Ϊ��"<<myRect.area()<<endl;
    
    if(myRect.square())
        cout<<"�˳�������һ��������"<<endl;
    else
        cout<<"�˳����β���һ��������"<<endl;
    
    return 0;
}
//StudybarCommentEnd
