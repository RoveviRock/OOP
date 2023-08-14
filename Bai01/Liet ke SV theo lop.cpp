#include <iostream>
#include <string>
#include <vector>
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

int main() {
	int n;
	cin >> n;
	vector<SinhVien> a;
	SinhVien temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	int q; cin >> q;
	while(q--)
	{
		string lop;
		cin >> lop;
		cout << "\nDanh sach SV lop " << lop << ":\n";
		for (SinhVien x : a) {
			if (x.getLop() == lop)
				cout << x;
		}
	}
	return 0;
}