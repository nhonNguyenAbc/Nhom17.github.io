#include<iostream>
using namespace std;


// Khai bao cau truc cua mot node trong queue
struct node
{
	int data;//queue dang chua cac so nguyen
	struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;


//khai bao cau truc cua queue
struct queue
{
	NODE* pHead;// dung con tro dau va cuoi de quan ly queue
	NODE* pTail;
};
typedef struct queue QUEUE;


//ham khoi tao stack
void khoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

//ham khoi tao mot cai node
NODE* khoiTaoNode(int x)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du du lieu de cap phat !!!";
		return NULL;
	}
	p->data = x;//them gia tri cua bien x vao trong data
	p->pNext = NULL;
	return p;
}

//ham IsEmpty( kiem tra queue co rong hay khong)
bool IsEmpty(QUEUE q)
{
	//neu danh sach rong
	if (q.pHead == NULL)
		return true;
	return false;//danh sach co phan tu
}


//them 1 phan tu vao cuoi queue
bool Enqueue(QUEUE& q, NODE* p)
{

	//neu stack rong
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;//node p gio la node dau va node cuoi cua queue
	}
	else //danh sach da co phan tu
	{
		q.pTail->pNext = p;//lien ket con tro cuoi cua danh sach voi phan tu p can them vao
		q.pTail = p;//cap nhap lai con tro cuoi la node p
	}
	return true;
}

//lay phan tu dau queue va huy no di
bool Dequeue(QUEUE& q, int& x)//x chinh la gia tri can lay trong node
{
	//neu danh sach rong
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* p = q.pHead;              //node p la node de chung ta xoa
		x = p->data;                  //gan gia tri dau danh sach vao bien x
		cout << x << endl;
		q.pHead = q.pHead->pNext;      //cap nhap lai node dau cua queue
		delete p;                   //xoa node dau queue vua lay
	}
	return true;//lay phan tu dau thanh cong
}

//xem thong tin phan tu dau queue va giu nguyen gia tri cua queue
bool Top(QUEUE& q, int& x)//x la bien de lay gia tri can xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data;//lay gia tri phan tu dau queue ra de xem
	return true;
}
//ham xuat queue
void xuat(QUEUE q)
{
	if (IsEmpty(q) == true)
	{
		cout << "Danh sach rong";
	}
	else
	{
		int x;
		node* temp = new node();
		temp = q.pHead;
		while (temp != NULL) {
			x = temp->data;
			temp = temp->pNext;
			cout << x << " ";
		}
	}
}

// ham nhap danh sach cac so nguyen trong stack
void nhap(QUEUE& q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1: Them phan tu vao queue" << endl;
		cout << "2. Xoa phan tu" << endl;
		cout << "3: Xuat danh sach queue ra man hinh" << endl;
		cout << "4: Xem phan tu dau cua queue" << endl;
		cout << "0: Thoat" << endl;
		cout << "END" << endl;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap phan tu can them: ";
			cin >> x;
			NODE* p = khoiTaoNode(x);
			Enqueue(q, p);
		}
		else if (luachon == 2)
		{
			int x;
			Dequeue(q, x);
			if (IsEmpty(q))
			{
				cout << "Danh sach rong" << endl;
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			xuat(q); cout << endl;
			system("pause");
		}
		else if (luachon == 4)
		{
			int x;
			Top(q, x);
			if (IsEmpty(q) == false)
				cout << "Phan tu dau queue la: " << x;
			else 
			{
				cout << "Danh sach rong";
			}
			cout << endl;
			system("pause");
		}
		else if(luachon == 0)
		{
			break;
		}
		else 
		{
			cout << "Moi ban nhap lai" << endl;
			system("pause");
		}
	}
}
int main()
{
	QUEUE q;
	khoiTaoQueue(q);
	nhap(q);
	system("pause");
	return 0;
}
