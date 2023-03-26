#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//================ danh sach xe===================
typedef struct xe
{
    //data
    string soXe;
    string hangSanXuat;
    string model;
    int soCho;
    int luotThucHien = 0;
    //pointer
    struct xe *pNext;
} xe;
typedef struct danhSachXe
{
    xe *pHead = NULL;
    xe *pTail = NULL;
} danhSachXe;
// struct ghe
// {
//     string model;
//     int soLuongVeDaDat=0;
// };
//================khoi tao xe ====================
xe *khoiTaoXe()
{
    xe *p = new xe();
    p->pNext = NULL;
    return p;
}

//===================them xe vao danh sach ==============
void themXe(danhSachXe &l, xe *x)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = x;
    }
    else
    {
        l.pTail->pNext = x;
        l.pTail = x;
    }
}
//=================nhap xe ===============================
bool kiemTraXeTrung(danhSachXe &l, string soXe);
void nhapXe(danhSachXe &l)
{
    bool check;
    xe *x = khoiTaoXe();
    cout << "\nNhap vao so xe : ";
    cin.ignore();
    getline(cin, x->soXe);

    if (kiemTraXeTrung(l, x->soXe))
    {
        system("cls");
        cout << "Xe da co trong danh sach.";
        return;
    }

    cout << "Nhap vao hang san xuat xe : ";
    // cin.ignore();
    getline(cin, x->hangSanXuat);

    cout << "Nhap vao model : ";
    // cin.ignore();
    getline(cin, x->model);
    cout << "Nhap vao so cho : ";
    do
    {
        cin >> x->soCho;
        check = cin.fail();
        cin.clear();
        
        if (check == true)
        {
            cout << "Nhap sai! Nhap lai so cho : ";
            cin.ignore(200,'\n');
        }
    } while (check == true);
    themXe(l, x);
    system("cls");
    cout<<"Them xe thanh cong.";
}

void xuatXe(danhSachXe &l)
{
    cout << "\nDanh sach cac xe hien co :";
    cout << endl;
    if (l.pHead == NULL)
    {
        cout << "Danh sach rong.";
    }
    else
    {
        cout << setw(15) << left << "So xe";
        cout << setw(15) << left << "Hang san xuat";
        cout << setw(15) << left << "Model";
        cout << setw(6) << right << "So cho" << endl;
        cout << setfill('-');            // set fill bằng ký tự '-' thay vì ' '
        cout << setw(51) << "-" << endl; // fill 80 ký tự '-'

        // reset fill bằng ký tự ' '
        cout << setfill(' ');

        for (xe *p = l.pHead; p != NULL; p = p->pNext)
        {
            cout << setw(15) << left << p->soXe;
            cout << setw(15) << left << p->hangSanXuat;
            cout << setw(15) << left << p->model;
            cout << setw(6) << right << p->soCho << endl;
        }
    }
}

//===================hàm xóa xe=================================
// hàm xóa đầu
void XoaDau(danhSachXe &l)
{
    // nếu danh sách rỗng
    if (l.pHead == NULL)
    {
        return;
    }
    xe *p = l.pHead;          // node p là node sẽ xóa
    l.pHead = l.pHead->pNext; // cập nhật lại l.pHead là phần tử kế tiếp
    delete p;
}

// xóa cuối
void XoaCuoi(danhSachXe &l)
{

    // nếu danh sách rỗng
    if (l.pHead == NULL)
    {
        return;
    }
    // trường hợp danh sách có phần tử
    if (l.pHead->pNext == NULL)
    {
        XoaDau(l);
        return;
    }
    // duyệt từ đầu danh sách đến thằng kế cuối
    for (xe *k = l.pHead; k != NULL; k = k->pNext)
    {
        // phát hiện thằng kế cuối
        if (k->pNext == l.pTail)
        {
            delete l.pTail;  // xóa đi phần tử cuối
            k->pNext = NULL; // cho con trỏ của node kế cuối trỏ đến vùng nhớ null
            l.pTail = k;     // cập nhật lại l.pTail
            return;
        }
    }
}

