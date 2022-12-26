#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

//thêm node mới vào list trống
struct Node* insertInEmpty(struct Node* last, int new_data)
{
    // kiểm tra mảng có trống không, không thì dừng 
    if (last != NULL)
        return last;

    // cấp phát bộ nhớ cho node
    struct Node* temp = new Node;

    // gán dữ liệu
    temp->data = new_data;
    last = temp;

    // tạo liên kết 
    last->next = last;

    return last;
}
//chèn nút mới vào đầu danh sách
struct Node* insertAtBegin(struct Node* last, int new_data)
{
    //nếu danh sách trống thì thêm nút bằng cách gọi insertInEmpty
    if (last == NULL)
        return insertInEmpty(last, new_data);

    // tạo một nút mới
    struct Node* temp = new Node;

    //khởi tạo dữ liệu cho node
    temp->data = new_data;
    temp->next = last->next;
    last->next = temp;

    return last;
}
//chèn node mới vào cuối danh sách
struct Node* insertAtEnd(struct Node* last, int new_data)
{
    //nếu danh sách trống thì thêm node bằng cách gọi insertInEmpty
    if (last == NULL)
        return insertInEmpty(last, new_data);

    //tạo một node mới
    struct Node* temp = new Node;

    //gán dữ liệu cho nút mới
    temp->data = new_data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

//chèn một nút mới vào giữa các nút
struct Node* insertAfter(struct Node* last, int new_data, int after_item)
{
    //trả về null nếu danh sách trống
    if (last == NULL)
        return NULL;

    struct Node* temp, * p;
    p = last->next;//node đầu
    do
    {
        if (p->data == after_item)//kiểm tra dữ liệu của các node trong danh sách có bằng node cần tìm
        {
            temp = new Node;
            temp->data = new_data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << "Nut co du lieu " << after_item << " khong co trong danh sach." << endl;
    system("pause");
    return last;

}
//duyệt danh sách liên kết 
void xuat(struct Node* last) 
{
    struct Node* p;

    // Nếu danh sách trống, return.
    if (last == NULL) {
        cout << "Danh sach lien ket vong trong." << endl;
        return;
    }
    p = last->next; // Trỏ tới Nút đầu tiên trong danh sách.

    // Duyệt qua danh sách bắt đầu từ nút đầu tiên cho đến khi nút đầu tiên được truy cập lại

    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != last->next);
    if (p == last->next)
        cout << p->data;
    cout << "\n\n";
}

//xóa nút khỏi danh sách
void deleteNode(Node** head, int key)
{
    // Nếu danh sách được liên kết trống, return
    if (*head == NULL)
        return;

    // Nếu danh sách chỉ chứa một nút, hãy xóa nút đó; Danh sách trống
    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
    }
    Node* last = *head, * d;

    // Nếu key là đầu
    if ((*head)->data == key) {
        while (last->next != *head) // Tìm nút cuối cùng của danh sách
            last = last->next;

        // Trỏ nút cuối cùng tới nút tiếp theo của đầu hoặc nút thứ hai của danh sách
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    // Đã đến cuối danh sách hoặc nút bị xóa không có trong danh sách
    while (last->next != *head && last->next->data != key) {
        last = last->next;
    }
    //Đã tìm thấy nút cần xóa, vì vậy hãy giải phóng bộ nhớ và hiển thị danh sách
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        cout << "Nut co du lieu " << key << " bi xoa khoi danh sach " << endl;
        free(d);
        cout << endl;
        cout << "Danh sach lien ket vong sau khi xoa " << key << " la nhu sau:" << endl;
        xuat(last);
    }
    else
    {
        cout << "Nut co du lieu " << key << " khong tim thay trong danh sach" << endl;
    }
}

void Menu(Node* cl)
{
    cl = NULL;
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t MENU";
        cout << "\n\n\t 1: Them node vao dau danh sach";
        cout << "\n\n\t 2: Them node vao cuoi danh sach";
        cout << "\n\n\t 3: Them node vao giua danh sach";
        cout << "\n\n\t 4: Xoa node trong danh sach";
        cout << "\n\n\t 5: Xuat danh sach lien ket don";
        cout << "\n\n\t 0: Thoat";
        cout << "\n\n\t END" << endl;

        cout << "Nhap lua chon: "; cin >> luachon;

        if (luachon == 1)
        {
            int x;
            cout << "Nhap gia tri can them vao: ";
            cin >> x;
            cl = insertAtBegin(cl, x);
        }
        else if (luachon == 2)
        {
            int x;
            cout << "Nhap gia tri can them vao: ";
            cin >> x;
            cl = insertAtEnd(cl, x);
        }
        else if (luachon == 3)
        {
            int x, y;
            cout << "Nhap gia tri can them vao: ";
            cin >> x;
            cout << "Nhap gia tri dung truoc gia tri can them: ";
            cin >> y;
            cl = insertAfter(cl, x, y);
        }
        else if (luachon == 4)
        {
            int x;
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            deleteNode(&cl, x);
            system("pause");
        }
        else if (luachon == 5)
        {
            xuat(cl);
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
    struct Node* cl = NULL;

    
    Menu(cl);
    return 0;
}