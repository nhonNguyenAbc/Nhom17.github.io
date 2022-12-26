#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>



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
void Dequeue(QUEUE& q)//x chinh la gia tri can lay trong node
{
    //neu danh sach rong
    NODE* p = q.pHead;              //node p la node de chung ta xoa
    q.pHead = q.pHead->pNext;      //cap nhap lai node dau cua queue
    delete p;                   //xoa node dau queue vua lay
}

//xem thong tin phan tu dau queue va giu nguyen gia tri cua queue
int Top(QUEUE& q)//x la bien de lay gia tri can xem
{
    if (IsEmpty(q))
        return -1;
    int x = q.pHead->data;//lay gia tri phan tu dau queue ra de xem
    return x;
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





// mo phong

int clst = 0; // color stack
int clr[6] = { 16,16,16,16,16,16 }; // color rectangle
int sx1 = 0, sx2 = 0, sx3 = 0, sx4 = 0, sx5 = 0; //speed x
int sy1 = 0, sy2 = 0, sy3 = 0, sy4 = 0, sy5 = 0; //speed y
char s1[100], s2[100], s3[100], s4[100], s5[100]; // Cac gia tri cua Queue

void Queue(int color)
{
    drawText(1230, 320, "FRONT");
    drawText(680, 320, "BACK");
    for (int i = 0; i < 1; i++)
    {
        setcolor(color);
        line(680, 350 + i, 1290, 350 + i);
        line(680, 550 + i, 1290, 550 + i);
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

// push s1 vao queue
void pushs1(int vitri) {
    clr[1] = 15;
    int n = 0;
    while (n < 21) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 21)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx1 += 30;
        }
        n++;
    }
}

// push s2 vao queue
void pushs2(int vitri) {
    int n = 0;
    clr[2] = 15;
    while (n < 25) {
        system("cls");
        if (n >= 0 && n < 4 + vitri)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx2 += 30;
        }
        n++;
    }
}

// push s3 vao queue
void pushs3(int vitri) {
    int n = 0;
    clr[3] = 15;
    while (n < 29) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 8 + vitri)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx3 += 30;
        }
        n++;
    }
}

// push s4 vao queue
void pushs4(int vitri) {
    int n = 0;
    clr[4] = 15;
    while (n < 33) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 12 + vitri)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx4 += 30;
        }
        n++;
    }
}

// push s5 vao queue
void pushs5(int vitri) {
    int n = 0;
    clr[5] = 15;
    while (n < 37) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 16 + vitri)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx5 += 30;
        }
        n++;
    }
}

// pop s1 ra queue
void pops1() {
    int n = 0;
    while (n < 46) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        // pop s1-> right
        if (n >= 0 && n < 20)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx1 += 30;
        }
        // pop s1-> down
        if (n >= 20 && n < 45)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sy1 += 30;
        }
        n++;
    }
}

// pop s2 ra queue
void pops2() {
    int n = 0;
    while (n < 46) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        // pop s2-> right
        if (n >= 0 && n < 20)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx2 += 30;
        }
        // pop s2-> down
        if (n >= 20 && n < 45)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sy2 += 30;
        }
        n++;
    }
}

// pop s3 ra queue
void pops3() {
    int n = 0;
    while (n < 46) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        // pop s3-> right
        if (n >= 0 && n < 20)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx3 += 30;
        }
        // pop s3-> down
        if (n >= 20 && n < 45)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sy3 += 30;
        }
        n++;
    }
}

// pop s4 ra queue
void pops4() {
    int n = 0;
    while (n < 46) { // n <22 la gia tri xau nhat cua truong hop nay
        system("cls");
        // pop s4-> right
        if (n >= 0 && n < 20)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx4 += 30;
        }
        // pop s4-> down
        if (n >= 20 && n < 45)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sy4 += 30;
        }
        n++;
    }
}

// pop s5 ra queue
void pops5() {
    int n = 0;
    while (n < 46) {
        system("cls");
        // pop s5-> right
        if (n >= 0 && n < 20)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx5 += 30;
        }
        // pop s5-> down
        if (n >= 20 && n < 45)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sy5 += 30;
        }
        n++;
    }
}


void diChuyenTops1() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // pop s1-> right
        if (n >= 0 && n < 4)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx1 += 30;
        }
        n++;
    }
}

void diChuyenTops2() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // pop s2-> right
        if (n >= 0 && n < 4)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx2 += 30;
        }
        n++;
    }
}

void diChuyenTops3() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // pop s3-> right
        if (n >= 0 && n < 4)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx3 += 30;
        }
        n++;
    }
}

void diChuyenTops4() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // pop s4-> right
        if (n >= 0 && n < 4)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx4 += 30;
        }
        n++;
    }
}

void diChuyenTops5() {
    int n = 0;
    while (n < 4) {
        system("cls");
        // pop s5-> right
        if (n >= 0 && n < 4)
        {
            Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
            drawText(98 + sx5, 440 + sy5, s5);
            Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
            drawText(224 + sx4, 440 + sy4, s4);
            Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
            drawText(346 + sx3, 440 + sy3, s3);
            Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
            drawText(468 + sx2, 440 + sy2, s2);
            Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
            drawText(590 + sx1, 440 + sy1, s1);
            Queue(clst);
            sx5 += 30;
        }
        n++;
    }
}

