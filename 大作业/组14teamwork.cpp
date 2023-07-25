#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;
int ss[20]; 
class TeamWorkBigInt
{
	private:	
		short integer[1015];//数字存放 
		int length;//记录数字长度
		int sign;//记录数字正负号 
	public:
		TeamWorkBigInt(int a=0)
		{
			ss[13]++;
			memset(integer,0,sizeof(integer));
    		if (a < 0)
    		{
        		sign = -1; a = -a;
   			 }
    		else
        		sign = 1;
    		int i = 0;
    		int temp = a;
    		while (temp) {
        	temp /= 10;
        	i++;
    		}
    		length=i;
    		for (int m = 0; m < i; m++) {
        		integer[m] = a % 10;
        		a /= 10;
    		}
		}
		TeamWorkBigInt operator+( const TeamWorkBigInt &b); //大整数相加 
		TeamWorkBigInt operator-(TeamWorkBigInt &b); //大整数相减 
		TeamWorkBigInt operator*(const TeamWorkBigInt &b);//大整数相乘 
		TeamWorkBigInt operator/(const TeamWorkBigInt &b);//大整数相除 
		TeamWorkBigInt operator+(int b);//大整数与整数相加
		TeamWorkBigInt operator-(int b);//大整数与整数相减 
		TeamWorkBigInt operator*(int b);//大整数与整数相乘 
		TeamWorkBigInt operator/(int b);//大整数除以整数 
		void operator+=(const TeamWorkBigInt b);//大整数自加 
		void operator/=(int b);//大整数自除 
		bool operator<=(TeamWorkBigInt &b);//大整数比较
		friend  TeamWorkBigInt pow(TeamWorkBigInt a, int b);//大整数pow运算 
		friend ostream &operator<<( ostream &, TeamWorkBigInt  b);//大整数输出 
};
TeamWorkBigInt TeamWorkBigInt::operator+(const TeamWorkBigInt &b)
{
	ss[0]++;
	if(sign==b.sign){
		TeamWorkBigInt c;
		int carry=0;
        int l = max(b.length, length);
        c.length=l;
        int i = 0;
        for (i = 0; i <= l; i++) {
        	if(i<b.length)
        		c.integer[i] += b.integer[i];
        	if(i<length)
        		c.integer[i] += integer[i];
        	c.integer[i]+=carry;
        	carry=c.integer[i]/10;
        	c.integer[i]%=10;        	
        }
        if(c.integer[i-1]!=0)
        	c.length++;
        c.sign = sign;
        return c;
	} 
	else{
		TeamWorkBigInt a1=*this,b1=b;
		if(sign==1)
		{
			b1.sign=1;
			return a1-b1;
		}
		else 
		{
			a1.sign=1;
			return b1-a1;
		}
	}
}
TeamWorkBigInt TeamWorkBigInt::operator-(TeamWorkBigInt &b )
{
	ss[1]++;
	if(sign==b.sign)  
	{	
		if(b<=*this) 
		{
			TeamWorkBigInt c=*this;
			int carry=0,ll=0,i; 
        	for ( i = 0; i <length; i++) {
        	if(i<b.length)
        		c.integer[i] -= b.integer[i];
        	c.integer[i]-=carry;
        	if(c.integer[i]<0)
        		carry=1,c.integer[i]+=10;
        	else
        		carry=0;
        	}
    		while(c.integer[c.length-1]==0)
    			c.length--;
    		if(c.length<0)
    			c.length=0;
    		return c;
		}
		else 
		{
			TeamWorkBigInt a1=*this,b1=b,aa;
			aa=b1-a1;
			aa.sign=(sign==1)?2:1;
			return aa;
		} 
	} 
	else{
		TeamWorkBigInt a1=*this,b1=b;
		b1.sign=(a1.sign==1)?1:2;
		return a1+b1;		
	}
}
TeamWorkBigInt TeamWorkBigInt::operator*(const TeamWorkBigInt &b)
{
	ss[2]++;
	TeamWorkBigInt aa=0,a1,a2;
	a1=*this;
	int i,j;
	for(i=0;i<b.length;i++)
	{
		for(j=0;j<b.integer[i];j++)
		{
			aa=aa+a1;
		}
		a2.length=a1.length+1;
		a2.integer[0]=0;
		for(j=0;j<a1.length;j++)
			a2.integer[j+1]=a1.integer[j];
    	a2.sign=a1.sign;
		a1=a2;
	}
	if(sign==b.sign)
	aa.sign=1;
	else aa.sign=2;
	return aa;
}

