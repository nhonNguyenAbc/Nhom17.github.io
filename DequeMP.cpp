#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>



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



// mo phong


void Deque(int color)
{
    for (int i = 0; i < 1; i++)
    {
        setcolor(color);
        line(600, 350 + i, 1200, 350 + i);
        line(600, 550 + i, 1200, 550 + i);
    }
}
void Rectangle(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    line(x1, y1, x1, y2);
    line(x1, y1, x2, y1);
    line(x2, y2, x2, y1);
    line(x2, y2, x1, y2);
}


int clst = 3; // color stack
int clr[7] = { 16,16,16,16,16,16,16 }; // color rectangle
int sx1 = 0, sx2 = 0, sx3 = 0, sx4 = 0, sx5 = 0, sx6 = 0; //speed x
int sy1 = 0, sy2 = 0, sy3 = 0, sy4 = 0, sy5 = 0, sy6 = 0; //speed y
char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100]; // Cac gia tri cua stack



//Them s1 vao dang truoc
void Pushs1_Front(int vitri) {
    int n = 0;
    clr[1] = 4;
    while (n < 33) { // n <33 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s1 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy1 += 25;
        }
        // s1 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 += 25;
        }
        n++;
    }
}


//Them s2 vao dang truoc
void Pushs2_Front(int vitri) {
    int n = 0;
    clr[2] = 4;
    while (n < 33) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s2 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy2 += 25;
        }
        // s2 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 += 25;
        }
        n++;
    }
}

//Them s3 vao dang truoc
void Pushs3_Front(int vitri) {
    int n = 0;
    clr[3] = 4;
    while (n < 33) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s3 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy3 += 25;
        }
        // s3 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 += 25;
        }
        n++;
    }
}

//Them s4 vao dang truoc
void Pushs4_Front(int vitri) {
    int n = 0;
    clr[4] = 4;
    while (n < 33) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s4 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy4 += 25;
        }
        // s4 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 += 25;
        }
        n++;
    }
}

//Them s5 vao dang truoc
void Pushs5_Front(int vitri) {
    int n = 0;
    clr[5] = 4;
    while (n < 33) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s5 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy5 += 25;
        }
        // s5 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 += 25;
        }
        n++;
    }
}

//Them s6 vao dang truoc
void Pushs6_Front(int vitri) {
    int n = 0;
    clr[6] = 4;
    while (n < 33) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s6 ->down
        if (n >= 0 && n < 8)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy6 += 25;
        }
        // s6 right
        if (n >= 8 && n < 8 + vitri)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 += 25;
        }
        n++;
    }
}


//Them s1 vao dang sau
void Pushs1_Back() {
    int n = 0;
    clr[1] = 4;
    while (n < 41) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s1 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 += 25;
        }
        // s1 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy1 += 25;
        }
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 -= 25;
        }
        n++;
    }
}


//Them s2 vao dang sau
void Pushs2_Back() {
    int n = 0;
    clr[2] = 4;
    while (n < 41) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s2 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 += 25;
        }
        // s2 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy2 += 25;
        }
        // s2 left
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 -= 25;
        }
        n++;
    }
}

//Them s3 vao dang sau
void Pushs3_Back() {
    int n = 0;
    clr[3] = 4;
    while (n < 41) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s1 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 += 25;
        }
        // s1 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy3 += 25;
        }
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 -= 25;
        }
        n++;
    }
}

//Them s4 vao dang sau
void Pushs4_Back() {
    int n = 0;
    clr[4] = 4;
    while (n < 41) { // n <41 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s4 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 += 25;
        }
        // s4 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy4 += 25;
        }
        // s4 left
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 -= 25;
        }
        n++;
    }
}

//Them s5 vao dang sau
void Pushs5_Back() {
    int n = 0;
    clr[5] = 4;
    while (n < 41) { // n <41 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s5 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 += 25;
        }
        // s5 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy5 += 25;
        }
        // s5 left
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 -= 25;
        }
        n++;
    }
}

//Them s6 vao dang sau
void Pushs6_Back() {
    int n = 0;
    clr[6] = 4;
    while (n < 41) { // n <41 la gia tri xau nhat cua truong hop nay
        system("cls");
        // s6 ->right
        if (n >= 0 && n < 28)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 += 25;
        }
        // s6 down
        if (n >= 28 && n < 36)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy6 += 25;
        }
        // s6 left
        if (n >= 36 && n < 40)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 -= 25;
        }
        n++;
    }
}


