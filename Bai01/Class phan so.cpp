#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

class PhanSo {
private:
	long long tu, mau;
public:
	PhanSo(long long tu, long long mau);
	friend ostream& operator << (ostream&, PhanSo);
	friend istream& operator >> (istream&, PhanSo&);
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

void PhanSo::rutgon() {
	long long gcd = GCD(tu, mau);
	tu /= gcd;
	mau /= gcd;
}

int main() {
	PhanSo p(1, 1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}