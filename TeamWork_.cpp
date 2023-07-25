
#include <cmath>
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class TeamWorkBigInt
{

public:
    static const int digits = 30;
    // 构造函数
    explicit TeamWorkBigInt(__int64 a = 0);
    explicit TeamWorkBigInt(const char *);
    // 拷贝构造函数

    // 加法
    TeamWorkBigInt operator+(const TeamWorkBigInt &) const;
    TeamWorkBigInt operator+(int) const;
    TeamWorkBigInt operator+(const char *) const;
    TeamWorkBigInt operator+=(const TeamWorkBigInt &);
    // 减法
    TeamWorkBigInt operator-(const TeamWorkBigInt &) const;
    // 乘法
    TeamWorkBigInt operator*(const TeamWorkBigInt &) const;
    TeamWorkBigInt operator*(const int &) const;


    // 除法
    TeamWorkBigInt operator/(const int &) const;
    TeamWorkBigInt operator/(const TeamWorkBigInt &) const;
    TeamWorkBigInt operator/=(const int &);


    bool operator>(const TeamWorkBigInt &) const;
    int getLength() const;                                                                  // 得到大数长度
    friend bool isgr(const TeamWorkBigInt a, const TeamWorkBigInt b, int n);                // 判断被除数部分与除数的大小
    friend TeamWorkBigInt partminus(const TeamWorkBigInt a, const TeamWorkBigInt b, int n); // 减去被除数的部分
    friend TeamWorkBigInt pow(const TeamWorkBigInt a,int );//实现大整数类为底与int类型为幂次的幂运算
    friend ostream &operator<<(ostream &, const TeamWorkBigInt &); // 输出符重载
private:
    int integer[digits];
};

TeamWorkBigInt::TeamWorkBigInt(__int64 t)
{
    __int64 m = t;
    __int64 n = t;
    __int64 count = 0;
    while (m > 0)
    {
        m /= 10;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        integer[i] = n % 10;
        n /= 10;
    }
    for (int i = count; i < 30; i++)
    {
        integer[i] = 0;
    }
}

TeamWorkBigInt::TeamWorkBigInt(const char *a)
{
    int i = 0;
    while (*a != '\0')
    {
        a++;
        i++;
    }
    a--;
    for (int m = 0; m < i; m++)
    {
        integer[m] = (*a - '0');
        a--;
    }
    for (int j = i; j < 30; j++)
    {
        integer[j] = 0;
    }
}

ostream &operator<<(ostream &out, const TeamWorkBigInt &a)
{
    int l = a.getLength();
    for (int i = 0; i < l; i++)
    {
        out << a.integer[a.getLength() - 1 - i];
    }
    return out;
}

TeamWorkBigInt TeamWorkBigInt::operator+(const TeamWorkBigInt &a) const
{
    TeamWorkBigInt b;
    if (a.getLength() > this->getLength())
    {
        b = a;
    }
    else
    {
        b = *this;
    }
    int l = min(a.getLength(), this->getLength());
    for (int i = 0; i < l; i++)
    {
        b.integer[i] = integer[i] + a.integer[i];
    }
    for (int i = 0; i < b.getLength(); i++)
    {
        if (b.integer[i] > 9)
        {
            b.integer[i] -= 10;
            b.integer[i + 1]++;
        }
    }
    return b;
}

TeamWorkBigInt TeamWorkBigInt::operator+(int b) const
{
    int a = b;
    return *this + TeamWorkBigInt(a);
}

TeamWorkBigInt TeamWorkBigInt::operator+(const char *b) const
{
    TeamWorkBigInt a(b);
    return *this + a;
}

TeamWorkBigInt TeamWorkBigInt::operator+=(const TeamWorkBigInt &a) 
{
    int carry = 0; // 进位
    for (int i = 0; i < digits; i++)
    {
        int temp = integer[i] + a.integer[i] + carry;
        carry = temp / 10; // 计算进位
        integer[i] = temp % 10; // 取余作为本位的值
    }
    return *this;
}

int TeamWorkBigInt::getLength() const
{
    int count = 0;
    for (int i = 29; i > 0; i--)
    {
        if (integer[i] != 0)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    return 30 - count;
}

TeamWorkBigInt TeamWorkBigInt::operator-(const TeamWorkBigInt &a) const
{
    TeamWorkBigInt b, c;
    if (*this > a)
    {
        b = *this;
        for (int i = 0; i < a.getLength(); i++)
        {
            if (b.integer[i] < a.integer[i])
            {
                b.integer[i] = 10 + b.integer[i] - a.integer[i];
                b.integer[i + 1] -= 1;
            }
            else
            {
                b.integer[i] -= a.integer[i];
            }
        }
        return b;
    }
    else
    {
        c = a - b;
        c.integer[c.getLength() - 1] *= -1;
        return c;
    }
}

TeamWorkBigInt TeamWorkBigInt::operator*(const TeamWorkBigInt &a) const
{
    TeamWorkBigInt b;
    int l1, l2, l3;
    l1 = a.getLength();
    l2 = this->getLength();
    if (*this>a)
    {
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                b.integer[j + i] += this->integer[j] * a.integer[i];
            }
        }
    }
    l3 = b.getLength();
    for (int i = 0; i < l3; i++)
    {
        if (b.integer[i] > 9)
        {
            b.integer[i + 1] += b.integer[i] / 10;
            b.integer[i] = b.integer[i] % 10;
        }
    }
    return b;
}