//Di chuyen s1 1 don vi sang ben trai
void S1_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s1 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 -= 25;
        }
        n++;
    }
}

//Di chuyen s2 1 don vi sang ben trai
void S2_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s2 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 -= 25;
        }
        n++;
    }
}

//Di chuyen s3 1 don vi sang ben trai
void S3_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s3 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 -= 25;
        }
        n++;
    }
}

//Di chuyen s4 1 don vi sang ben trai
void S4_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s4 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 -= 25;
        }
        n++;
    }
}

//Di chuyen s5 1 don vi sang ben trai
void S5_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s5 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 -= 25;
        }
        n++;
    }
}

//Di chuyen s6 1 don vi sang ben trai
void S6_left() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s6 -> left
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 -= 25;
        }
        n++;
    }
}

//Di chuyen s1 1 don vi sang ben phai
void S1_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s1 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 += 25;
        }
        n++;
    }
}

//Di chuyen s2 1 don vi sang ben phai
void S2_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s2 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 += 25;
        }
        n++;
    }
}


//Di chuyen s3 1 don vi sang ben phai
void S3_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s3 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 += 25;
        }
        n++;
    }
}

//Di chuyen s4 1 don vi sang ben phai
void S4_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s4 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 += 25;
        }
        n++;
    }
}

//Di chuyen s5 1 don vi sang ben phai
void S5_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s5 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 += 25;
        }
        n++;
    }
}



//Di chuyen s6 1 don vi sang ben phai
void S6_right() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // s6 -> right
        if (n >= 0 && n < 4)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 += 25;
        }
        n++;
    }
}


//xoa s1 ra tu truoc
void Pops1_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s1 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 -= 25;
        }
        // s1 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy1 += 25;
        }
        n++;
    }
}

//xoa s2 ra tu truoc
void Pops2_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s2 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 -= 25;
        }
        // s2 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy2 += 25;
        }
        n++;
    }
}

//xoa s3 ra tu truoc
void Pops3_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s3 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 -= 25;
        }
        // s3 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy3 += 25;
        }
        n++;
    }
}

//xoa s4 ra tu truoc
void Pops4_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s4 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 -= 25;
        }
        // s4 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy4 += 25;
        }
        n++;
    }
}

//xoa s5 ra tu truoc
void Pops5_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s5 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 -= 25;
        }
        // s5 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy5 += 25;
        }
        n++;
    }
}

//xoa s6 ra tu truoc
void Pops6_Front() {
    int n = 0;
    while (n < 55) {
        system("cls");
        // s6 -> left
        if (n >= 0 && n < 24)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 -= 25;
        }
        // s6 -> down
        if (n >= 24 && n < 55)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy6 += 25;
        }
        n++;
    }
}

//xoa s1 ra tu sau
void Pops1_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s1 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx1 += 25;
        }
        // s1 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy1 += 25;
        }
        n++;
    }
}

//xoa s2 ra tu sau
void Pops2_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s2 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx2 += 25;
        }
        // s2 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy2 += 25;
        }
        n++;
    }
}

//xoa s3 ra tu sau
void Pops3_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s3 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx3 += 25;
        }
        // s3 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy3 += 25;
        }
        n++;
    }
}

//xoa s4 ra tu sau
void Pops4_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s4 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx4 += 25;
        }
        // s4 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy4 += 25;
        }
        n++;
    }
}

//xoa s5 ra tu sau
void Pops5_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s5 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx5 += 25;
        }
        // s5 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy5 += 25;
        }
        n++;
    }
}

//xoa s6 ra tu sau
void Pops6_Back() {
    int n = 0;
    while (n < 35) {
        system("cls");
        // s6 -> right
        if (n >= 0 && n < 5)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sx6 += 25;
        }
        // s6 -> down
        if (n >= 5 && n < 35)
        {
            Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
            drawText(538 + sx6, 240 + sy6, s6);
            Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
            drawText(538 + sx5, 240 + sy5, s5);
            Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
            drawText(538 + sx4, 240 + sy4, s4);
            Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
            drawText(538 + sx3, 240 + sy3, s3);
            Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
            drawText(538 + sx2, 240 + sy2, s2);
            Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
            drawText(538 + sx1, 240 + sy1, s1);
            Deque(clst);
            sy6 += 25;
        }
        n++;
    }
}

