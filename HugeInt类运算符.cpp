#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

class HugeInt {
		friend ostream &operator<<( ostream &, const HugeInt & );
	public:
		static const int digits = 30;
		HugeInt( long = 0 ); // conversion/default constructor
		HugeInt( const char * ); // conversion constructor

		// addition operator; HugeInt + HugeInt
		HugeInt operator+( const HugeInt & ) const;
		HugeInt operator-( const HugeInt & ) const;
		bool operator>( const HugeInt & ) const;
		bool operator>=( const HugeInt & ) const;
		bool operator<( const HugeInt & ) const;
		bool operator<=( const HugeInt & ) const;
		bool operator==( const HugeInt & ) const;
		bool operator!=( const HugeInt & ) const;

		// addition operator; HugeInt + int
		HugeInt operator+( int ) const;

		// addition operator;
		// HugeInt + string that represents large integer value
		HugeInt operator+( const char * ) const;

		int getLength() const;
	private:
		short integer[ digits ];
}; // end class HugeInt


HugeInt HugeInt::operator+(const HugeInt &op2) const {
	HugeInt temp;
	int carry = 0; //进位
	for (int i = 29; i >= 0; i--) {
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		if (temp.integer[i] > 9) {
			temp.integer[i] %= 10;
			carry = 1;
		} else
			carry = 0;
	}
	return temp;
}


HugeInt HugeInt::operator-( const HugeInt &op2) const {
	HugeInt temp;
	int carry = 0; //进位
	for (int i = 29; i >= 0; i--) {
		temp.integer[i] = integer[i] - op2.integer[i] + carry;
		if (temp.integer[i] < 0) {
			temp.integer[i] += 10;
			carry = -1;
		} else
			carry = 0;
	}
	return temp;
}

bool HugeInt::operator>( const HugeInt &op2) const {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (integer[i] == op2.integer[i]) {
			sum++;
			if (sum == 30)
				return false;
		} else if (integer[i] < op2.integer[i]) {
			return false;
		} else
			return true;
	}
}

bool HugeInt::operator>=( const HugeInt &op2) const {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (integer[i] == op2.integer[i]) {
			sum++;
			if (sum == 30)
				return true;
		} else if (integer[i] < op2.integer[i]) {
			return false;
		} else
			return true;
	}
}

bool HugeInt::operator<( const HugeInt &op2) const {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (integer[i] == op2.integer[i]) {
			sum++;
			if (sum == 30)
				return false;
		} else if (integer[i] > op2.integer[i]) {
			return false;
		} else
			return true;
	}
}

bool HugeInt::operator<=( const HugeInt &op2) const {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (integer[i] == op2.integer[i]) {
			sum++;
			if (sum == 30)
				return true;
		} else if (integer[i] > op2.integer[i]) {
			return false;
		} else
			return true;
	}
}

bool HugeInt::operator==( const HugeInt &op2) const {
	if (integer == op2.integer)
		return true;
	return false;

}

bool HugeInt::operator!=( const HugeInt &op2) const {
	if (integer != op2.integer)
		return true;
	return false;

}









HugeInt HugeInt::operator+( int val) const {
	HugeInt va(val), result;
	result = va + *this;
	return result;
}

HugeInt HugeInt::operator+( const char *c) const {
	HugeInt va(c), result;
	result = va + *this;
	return result;
}

HugeInt::HugeInt(long val) {
	for (int i = 0; i <= 29; i++)
		integer[i] = 0;
	for (int i = 29; val != 0 && i >= 0; i --) {
		integer[i] = val % 10;
		val /= 10;
	}
}

HugeInt::HugeInt(const char *s) {
	for (int i = 0; i <= 29; i++)
		integer[i] = 0;
	for (int i = 30 - strlen(s), j = 0; i <= 29; i++, j++)
		integer[i] = s[j] - '0';
}



ostream &operator << (ostream &output, const HugeInt &num) {
	int i = 0;
	for (; (num.integer[i] == 0) && (i <= 29); i++)
		; // 跳过前导0
	if (i == 30)
		output << 0;
	else
		for (; i <= 29; i++)
			output << num.integer[i];
	return output;
}


//StudybarCommentBegin
int main() {
	HugeInt n1( 7654321 );
	HugeInt n2( 7891234 );
	HugeInt n3( "99999999999999999999999999999" );
	HugeInt n4( "1" );
	HugeInt n5( "12341234" );
	HugeInt n6( "7888" );
	HugeInt result;

	cout << "n1 is " << n1 << "\nn2 is " << n2
	     << "\nn3 is " << n3 << "\nn4 is " << n4
	     << "\nn5 is " << n5 << "\nn6 is " << n6
	     << "\nresult is " << result << "\n\n";

	// test relational and equality operators
	if ( n1 == n2 )
		cout << "n1 equals n2" << endl;

	if ( n1 != n2 )
		cout << "n1 is not equal to n2" << endl;

	if ( n1 < n2 )
		cout << "n1 is less than n2" << endl;

	if ( n1 <= n2 )
		cout << "n1 is less than or equal to n2" << endl;

	if ( n1 > n2 )
		cout << "n1 is greater than n2" << endl;

	if ( n1 >= n2 )
		cout << "n1 is greater than or equal to n2" << endl;

	result = n1 + n2;
	cout << n1 << " + " << n2 << " = " << result << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";

	result = n1 + 9;
	cout << n1 << " + " << 9 << " = " << result << endl;

	result = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << result << endl;

	result = n5 - n6;
	cout << n5 << " - " << n6 << " = " << result << endl;

	return 0;
} // end main

//StudybarCommentEnd
