#include <iostream>
#include <time.h>
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
    cout << endl;
}

void khoiTao(int a[],int &n)
{
    srand(time(0));
    cout<<"Nhap:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 100+1;
    }
    cout<<"Ngau nhien: ";
    xuatDs(a,n);
}

void hoanVi(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void SelectionSort(int a[], int &n )
{
    int min;
    for (int i=0; i<n-1 ; i++)
    {
        min = i;
        for(int j = i+1; j < n ; j++)
        if (a[j] < a[min])
        min = j;
        if (min != i)
        hoanVi(a[min], a[i]);
    }
}
void insertion(int a[], int n)
{
    for (int i = 1; i < n;i++) {
        int x , j;
        j = i -1;
        x = a[i];
        while (j>=0 && a[j]>x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
        
    }
}

void bubble(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        if (a[j] < a[j-1])
        hoanVi(a[j], a[j-1]);
    }
    
}
void InterchangeSort(int a[], int n)
{
    int i, j;
    for (i = 0 ; i<n-1 ; i++)
    for (j =i+1; j < n ; j++)
    if(a[j]< a[i])
    hoanVi(a[i], a[j]);
}

void QuickSort(int a[], int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
                i++; j--;
        }
    }
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
    int j = 2 * i + 1;
    if (j >= n) 
        return;
    if (j + 1 < n) 
        if (a[j] < a[j + 1]) 
            j++;
    if (a[i] >= a[j])
        return;
    else {
        int x = a[i];
        a[i] = a[j];
        a[j] = x;
        shift(a, j, n);
    }
}

void HeapSort(int a[], int n)
{
    int i = n / 2;
    while (i >= 0) 
    {
        shift(a, i, n - 1); i--;
    }
    int right = n - 1; 
    while (right > 0)
    {
        swap(a[0], a[right]); 
        right--; 
        if (right > 0) 
            shift(a, 0, right); 
    }
}
int timkiem(int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        return i;
    }
    return -1;
}
int BinarySearch(int a[], int n, int x)
{
    int left=0, right=n-1, mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==x) return mid;
        if(x>a[mid]) left=mid+1;
        else right=mid-1;
    }
    return -1; // không tìm thấy x trong danh sách a;
}

// void shift(int a[], int i, int n)
// {
//     int j = 2*i+1;
//     if (j>=n) 
//         return;
//     if (j+1 <n) 
//     if ( a[j]<a[j+1] ) 
//         j++;
//     if (a[i] >= a[j] )
//         return;
//     else {
//        hoanVi(a[i],a[j]);
//         shift(a, j, n);
//     }
// }
// void HeapSort(int a[], int n)
// {
//     int i = n/2;
//     while (i >=0)
//     {
//         shift(a, i, n-1);
//          i--;
//     }
//         int right=n-1; 
//     {
//     if(a[0] > a[right])
//         swap(a[0], a[right]); 
  
//     right--; 
//     if (right > 0) 
//     shift(a, 0, right); 
//     }
// }
int main(int argc, char const *argv[])
{   
    int x,chon,n, left,right, vt;
        left = 0;
        right = n -1;
        int a[MAX];
    do
    {
        
        cout << "-----BTH 3, CHUONG 3, XEP THU TU - TIM KIEM-----\n";
        cout << "0. Khoi tao danh sach ngau nhien " << endl;
        cout << "1. Nhap danh sach " << endl;
        cout << "2. Xuat danh sach " << endl;
        cout << "3. Xep thu tu danh sach bang SELECTION SORT" << endl;
        cout << "4. Xep thu tu danh sach bang INSERTION SORT" << endl;
        cout << "5. Xep thu tu danh sach bang BUBBLE SORT" << endl;
        cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
        cout << "7. Xep thu tu danh sach bang QUICK SORT" << endl;
        cout << "8. Xep thu tu danh sach bang HEAP SORT" << endl;
        cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
        cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
        cout << "11. Thoat" << endl;
        cout << "----------------\n";
        cin >> chon;
        switch (chon)
        {
        case 0:
            khoiTao(a,n);
            break;
        case 1:
            nhapDs(a, n);
            break;
        case 2:
            xuatDs(a, n);
            cout << endl;
            break;
        case 3:
            SelectionSort(a, n);
            xuatDs(a, n);
            break;
        case 4:
            insertion(a, n);
            xuatDs(a, n);
            break;
        case 5:
            bubble(a, n);
            xuatDs(a, n);
            break;
        case 6:
            insertion(a, n);
            xuatDs(a, n);
            break;
        case 7: 
            QuickSort(a,0,n-1);
            xuatDs(a,n);
            break;
        case 8:
            HeapSort(a, n);
            xuatDs(a, n);
            break;
        case 9:
            cout << "Nhap so can tim: ";
            cin>>x;
            vt = timkiem(a,n,x);
            if(vt!= -1)
                cout << x << " nam o vi tri: "<< vt <<endl;
            else
                cout <<"khong tim duoc \n";
            break;
            break;
        case 10:
            InterchangeSort(a, n);
            xuatDs(a, n);
            cout << "Nhap so can tim: ";
            cin>>x;
            vt = BinarySearch(a,n,x);
            if(vt!= -1)
                cout << x << " nam o vi tri: "<< vt <<endl;
            else
                cout <<"khong tim duoc \n";
            break;
        case 11: 
            cout<<" Da thoat " << endl;
        default:
            cout<<"Chon lai chuc nang!!!!"<<endl;
        }     
    } while (chon != 11);
    return 0;
}


// cout << "-----BTH 3, CHUONG 3, XEP THU TU - TIM KIEM-----\n";
// 		cout << "0. Khoi tao danh sach ngau nhien " << endl;
// 		cout << "1. Nhap danh sach " << endl;
// 		cout << "2. Xuat danh sach " << endl;
// 		cout << "3. Xep thu tu danh sach bang SELECTION SORT" << endl;
// 		cout << "4. Xep thu tu danh sach bang INSERTION SORT" << endl;
// 		cout << "5. Xep thu tu danh sach bang BUBBLE SORT" << endl;
// 		cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
// 		cout << "7. Xep thu tu danh sach bang QUICK SORT" << endl;
		// cout << "8. Xep thu tu danh sach bang HEAP SORT" << endl;
		// cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
		// cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
		// cout << "11. Thoat" << endl;
		// cout << "----------------\n";