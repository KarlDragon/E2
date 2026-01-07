#include <bits/stdc++.h>
using namespace std;

// TODO : nhap ds thong tin roi xuat ra file DSNV.txt 
void nhapthongtin(){
	int n, i;
	cout << "Nhap so luong nhan vien can quan li: ";
	cin>>n;
	vector<string> arr(n);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (i = 0; i<n ; i++){
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ": "; 
		getline(cin, arr[i]);
	}
	
	freopen("DSNV.txt","w",stdout);
	for (i = 0; i < n ; i++){
		cout << i + 1 <<" " ; 
		cout << arr[i] << endl;
	}
	fclose(stdout);

}

//TODO : Xoa 1 nv theo id roi ghi ds ra DSNV_XOA.txt
void xoaNhanVien(){
	int id, i = 1;
	string line;
	cout << "Nhap ma so nhan vien can xoa: ";
	cin >> id;
	
	freopen("DSNV.txt", "r", stdin);
	freopen("DSNV_XOA.txt","w",stdout);
	while(getline(cin, line)){
		if ( id == i ){
			i++;
			continue;
		}
		else{
			if (line == ""){
				break;
			}
			cout << line << endl;
		}
		i++;
	}
	fclose(stdin);
	fclose(stdout);
	
}
//TODO: Doc danh sach nhan vien (cau2)
void docDanhSachNhanVien() {
	ifstream fin("DSNV.txt");
	if (!fin) {
		cout << "Khong mo duoc file DSNV.txt" << endl;
		return;
	}
	string line;
	int count = 0;                    // count BẮT ĐẦU = 0
	while (getline(fin, line)) {     // Đọc dòng ĐẦU TIÊN
			cout << line << endl;         // In dòng ĐẦU TIÊN
			count++;                      // count TĂNG LÊN 1
	}
	fin.close();
}
int main() {
	docDanhSachNhanVien();
	return 0;

}


