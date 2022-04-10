#include <iostream>
using namespace std;

void input(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Nhap phan tu thu "i <<" :";
        cin>>a[i];
    }
}
void output(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"a[ "<<i<<" ] "<< a[i]<<endl;
    }
}
//ham tim kiem
int search(int a[], int n, int x)
{
   int i =0;
   while((i<n)&&(a[i]!=x))
    i++;
   if(i==n)
    return -1;
   return i;
}

//them phan tu thu
void insert(int a[], int &n, int x, int i)
{
    if(i>=0&& i<n)
    {
        for(int j = n-1, j>=i;j--)
            a[j+1] = a[j];
            a[j] = x;
            n++;
            return 1;
    }
    return 0;
}