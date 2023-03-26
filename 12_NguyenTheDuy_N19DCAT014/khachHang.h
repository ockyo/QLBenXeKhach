#include <iostream>
using namespace std;

//===================danh sach khach hang=====================
typedef struct khachHang
{
    ///data
    long cmnd;
    string ho;
    string ten;
    string phai;
    //pointer
    struct khachHang *pLeft;
    struct khachHang *pRight;
} khachHang;
typedef khachHang *tree;
typedef struct danhSachKhachHang
{
    tree ds = NULL;
    // int sl = 0;
} danhSachKhachHang;

//===========khoi tao khach hang ===========
khachHang *khoiTaoKhachHang()
{
    khachHang *p = new khachHang();
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

//==========them 1 khach hang  =============
void themKhachHang(tree &t, khachHang *p)
{
    if (t == NULL)
    {
        t = p;
        return;
    }
    else
    {
        if (p->cmnd > t->cmnd)
        {
            themKhachHang(t->pRight, p);
        }
        else if (p->cmnd < t->cmnd)
        {
            themKhachHang(t->pLeft, p);
        }
    }
}
//=============nhap khach hang ===============
bool kiemTraKHTrung(tree t, long cmnd);
void nhapHanhKhach(danhSachKhachHang &ds,long cmnd)
{
    khachHang *p = khoiTaoKhachHang();

    // cout << "Nhap cmnd : ";
    // cin >> p->cmnd;
    p->cmnd=cmnd;

    cout << "Nhap ho : ";
    cin.ignore();
    getline(cin, p->ho);

    cout << "Nhap ten : ";
    // cin.ignore();
    getline(cin, p->ten);

    cout << "Nhap phai : ";
    // cin.ignore();
    getline(cin, p->phai);
    themKhachHang(ds.ds, p);
}

//===================kiem tra trung cmnd==============
bool kiemTraKHTrung(tree t, long cmnd)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->cmnd == cmnd)
        {
            return 1;
        }
        else if (t->cmnd > cmnd)
        {
            kiemTraKHTrung(t->pLeft, cmnd);
        }
        else if (t->cmnd < cmnd)
        {
            kiemTraKHTrung(t->pRight, cmnd);
        }
    }
}

void xuatHanhKhach(tree t, long cmnd)
{
    if (t == NULL)
    {
        cout << "trong";
        return;
    }
    else
    {
        if (t->cmnd == cmnd)
        {
            cout << setw(10) << left << t->cmnd;
            cout << setw(10) << left << t->ho;
            cout << setw(10) << left << t->ten;
            cout << setw(4) << left << t->phai;
            return;
        }
        else if (t->cmnd > cmnd)
        {
            xuatHanhKhach(t->pLeft, cmnd);
        }
        else if (t->cmnd < cmnd)
        {
            xuatHanhKhach(t->pRight, cmnd);
        }
    }
    return;
}
