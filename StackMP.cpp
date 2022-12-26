#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

// Tao stack

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
void Pop(STACK& s)//x chinh la gia tri can lay trong node
{
    //neu danh sach rong
    if (IsEmpty(s))
    {
        cout << "Danh sach rong";
    }
    else
    {
        NODE* p = s.pTop;              //node p la node de chung ta xoa
        s.pTop = s.pTop->pNext;      //cap nhap lai node dau cua stack
        delete p;                   //xoa node dau stack vua lay
    }

}

//xem thong tin phan tu dau stack va giu nguyen gia tri cua stack
int getTop(STACK s)//x la bien de lay gia tri can xem
{
    int x;
    if (IsEmpty(s))
        return -1;
    else
        x = s.pTop->data;//lay gia tri phan tu dau stack ra de xem
    return x;
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




//Mo phong

int clst = 0; // color stack
int clr[6] = { 16,16,16,16,16,16 }; // color rectangle
int sx1 = 0, sx2 = 0, sx3 = 0, sx4 = 0, sx5 = 0; //speed x
int sy1 = 0, sy2 = 0, sy3 = 0, sy4 = 0, sy5 = 0; //speed y
char s1[100], s2[100], s3[100], s4[100], s5[100]; // Cac gia tri cua stack


void Stack(int color)
{
    for (int i = 0; i < 3; i++)
    {
        setcolor(color);
        line(650 + i, 300, 650 + i, 800);
        line(895 + i, 800, 895 + i, 300);
        line(895, 800 + i, 650, 800 + i);
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


// Ham push s1 vao stack

void Pushs1(int vitri) {

    int n = 0;
    clr[1] = 15;
    while (n < 55) { // n <55 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 10)
        {
            Rectangle(150 + sx1, 500, 350 + sx1, 570, clr[1]);
            drawText(240 + sx1, 515, s1);
            Rectangle(400, 600, 600, 670, clr[2]);
            drawText(490, 615, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx1 += 25;
        }
        // push s1 -> up
        if (n >= 10 && n < 22)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400, 600, 600, 670, clr[2]);
            drawText(490, 615, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy1 -= 25;
        }
        // push s1 -> right
        if (n >= 22 && n < 33)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400, 600, 600, 670, clr[2]);
            drawText(490, 615, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx1 += 25;
        }
        // push s1 -> down
        if (n >= 33 && n < 33 + vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400, 600, 600, 670, clr[2]);
            drawText(490, 615, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy1 += 25;
        }
        n++;
    }
}

// Ham push s2 vao stack

void Pushs2(int vitri) {

    int n = 0;
    clr[2] = 15;
    while (n < 50) { // n <50 la gia tri xau nhat cua truong hop nay
        system("cls");
        if (n >= 0 && n < 16)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400, 600 + sy2, 600, 670 + sy2, clr[2]);
            drawText(490, 615 + sy2, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy2 -= 25;
        }
        // push s2 -> right
        if (n >= 16 && n < 27)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx2 += 25;
        }
        // push s2 -> down
        if (n >= 27 && n < 27 + vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150, 600, 350, 670, clr[3]);
            drawText(240, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy2 += 25;
        }
        n++;
    }
}

// Ham push s3 vao stack

void Pushs3(int vitri) {

    int n = 0;
    clr[3] = 15;
    while (n < 60) { // n <60 la gia tri xau nhat cua truong hop nay
        system("cls");
        // push s3 -> right
        if (n >= 0 && n < 10)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600, 350 + sx3, 670, clr[3]);
            drawText(240 + sx3, 615, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx3 += 25;
        }
        // push s3 -> up
        if (n >= 10 && n < 26)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy3 -= 25;
        }
        // push s3 -> right
        if (n >= 26 && n < 37)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx3 += 25;
        }
        // push s3 -> down
        if (n >= 37 && n < 37 + vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400, 700, 600, 770, clr[4]);
            drawText(490, 715, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy3 += 25;
        }
        n++;
    }
}


