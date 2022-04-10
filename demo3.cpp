#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct SinhVien {
    int ID;
    string name;
    string sex;
    string address;
    int date;
    double avg;
};

void nhapDs(SinhVien sv[], long n)
{
    for(int i=0; i<n; i++)
    {
        cin.ignore(1);
        cout<<"ID: ";
        cin>>sv[i].ID;
        cin.ignore(1);
        cout<<"Name: ";
        getline(cin,sv[i].name);
        cout<<"Address: ";
        getline(cin,sv[i].address);
        cout<<"Date: ";
        cin>>sv[i].date;
        cin.ignore(1);
        cout<<"Avg: ";
        cin>>sv[i].avg;
        cout<<endl;
    }
}
void nhapDStuFile(SinhVien sv[],long &n)
{
    ifstream myFile("SinhVien.txt");
    if(myFile.is_open())
    {
        int i = 0;
        while (!myFile.eof())
        {
            myFile >> sv[i].ID
            myFile.ignore(1);
            getline(myFile,sv[i].name,',');
            getline(myFile,sv[i].sex,',');
            getline(myFile,sv[i].address,',');
            myFile >> sv[i].date;
            myFile.ignore(1);
            myFile >> sv[i].avg;
            i++;
        }
        n=i;
        myFile.close();
    }
    else
    cout<<"ERROR!!!"<<endl;
}
void xuatDs(SinhVien sv[],long n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"ID: "<<sv[i].ID<<endl;
        cout<<"Name: "<<sv[i].name<<endl;
        cout<<"Address: "<<sv[i].address<<endl;
        cout<<"Date: "<<sv[i].date<<endl;
        cout<<"Avergate"<<sv[i].avg<<endl;
    }
}
void suaThongTin(SinhVien sv[],long n, long i)
{
    cout<<"ID: ";
    cin>>sv[i].ID;
    cin.ignore(1);
    cout<<"name: ";
    getline(cin,sv[i].name);
    cout<<"address: ";
    getline(cin,sv[i].address);
    cout<<"Date: ";
    cin>>sv[i].date;
    cout<<"Avergate: ";
    cin>>sv[i].avg;
    xuatDs(sv,n);
}