#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct SinhVien
{
	string id, name, sex, address;
	int date;
	double avg;
	SinhVien *next;
};

void init(SinhVien*& first) 
{
	first = NULL;
}

void nhapDS(SinhVien*& first) {
	SinhVien* sv = new SinhVien;
	if (first == NULL) {
		first = sv;
	}
	else {
		SinhVien *temp = first;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = sv;
	}
	sv->next = NULL;
	cin.ignore();
	cout << "Nhap mssv: ";
	getline(cin, sv->id);
	cout << "Nhap Ho ten: ";
	getline(cin, sv->name);
	cout << "Nhap gt: ";
	getline(cin, sv->sex);
	cout << "Nhap dia chi: ";
	getline(cin, sv->address);
	cout << "Nhap nam sinh: ";
	cin >> sv->date;
	cout << "Nhap diem trung binh: ";
	cin >> sv->avg;
	cin.ignore();
	cout << "------------------------------------------" << endl;
}

void nhapDSNhieu(SinhVien*& first, long n) 
{
	for (int i = 0; i < n; i++) {
		nhapDS(first);
	}

}

void xuatDS(SinhVien* first) 
{
	while (first != NULL) {
		cout << "MSSV: " << first->id << endl;
		cout << "Ho va Ten: " << first->name << endl;
		cout << "Gioi tinh: " << first->sex << endl;
		cout << "Nam sinh: " << first->date << endl;
		cout << "Diem Trung Binh: " << first->avg << endl;
		cout << "------------------------------------------" << endl;
		first = first->next;
	}
}

void hieuChinhSV(SinhVien*& sv, string ms) 
{
	SinhVien *temp = sv;
	while (temp != NULL) {
		if (temp->mssv == ms) {
			cout << "Nhap mssv: ";
			getline(cin, sv->id);
			cout << "Nhap Ho ten: ";
			getline(cin, sv->name);
			cout << "Nhap gt: ";
			getline(cin, sv->sex);
			cout << "Nhap dia chi: ";
			getline(cin, sv->address);
			cout << "Nhap nam sinh: ";
			cin >> sv->date;
			cout << "Nhap diem trung binh: ";
			cin >> sv->avg;
			cin.ignore();
			break;
		}
		temp = temp->next;

	}
	xuatDS(sv);
}

void xoaCuoi(SinhVien *&sv) 
{
	SinhVien *temp = sv;
	while (temp->next->next != NULL) 
    {
		temp = temp->next;
	}
	SinhVien *x = temp->next;
	delete x;
	temp->next = NULL;
}

void xoaDau(SinhVien *&sv) 
{
	SinhVien *temp = sv;
	sv = sv->next;
	delete temp;
}

void xoaSV(SinhVien *&sv, string ms) 
{
	SinhVien* temp = sv;
	while (temp != NULL) {
		if (temp->mssv == ms) {
			if (temp->next == NULL) 
            {				
				xoaCuoi(sv);
			}
			else if (temp == sv) 
            {
				xoaDau(sv);
			}
			else 
            {
				SinhVien* temp1 = sv;
				while (temp1->next != temp) 
                {
					temp1 = temp1->next;
				}
				temp1->next = temp->next;
				delete temp;
			}
			break;
		}
		temp = temp->next;
	}
	cout << "Danh sach hien tai: " << endl;
	xuatDS(sv);
}

void xemThongTin(SinhVien* first, string ms) 
{
	cout << "Thong tin sv co MS: " << ms << endl;
	while (first != NULL) 
    {
		if (first->id == ms)
			break;
		first = first->next;
	}
	cout << "MSSV: " << first->id << endl;
	cout << "Ho va Ten: " << first->name << endl;
	cout << "Gioi tinh: " << first->sex<< endl;
	cout << "Nam sinh: " << first->date<< endl;
	cout << "Diem Trung Binh: " << first->avg << endl;
	cout << "------------------------------------------" << endl;
}

void sapXepTheoTB(SinhVien *&sv) 
{
	SinhVien *temp = sv;
	SinhVien *temp1 = sv;
	long count = 1;
	while (temp != NULL) 
    {
		while (temp1->next != NULL) 
        {
			if (temp1->avg < temp1->next->avg) 
            {
				swap(temp1->avg, temp1->next->avg);
				swap(temp1->name, temp1->next->name);
				swap(temp1->address, temp1->next->address);
				swap(temp1->sex, temp1->next->sex);
				swap(temp1->id, temp1->next->id);
				swap(temp1->date, temp1->next->date);
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
		temp1 = sv;
	}
	cout << "DS sau sap xep: " << endl;
	xuatDS(sv);
}

long demSVCoAvgHon5(SinhVien *sv) 
{
	long count = 0;
	while (sv != NULL) 
    {
		if (sv->avg >= 5) 
        {
			count++;
		}
		sv = sv->next;
	}
	return count;
}



int main()
{
	SinhVien* sv = new SinhVien;
	long n, chon;
	string ms;

	do {
		cout << "--------------------------------------" << endl;
		cout << "1. Khoi tao ds" << endl;
		cout << "2. Nhap ds" << endl;
		cout << "3. Xuat ds" << endl;
		cout << "4. Them thong tin 1 sv" << endl;
		cout << "5. Xoa thong tin 1 sv" << endl;
		cout << "6. Xem thong tin 1 sv" << endl;
		cout << "7. Sap xep theo TB giam" << endl;
		cout << "8. Dem so luon sv co tb > 5" << endl;
		cout << "Press other key to quit" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Chon: ";
		cin >> chon;
		if (chon == 9)
			break;
		switch (chon) {
		case 1:
			init(sv);
			break;
		case 2:
			cout << "Nhap so luon muon nhap: ";
			cin >> n;
			nhapDSNhieu(sv, n);
			break;
		case 3:
			xuatDS(sv);
			break;
		case 4:
			nhapDS(sv);
			break;
		case 5:
			cout << "Nhap mssv: ";
			getline(cin, ms);
			xoaSV(sv, ms);
			break;
		case 6:
			cout << "Nhap mssv: ";
			getline(cin, ms);
			xemThongTin(sv, ms);
			break;
		case 7:
			sapXepTheoTB(sv);
			break;
		case 8:
			cout << "So sv co TB > 5: " << demSVCoAvgHon5(sv) << endl;
			break;

		}
		system("pause");
	} while (chon >= 1 && chon <= 8);
}