TeamWorkBigInt TeamWorkBigInt::operator*(const int &b) const
    {
        TeamWorkBigInt d1;
        int l = this->getLength();
        for (int i = 0; i < l; i++)
        {
            d1.integer[i] = this->integer[i] * b;
        }
        for (int i = 0; i < 30; i++)
        {
            if (d1.integer[i] > 9)
            {
                d1.integer[i + 1] += d1.integer[i] / 10;
                d1.integer[i] = d1.integer[i] % 10;
            }
        }
        return d1;
    }


// 除法
TeamWorkBigInt TeamWorkBigInt::operator/(const int &a) const {
    TeamWorkBigInt aa(a);
    return *this/aa;
}


TeamWorkBigInt TeamWorkBigInt::operator/(const TeamWorkBigInt &b) const
{
    int zero=0;
    TeamWorkBigInt quotient(zero); // 商
    TeamWorkBigInt remainder(*this); // 余数
    int bitOffset = remainder.getLength() - b.getLength();//表示商有多少位

    while (bitOffset >= 0) // 处理被除数和除数的最高位对齐的各个二进制位
    {
        int q = 0; // 商逐位计算的结果
        if (isgr(remainder, b, bitOffset + 1)) // 判断余数与除数大小关系  //if改成while
        {
            TeamWorkBigInt part = partminus(remainder, b, bitOffset + 1); // 减去被除数部分
            remainder = part; // 更新余数
            q++; // 商加一
        }
        bitOffset--; // 处理下一位
        quotient.integer[bitOffset] = q; // 将计算得到的商存储到相应位置上
    }

    return quotient;
}

TeamWorkBigInt TeamWorkBigInt::operator/=(const int &a) {
    TeamWorkBigInt quotient = *this / a;
    memcpy(this->integer, quotient.integer, sizeof(integer));
    return *this;
}


bool TeamWorkBigInt::operator>(const TeamWorkBigInt &a) const {
    if(this->getLength()==a.getLength()){
        for(int i=a.getLength()-1;i>=0;i--){
            if(this->integer[i]>a.integer[i]){
                return true;
            }else if(this->integer[i]<a.integer[i]){
                return false;
            }else{
                if(i==0){
                    return false;
                }
            }
        }
    }else if(this->getLength()>a.getLength()){
        return true;
    }else {
        return false;
    }
    return 0;
}
bool isgr(const TeamWorkBigInt a, const TeamWorkBigInt b, int n)
{
    TeamWorkBigInt m;
    int l = a.getLength();
    for (int i = l - 1; i >= l - n; i--)
    {
        m.integer[n + i - l] = a.integer[i];
    }
    return m > b;
}

TeamWorkBigInt partminus(const TeamWorkBigInt a, const TeamWorkBigInt b, int n)
{
    TeamWorkBigInt c2 = a, d = b;
    TeamWorkBigInt e;
    int x;
    int m = 0;
    int ll = a.getLength();
    int ll1 = n;
    int ll2 = d.getLength();
    for (int j = 0; j < ll2 + ll - ll1; j++)
    {
        if (j < ll - ll1)
        {
            // e.integer[j]=0;
            d.integer[j] = 0;
        }
        else
        {
            // e.integer[j]=c2.integer[l-n+m];
            d.integer[j] = b.integer[m];
            m++;
        }
    }
    return a - d;
}



// StudybarCommentBegin
int main()
{
    int i, N;
    TeamWorkBigInt n = 10, b, x1, x2, s, t, pi; // 拷贝构造函数

    cin >> N;
    N--;
    b = pow(n, N + 10); // pow

    x1 = b * 4 / 5; // 把multi改为*
    x2 = b / -239;  // 除法也需要有普通int的，注意判断正负
    s = x1 + x2;

    for (i = 3; i <= N * 2; i += 2)
    {
        x1 /= -25; // 把上面的搞定了比较容易得到
        x2 /= -57121;
        t = (x1 + x2) / i;
        s += t;
    }
    pi = s * 4;
    cout << (pi / pow(n, 10)) << endl;
    return 0;
}
// StudybarCommentEnd