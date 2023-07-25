#include <iostream>
#include <cstring> // �����ַ�������
using namespace std;

const int MAXN = 1005; // �ò���20�ڣ�����1005�洢�߾�����������

// �߾��������ඨ��
class BigInt {
public:
    // ���캯��
    BigInt() {
        length = 1;
        memset(data, 0, sizeof(data));
    }
    BigInt(int num) {
        *this = num;
    }
    BigInt(const char* str) {
        *this = str;
    }

    // ���������
    void operator = (int num) {
        char temp[25];
        sprintf(temp, "%d", num);
        *this = temp;
    }
    void operator = (const char* str) {
        memset(data, 0, sizeof(data));
        length = strlen(str);
        for (int i = 0; i < length; i++) {
            data[i] = str[length - i - 1] - '0';
        }
    }
    BigInt operator * (const BigInt& b) const {
        BigInt result;
        int carry = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < b.length; j++) {
                int temp = data[i] * b.data[j] + carry + result.data[i + j];
                result.data[i + j] = temp % 10;
                carry = temp / 10;
            }
            int index = b.length + i;
            while (carry > 0) {
                int temp = carry + result.data[index];
                result.data[index] = temp % 10;
                carry = temp / 10;
                index++;
            }
        }
        result.length = length + b.length;
        while (result.length > 1 && result.data[result.length - 1] == 0) {
            result.length--;
        }
        return result;
    }
    BigInt operator / (int num) const {
        BigInt result;
        result.length = length;
        int remainder = 0;
        for (int i = length - 1; i >= 0; i--) {
            int temp = remainder * 10 + data[i];
            result.data[i] = temp / num;
            remainder = temp % num;
        }
        while (result.length > 1 && result.data[result.length - 1] == 0) {
            result.length--;
        }
        return result;
    }
    BigInt operator + (const BigInt& b) const {
        BigInt result;
        result.length = max(length, b.length) + 1;
        for (int i = 0; i < result.length; i++) {
            result.data[i] += (i < length ? data[i] : 0) + (i < b.length ? b.data[i] : 0);
            if (result.data[i] > 9) {
                result.data[i] -= 10;
                result.data[i + 1] += 1;
            }
        }
        while (result.length > 1 && result.data[result.length - 1] == 0) {
            result.length--;
        }
        return result;
    }
    BigInt operator - ( BigInt& b) {
        BigInt result;
        result.length = length;
        for (int i = 0; i < length; i++) {
            result.data[i] = data[i] - (i < b.length ? b.data[i] : 0);
            if (result.data[i] < 0) {
                result.data[i] += 10;
                data[i + 1] -= 1;
            }
        }
        while (result.length > 1 && result.data[result.length - 1] == 0) {
            result.length--;
        }
        return result;
    }

    // ��Ԫ����������������
    friend ostream& operator << (ostream& out, const BigInt& x) {
        for (int i = x.length - 1; i >= 0; i--) {
            out << x.data[i];
        }
        return out;
    }

private:
    int data[MAXN]; // ���ڴ洢�߾���������ÿһλ
    int length; // �߾���������λ��
};

// ����pi�ĺ���
BigInt calcPi(int n) {
    BigInt  nVal = 10,BigInt bVal = pow(nVal, n + 10);
    BigInt b = bVal,BigInt x1 = b * 4 / 5,BigInt x2 = b / -239,BigInt s = x1 + x2,BigInt t;
    for (int i = 3; ; i += 2) {
        x1 /= -25;
        x2 /= -57121;
        t = (x1 + x2) / i;
        if (t == 0) {
            break;
        }
        s += t;
    }
    BigInt pi = (s * 4) / pow(nVal, 10);
    return pi;
}

int main() {
    int n;
    cin >> n;
    BigInt pi = calcPi(n);
    cout << pi << endl;
    return 0;
}
