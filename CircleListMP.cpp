#include"graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>


int _time = 0;// thoi gian them, xoa 1 phan tu
int sy = 0;// toc do di chuyen phan tu tren Oy
int sx = 0;// toc do di chuyen phan tu tren Ox
int hide = 0;

void Rectangle(int x1, int y1, int x2, int y2, int color)
{
	setcolor(color);
	line(x1, y1, x1, y2 - 35);
	line(x1, y1, x2, y1);
	line(x2, y2, x2, y1);
}

void Node(int x1, int y1, int x2, int y2)
{

	line(x1, y1, x1, y2);
	line(x1, y1, x2, y1);
	line(x2, y2, x2, y1);
	line(x2, y2, x1, y2);
	line((x1 + x2) / 2, y1, (x1 + x2) / 2, y2);
}

void lastPointer(int n, int clr)
{
	Rectangle(400 * hide, 400 * hide, 300 * hide + 300 * n, 535 * hide, clr);
	line(390 * hide, 480 * hide, 400 * hide, 500 * hide);
	line(410 * hide, 480 * hide, 400 * hide, 500 * hide);
}

void printNode(int n)
{
	rectangle(300, 300, 400, 370);
	drawText(320, 320, "Head");
	line(350, 370, 350, 500);
	line(340, 460, 350, 500);
	line(360, 460, 350, 500);

	drawText(35 + 300 * n, 520, "data");
	drawText(125 + 300 * n, 520, "index");

	Node(300 * n, 500, 200 + 300 * n, 570);
	line(200 + 300 * n, 535, 300 + 300 * n, 535);
	line(290 + 300 * n, 525, 300 + 300 * n, 535);
	line(290 + 300 * n, 545, 300 + 300 * n, 535);

}