// Ham push s4 vao stack

void Pushs4(int vitri) {

    int n = 0;
    clr[4] = 15;
    while (n < 52) { // n <52 la gia tri xau nhat cua truong hop nay
        system("cls");
        // push s4 -> up
        if (n >= 0 && n < 20)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400, 700 + sy4, 600, 770 + sy4, clr[4]);
            drawText(490, 715 + sy4, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy4 -= 25;
        }
        // push s4 -> right
        if (n >= 20 && n < 31)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sx4 += 25;
        }
        // push s4 -> down
        if (n >= 31 && n < 31 + vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150, 700, 350, 770, clr[5]);
            drawText(240, 715, s5);
            Stack(clst);
            sy4 += 25;
        }
        n++;
    }
}

// Ham push s5 vao stack

void Pushs5(int vitri) {

    int n = 0;
    clr[5] = 15;
    while (n < 63) { // n <63 la gia tri xau nhat cua truong hop nay
        system("cls");
        // push s5-> right
        if (n >= 1 && n < 11)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700, 350 + sx5, 770, clr[5]);
            drawText(240 + sx5, 715, s5);
            Stack(clst);
            sx5 += 25;
        }
        // push s5 -> up
        if (n >= 11 && n < 31)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy5 -= 25;
        }
        // push s5 -> right
        if (n >= 31 && n < 42)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx5 += 25;
        }
        // push s5 -> down
        if (n >= 42 && n < 42 + vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy5 += 25;
        }
        n++;
    }
}


// Ham pop s5 ra stack
void Pops5(int vitri) {
    int n = 0;
    while (n < 66) {
        system("cls");
        // pop s5 -> up
        if (n >= 0 && n < vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy5 -= 25;
        }
        // pop s5 -> right
        if (n >= vitri && n < 30)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx5 += 25;
        }
        // pop s5 -> down
        if (n >= 30 && n < 65)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy5 += 25;
        }
        n++;
    }
}

// Ham pop s4 ra stack
void Pops4(int vitri) {
    int n = 0;
    while (n < 66) {
        system("cls");
        // pop s4 -> up
        if (n >= 0 && n < vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy4 -= 25;
        }
        // pop s4 -> right
        if (n >= vitri && n < 30)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx4 += 25;
        }
        // pop s4 -> down
        if (n >= 30 && n < 65)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy4 += 25;
        }
        n++;
    }
}

// Ham pop s3 ra stack
void Pops3(int vitri) {
    int n = 0;
    while (n < 66) {
        system("cls");
        // pop s3 -> up
        if (n >= 0 && n < vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy3 -= 25;
        }
        // pop 8 -> right
        if (n >= vitri && n < 30)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx3 += 25;
        }
        // pop s3 -> down
        if (n >= 30 && n < 65)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy3 += 25;
        }
        n++;
    }
}

// Ham pop s2 ra stack
void Pops2(int vitri) {
    int n = 0;
    while (n < 66) {
        system("cls");
        // pop s2 -> up
        if (n >= 0 && n < vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy2 -= 25;
        }
        // pop s2 -> right
        if (n >= vitri && n < 30)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx2 += 25;
        }
        // pop s2 -> down
        if (n >= 30 && n < 65)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy2 += 25;
        }
        n++;
    }
}

// Ham pop s1 ra stack
void Pops1(int vitri) {
    int n = 0;
    while (n < 66) {
        system("cls");
        // pop s1 -> up
        if (n >= 0 && n < vitri)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy1 -= 25;
        }
        // pop s1 -> right
        if (n >= vitri && n < 30)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sx1 += 25;
        }
        // pop s1 -> down
        if (n >= 30 && n < 65)
        {
            Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
            drawText(240 + sx1, 515 + sy1, s1);
            Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
            drawText(490 + sx2, 615 + sy2, s2);
            Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
            drawText(240 + sx3, 615 + sy3, s3);
            Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
            drawText(490 + sx4, 715 + sy4, s4);
            Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
            drawText(240 + sx5, 715 + sy5, s5);
            Stack(clst);
            sy1 += 25;
        }
        n++;
    }
}

