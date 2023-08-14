#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class SinhVien {
private:
	string maSV, hoten, lop, email;
public:
	SinhVien() {
		maSV = hoten = lop = email = "";
	}
	SinhVien(string maSV, string hoten, string lop, string email, float gpa) {
		this->maSV = maSV;
		this->hoten = hoten;
		this->lop = lop;
		this->email = email;
	}
	friend istream& operator >> (istream&, SinhVien&);
	friend ostream& operator << (ostream&, SinhVien);
	string getLop() {
		return this->lop;	//truy cap vao thuoc tinh private "lop" cua SV
	}
	bool operator < (SinhVien another) {
		return this->lop < another.lop;
	}
};

istream& operator >> (istream& in, SinhVien& a) {
	in >> a.maSV;
	in.ignore();
	getline(in, a.hoten);
	in >> a.lop >> a.email;
	return in;
}

ostream& operator << (ostream& out, SinhVien a) {
	out << a.maSV << "___" << a.hoten << "___" << a.lop << "___" << a.email << endl;
	return out;
}

//bool cmp(SinhVien a, SinhVien b) {
//	return a.getLop() < b.getLop();
//}

int main() {
	int n;
	cin >> n;
	SinhVien* a = new SinhVien[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//sort(a, a + n, cmp);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i];
	return 0;
}