void insertNode(int n, int a[], int b[], int c[], int d[])
{
	while (_time < 15)
	{
		system("cls");


		Node(300 * a[1] + b[1] * sx, 500 * c[1], 200 * c[1] + 300 * a[1] + b[1] * sx, 570 * c[1]);
		line(200 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);
		line(290 * c[1] + 300 * a[1] + b[1] * sx, 525 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);
		line(290 * c[1] + 300 * a[1] + b[1] * sx, 545 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);

		drawText(35 + 300 * a[1] + b[1] * sx, 520 * d[1], "data");
		drawText(125 + 300 * a[1] + b[1] * sx, 520 * d[1], "index");

		Node(300 * a[2] + b[2] * sx, 500 * c[2], 200 * c[2] + 300 * a[2] + b[2] * sx, 570 * c[2]);
		line(200 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);
		line(290 * c[2] + 300 * a[2] + b[2] * sx, 525 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);
		line(290 * c[2] + 300 * a[2] + b[2] * sx, 545 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);

		drawText(35 + 300 * a[2] + b[2] * sx, 520 * d[2], "data");
		drawText(125 + 300 * a[2] + b[2] * sx, 520 * d[2], "index");

		Node(300 * a[3] + b[3] * sx, 500 * c[3], 200 * c[3] + 300 * a[3] + b[3] * sx, 570 * c[3]);
		line(200 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);
		line(290 * c[3] + 300 * a[3] + b[3] * sx, 525 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);
		line(290 * c[3] + 300 * a[3] + b[3] * sx, 545 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);

		drawText(35 + 300 * a[3] + b[3] * sx, 520 * d[3], "data");
		drawText(125 + 300 * a[3] + b[3] * sx, 520 * d[3], "index");

		Node(300 * a[4] + b[4] * sx, 500 * c[4], 200 * c[4] + 300 * a[4] + b[4] * sx, 570 * c[4]);
		line(200 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);
		line(290 * c[4] + 300 * a[4] + b[4] * sx, 525 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);
		line(290 * c[4] + 300 * a[4] + b[4] * sx, 545 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);

		drawText(35 + 300 * a[4] + b[4] * sx, 520 * d[4], "data");
		drawText(125 + 300 * a[4] + b[4] * sx, 520 * d[4], "index");

		Node(300 * a[5] + b[5] * sx, 500 * c[5], 200 * c[5] + 300 * a[5] + b[5] * sx, 570 * c[5]);
		line(200 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);
		line(290 * c[5] + 300 * a[5] + b[5] * sx, 525 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);
		line(290 * c[5] + 300 * a[5] + b[5] * sx, 545 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);

		drawText(35 + 300 * a[5] + b[5] * sx, 520 * d[5], "data");
		drawText(125 + 300 * a[5] + b[5] * sx, 520 * d[5], "index");

		Node(300 * a[6] + b[6] * sx, 500 * c[5], 200 * c[6] + 300 * a[6] + b[6] * sx, 570 * c[6]);
		line(200 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);
		line(290 * c[6] + 300 * a[6] + b[6] * sx, 525 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);
		line(290 * c[6] + 300 * a[6] + b[6] * sx, 545 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);

		drawText(35 + 300 * a[6] + b[6] * sx, 520 * d[6], "data");
		drawText(125 + 300 * a[6] + b[6] * sx, 520 * d[6], "index");

		Node(300 * n, 650 + sy, 200 + 300 * n, 720 + sy);
		line(200 + 300 * n, 685 + sy, 300 + 300 * n, 685 + sy);
		line(290 + 300 * n, 675 + sy, 300 + 300 * n, 685 + sy);
		line(290 + 300 * n, 695 + sy, 300 + 300 * n, 685 + sy);

		drawText(35 + 300 * n, 670 + sy, "data");
		drawText(125 + 300 * n, 670 + sy, "index");

		sy -= 10;
		sx += 20;
		_time++;
	}
}
void deleteNode(int n, int a[], int b[], int c[], int d[])
{
	while (_time < 15)
	{
		system("cls");


		Node(300 * a[1] + b[1] * sx, 500 * c[1], 200 * c[1] + 300 * a[1] + b[1] * sx, 570 * c[1]);
		line(200 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);
		line(290 * c[1] + 300 * a[1] + b[1] * sx, 525 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);
		line(290 * c[1] + 300 * a[1] + b[1] * sx, 545 * c[1], 300 * c[1] + 300 * a[1] + b[1] * sx, 535 * c[1]);

		drawText(35 + 300 * a[1] + b[1] * sx, 520 * d[1], "data");
		drawText(125 + 300 * a[1] + b[1] * sx, 520 * d[1], "index");

		Node(300 * a[2] + b[2] * sx, 500 * c[2], 200 * c[2] + 300 * a[2] + b[2] * sx, 570 * c[2]);
		line(200 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);
		line(290 * c[2] + 300 * a[2] + b[2] * sx, 525 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);
		line(290 * c[2] + 300 * a[2] + b[2] * sx, 545 * c[2], 300 * c[2] + 300 * a[2] + b[2] * sx, 535 * c[2]);

		drawText(35 + 300 * a[2] + b[2] * sx, 520 * d[2], "data");
		drawText(125 + 300 * a[2] + b[2] * sx, 520 * d[2], "index");

		Node(300 * a[3] + b[3] * sx, 500 * c[3], 200 * c[3] + 300 * a[3] + b[3] * sx, 570 * c[3]);
		line(200 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);
		line(290 * c[3] + 300 * a[3] + b[3] * sx, 525 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);
		line(290 * c[3] + 300 * a[3] + b[3] * sx, 545 * c[3], 300 * c[3] + 300 * a[3] + b[3] * sx, 535 * c[3]);

		drawText(35 + 300 * a[3] + b[3] * sx, 520 * d[3], "data");
		drawText(125 + 300 * a[3] + b[3] * sx, 520 * d[3], "index");

		Node(300 * a[4] + b[4] * sx, 500 * c[4], 200 * c[4] + 300 * a[4] + b[4] * sx, 570 * c[4]);
		line(200 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);
		line(290 * c[4] + 300 * a[4] + b[4] * sx, 525 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);
		line(290 * c[4] + 300 * a[4] + b[4] * sx, 545 * c[4], 300 * c[4] + 300 * a[4] + b[4] * sx, 535 * c[4]);

		drawText(35 + 300 * a[4] + b[4] * sx, 520 * d[4], "data");
		drawText(125 + 300 * a[4] + b[4] * sx, 520 * d[4], "index");

		Node(300 * a[5] + b[5] * sx, 500 * c[5], 200 * c[5] + 300 * a[5] + b[5] * sx, 570 * c[5]);
		line(200 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);
		line(290 * c[5] + 300 * a[5] + b[5] * sx, 525 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);
		line(290 * c[5] + 300 * a[5] + b[5] * sx, 545 * c[5], 300 * c[5] + 300 * a[5] + b[5] * sx, 535 * c[5]);

		drawText(35 + 300 * a[5] + b[5] * sx, 520 * d[5], "data");
		drawText(125 + 300 * a[5] + b[5] * sx, 520 * d[5], "index");

		Node(300 * a[6] + b[6] * sx, 500 * c[5], 200 * c[6] + 300 * a[6] + b[6] * sx, 570 * c[6]);
		line(200 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);
		line(290 * c[6] + 300 * a[6] + b[6] * sx, 525 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);
		line(290 * c[6] + 300 * a[6] + b[6] * sx, 545 * c[6], 300 * c[6] + 300 * a[6] + b[6] * sx, 535 * c[6]);

		drawText(35 + 300 * a[6] + b[6] * sx, 520 * d[6], "data");
		drawText(125 + 300 * a[6] + b[6] * sx, 520 * d[6], "index");

		Node(300 * n, 650 + sy, 200 + 300 * n, 720 + sy);
		line(200 + 300 * n, 685 + sy, 300 + 300 * n, 685 + sy);
		line(290 + 300 * n, 675 + sy, 300 + 300 * n, 685 + sy);
		line(290 + 300 * n, 695 + sy, 300 + 300 * n, 685 + sy);

		drawText(35 + 300 * n, 670 + sy, "data");
		drawText(125 + 300 * n, 670 + sy, "index");

		sy += 10;
		sx -= 20;
		_time++;
	}
}