int main()
{
    QUEUE q;
    khoiTaoQueue(q);
    initgraph();
    char c[] = "Press any key to view the Queue";
    outtextxy(0, 0, c);
    _getch();// du man hinh do hoa

    int A[6] = { 0,0,0,0,0,0 }; // mang danh dau xem cho do co phan tu nao chua
    int B[5] = { 21, 17, 13, 9, 5 }; // mang vi tri cua queue
    system("cls");
    int chon; // lua chon menu
    int dem = 0; // bien nay dem xem bao nhieu phan tu da vao stack
    clst = 3;
    while (true)
    {
        system("cls");
        Rectangle(52 + sx5, 360 + sy5, 172 + sx5, 540 + sy5, clr[5]);
        drawText(98 + sx5, 440 + sy5, s5);
        Rectangle(174 + sx4, 360 + sy4, 294 + sx4, 540 + sy4, clr[4]);
        drawText(224 + sx4, 440 + sy4, s4);
        Rectangle(296 + sx3, 360 + sy3, 416 + sx3, 540 + sy3, clr[3]);
        drawText(346 + sx3, 440 + sy3, s3);
        Rectangle(418 + sx2, 360 + sy2, 538 + sx2, 540 + sy2, clr[2]);
        drawText(468 + sx2, 440 + sy2, s2);
        Rectangle(540 + sx1, 360 + sy1, 660 + sx1, 540 + sy1, clr[1]);
        drawText(590 + sx1, 440 + sy1, s1);
        Queue(clst);

        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "0.Exit" << endl;
        cin >> chon;
        if (chon == 1)
        {

            if (dem == 0)
            {
                cout << "Nhap gia tri can them:";
                cin >> s1;
                dem++;
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        pushs1(B[i]);
                        NODE* p = khoiTaoNode(1);
                        Enqueue(q, p);
                        break;
                    }
                }
            }
            else if (dem == 1)
            {
                cout << "Nhap gia tri can them:";
                cin >> s2;
                dem++;
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        pushs2(B[i]);
                        NODE* p = khoiTaoNode(2);
                        Enqueue(q, p);
                        break;
                    }
                }
            }
            else if (dem == 2)
            {
                cout << "Nhap gia tri can them:";
                cin >> s3;
                dem++;
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        pushs3(B[i]);
                        NODE* p = khoiTaoNode(3);
                        Enqueue(q, p);
                        break;
                    }
                }
            }
            else if (dem == 3)
            {
                cout << "Nhap gia tri can them:";
                cin >> s4;
                dem++;
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        pushs4(B[i]);
                        NODE* p = khoiTaoNode(4);
                        Enqueue(q, p);
                        break;
                    }
                }
            }
            else if (dem == 4)
            {
                cout << "Nhap gia tri can them:";
                cin >> s5;
                dem++;
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i] = dem;
                        pushs5(B[i]);
                        NODE* p = khoiTaoNode(5);
                        Enqueue(q, p);
                        break;
                    }
                }
            }
            else
            {
                cout << "Khong the PUSH!!!!!!!" << endl;
                Sleep(1500);

            }
        }
        if (chon == 2) {
            int topQueue = Top(q);
            if (topQueue == 1)
            {
                Dequeue(q);
                A[0] = 0;
                pops1();
                for (int i = 0; i < 5; i++)
                {
                    if (A[i] == 1)
                        diChuyenTops1();
                    else if (A[i] == 2)
                        diChuyenTops2();
                    else if (A[i] == 3)
                        diChuyenTops3();
                    else if (A[i] == 4)
                        diChuyenTops4();
                    else if (A[i] == 5)
                        diChuyenTops5();
                }
                int i = 1;
                while (i < 6) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (topQueue == 2)
            {
                Dequeue(q);
                A[0] = 0;
                pops2();
                for (int i = 0; i < 5; i++)
                {
                    if (A[i] == 1)
                        diChuyenTops1();
                    else if (A[i] == 2)
                        diChuyenTops2();
                    else if (A[i] == 3)
                        diChuyenTops3();
                    else if (A[i] == 4)
                        diChuyenTops4();
                    else if (A[i] == 5)
                        diChuyenTops5();
                }
                int i = 1;
                while (i < 6) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (topQueue == 3)
            {
                Dequeue(q);
                A[0] = 0;
                pops3();
                for (int i = 0; i < 5; i++)
                {
                    if (A[i] == 1)
                        diChuyenTops1();
                    else if (A[i] == 2)
                        diChuyenTops2();
                    else if (A[i] == 3)
                        diChuyenTops3();
                    else if (A[i] == 4)
                        diChuyenTops4();
                    else if (A[i] == 5)
                        diChuyenTops5();
                }
                int i = 1;
                while (i < 6) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (topQueue == 4)
            {
                Dequeue(q);
                A[0] = 0;
                pops4();
                for (int i = 0; i < 5; i++)
                {
                    if (A[i] == 1)
                        diChuyenTops1();
                    else if (A[i] == 2)
                        diChuyenTops2();
                    else if (A[i] == 3)
                        diChuyenTops3();
                    else if (A[i] == 4)
                        diChuyenTops4();
                    else if (A[i] == 5)
                        diChuyenTops5();
                }
                int i = 1;
                while (i < 6) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (topQueue == 5)
            {
                Dequeue(q);
                A[0] = 0;
                pops5();
                for (int i = 0; i < 5; i++)
                {
                    if (A[i] == 1)
                        diChuyenTops1();
                    else if (A[i] == 2)
                        diChuyenTops2();
                    else if (A[i] == 3)
                        diChuyenTops3();
                    else if (A[i] == 4)
                        diChuyenTops4();
                    else if (A[i] == 5)
                        diChuyenTops5();
                }
                int i = 1;
                while (i < 6) {
                    A[i - 1] = A[i];
                    i++;
                }
            }
            else if (topQueue == -1) {
                cout << "KHONG THE POP!!!";
                Sleep(1500);
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
    return 0;
}