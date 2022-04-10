#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

struct SinhVien
{
    string id,name,sex,address;
    int date,
    double avg;
    SinhVien *next;
};

void init(SinhVien*& first)
{
    first = NULL;
}
void input(SinhVien*& first)
{
    SinhVien* sv = new SinhVien;
    if(first == NULL){
        first = sv;
    }
    else
    {
        SinhVien *temp = first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = sv;
    }
    sv->next = NULL;
    cin.ignore();
    cout<<"Insert ID: ";
    getline(cin, sv->id);
    cout<<" Insert name: ";
    getline(cin, sv->name);
    cout<<" Insert sex: ";
    getline(cin, sv->sex);
    cout<<" Address";
    getline(cin, sv->address);
    cout<<"Date: ";
    cin>>sv->date;
    cout<<"Average: ";
    cin>>sv-avg;
    cin.ignore();
}

void insertes(SinhVien*& first,long n)
{
    for(int i=0;i<n;i++){
        input(first);
    }
}
void output(SinhVien* first)
{
    while (first != NULL)
    {
        cout << "MSSV: " << first->id << endl;
		cout << "Ho va Ten: " << first->name << endl;
		cout << "Gioi tinh: " << first->sex << endl;
		cout << "Nam sinh: " << first->date << endl;
		cout << "Diem Trung Binh: " << first->avg << endl;
		cout << "------------------------------------------" << endl;
		first = first->next;
    }
    
}
void hieuChinhSV(SinhVien*& first,string ms)
{
    SinhVien *temp = sv;
    while (temp != NULL)
    {
        if(temp->id == ms){
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
    output(sv);
    
}
void xoaCuoi(SinhVien*& sv)
{
    SinhVIen *temp = sv;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    SinhVIen *x = temp->next;
    delete x;
    tem->next = NULL;
}
void xoaDau(SinhVien*& sv)
{
    SinhVIen *temp = sv;
    sv=sv->next;
    delete temp;
}
void xoaSV(SinhVien *&sv, string ms)
{
    SinhVien *temp = sv;
    while (temp!= NULL)
    {
        if(temp->id === ms)
        {
            if(temp->next ==NULL)
            {
                xoaCuoi(sv);
            }
            else if(temp == sv)
            {
                xoaDau(sv);
            }
            else
            {
                SinhVien* temp1 =sv;
                while(temp1->next != temp)
                {
                    temp1 = temp1->next;
                }
                temp1->next = temp->next
                delete temp;
            }
            break;
        }
        temp = temp->next;
    }
    cout<<"Danh sach hien tai: "<<endl;
    output(sv);
}

void viewer(SinhVien*& first, string ms)
{
    cout<<"Thong tin sv co ms: "<< ms<<endl;
    while(first!=NULL)
    {
        if(first->id ==ms)
        break;
        first = first->next;
    }
    cout<<"ID: "<< first->id<<endl;
    cout<<"Name: "<< first->name<<endl;
    cout<<"Sex: "<<first-> sex<<endl;
    cout<<"Address: "<< first-> address<<endl;
    cout<<"Date: "<< first-> date<<endl;
    cout << "Average"<< first->avg<<endl;  
}
void sortWithAvg(SinhVien*& sv)
{
    SinhVien *temp;
    SinhVien *temp1;
    long n =1;
    while(temp != NULL)
    {
        while(temp1->next != NULL)
        {
            if(temp1 -> avg < temp1 -> next->avg)
            {
                swap(temp1->avg,temp1 -> next->avg);
                swap(temp1->name, temp1->next->name);
				swap(temp1->address, temp1->next->address);
				swap(temp1->sex, temp1->next->sex);
				swap(temp1->id, temp1->next->id);
				swap(temp1->date, temp1->next->date);
            }
            tem1= tem1->next;
        }
        temp = temp1->next;
        temp1 = sv;
    }
    cout<<"Sort Compele: ";
    output(sv);
}
long avgB5(SinhVien *&sv)
{
    long n = 0;
    while(sv != NULL)
    {
        if(sv ->avg>=5)
        {
            n++;
        }
        sv= sv->next;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    SinhVien* sv = new SinhVien;
    long n, chon;
    string ms;
    return 0;
}
