#include<iostream>
using namespace std;

struct node
{
	int info;
	node* left;
	node* right;
}*root;

int MAX = 100;

void init() {
	root = NULL;
}

void add(node*& p, int x) {
	p = new node;
	if (p == NULL) {
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else {
		if (p->info == x) {
			return;
		}
		else if (p->info > x) {
			return add(p->left, x);
		}
		else {
			return add(p->right, x);
		}
	}
}

node* timKiem(node* p, int x) {
	if (p != NULL) {
		if (p->info == x) {
			return p;
		}
		else
		{
			if (p->info < x) {
				return TimKiem(p->right, x);
			}
			else
				return TimKiem(p->left, x);
		}
	}
	return NULL;
}

void searchStandFor(node*& p, node*& q) {
	if (q->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}

int deleteNode(node*& p, int x) {
	if (p == NULL)
		return 0;
	if (p->info == x) {
		node* T = p;
		if (p->left == NULL)
			p = p->right;
		else if (p->right == NULL)
			p = p->left;
		else
			searchStandFor(T, p->right);
		delete T;
		return 1;
	}
	if (p->info < x)
		return deleteNode(p->right, x);
	if (p->info > x)
		return deleteNode(p->left, x);
}

void duyetNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

void duyetLRN(node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}

void duyetLNR(node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

int demNut(node* p)
{
	if (p == NULL)
	{
		return 0;
	}
	int demL = demNut(p->left);
	int demR = demNut(p->right);
	return demL + demR + 1;
}

int aggregate(node* p)
{
	if (p != NULL)
	{
		int A = aggregate(p->left);
		int B = aggregate(p->right);
		return   p->info + A + B;
	}
	return 0;
}

float avg(node* p) {
	return aggregate(p) / demNut(p);
}

void timMax(node* t)
{
	if (t != NULL)
	{
		if (t->info > MAX)
		{
			MAX= t->info; 
		}
		timMax(t->left);
		timMax(t->right);
	}
}

bool kiemTraSNT(int x) {
	if (x < 2)
	{
		return false;
	}
	else
	{
		if (x == 2) {
			return true;
		}
		else
		{
			if (x % 2 == 0) {
				return false;
			}
			else {
				for (int i = 2; i < x / 2; i++) {
					if (x % i == 0)
						return false;
				}
			}
		}
	}
	return true;
}

int sLSNT(node* t) {
	int dem = 0;
	if (t != NULL) {
		if (kiemTraSNT(t->info)) {
			dem++;
		}
		sLSNT(t->left);
		sLSNT(t->right);
	}
	return dem;
}
int main() {
	int chon;
	bool in = false;
	do {
		cout << "====MENU===\n";
		cout << "1.Khoi Tao\n"
			"2.Them Node \n"
			"3.Tim Phan tu\n"
			"4. Xoa phan tu\n"
			"5. Duyet LNR\n"
			"6. Duyet NLR\n"
			"7. Duyet LRN\n"
			"8. Viet thu tuc dem so phan tu\n"
			"9. Trung Binh Cong cac phan tu\n"
			"10. Tim Max\n"
			"11. Dem so phan tu la so nguyen to\n"
			"12. Thoat\n"
			"BAN CHON: ";
		cout << "\n";
		cin >> chon;
		switch (chon) {
		case 1: {
			init();
			in = true;
			break;
		}
		case 2:
		{
			if (in) {
				int x;
				cout << "Nhap gia tri can them: ";
				cin >> x;
				add(root, x);
			}
			else {
				cout << "Vui long chon khoi tao\n";
			}
			break;
		}
		case 3:
		{
			if (in) {
				int x;
				cout << "Nhap gia tri can tim: ";
				cin >> x;

				if (timKiem(root, x) != NULL) {
					cout << "Gia tri " << x << " co ton tai trong cay nhi phan tai vi tri " << timKiem(root, x) << endl;
				}
				else
					cout << "Gia tri " << x << " khon ton tai trong cay\n";
			}
			else {
				cout << "Vui long chon khoi tao\n";
			}
			break;
		}
		case 4:
		{
			if (in) {
				int x;
				cout << "Nhap gia tri can xoa: ";
				cin >> x;
				if (deleteNode(root, x)) {
					cout << "Xoa thanh cong\n";
				}
				else
					cout << "Khong xoa thanh cong\n";
			}
			else {
				cout << "Vui long chon khoi tao\n";
			}
			break;
		}
		case 5:
		{
			if (in) {

				cout << "Duyet LNR: ";
				duyetLNR(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 6:
		{
			if (in) {
				cout << "DuyetNLR:";
				duyetNLR(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 7:
		{
			if (in) {
				cout << "Duyet LRN:";
				duyetLRN(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 8:
		{
			if (in) {
				cout << "So phan tu trong cay: " << demNut(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 9:
		{
			if (in) {
				cout << "TB CONG CUA CAC PHAN TU TRONG CAY: " << avg(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 10:
		{
			if (in) {
				timMax(root);
				cout << "Gia tri lon nhat trong cay: " << MAX;
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		case 11:
		{
			if (in) {
				cout << "So phan tu la so nguyen to trong cay: " << sLSNT(root);
			}
			else {
				cout << "Vui long chon khoi tao" <<endl;
			}
			break;
		}
		default:
			cout << "Byeee!" <<endl;
			break;
		}
		
	} while (chon >= 0 && chon <= 11);
	system("pause");
	return 0;
}