TeamWorkBigInt TeamWorkBigInt::operator/(const TeamWorkBigInt &b)
{
	ss[3]++;
	 TeamWorkBigInt q, r=*this, d,bb=b; 
    int l1 = length;    
    int l2 = b.length;        
    //int ld = l1 - l2;             
    int i = 0,j,k=0;
    d.sign=1,bb.sign=1;
    for (i = r.length-b.length,q.length=0; i >= 0; i--)     
    {
        //d = b << i;
        //memset(d.integer,0,sizeof(integer));
    	for (j = i; j<r.length; j++)
    	{
        	d.integer[j-i] = r.integer[j];
    	}
    	d.length=j-i;
        //d.sign=1,bb.sign=1;
        while (bb<=d)             
        {
            d = d-bb;               
            q.integer[i]++;       
            q.length<i?q.length=i+1:1;
    	}
    	for (j = i; j<i+d.length; j++)
    	{
        	 r.integer[j]=d.integer[j-i];
    	}
    	r.length=d.length+i;
    	while(r.integer[r.length-1]==0)
    		r.length--,i=r.length-b.length+1;
    }
    if (sign!=b.sign)
        q.sign = -1;
    return q;
}
TeamWorkBigInt TeamWorkBigInt::operator+(int b)
{
	ss[4]++;
	TeamWorkBigInt b1=b;
	return *this+b1;
}
TeamWorkBigInt TeamWorkBigInt::operator-(int b)
{
	ss[5]++;
	TeamWorkBigInt b1=b;
	return *this-b1;
}
TeamWorkBigInt TeamWorkBigInt::operator*(int b)
{
	ss[6]++;
	TeamWorkBigInt b1=b;
	return *this*b1;
}
TeamWorkBigInt TeamWorkBigInt::operator/(int b)
{
	ss[7]++;
	TeamWorkBigInt b1=b;
	return *this/b1;
}
void TeamWorkBigInt::operator+=(const TeamWorkBigInt b)
{
	ss[8]++;
	*this=*this+b;
}
void TeamWorkBigInt::operator/=(int b)
{
	ss[9]++;
	TeamWorkBigInt b1=b;
	*this=*this/b1;
}
TeamWorkBigInt pow(TeamWorkBigInt a, int b) {
	ss[10]++;
    TeamWorkBigInt c;
    for (int i = 0; i < a.length; i++)
    {
        c.integer[i + b] = a.integer[i];
    }
    c.length=a.length+b;
    return c;
}
ostream &operator<<( ostream &out, const TeamWorkBigInt b )
{
	ss[11]++;
	if(b.sign==1)
	{
		for(int i=b.length;i!=0;i--)
			cout<<b.integer[i-1];//遍历输出
	}else
		{
			cout<<"-";
			for(int i=b.length;i!=0;i--)
				cout<<b.integer[i-1];//遍历输出
		}
	return out;
}
bool TeamWorkBigInt::operator<=(TeamWorkBigInt &b )
{
	ss[12]++;
	int c=0,a1=0,b1=0;
	a1=length,b1=b.length;
	if(a1==b1)
	{
		for(;a1!=0;a1--)
		{
			if(integer[a1-1]<b.integer[a1-1])
			{
				c=0;
				break;//大于触发开关 c 
			}
			if(integer[a1-1]>b.integer[a1-1])
			{
				c=1;
				break;//大于触发开关 c 
			}
		}
	}
	else if(a1<b1)
		return true;
		else return false;
	if(c==0)
	return true;
	else return false;
}

//StudybarCommentBegin
int main()
{	
int i,N;
        TeamWorkBigInt  n=10,b,x1,x2,s,t,pi;

        cin>>N;
	N--;  
	b=pow(n,N+10);
	x1=b*4;
	x1=x1/5;
	x2=b/-239;
	s=x1+x2;
	for(i=3;i<=N*2;i+=2)
	{	x1/=-25;
		x2/=-57121;
		t=(x1+x2)/i;
		s+=t;	
	}
	pi=s*4;
	cout<< (pi/pow(n,10))<<endl;

    return 0;
}
//StudybarCommentEnd
