#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class Cmycomplex {
	public:
		Cmycomplex(double real = 0, double imag = 0) : real(real), imag(imag) {}
		bool operator<(const Cmycomplex &other) const {
			return abs() < other.abs();
		}
		bool operator==(const Cmycomplex &other) const {
			return real == other.real && imag == other.imag;
		}
		Cmycomplex operator+(const Cmycomplex &other) const {
			return Cmycomplex(real + other.real, imag + other.imag);
		}
		Cmycomplex operator-(const Cmycomplex &other) const {
			return Cmycomplex(real - other.real, imag - other.imag);
		}
		Cmycomplex operator*(const Cmycomplex &other) const {
			double tmpReal = real * other.real - imag * other.imag;
			double tmpImag = real * other.imag + imag * other.real;
			return Cmycomplex(tmpReal, tmpImag);
		}
		Cmycomplex operator/(const Cmycomplex &other) const {
			double tmpDenom = other.real * other.real + other.imag * other.imag;
			double tmpReal = (real * other.real + imag * other.imag) / tmpDenom;
			double tmpImag = (imag * other.real - real * other.imag) / tmpDenom;
			return Cmycomplex(tmpReal, tmpImag);
		}
		void output() const {
			if (imag >= 0) {
				cout << "(" << real << "+" << imag << "i)";
			} else {
				cout << "(" << real << imag << "i)";
			}
		}
		double abs() const {
			return sqrt(real * real + imag * imag);
		}
	private:
		double real;
		double imag;
};

class Cassemblage {
	public:
		void add(Cmycomplex num) {
			nums.insert(num);
		}
		void remove(Cmycomplex num) {
			nums.erase(num);
		}
		void output() const {
			if (nums.empty()) {
				cout << "empty";
			} else {
				for (auto num : nums) {
					num.output();
					cout << " ";
				}
			}
			cout << endl;
		}
		Cassemblage operator+(const Cassemblage &other) const {
			Cassemblage result = *this;
			for (auto num : other.nums) {
				result.add(num);
			}
			return result;
		}
		Cassemblage operator&(const Cassemblage &other) const {
			Cassemblage result;
			for (auto num : nums) {
				if (other.nums.count(num)) {
					result.add(num);
				}
			}
			return result;
		}
		Cassemblage operator-(const Cassemblage &other) const {
			Cassemblage result = *this;
			for (auto num : other.nums) {
				result.remove(num);
			}
			return result;
		}
	private:
		set<Cmycomplex> nums;
};

int main() {
	int n;
	cin >> n;

	Cassemblage assemblage1;
	for (int i = 0; i < n; i++) {
		double real, imag;
		cin >> real >> imag;
		Cmycomplex num(real, imag);
		assemblage1.add(num);
	}

	cin >> n;
	Cassemblage assemblage2;
	for (int i = 0; i < n; i++) {
		double real, imag;
		cin >> real >> imag;
		Cmycomplex num(real, imag);
		assemblage2.add(num);
	}

	Cassemblage unionSet = assemblage1 + assemblage2;
	unionSet.output();

	Cassemblage intersectSet = assemblage1 & assemblage2;
	intersectSet.output();

	Cassemblage diffSet = assemblage1 - assemblage2;
	diffSet.output();

	return 0;
}

