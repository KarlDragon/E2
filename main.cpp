#include <bits/stdc++.h>
using namespace std;

// TODO : nhap ds thong tin roi xuat ra file DSNV.txt
void nhapthongtin(){
	int n, i, arrSize, soNgaycong, luongNgay, thucLinh;
	cout << "Nhap so luong nhan vien can quan li: ";
	cin>>n;
	vector<vector<string>> arr(n);
	vector<int> thuclinh(n);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string line, row;
	i = 0;
	while(i < n){
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ": ";

		getline(cin, line);
		arr[i].clear();
		stringstream ss(line);
		while (ss >> row) {
			arr[i].push_back(row);
		}

		arrSize = arr[i].size();

		if (arrSize < 7) {
			cout << "Thong tin nhan vien khong du. Vui long nhap lai." << endl;
			continue;
		}
		try{
			soNgaycong = stoi(arr[i][arrSize - 2]);
			if (soNgaycong > 31) {
				cout << "So ngay cong khong hop le. Vui long nhap lai." << endl;
				continue;
			}
			luongNgay = stoi(arr[i][arrSize - 1]);
			thucLinh = soNgaycong * luongNgay;
			arr[i].push_back(to_string(thucLinh));
			i++;
		}
		catch (invalid_argument&) {
			cout << "So ngay cong hoac luong ngay khong hop le. Vui long nhap lai." << endl;
			continue;
		}
	}



	ofstream fout("DSNV.txt");
	if (!fout) {
		cout << "Khong the mo file DSNV.txt de ghi." << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		fout << i + 1 << " ";

		for (int j = 0; j < arr[i].size(); j++) {
			fout << arr[i][j] << " ";
		}

		fout << endl;
	}

	fout.close();
}