int main() {
    // tao stack
    STACK s;
    initStack(s);
    //cout << "Nhap Stack:" << endl;
    //cin >> s1 >> s2 >> s3 >> s4 >> s5;
    initgraph();
    char c[] = "Press any key to view the Stack";
    outtextxy(0, 0, c);
    _getch();
    int n = 0;


    int A[5] = { 0,0,0,0,0 };  // mang danh dau xem vi tri do da co phan tu chua
    int B[5] = { 20, 16, 12, 8, 4 }; //
    system("cls");
    int chon; // lua chon menu
    int dem = 0; // bien nay dem xem bao nhieu phan tu da vao stack
    clst = 3;
    while (true)
    {
        Rectangle(150 + sx1, 500 + sy1, 350 + sx1, 570 + sy1, clr[1]);
        drawText(240 + sx1, 515 + sy1, s1);
        Rectangle(400 + sx2, 600 + sy2, 600 + sx2, 670 + sy2, clr[2]);
        drawText(490 + sx2, 615 + sy2, s2);
        Rectangle(150 + sx3, 600 + sy3, 350 + sx3, 670 + sy3, clr[3]);
        drawText(240 + sx3, 615 + sy3, s3);
        Rectangle(400 + sx4, 700 + sy4, 600 + sx4, 770 + sy4, clr[4]);
        drawText(490 + sx4, 715 + sy4, s4);
        Rectangle(150 + sx5, 700 + sy5, 350 + sx5, 770 + sy5, clr[5]);
        drawText(240 + sx5, 715 + sy5, s5);
        Stack(clst);

        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "0.Exit" << endl;
        cin >> chon;
        if (chon == 1)
        {
            if (dem == 0)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s1;
                Push(s, 1);
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i]++;
                        Pushs1(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 1)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s2;
                Push(s, 2);
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i]++;
                        Pushs2(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 2)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s3;
                Push(s, 3);
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i]++;
                        Pushs3(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 3)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s4;
                Push(s, 4);
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i]++;
                        Pushs4(B[i]);
                        break;
                    }
                }
            }
            else if (dem == 4)
            {
                dem++;
                cout << "Nhap Phan tu can them:" << endl;
                cin >> s5;
                Push(s, 5);
                for (int i = 0; i < 5; i++) {
                    if (A[i] == 0) {
                        A[i]++;
                        Pushs5(B[i]);
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
            int topStack = getTop(s);
            if (topStack == 1)
            {
                Pop(s);
                for (int i = 4; i >= 0; i--) {
                    if (A[i] == 1) {
                        A[i]--;
                        Pops1(B[i]);
                        break;
                    }
                }
            }
            else if (topStack == 2)
            {
                Pop(s);
                for (int i = 4; i >= 0; i--) {
                    if (A[i] == 1) {
                        A[i]--;
                        Pops2(B[i]);
                        break;
                    }
                }
            }
            else if (topStack == 3)
            {
                Pop(s);
                for (int i = 4; i >= 0; i--) {
                    if (A[i] == 1) {
                        A[i]--;
                        Pops3(B[i]);
                        break;
                    }
                }
            }
            else if (topStack == 4)
            {
                Pop(s);
                for (int i = 4; i >= 0; i--) {
                    if (A[i] == 1) {
                        A[i]--;
                        Pops4(B[i]);
                        break;
                    }
                }
            }
            else if (topStack == 5)
            {
                Pop(s);
                for (int i = 4; i >= 0; i--) {
                    if (A[i] == 1) {
                        A[i]--;
                        Pops5(B[i]);
                        break;
                    }
                }
            }
            else if (topStack == -1) {
                cout << "KHONG THE POP!!!\n";
            }
        }
        if (chon == 0) {
            exit(0);
        }
    }
}