#include<iostream>
using namespace std;


// Khai bao cau truc cua mot node trong deque
struct node
{
	int data;//deque dang chua cac so nguyen
	struct node* pNext; //con tro lien ket giua cac node voi nhau
};
typedef struct node NODE;


//khai bao cau truc cua deque
struct deque
{
	NODE* pHead;// dung con tro dau va cuoi de quan ly deque
	NODE* pTail;
};
typedef struct deque DEQUE;


//ham khoi tao deque
void khoiTaoDeque(DEQUE& q)
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

//ham IsEmpty( kiem tra deque co rong hay khong)
bool IsEmpty(DEQUE q)
{
	//neu danh sach rong
	if (q.pHead == NULL)
		return true;
	return false;//danh sach co phan tu
}

void Pushfront(DEQUE& q, NODE* p)
{
	if (q.pHead == NULL)// danh sách rỗng
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		p->pNext = q.pHead;//cho node p trỏ đến node đầu tiên
		q.pHead = p;//cập nhập lại node đầu bằng p		
	}
}

void Pushback(DEQUE& q, NODE* p)
{
	if (q.pHead == NULL)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
}

void Popfront(DEQUE& q)
{
	//nếu danh sách rỗng
	if (q.pHead == NULL)
	{
		return;
	}
	NODE* p = q.pHead;//node p là node sẽ xóa
	q.pHead = q.pHead->pNext;//cập nhập lại pHead là phần tử kế tiếp
	delete p;
}


void Popback(DEQUE& q)
{
	//nếu deque rỗng
	if (q.pHead == NULL)
		return;
	//trường hợp deque có một phần tử
	if (q.pHead->pNext == NULL)
	{
		Popfront(q);
		return;
	}
	//duyệt từ đầu deque đến phần tử kế cuối
	for (NODE* k = q.pHead; k != NULL; k = k->pNext)
	{
		//phát hiện phần tử kế cuối
		if (k->pNext == q.pTail)
		{
			delete q.pTail;// xóa đi phần tử cuối
			k->pNext = NULL;// cho con trỏ của node kế cuối trỏ đến vùng nhớ NULL
			q.pTail = k;// cập nhập lại l.pTail.
			break;
		}
	}

}


//ham xuat deque
void xuat(DEQUE q)
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


void Menu(DEQUE& q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t MENU";
		cout << "\n\n\t 1: Them node vao cuoi danh sach";
		cout << "\n\n\t 2: Them node vao dau danh sach";
		cout << "\n\n\t 3: Xoa node dau danh sach";
		cout << "\n\n\t 4: Xoa node cuoi danh sach";
		cout << "\n\n\t 5: Xuat danh sach lien ket don";
		cout << "\n\n\t 0: Thoat";

		cout << "\n\n\t END" << endl;

		cout << "Nhap lua chon: "; cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE* p = khoiTaoNode(x);
			Pushback(q, p);
		}
		else if (luachon == 2)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE* p = khoiTaoNode(x);
			Pushfront(q, p);
		}
		else if (luachon == 3)
		{
			cout << q.pHead->data << endl;
			system("pause");
			Popfront(q);
		}
		else if (luachon == 4)
		{
			cout << q.pTail->data << endl;
			system("pause");
			Popback(q);
		}
		else if (luachon == 5)
		{
			xuat(q);
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
			//cin >> luachon;
		}
	}
}


int main()
{
	DEQUE q;
	khoiTaoDeque(q);
	Menu(q);
	system("pause");
	return 0;
}
