#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
    Node * previous;
};
Node *first;
Node *last;

void khoiTao(){
    first = NULL;
    last = NULL;
}

void duyetDsLast(){
    Node *temp;
    while(temp != NULL){
        cout<<temp->info<<endl;
        temp = temp-> previous;
    }
}

void themDau(int x)
{

    Node *p = new Node;
    p->info = x;
    p->next = first;
    p->previous = first;
    if(first != NULL){
        first -> previous = p;
    }
    else
        last = p;
    first = p;
}
void themCuoi(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    p->previous = last;
    if(last == NULL)
        first = p;
    else 
        last -> next = p;
    last = p;
}

int xoaDau()
{
    if(first != NULL)
    {
        Node *p, *q;
         p = first;
         q= NULL;
         while (p->next != NULL)
         {
             q = p;
             p = p->next;/* code */
         }
         if (p == first)
         first = NULL;
         else
          q->next = NULL;
            delete p;
            return 1
         
    }
    return 0;

}
int xoaCuoi()
{
    if (first != NULL)
    {
       Node * tmp = last;
    last = last -> previous;
    if(last != NULL)
    last -> next = NULL;
    else
    first = NULL;
    delete tmp;
    retrun 1; /* code */
    }
}
Node * timKiem(int x)
{
    Node * tmp = first;
    while ((tmp != NULL)&& (tmp->info != x))
    {
        tmp = tmp-> next;
    }
    return tmp;
}

Node * timKiemTuCuoi(int x)
{
    Node * tmp = last;
    while ((tmp != NULL)&& (tmp->info != x))
    {
        tmp = tmp-> previous;
    }
    return tmp;
}


int main() {
    int chon;
    do {
        cout << "1. Khoi tao ds\n";
        cout << "2. Duyet ds\n";
        cout << "3. Them mot phan tu vao dau ds\n";
        cout << "4. Them mot phan tu vao cuoi ds\n";
        cout << "5. Xoa mot phan tu dau ds\n";
        cout << "6. Xoa mot phan tu cuoi ds\n";
        cout << "7. Tim mot phan tu cuoi ds\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "================================\n";
        cout << "Moi ban chon: ";
        cin >> chon;
        system("cls");

        switch (chon)
        {
        case 0:
            break;
        case 1:
            unit();
            cout << "Khoi tao thanh cong.\n";
            break;
        case 2:
            cout << "Cac phan tu trong DS: ";
            duyetcuoi();
            break;
        case 3:
            int n;
            cout << "Nhap phtu can them: ";
            cin >> n;
            if (themdau(n) == 1)
                cout << "Them thanh cong.";
            else
                cout << " Them khong thanh cong.";
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
            break;
        }
    } while (chon != 0);
    return 0;
}

