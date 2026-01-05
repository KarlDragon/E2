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

int main(){
	// Truong nhom da lam 1 DSNV r, nen se tam comment func, tranh nhap di nhap lai
//	nhapthongtin();
	
	return 0;
}
