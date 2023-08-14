#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

class PhanSo {
private:
	long long tu, mau;
public:
	PhanSo(long long tu, long long mau);
	friend ostream& operator << (ostream&, PhanSo);
	friend istream& operator >> (istream&, PhanSo&);
	friend PhanSo operator + (PhanSo, PhanSo);
	void rutgon();
};

PhanSo::PhanSo(long long tu, long long mau) {
	this->tu = tu;
	this->mau = mau;
}

ostream& operator << (ostream& out, PhanSo a) {
	out << a.tu << "/" << a.mau << endl;
	return out;
}

istream& operator >> (istream& in, PhanSo& a) {
	in >> a.tu >> a.mau;
	return in;
}

PhanSo operator + (PhanSo a, PhanSo b) {
	PhanSo tong(1, 1);
	long long lcm = LCM(a.mau, b.mau);
	tong.tu = (lcm / a.mau) * a.tu + (lcm / b.mau) * b.tu;
	tong.mau = lcm;
	/*long long gcd = GCD(tong.tu, tong.mau);
	tong.tu /= gcd;
	tong.mau /= gcd;*/
	tong.rutgon();
	return tong;
}

void PhanSo::rutgon() {
	long long gcd = GCD(tu, mau);
	tu /= gcd;
	mau /= gcd;
}

int main() {
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}