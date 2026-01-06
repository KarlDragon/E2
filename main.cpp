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
int main(){

	// Truong nhom da lam 1 DSNV r, nen se tam comment func, tranh nhap di nhap lai
//	nhapthongtin();
  // themNhanVien();
//  xoaNhanVien();
//	suaNhanVien();
	return 0;
}