void xoaXe(danhSachXe &l, string soXe)
{
    // nếu danh sách rỗng thì không làm gì hết
    if (l.pHead == NULL)
    {
        cout << "\nDanh sach trong";
        return;
    }
    // nếu node cần xóa nằm đầu danh sách
    if (l.pHead->soXe == soXe)
    {
        XoaDau(l);
        cout << "\nDa xoa xe khoi danh sach.";
        return;
    }
    // nếu node cần xóa nằm ở cuối danh sách
    if (l.pTail->soXe == soXe)
    {
        XoaCuoi(l);
        cout << "\nDa xoa xe khoi danh sach.";
        return;
    }

    xe *g = new xe();
    for (xe *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->soXe == soXe)
        {
            g->pNext = k->pNext;
            delete k;
            cout << "\nDa xoa xe khoi danh sach.";
            return;
        }
        g = k;
    }
    {
        system("cls");
        cout << "\nXe can xoa khong nam trong danh sach";
    }
}

//===========Hieu chinh xe =======================
void hieuChinhXe(danhSachXe &l, string soXe)
{
    if (l.pHead == NULL)
    {
        system("cls");
        cout << "\nDanh sach trong";
        return;
    }
    else
    {
        for (xe *k = l.pHead; k != NULL; k = k->pNext)
        {
            if (k->soXe == soXe)
            {
                cout << "\nNhap lai so xe : ";
                getline(cin, k->soXe);
                cout << "Nhap lai hang san xuat : ";
                getline(cin, k->hangSanXuat);
                cout << "Nhap lai so model : ";
                getline(cin, k->model);
                cout << "Nhap lai so cho : ";
                cin >> k->soCho;
                system("cls");
                cout << "Xe da duoc hieu chinh thanh cong.";
                return;
            }
        }

        {
            system("cls");
            cout << "\nKhong tim thay xe.";
            return;
        }
    }
}

//===================Kiểm tra trùng===============
bool kiemTraXeTrung(danhSachXe &l, string soXe)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    else
    {
        for (xe *x = l.pHead; x != NULL; x = x->pNext)
        {
            if (x->soXe == soXe)
            {
                return 1;
            }
        }
    }
    return 0;
}
void luotThucHien(danhSachXe l)
{
    if (l.pHead == NULL)
    {
        system("cls");
        cout<<"\nDanh sach xe trong.";
        return;
    }
    else
    {
        for (xe *x = l.pHead; x != NULL; x = x->pNext)
        {
            for (xe *x2 = x->pNext; x2 != NULL; x2 = x2->pNext)
            {
                if (x->luotThucHien < x2->luotThucHien)
                {
                    int temp1 = x->luotThucHien;
                    string temp2 = x->soXe;
                    string hangSanXuat = x->hangSanXuat;
                    string model = x->model;
                    int soCho = x->soCho;

                    x->luotThucHien = x2->luotThucHien;
                    x->soXe = x2->soXe;
                    x->hangSanXuat = x2->hangSanXuat;
                    x->model = x2->model;
                    x->soCho = x2->soCho;

                    x2->luotThucHien = temp1;
                    x2->soXe = temp2;
                    x2->hangSanXuat = hangSanXuat;
                    x2->model = model;
                    x2->soCho = soCho;
                }
            }
        }
    }
    system("cls");
    cout << "Ket xuat so luot thuc hien chuyen xe : \n";
    cout << setw(15) << left << "So xe";
    cout << setw(7) << right << "So luot\n";
    cout << setfill('-');
    cout << setw(22) << "-" << endl;
    cout << setfill(' ');
    for (xe *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << setw(15) << left << p->soXe;
        cout << setw(6) << right << p->luotThucHien << endl;
    }

    return;
}

int getSoCho(danhSachXe l, string soXe)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    else
    {
        for (xe *x = l.pHead; x != NULL; x = x->pNext)
        {
            if (x->soXe == soXe)
            {

                return x->soCho;
            }
        }
    }
    return 0;
}
bool themLuotThucHien(danhSachXe &l, string soXe)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    else
    {
        for (xe *x = l.pHead; x != NULL; x = x->pNext)
        {
            if (x->soXe == soXe)
            {
                x->luotThucHien++;
                return 1;
            }
        }
    }
    return 0;
}
bool giamLuotThucHien(danhSachXe &l, string soXe)
{
    if (l.pHead == NULL)
    {
        return 0;
    }
    else
    {
        for (xe *x = l.pHead; x != NULL; x = x->pNext)
        {
            if (x->soXe == soXe)
            {
                x->luotThucHien--;
                return 1;
            }
        }
    }
    return 0;
}