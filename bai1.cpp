#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void nhapDs(int a[],int &n)
{
    cout<<"nhap" ;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout<<"a[ "<<i<<"] = ";
        cin >> a[i];
    }
}
void xuatDs(int a[],int n)
{
     for(int i=0;i<n;i++)
    {
        cout<< a[i]<<"\t";
        
    }
}

int main(){}