int main()
{
    initgraph();
    char c1[] = "Press any key to view the Deque";
    outtextxy(0, 0, c1);

    _getch();// du man hinh do hoa

    int A[7] = { 0,0,0,0,0,0,0 }; // mang danh dau xem cho do co phan tu nao chua
    int B[6] = { 24, 20, 16, 12, 8 , 4 }; // mang vi tri cua deque
    system("cls");
    int chon; // lua chon menu
    int dem = 0; // bien nay dem xem bao nhieu phan tu da vao deque

    DEQUE q;
    khoiTaoDeque(q);

    while (true) {
        system("cls");
        Rectangle(500 + sx1, 160 + sy1, 600 + sx1, 340 + sy1, clr[1]);
        drawText(538 + sx1, 240 + sy1, s1);
        Rectangle(500 + sx2, 160 + sy2, 600 + sx2, 340 + sy2, clr[2]);
        drawText(538 + sx2, 240 + sy2, s2);
        Rectangle(500 + sx3, 160 + sy3, 600 + sx3, 340 + sy3, clr[3]);
        drawText(538 + sx3, 240 + sy3, s3);
        Rectangle(500 + sx4, 160 + sy4, 600 + sx4, 340 + sy4, clr[4]);
        drawText(538 + sx4, 240 + sy4, s4);
        Rectangle(500 + sx5, 160 + sy5, 600 + sx5, 340 + sy5, clr[5]);
        drawText(538 + sx5, 240 + sy5, s5);
        Rectangle(500 + sx6, 160 + sy6, 600 + sx6, 340 + sy6, clr[6]);
        drawText(538 + sx6, 240 + sy6, s6);
        Deque(clst);
        cout << "1.Them Vao Truoc" << endl;
        cout << "2.Them Vao Sau" << endl;
        cout << "3.Xoa Phan Tu Truoc" << endl;
        cout << "4.Xoa Phan Tu Sau" << endl;
        cout << "0.Exit" << endl;
        cin >> chon;
        if (chon == 1)
        {
            if (dem == 0)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s1;
                NODE* p = khoiTaoNode(1);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs1_Front(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 1)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s2;
                NODE* p = khoiTaoNode(2);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs2_Front(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 2)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s3;
                NODE* p = khoiTaoNode(3);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs3_Front(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 3)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s4;
                NODE* p = khoiTaoNode(4);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs4_Front(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 4)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s5;
                NODE* p = khoiTaoNode(5);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs5_Front(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 5)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s6;
                NODE* p = khoiTaoNode(6);
                Pushfront(q, p);
                for (int i = 0; i < 6; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        Pushs6_Front(B[i]);
                        break;
                    }
                }
            }
            else
            {
                cout << "Khong the them!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 2)
        {
            if (dem == 0)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s1;
                NODE* p = khoiTaoNode(1);
                Pushback(q, p);
                A[0] = 1;
                Pushs1_Back();

            }
            else if (dem == 1)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s2;
                NODE* p = khoiTaoNode(2);
                Pushback(q, p);
                for (int i = 5; i > 0; i--)
                {
                    if (A[i] == 0 && A[i - 1] != 0) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (A[j] == 1)
                                S1_left();
                            else if (A[j] == 2)
                                S2_left();
                            else if (A[j] == 3)
                                S3_left();
                            else if (A[j] == 4)
                                S4_left();
                            else if (A[j] == 5)
                                S5_left();
                            else if (A[j] == 6)
                                S6_left();
                        }
                        Pushs2_Back();
                        for (int k = 5; k > 0; k--) {
                            A[k] = A[k - 1];
                        }
                        A[0] = 2;
                        break;
                    }
                }
            }
            else if (dem == 2)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s3;
                NODE* p = khoiTaoNode(3);
                Pushback(q, p);
                for (int i = 5; i > 0; i--)
                {
                    if (A[i] == 0 && A[i - 1] != 0) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (A[j] == 1)
                                S1_left();
                            else if (A[j] == 2)
                                S2_left();
                            else if (A[j] == 3)
                                S3_left();
                            else if (A[j] == 4)
                                S4_left();
                            else if (A[j] == 5)
                                S5_left();
                            else if (A[j] == 6)
                                S6_left();
                        }
                        Pushs3_Back();
                        for (int k = 5; k > 0; k--) {
                            A[k] = A[k - 1];
                        }
                        A[0] = 3;
                        break;
                    }
                }
            }
            else if (dem == 3)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s4;
                NODE* p = khoiTaoNode(4);
                Pushback(q, p);
                for (int i = 5; i > 0; i--)
                {
                    if (A[i] == 0 && A[i - 1] != 0) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (A[j] == 1)
                                S1_left();
                            else if (A[j] == 2)
                                S2_left();
                            else if (A[j] == 3)
                                S3_left();
                            else if (A[j] == 4)
                                S4_left();
                            else if (A[j] == 5)
                                S5_left();
                            else if (A[j] == 6)
                                S6_left();
                        }
                        Pushs4_Back();
                        for (int k = 5; k > 0; k--) {
                            A[k] = A[k - 1];
                        }
                        A[0] = 4;
                        break;
                    }
                }
            }
            else if (dem == 4)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s5;
                NODE* p = khoiTaoNode(5);
                Pushback(q, p);
                for (int i = 5; i > 0; i--)
                {
                    if (A[i] == 0 && A[i - 1] != 0) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (A[j] == 1)
                                S1_left();
                            else if (A[j] == 2)
                                S2_left();
                            else if (A[j] == 3)
                                S3_left();
                            else if (A[j] == 4)
                                S4_left();
                            else if (A[j] == 5)
                                S5_left();
                            else if (A[j] == 6)
                                S6_left();
                        }
                        Pushs5_Back();
                        for (int k = 5; k > 0; k--) {
                            A[k] = A[k - 1];
                        }
                        A[0] = 5;
                        break;
                    }
                }
            }
            else if (dem == 5)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s6;
                NODE* p = khoiTaoNode(6);
                Pushback(q, p);
                for (int i = 5; i > 0; i--)
                {
                    if (A[i] == 0 && A[i - 1] != 0) {
                        for (int j = i - 1; j >= 0; j--) {
                            if (A[j] == 1)
                                S1_left();
                            else if (A[j] == 2)
                                S2_left();
                            else if (A[j] == 3)
                                S3_left();
                            else if (A[j] == 4)
                                S4_left();
                            else if (A[j] == 5)
                                S5_left();
                            else if (A[j] == 6)
                                S6_left();
                        }
                        Pushs6_Back();
                        for (int k = 5; k > 0; k--) {
                            A[k] = A[k - 1];
                        }
                        A[0] = 6;
                        break;
                    }
                }
            }
            else
            {
                cout << "Khong the them!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 3)
        {
            int frontDeque;
            if (IsEmpty(q))
                frontDeque = -1;
            else
                frontDeque = q.pHead->data;
            Popfront(q);
            if (frontDeque == 1) {
                Pops1_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == 2) {
                Pops2_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == 3) {
                Pops3_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == 4) {
                Pops4_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == 5) {
                Pops5_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == 6) {
                Pops6_Front();
                for (int i = 5; i >= 0; i--) {
                    if (A[i] != 0) {
                        A[i] = 0;
                        break;
                    }
                }
            }
            else if (frontDeque == -1)
            {
                cout << "Khong the xoa!!!!!!!" << endl;
                Sleep(1500);
            }
        }
        if (chon == 4) {
            int backDeque;
            if (IsEmpty(q))
                backDeque = -1;
            else
                backDeque = q.pTail->data;
            Popback(q);
            if (backDeque == 1)
            {
                A[0] = 0;
                Pops1_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == 2)
            {
                A[0] = 0;
                Pops2_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == 3)
            {
                A[0] = 0;
                Pops3_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == 4)
            {
                A[0] = 0;
                Pops4_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == 5)
            {
                A[0] = 0;
                Pops5_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == 6)
            {
                A[0] = 0;
                Pops6_Back();
                for (int i = 0; i < 6; i++)
                {
                    if (A[i] == 1)
                        S1_right();
                    else if (A[i] == 2)
                        S2_right();
                    else if (A[i] == 3)
                        S3_right();
                    else if (A[i] == 4)
                        S4_right();
                    else if (A[i] == 5)
                        S5_right();
                    else if (A[i] == 6)
                        S6_right();
                }
                int i = 1;
                while (i < 7) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (backDeque == -1) {
                cout << "Khong the xoa!!!!!!!";
                Sleep(1500);
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
    return 0;
}