int main()
{

	initgraph();
	char c[] = "Press any key";
	outtextxy(0, 0, c);
	_getch();
	int h = 1;
	int n = 0;
	int k = 1;
	int p = 1;
	int dem = 0;
	int clr = 5;

	int A[20] = { 0 };
	int C[20] = { 0 };
	int D[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int luachon;
	while (true)
	{
		int B[20] = { 0 };//move
		system("cls");
		if (n != 0)
			hide = 1;
		else hide = 0;
		for (int i = 1; i <= n; i++)
		{
			printNode(i);
		}
		lastPointer(n, clr);

		cout << "\n\n\t 1: Them node vao danh sach";
		cout << "\n\n\t 2: Xoa node trong danh sach";
		cout << endl;
		cin >> luachon;

		if (luachon == 1)
		{

			dem++;

			int vitri;
			cout << "\nNhap vi tri can them: ";
			cin >> vitri;

			for (int j = 1; j <= dem; j++)
			{
				if (A[j] == vitri)
				{

					for (int l = vitri; l <= dem; l++)
					{
						B[l] = 1;
					}

					insertNode(vitri, A, B, C, D);
					_time = 0;
					sy = 0;
					sx = 0;
					break;
				}
			}
			C[k++] = 1;
			D[p++] = 1;
			A[h++] = dem;
			n++;
		}
		if (luachon == 2)
		{
			int vitri;
			cout << "\nNhap vi tri can xoa: ";
			cin >> vitri;
			C[vitri] = 0;
			D[vitri] = -1;
			for (int l = vitri + 1; l <= dem; l++)
			{
				B[l] = 1;
			}

			deleteNode(vitri, A, B, C, D);
			_time = 0;
			sy = 0;
			sx = 0;

			for (int l = vitri; l <= n; l++)
			{
				C[l] = C[l + 1];
			}
			for (int q = vitri; q <= n; q++)
			{
				D[q] = D[q + 1];
			}
			A[h] = 0;
			h--;
			k--;
			n--;
			p--;
			dem--;
		}
	}
	system("pause");
	return 0;
}