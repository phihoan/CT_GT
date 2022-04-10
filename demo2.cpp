#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void nhap(long a[],long &n)
{
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void xuat(long a[],long n)
{
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
void xoa(long a[],long &n,long x)
{
    for(int i = x; i < n; i++){
        a[i] = a[i+1];
    }
    n--;
    xuat(a,n);
}
void xuatLH5(long a[],long n)
{
    for(int i = 0; i < n; i++)
    {
        if (a[i]>5)
        {
            cout << a[i] << " ";/* code */
        }
        
    }
}
void sort(long a[],long n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n-1; j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
     }
     xuat(a,n);
}

void them(long a[],long n,long x, long gt)
{
    n++;
    for (int i = n; i > x; i--)
    {
        a[i] =a[i+1]; /* code */
    }
    a[x] = gt;
    xuat(a,n);
    
}
void capnhat(long a[],long n,long x,long gt){
    a[x] = gt;
    xuat(a,n);
}
int main(int argc, char const *argv[])
{
    long a[100];
    long n, chon,vt,gt;
    do
    {
        cout<<"chon: ";
        cin>>chon;
        if(chon == 8)
        break;
        switch(chon){
            case 1: 
            cout<<"nhap so luong: ";
            cin>>n;
            nhap(a,n);
            break;
            case 2:
                xuat(a,n);
                break;
            case 3:
                xuatLH5(a,n);
                break;
            case 4:
                sort(a,n);
                break;
            case 5:
                cout<<"Nhap vi tri: ";
                cin >> vt;
                cout<<"nhap gt:  ";
                cin>>gt;
                them(a,n,vt,gt);
                break;
            case 6:
                cout<<"Nhap vi tri: ";
                cin>>vt;
                xoa(a,n,vt);break;
            case 7:
                cin>>vt;
                cin>>gt;
                capnhat(a,n,vt,gt);break;
        }
    }while(chon >= 1 && chon <= 7);
    return 0;
}
