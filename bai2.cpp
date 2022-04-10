#include <iostream>
using namespace std;

//DS lien ket don
//khai bao DS
struct Node
 {
     int info; 
     Node *link;
 };
 Node *first;

 void khoiTao(){
     first = NULL;
 }
 void Them_Dau(int x){
    Node*p;
    p= new Node;
    p->info= x;
    p->link= first;
    first= p;
}
void themCuoi(int x)
 {
     Node *p = new Node;
     p->info = x;
     p->link = NULL;
     if (first == NULL)
     {
        first = p;
     }
     else
     {
         Node *temp = first;
         while (temp->link != NULL)
         temp = temp->link;
         temp->link =p;
     }
 }
// xoa phan tu dau
int xoaDau(){
    if(first != NULL)
    {
        Node *temp = first;
        first = first->link;
        delete temp;
        return 1;
    }
    return 0;
}
int *timKiem(int x)
{
    Node * temp = first;
    while(temp != NULL)
    {
        if(temp->info ==x)
        temp = temp->link;
        return temp;
    }
    return NULL

    // Node *temp = first;
    // while((temp != NULL) && (temp ->info !=x))
    //      temp = temp ->link;
    //     return temp;
}
 