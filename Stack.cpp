#include<iostream>

using namespace std;

// Khai bao cau truc cua mot node trong stack
struct node
{
	int data;//stack dang chua cac so nguyen
	struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;


//khai bao cau truc cua stack
struct stack
{
	NODE* pTop; // dung con tro dau de quan ly stack
};
typedef struct stack STACK;


//ham khoi tao stack
void initStack(STACK& s)
{
	s.pTop = NULL;
}

//ham khoi tao mot cai node
NODE* initNode(int x)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "Khong du du lieu de cap phat !!!";
		return NULL;
	}
	p->data = x;//them gia tri cua bien x vao trong data
	p->pNext = NULL;
	return p;
}

//ham IsEmpty( kiem tra stack co rong hay khong)
bool IsEmpty(STACK s)
{
	return(s.pTop == NULL);
}


//them 1 phan tu vao dau satck
bool Push(STACK& s, int data)
{
	NODE* p = initNode(data);
	if (p == NULL)
		return false;
	//neu stack rong
	if (IsEmpty(s))
	{
		s.pTop = p;//node p gio la node dau cua stack
	}
	else //danh sach da co phan tu
	{
		p->pNext = s.pTop;//cho con tro cua node p tro den dau danh sach <=> tao lien ket
		s.pTop = p;//cap nhap lai node dau cua stack
	}
	return true;
}

//lay phan tu dau stack va huy no di
void Pop(STACK& s, int& x)//x chinh la gia tri can lay trong node
{
	//neu danh sach rong
	if (IsEmpty(s))
	{
		cout << "Danh sach rong" << endl;
	}
	else
	{
		NODE* p = s.pTop;              //node p la node de chung ta xoa
		x = p->data;                  //gan gia tri dau danh sach vao bien x
		s.pTop = s.pTop->pNext;      //cap nhap lai node dau cua stack
		delete p;                   //xoa node dau stack vua lay
		cout << x << " " << endl;
	}

}

//xem thong tin phan tu dau stack va giu nguyen gia tri cua stack
void getTop(STACK& s)//x la bien de lay gia tri can xem
{
	int x;
	if (IsEmpty(s))
		cout << "Danh sach rong" << endl;
	else {
		x = s.pTop->data;//lay gia tri phan tu dau stack ra de xem
		cout << "Phan tu dau stack la: " << x << endl;
	}
}
//ham xuat stack
void xuat(STACK s)
{
	if (IsEmpty(s) == true)
	{
		cout << "Danh sach rong";
	}
	else
	{
		int x;
		node* temp = new node();
		temp = s.pTop;
		while (temp != NULL) {
			x = temp->data;
			temp = temp->pNext;
			cout << x << " ";
		}
	}
}

// ham nhap danh sach cac so nguyen trong stack
void nhap(STACK& s)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1: PUSH" << endl;
		cout << "2: POP" << endl;
		cout << "3: Xem phan tu dau cua stack" << endl;
		cout << "4: Xuat danh sach stack ra man hinh" << endl;
		cout << "5: Thoat" << endl;
		cout << "-----------------------------------";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		switch (luachon) {
		case 1:
		{
			int x;
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Push(s, x);
			break;
		}
		case 2:
		{
			int x;
			Pop(s, x);
			system("pause");
			break;
		}
		case 3:
		{
			getTop(s);
			system("pause");
			break;
		}
		case 4:
		{
			xuat(s);
			cout << endl;
			system("pause");
			break;
		}
		case 5:
		{
			exit(0);
		}
		}
	}
}
int main()
{
	STACK s;
	initStack(s);
	nhap(s);
	system("pause");
	return 0;
}