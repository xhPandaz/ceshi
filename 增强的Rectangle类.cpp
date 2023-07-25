#include<iostream>
#include<cmath>
using namespace std;
class Rectangle{
	private:
		double X[4],Y[4],Width,Length;
		int isRectangle;//是否是长方形标记 
	public:
		Rectangle(double rect[4][2]);
		void zuobiao(double rect[4][2]);//设置坐标
		double length();//获得长
		double width(); //获得宽 
		double perimeter();//计算周长
		double area();//计算面积
		int square();//判断是否为正方形 
};
Rectangle::Rectangle(double rect[4][2])
{
	Width=0;
	Length=0;
	zuobiao(rect);
}
void Rectangle::zuobiao(double rect[4][2])//输入顺序为左上，右上，左下，右下，按照顺时针保存 
{
	X[0]=rect[0][0];
	X[1]=rect[1][0];
	X[2]=rect[3][0];
	X[3]=rect[2][0];
	
	Y[0]=rect[0][1];
	Y[1]=rect[1][1];
	Y[2]=rect[3][1];
	Y[3]=rect[2][1];
	//判断是否在第一象限
	for (int i=0;i<4;i++){
            for (int j=0;j<2;j++){
                if (rect[i][j]<0||rect[i][j]>20) {
                    rect[i][j]=0;
                    if (j==0) {
                        cout<<"第"<<i+1<<"个点的纵坐标值无效,被置为0"<<endl;
                    } else {
                        cout<<"第"<<i+1<<"个点的横坐标值无效,被置为0"<<endl;
                    }
                    
                }
            }
        } 
		double length1 = (X[1] - X[0]) * (X[1] - X[0]) + (Y[1]-Y[0]) * (Y[1]-Y[0]);
        double width1 = (X[1] - X[2]) * (X[1] - X[2]) + (Y[1] - Y[2]) * (Y[1] - Y[2]);
        double duijiaoxian = (X[2] - X[0]) * (X[2] - X[0]) + (Y[2] - Y[0]) * (Y[2] - Y[0]);
        //0 2 3节点构成直角三角形
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
            cout << "不能构成长方形！\n";
        
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
//        cout<<"请输入第"<<i+1<<"个点的横纵坐标（大于0且小于20）,以空格分隔：";
        cin>>rect[i][0]>>rect[i][1];
    }
    
    Rectangle myRect(rect);
    cout<<"长度为："<<myRect.length()<<endl;
    cout<<"宽度为："<<myRect.width()<<endl;
    cout<<"周长为："<<myRect.perimeter()<<endl;
    cout<<"面积为："<<myRect.area()<<endl;
    
    if(myRect.square())
        cout<<"此长方形是一个正方形"<<endl;
    else
        cout<<"此长方形不是一个正方形"<<endl;
    
    return 0;
}
//StudybarCommentEnd
