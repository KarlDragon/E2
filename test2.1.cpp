#include <bits/stdc++.h>
#include <string>
using namespace std;
char maNV[100][20];
char Hoten[100][50];
char ngaysinh[100][15];
char email[100][50];
char soDT[100][10];
int songaycong[100];
float luongngay[100];
float thuclinh[100]
// TODO : Xuat danh sach nhan vien co thuc linh thap nhat
void xuatdanhsachnhanviencothuclinhthapnhat(int n) {
	float min_thuclinh = thuclinh[0];
	for (int i = 1; i < n; i++) {
		if (thuclinh[i] < min_thuclinh) {
			min_thuclinh = thuclinh[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (thuclinh[i] == min_thuclinh) {
			cout << "Ma NV: " << maNV[i] << endl;
			cout << "Ho ten: " << Hoten[i] << endl;
			cout << "Ngay sinh: " << ngaysinh[i] << endl;
			cout << "Email: " << email[i] << endl;
			cout << "So DT: " << soDT[i] << endl;
			cout << "So ngay cong: " << songaycong[i] << endl;
			cout << "Luong ngay: " << luongngay[i] << endl;
			cout << "Thuc linh: " << thuclinh[i] << endl;
		}
	}
	return 0;
}
int main() {
	cout << "danh sach nhan vien co thuc linh thap nhat:" << min_thuclinh << endl;
	return 0;
}