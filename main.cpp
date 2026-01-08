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
//TODO : T?m thông tin nhân viên theo tên nhân viên ( không phân bi?t hoa thý?ng), r?i xu?t thông tin nhân viên ðó ra màn h?nh.
    struct NhanVien {
		char ma[20];
		char ten[50];
		int tuoi;
	};
void timthongtinNVtheotenNV(char s[]) {
    for (int i = 0; s[i]; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();

    NhanVien a[100];

    for (int i = 0; i < n; i++) {
        cin.getline(a[i].ma, 20);
        cin.getline(a[i].ten, 50);
        cin >> a[i].tuoi;
        cin.ignore();
    }

    char t[50];
    cin.getline(t, 50);
    timthongtinNVtheotenNV(t);

    for (int i = 0; i < n; i++) {
        char x[50];
        strcpy(x, a[i].ten);
        timthongtinNVtheotenNV(x);

        if (strcmp(x, t) == 0)
            cout << a[i].ma << "\n"
                 << a[i].ten << "\n"
                 << a[i].tuoi << endl;
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
	cout <<"Sua thong tin thanh vien vÃµi ma "<<id<<": ";
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
int main(){

	// Truong nhom da lam 1 DSNV r, nen se tam comment func, tranh nhap di nhap lai
//	nhapthongtin();
  // themNhanVien();
//  xoaNhanVien();
//	suaNhanVien();
	return 0;
}