//TODO : tim thong tin theo ten nhan vien (khong phan biet hoa thuong) roi xuat ra man hinh
void timNhanVienTheoTen() {
    ifstream f("DSNV.txt");
    if (!f) {
        cout << "Khong mo duoc file DSNV.txt";
        return;
    }

    char tenTim[100];
    cout << "Nhap ten nhan vien: ";
    cin.getline(tenTim, 100);

    for (int i = 0; tenTim[i]; i++) {
        if (tenTim[i] >= 'A' && tenTim[i] <= 'Z')
            tenTim[i] += 32;
    }

    char line[300];
    int timThay = 0;

    while (f.getline(line, 300)) {
        char copy[300];
        strcpy(copy, line);

        strtok(copy, " ");

        char* ho = strtok(NULL, " ");
        char* dem = strtok(NULL, " ");
        char* ten = strtok(NULL, " ");

        if (ho == NULL || dem == NULL || ten == NULL)
            continue;

        char hoTen[100];
        strcpy(hoTen, ho);
        strcat(hoTen, " ");
        strcat(hoTen, dem);
        strcat(hoTen, " ");
        strcat(hoTen, ten);

        for (int i = 0; hoTen[i]; i++) {
            if (hoTen[i] >= 'A' && hoTen[i] <= 'Z')
                hoTen[i] += 32;
        }

        if (strcmp(hoTen, tenTim) == 0) {
            cout << "Thong tin nhan vien tim thay:\n";
            cout << line << endl;
            timThay = 1;
            break;
        }
    }

    if (!timThay)
        cout << "Khong tim thay nhan vien";

    f.close();
    return;
}
// TODO : Sap xep danh sach nhan vien giam dan theo thuc linh roi ghi ra file DSNV_SAPXEP.txt
void sapXepNhanVien() {
	string dsNoiDung[1000];
	double dsThucLinh[1000];
	int count = 0;
	string line;

	ifstream fin("DSNV.txt");
	if (!fin) {
		cout << "Khong the mo file DSNV.txt de doc." << endl;
		return;
	}

	while (getline(fin, line) && count < 1000) {
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
	fin.close();

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

	ofstream fout("DSNV_SAPXEP.txt");
	if (fout) {
		for (int i = 0; i < count; i++) {
			fout << dsNoiDung[i] << endl;
		}
		fout.close();
	}
}

//TODO : Xoa 1 nv theo id roi ghi ds ra DSNV_XOA.txt
void xoaNhanVien(){
	int id, i = 1;
	string line;
	cout << "Nhap ma so nhan vien can xoa: ";
	cin >> id;

	ifstream fin("DSNV.txt");
	ofstream fout("DSNV_XOA.txt");
	while(getline(fin, line)){
		if ( id == i ){
		    i++;
			continue;
		}
		else{
			fout << line << endl;
		}
		i++;
	}
	fin.close();
	fout.close();

}
// TODO : Them thong tin cua 1 nhan vien roi ghi ds ra DSNV_THEM.txt

void themNhanVien(){
    int id,n,i=1,arrSize, soNgaycong, luongNgay, thucLinh;
    vector<string> nv;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string line,row,them;
    while(true){
            cout<<"Nhap thong tin nhan vien can them: ";
            getline(cin,them);
            stringstream ss(them);
            nv.clear();
            while(ss>>row){
                    nv.push_back(row);
            }
            arrSize=nv.size();
            if (arrSize<7){
                    cout << "Thong tin nhan vien khong du. Vui long nhap lai."<<endl;
                    continue;
            }
            try{

                 soNgaycong= stoi(nv[arrSize-2]);
                 if (soNgaycong>31){
                    cout << "So ngay cong khong hop le. Vui long nhap lai."<<endl;
            continue;}
                 luongNgay = stoi(nv[arrSize-1]);
                 thucLinh = soNgaycong * luongNgay;
                 them+=" "+(to_string(thucLinh));
                 break;
            }
            catch (invalid_argument&) { cout << "So ngay cong hoac luong ngay khong hop le. Vui long nhap lai." << endl; }
            }
            ifstream fin("DSNV.txt");
            ofstream fout("DSNV_THEM.txt");
            while(getline(fin, line)){
                    fout << line << endl; i++;
            }
            fout<<i++<<" "<<them;
            fin.close();
            fout.close();
}
// TODO : Sua thong tin cua 1 nhan vien roi ghi ds ra DSNV_SUA.txt
void suaNhanVien(){
    int id,n,i=1,arrSize, soNgaycong, luongNgay, thucLinh;
    cout<<"Nhap ID nhan vien can sua: ";
    cin>>id;
    vector<string> nv;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string line,row,sua;
    while(true){
            cout<<"Nhap thong tin nhan vien can sua: ";
            getline(cin,sua);
            stringstream ss(sua);
            nv.clear();
            while(ss>>row){
                    nv.push_back(row);
            }
            arrSize=nv.size();
            if (arrSize<7){
                    cout << "Thong tin nhan vien khong du. Vui long nhap lai."<<endl;
                    continue;
            }
            try{

                 soNgaycong= stoi(nv[arrSize-2]);
                 if (soNgaycong>31){
                    cout << "So ngay cong khong hop le. Vui long nhap lai."<<endl;
            continue;}
                 luongNgay = stoi(nv[arrSize-1]);
                 thucLinh = soNgaycong * luongNgay;
                 sua+=" "+(to_string(thucLinh));
                 break;
            }
            catch (invalid_argument&){ cout << "So ngay cong hoac luong ngay khong hop le. Vui long nhap lai." << endl; }
            }
            ifstream fin("DSNV.txt");
	        ofstream fout("DSNV_SUA.txt");
	        while(getline(fin, line)){
		    if ( id == i ){
			   fout<<i<<" "<<sua<<endl;
	      	}
	    	else{
		    	fout<<line<<endl;
		    }
		    i++;
	        }
	        fin.close();
	        fout.close();

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

	cout << "\nNhan vien co thuc linh thap nhat:\n";
	for (size_t i = 0; i < ds.size(); i++){
		if (thuclinh[i] == minTL) {
			cout << ds[i] << endl;
		}
	}
}

void UI(){
	cout << "===== CHUONG TRINH QUAN LI NHAN VIEN =====\n";
	cout << "1. Nhap danh sach nhan vien va luu vao file DSNV.txt\n";
	cout << "2. Doc danh sach nhan vien tu file DSNV.txt\n";
	cout << "3. Tim nhan vien theo ma so\n";
	cout << "4. Tim nhan vien theo ten\n";
	cout << "5. Xuat nhan vien co thuc linh thap nhat\n";
	cout << "6. Sap xep danh sach nhan vien giam dan theo thuc linh va luu vao file DSNV_SAPXEP.txt\n";
	cout << "7. Xoa nhan vien theo ma so va luu vao file DSNV_XOA.txt\n";
	cout << "8. Them nhan vien moi va luu vao file DSNV_THEM.txt\n";
	cout << "9. Sua thong tin nhan vien va luu vao file DSNV_SUA.txt\n";
	cout << "0. Thoat chuong trinh\n";
	cout << "===========================================\n";

	int option;
	while (true) {
		cout << "Chon chuc nang (0-9): ";
		cin >> option;

		if (option == 0) {
			cout << "Thoat chuong trinh.\n";
			return;
		}
		else if (option == 1) {
			nhapthongtin();
			cout << "===========================================\n";
		}
		else if (option == 2) {
			docDanhSachNhanVien();
			cout << "===========================================\n";
		}
		else if (option == 3) {
			timNhanVienTheoid();
			cout << "===========================================\n";
		}
		else if (option == 4) {
			timNhanVienTheoTen();
			cout << "===========================================\n";
		}
		else if (option == 5) {
			xuatNhanvienthuclinhthapnhat();
			cout << "===========================================\n";
		}
		else if (option == 6) {
			sapXepNhanVien();
			cout << "===========================================\n";
		}
		else if (option == 7) {
			xoaNhanVien();
			cout << "===========================================\n";
		}
		else if (option == 8) {
			themNhanVien();
			cout << "===========================================\n";
		}
		else if (option == 9) {
			suaNhanVien();
			cout << "===========================================\n";
		}
		else {
			cout << "Chuc nang khong hop le. Vui long chon lai.\n";
			cout << "===========================================\n";
		}
	}

}
int main() {
	UI();
	return 0;
}
