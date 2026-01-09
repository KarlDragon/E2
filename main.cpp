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
//TODO : tim thong tin theo ten nhan vien (khong phan biet hoa thuong) roi xuat ra man hinh
void toLower(char s[]) {
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}

void spaceToUnderscore(char s[]) {
    for (int i = 0; s[i]; i++)
        if (s[i] == ' ')
            s[i] = '_';
}

int main() {
    const int MAX = 100;

    int STT[MAX], tuoi[MAX], luong[MAX], tongLuong[MAX];
    char ten[MAX][50], ngaySinh[MAX][20], email[MAX][50], sdt[MAX][20];

    ifstream fin("DSNV.txt");
    if (!fin) {
        cout << "Khong mo duoc file DSNV.txt";
        return 0;
    }

    int n = 0;

    while (fin >> STT[n]
               >> ten[n]
               >> ngaySinh[n]
               >> email[n]
               >> sdt[n]
               >> tuoi[n]
               >> luong[n]
               >> tongLuong[n]) {
        n++;
    }
    fin.close();

    char tenTim[50];
    cout << "Nhap ten nhan vien: ";
    cin.getline(tenTim, 50);

    spaceToUnderscore(tenTim); 
    toLower(tenTim);

    bool timThay = false;

    for (int i = 0; i < n; i++) {
        char temp[50];
        strcpy(temp, ten[i]);
        toLower(temp);

        if (strcmp(temp, tenTim) == 0) {
            cout << "\nSTT: " << STT[i];
            cout << "\nTen: " << ten[i];
            cout << "\nNgay sinh: " << ngaySinh[i];
            cout << "\nEmail: " << email[i];
            cout << "\nSDT: " << sdt[i];
            cout << "\nTuoi: " << tuoi[i];
            cout << "\nLuong: " << luong[i];
            cout << "\nTong luong: " << tongLuong[i];
            timThay = true;
            break;
        }
    }

    if (!timThay)
        cout << "\nKhong tim thay nhan vien";

    fclos(stdout);
}
// TODO : Sap xep danh sach nhan vien giam dan theo thuc linh roi ghi ra file DSNV_SAPXEP.txt
void sapXepNhanVien() {
	string dsNoiDung[1000];
	double dsThucLinh[1000];
	int count = 0;
	string line;

	if (freopen("DSNV.txt", "r", stdin) == NULL) return;

	while (getline(cin, line) && count < 1000) {
		if (line.empty()) continue;

		dsNoiDung[count] = line;

		size_t pos = line.find_last_of(' ');
		if (pos != string::npos) {
			dsThucLinh[count] = stod(line.substr(pos + 1));
		}
		else {
			dsThucLinh[count] = 0;
		}
		count++;
	}
	fclose(stdin);

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (dsThucLinh[i] < dsThucLinh[j]) { 

				double tempLuong = dsThucLinh[i];
				dsThucLinh[i] = dsThucLinh[j];
				dsThucLinh[j] = tempLuong;


				string tempNoiDung = dsNoiDung[i];
				dsNoiDung[i] = dsNoiDung[j];
				dsNoiDung[j] = tempNoiDung;
			}
		}
	}


	if (freopen("DSNV_SAPXEP.txt", "w", stdout) != NULL) {
		for (int i = 0; i < count; i++) {
			cout << dsNoiDung[i] << endl;
		}
		fclose(stdout);
	}
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
			cout << line << endl;
		}
		i++;
	}
	fclose(stdin);
	fclose(stdout);

}
// TODO : Them thong tin cua 1 nhan vien roi ghi ds ra DSNV_THEM.txt
void themNhanVien(){
    int id;
	string line,them;
	cout <<"Nhap thong tin nhan vien moi: ";
	getline(cin,them);
	freopen("DSNV.txt", "r", stdin);
	freopen("DSNV_THEM.txt","w",stdout);
	while(getline(cin, line)){
            cout<<line<<endl;
	}
	stringstream ss(line);
	ss>>id;
	cout<<id+1<<" "<<them;
	fclose(stdin);
	fclose(stdout);

}
// TODO : Sua thong tin cua 1 nhan vien roi ghi ds ra DSNV_SUA.txt
void suaNhanVien(){
	int id,i = 1;
	string line,sua;
	cout << "Nhap ma so nhan vien can sua: ";
	cin >> id;
	cout <<"Sua thong tin thanh vien või ma "<<id<<": ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin,sua);
	freopen("DSNV.txt", "r", stdin);
	freopen("DSNV_SUA.txt","w",stdout);
	while(getline(cin, line)){
		if ( id == i ){
            cout<<i<<" "<<sua<<"\n";
			i++;

			continue;
		}
		else{
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

	while (getline(fin, line)) {     
			cout << line << endl;         

	}
	fin.close();


}
// TODO: Tìm thông tin nhân viên theo mã (Câu 3)
void timNhanVienTheoid() 
{
    int idCanTim, i = 1;
    string line;
    bool timThay = false;

    cout << "Nhap ma so nhan vien can tim: ";
    cin >> idCanTim;

    ifstream file("DSNV.txt");

    while (getline(file, line)) 
    {
        if (i == idCanTim) 
        {
            cout << "Thong tin nhan vien tim thay:" << endl;
            cout << line << endl;
            timThay = true;
            break; 
        }
        i++;
    }

    if (!timThay) 
    {
        cout << "Khong tim thay nhan vien co ID: " << idCanTim << endl;
    }

    file.close();
}
// TODO : Xuat danh sanh nhan vien co thuc linh thap nhat
void xuatNhanvienthuclinhthapnhat() {
	ifstream fin("DSNV.txt");
	vector<string>ds;
	vector<double> thuclinh;
	string line;
	double minTL = DBL_MAX;
	while (getline(fin, line)) {
		ds.push_back(line);
		stringstream ss(line);
		string temp;
		double tl = 0;
		while (ss >> temp) {
			if (stringstream(temp) >> tl) {

			}
		}
		thuclinh.push_back(tl);
		minTL = min(minTL, tl);
	}
	fin.close();

	cout << "\nNhan vien co thuc linh thap nhat (" << minTL << "):\n";
	for (size_t i = 0; i < ds.size(); i++){
		if (thuclinh[i] == minTL) {
			cout << ds[i] << endl;
		}
	}
}
int main() {
	 // Truong nhom da lam 1 DSNV r, nen se tam comment func, tranh nhap di nhap lai
//     nhapthongtin();
  // themNhanVien();
//  xoaNhanVien();
//     suaNhanVien();
	// docDanhSachNhanVien();
	// sapXepNhanVien();
	// timNhanVienTheoid();
	// xuatNhanvienthuclinhthapnhat();
	return 0;

}