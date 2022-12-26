#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void khoiTaoDSLK(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* khoiTaoNODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void themVaoDau(LIST& l, NODE* p)
{
	if (l.pHead == NULL)// danh sách rỗng
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;//cho node p trỏ đến node đầu tiên
		l.pHead = p;//cập nhập lại node đầu bằng p		
	}
}

void themVaoCuoi(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

//xuat
void xuat(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		cout << k->data << " ";
}


// ham them node p vao vi tri vt bat ki
void themNodePBatKi(LIST& l, NODE* p, int vt, int n)
{

	//danh sach rong
	if (l.pHead == NULL || vt == 1)
	{
		//them p vao dau danh sach
		themVaoDau(l, p);
	}
	else if (vt == n + 1)
	{
		//them node p vao cuoi danh sach
		themVaoCuoi(l, p);
	}
	else //vt nam trong khoang [2,n]
	{
		int dem = 0; // xac dinh vi tri can them
		NODE* g = new NODE;//node giu lien ket voi node nam truoc vt  trong danh sach

		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			//tim vi tri vt can them 
			if (dem == vt)
			{
				// thuc hien them node p vao sau node g <=> them node p vao truoc node q
				NODE* h = khoiTaoNODE(p->data);
				h->pNext = k;//tao moi lien ket giua p va q
				g->pNext = h;//tao moi lien ket giua node truoc q voi p
				break;
			}
			g = k;//giu lien ket lan luot voi node nam truoc node q trong danh sach
		}
	}
}

//ham xoa phan tu dau danh sach
void xoaDau(LIST& l)
{
	//nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		return;
	}
	NODE* p = l.pHead;//node p là node sẽ xóa
	l.pHead = l.pHead->pNext;//cập nhập lại pHead là phần tử kế tiếp
	delete p;
}

//ham xóa phần tử cuối danh sách
void xoaCuoi(LIST& l)
{
	//nếu danh sách rỗng
	if (l.pHead == NULL)
		return;
	//trường hợp danh sách có một phần tử
	if (l.pHead->pNext == NULL)
	{
		xoaDau(l);
		return;
	}
	//duyệt từ đầu danh sách đến thằng kế cuối
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		//phát hiện phần tử kế cuối
		if (k->pNext == l.pTail)
		{
			delete l.pTail;// xóa đi phần tử cuối
			k->pNext = NULL;// cho con trỏ của node kế cuối trỏ đến vùng nhớ NULL
			l.pTail = k;// cập nhập lại l.pTail.
			break;
		}
	}

}


//hàm xóa mội node có khóa k bất kì 
void xoaNodeCoKhoaBatKy(LIST& l, int x)
{
	// nếu danh sách rỗng
	if (l.pHead == NULL)
	{
		return;
	}
	//nếu node cần xóa nằm đầu danh sách
	if (l.pHead->data == x)
	{
		xoaDau(l);
		return;
	}
	// nếu node cần xóa nằm cuối danh sách
	if (l.pTail->data == x)
	{
		xoaCuoi(l);
		return;
	}

	// duyệt danh sách tìm node cần xóa
	NODE* g = new NODE;// node đứng trước phần tử cần xóa

	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == x)//phát hiện phần tử cần xóa
		{

			g->pNext = k->pNext;//
			delete k;// xóa node nằm sau node g;
			return;
		}
		g = k;//cho node g trỏ đến node k node truoc node chung ta can xoa
	}
	cout << "Khong co " << x << " trong danh sach" << endl;
	system("pause");
}

// hàm giải phóng vùng nhớ cho danh sách liên kết đơn
void giaiPhongDanhSach(LIST& l)
{
	NODE* k = NULL;
	while (l.pHead != NULL)
	{
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

//menu
void Menu(LIST& l)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t MENU";
		cout << "\n\n\t 1: Them node vao dau danh sach";
		cout << "\n\n\t 2: Them node vao cuoi danh sach";
		cout << "\n\n\t 3: Them node vao vi tri bat ki trong danh sach";
		cout << "\n\n\t 4: Xoa phan tu dau danh sach";
		cout << "\n\n\t 5: Xoa phan tu cuoi danh sach";
		cout << "\n\n\t 6: Xoa node bat ky";
		cout << "\n\n\t 7: Xuat danh sach lien ket don";
		cout << "\n\n\t 0: Thoat";
		cout << "\n\n\t END" << endl;

		cout << "Nhap lua chon: "; cin >> luachon;

		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE* p = khoiTaoNODE(x);
			themVaoDau(l, p);
		}
		else if (luachon == 2)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao: ";
			cin >> x;
			NODE* p = khoiTaoNODE(x);
			themVaoCuoi(l, p);//them node p vao sau node q 
		}		
		else if (luachon == 3)
		{
			int n = 0;
			//vong lap lay so luong node
			for (NODE* k = l.pHead; k != NULL; k = k->pNext)
			{
				n++;
			}
			int x;
			cout << "\nNhap gia tri node p: ";
			cin >> x;

			NODE* p = khoiTaoNODE(x);
			//nhap vi tri can them cho node p ==> can kiem tra dieu kien

			int vt;
			do {
				cout << "\nNhap vi tri can them node p: ";
				cin >> vt;
				if (vt<1 || vt> n + 1)
				{
					cout << "\nVi tri can them nam trong khoang tu [1, " << n + 1 << "]";
					system("pause");
				}
			} while (vt<1 || vt> n + 1);
			themNodePBatKi(l, p, vt, n);
		}
		else if (luachon == 4)
		{
			xoaDau(l);
			system("pause");
		}
		else if (luachon == 5)
		{
			xoaCuoi(l);
			system("pause");
		}
		else if (luachon == 6)
		{
			int x;
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			xoaNodeCoKhoaBatKy(l, x);
		}
		else if (luachon == 7)
		{
			xuat(l);
			cout << endl;
			system("pause");
		}
		else if (luachon == 0)
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
	LIST l;
	khoiTaoDSLK(l);
	Menu(l);
	giaiPhongDanhSach(l);
	system("pause");
	return 0;
}









