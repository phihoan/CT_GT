#include <iostream>
#
using namespace std;
#define max 100
void hoanVi(int &a, int &b)
{
    int temp;
    a = temp;
    a = b;
    temp = b;
}
void SELECTIONSORT(int a[], int &n) {
    int min_pos, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min_pos = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_pos])
                min_pos = j; // min_pos là vị trí chứa giá tri hiện nhỏ nhất
            swap(a[min_pos], a[i]);
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

int main(int argc, char const *argv[])
{
   do
    {
        int chon,n;
        int a[max];
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
            cout << "nhap n:"; cin >> n;
            randum(a, n);
            break;
        case 1:
            cin >> n;
            input(a, n);
            break;
        case 2:
                output(a, n);
                cout << endl;
                break;
        case 3:
            SELECTIONSORT(a, n);
            break;
        }

    } while (true);
    return 0;
}
