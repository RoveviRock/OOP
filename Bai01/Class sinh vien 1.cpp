#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
	string maSV, hoten, lop, birth;
	float gpa;
public:
	SinhVien() {
		maSV = hoten = lop = birth = "";
		gpa = 0;
	}
	SinhVien(string maSV, string hoten, string lop, string birth, float gpa) {
		this->maSV = maSV;
		this->hoten = hoten;
		this->lop = lop;
		this->birth = birth;
		this->gpa = gpa;
	}
	friend void nhap(SinhVien&);
	friend void in(SinhVien);
};

void nhap(SinhVien& a) {
	cin >> a.maSV;
	cin.ignore();
	getline(cin, a.hoten);
	cin >> a.lop >> a.birth >> a.gpa;
	if (a.birth[2] != '/')
		a.birth = '0' + a.birth;
	if (a.birth[5] != '/')
		a.birth.insert(3, "0");
}

void in(SinhVien a) {
	cout << a.maSV << "___" << a.hoten << "___" << a.lop << "___" << a.birth << "___" << a.gpa << endl;
}

int main() {
	SinhVien a;
	nhap(a);
	in(a);
	return 0;
}