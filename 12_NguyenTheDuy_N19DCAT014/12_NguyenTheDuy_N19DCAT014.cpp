// #pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "xe.h"
#include "khachHang.h"
#define MAXLIST 100
using namespace std;

typedef struct veXe veXe;
typedef struct danhSachVeXe danhSachVeXe;

struct veXe
{
    string maChuyen;
    long cmnd = 0;
    int stt; //so ghe
};
struct danhSachVeXe
{
    int soLuongVe;            //so luong ve cua chuyen xe
    int soVe = 0;             //so ve da dat cua chuyen xe
    veXe danhsachve[MAXLIST];
};

danhSachXe xs;

//=====================chuyen xe ===========================
typedef struct chuyenXe
{
    string maChuyen;
    string noiDen;
    string soXe;
    string dayTime;
    int trangThai;
    // 0 la huy chuyen ; 1 la con ve ; 2 la het ve ; 3 la hoan tat;
    danhSachVeXe danhSachVe;
} chuyenXe;

typedef struct danhSachChuyenXe
{
    chuyenXe duLieuChuyenXe;
    int slChuyenXe;         //so node cua danh sach chuyen xe
    chuyenXe node[MAXLIST];
} danhSachChuyenXe;

void khoiTaoChuyenXe(danhSachChuyenXe &ds)
{
    ds.slChuyenXe = 0;
}

void themChuyenXe(danhSachChuyenXe &ds, danhSachXe vs)
{
    int soChuyenXe = 1;
    xe x;
    cin.ignore();
    for (int i = ds.slChuyenXe; i < ds.slChuyenXe + soChuyenXe; i++)
    {
        cout << "Chuyen : " << i + 1;
        cout << "\nNhap vao so xe : ";
        getline(cin, ds.duLieuChuyenXe.soXe);

        if (kiemTraXeTrung(vs, ds.duLieuChuyenXe.soXe) == 0)
        {
            system("cls");
            cout << "\nXe khong ton tai.(Neu muon lap chuyen voi so xe tren vui long them xe vao danh sach.";
            return;
        }
        else
        {
            ds.node[i].soXe = ds.duLieuChuyenXe.soXe;
            cout << "Nhap vao ma chuyen xe : ";
            getline(cin, ds.duLieuChuyenXe.maChuyen);
            for (int j = 0; j <= ds.slChuyenXe; j++)
            {
                if (ds.node[j].maChuyen == ds.duLieuChuyenXe.maChuyen)
                {
                    system("cls");
                    cout << "Trung ma chuyen xe.";
                    return;
                }
            }
            ds.node[i].maChuyen = ds.duLieuChuyenXe.maChuyen;
            cout << "Nhap ngay khoi hanh : ";
            getline(cin, ds.duLieuChuyenXe.dayTime);
            ds.node[i].dayTime = ds.duLieuChuyenXe.dayTime;
            cout << "Nhap noi den : ";
            getline(cin, ds.duLieuChuyenXe.noiDen);
            ds.node[i].noiDen = ds.duLieuChuyenXe.noiDen;
            ds.node[i].trangThai = 1;
            // ds.node[i].soCho = getSoCho(vs, ds.node[i].soXe);
            ds.node[i].danhSachVe.soLuongVe = getSoCho(vs, ds.node[i].soXe);
            themLuotThucHien(vs, ds.duLieuChuyenXe.soXe);
        }
    }
    ds.slChuyenXe += soChuyenXe;
    system("cls");
}
int timViTriChuyenXe(danhSachChuyenXe ds, string maChuyen)
{
    for (int i = 0; i < ds.slChuyenXe; i++)
    {
        if (maChuyen == ds.node[i].maChuyen)
        {
            return i;
        }
    }
    return -1;
}
void xoaChuyenXe(danhSachChuyenXe &ds)
{
    string maChuyen;
    cout << "\nNhap vao ma chuyen xe : ";
    cin.ignore();
    getline(cin, maChuyen);
    int vt = timViTriChuyenXe(ds, maChuyen);
    if (ds.slChuyenXe == 0)
    {
        system("cls");
        cout << "Danh sach chuyen xe hien dang rong.";
        return;
    }
    if (vt == -1)
    {
        system("cls");
        cout << "\nKhong tim thay chuyen xe.";
    }
    else
    {
        for (int i = 0; i < ds.slChuyenXe - 1; i++)
        {
            ds.node[i].maChuyen = ds.node[i + 1].maChuyen;
        }
        ds.slChuyenXe--;
        system("cls");
        cout << "Da xoa chuyen xe thanh cong.";
    }
}
void hieuChinhChuyenXe(danhSachChuyenXe &ds, danhSachXe l)
{
    string maChuyen;
    cout << "Nhap vao ma chuyen xe can hieu chinh : ";
    cin.ignore();
    getline(cin, maChuyen);
    int vt = timViTriChuyenXe(ds, maChuyen);
    if (vt == -1)
    {
        system("cls");
        cout << "\nKhong tim thay chuyen xe.";
    }
    else
    {
        cout << "\nNhap lai ma chuyen xe : ";
        getline(cin, ds.duLieuChuyenXe.maChuyen);
        ds.node[vt].maChuyen = ds.duLieuChuyenXe.maChuyen;

        cout << "Nhap lai so xe : ";
        getline(cin, ds.duLieuChuyenXe.soXe);
        ds.node[vt].soXe = ds.duLieuChuyenXe.soXe;

        cout << "Nhap lai ngay khoi hanh : ";
        getline(cin, ds.duLieuChuyenXe.dayTime);
        ds.node[vt].dayTime = ds.duLieuChuyenXe.dayTime;

        cout << "Nhap lai noi den : ";
        getline(cin, ds.duLieuChuyenXe.noiDen);
        ds.node[vt].noiDen = ds.duLieuChuyenXe.noiDen;
    }
}
void huyChuyenXe(danhSachChuyenXe &ds, danhSachXe l)
{
    string maChuyen;
    cout << "Nhap vao ma chuyen xe can huy : ";
    cin.ignore();
    getline(cin, maChuyen);
    int vt = timViTriChuyenXe(ds, maChuyen);
    if (vt == -1)
    {
        system("cls");
        cout << "\nKhong tim thay chuyen xe.";
    }
    else
    {
        giamLuotThucHien(l, ds.node[vt].soXe);
        system("cls");
        cout << "Da huy chuyen xe thanh cong.";
        ds.node[vt].trangThai = 0;
    }
}
void xuatChuyenXe(danhSachChuyenXe ds)
{
    int i;
    if (ds.slChuyenXe == 0)
    {
        cout << "\nDanh sach chuyen xe trong.";
    }
    else
    {
        cout << "\nDanh sach cac chuyen hien co.";
        cout << endl;

        cout << setw(15) << left << "Ma chuyen";
        cout << setw(15) << left << "So xe";
        cout << setw(20) << left << "ngay khoi hanh";
        cout << setw(20) << left << "Tinh den";
        cout << setw(15) << right << "Trang thai" << endl;
        cout << setfill('-');            // set fill bằng ký tự '-' thay vì ' '
        cout << setw(85) << "-" << endl; // fill 80 ký tự '-'

        // reset fill bằng ký tự ' '
        cout << setfill(' ');
        for (i = 0; i < ds.slChuyenXe; i++)
        {
            cout << setw(15) << left << ds.node[i].maChuyen;
            cout << setw(15) << left << ds.node[i].soXe;
            cout << setw(20) << left << ds.node[i].dayTime;
            cout << setw(20) << left << ds.node[i].noiDen;
            cout << setw(15) << right << ds.node[i].trangThai << endl;
        }
    }
}

// void docFileChuyenXe(danhSachChuyenXe &ds)
// {
//     ifstream fileIn;
//     fileIn.open("docChuyenXe.txt",ios_base::in);
//     while (fileIn.eof()!=true)
//     {
//         getline(fileIn,ds.node[ds.slChuyenXe].maChuyen,'|');
//         getline(fileIn,ds.node[ds.slChuyenXe].soXe,'|');
//         getline(fileIn,ds.node[ds.slChuyenXe].dayTime,'|');
//         getline(fileIn,ds.node[ds.slChuyenXe].noiDen,'|');
//         fileIn.ignore();
//         ds.slChuyenXe++;
//     }
//     fileIn.close();
// }
//=========================end chuyen xe ==========================

//========== cau truc ve xe ===============

void themVe(danhSachChuyenXe &cx, int i, long cmnd)
{
    // for (int j = 0; j <= cx.node[i].soCho; j++)
    for (int j = 0; j < cx.node[i].danhSachVe.soLuongVe; j++)
    {
        if (cx.node[i].danhSachVe.danhsachve[j].cmnd == cmnd)
        {
            cout << "\nKhach hang da dat ve.";
            return;
        }
        else if (cx.node[i].danhSachVe.danhsachve[j].cmnd == 0)
        {
            cx.node[i].danhSachVe.danhsachve[j].cmnd = cmnd;
            cx.node[i].danhSachVe.danhsachve[j].maChuyen = cx.node[i].maChuyen;
            cx.node[i].danhSachVe.danhsachve[j].stt = j;
            cx.node[i].danhSachVe.soVe++;
            if (cx.node[i].danhSachVe.soVe == cx.node[i].danhSachVe.soLuongVe)
            {
                cx.node[i].trangThai = 2;
            }
            else
            {
                cx.node[i].trangThai = 1;
            }
            cout << "\nDa dat ve thanh cong.";
            return;
        }
    }
}

void datVe(danhSachVeXe &vs, danhSachChuyenXe &ds, danhSachKhachHang &kh)
{
    chuyenXe x;
    string maChuyen;
    long cmnd;bool check;
    cout << "\nNhap vao ma chuyen xe : ";
    cin.ignore();
    getline(cin, maChuyen);

    for (int i = 0; i <= ds.slChuyenXe; i++)
    {
        if (ds.slChuyenXe == 0)
        {
            system("cls");
            cout << "Danh sach chuyen xe hien dang trong.";
            return;
        }

        else if (ds.node[i].maChuyen == maChuyen)
        {
            if (ds.node[i].trangThai == 2)
            {
                system("cls");
                cout << "Chuyen xe da het ve.";
                return;
            }
            if (ds.node[i].trangThai == 0)
            {
                system("cls");
                cout << "Chuyen xe da bi huy.";
                return;
            }

            cout << "nhap cmnd hanh khach : ";
            do
            {
                cin >> cmnd;
                check = cin.fail();
                cin.clear();
                if (check == true)
                {
                    cout << "Nhap sai! Nhap lai cmnd : ";
                    cin.ignore(200, '\n');
                }
            } while (check == true);

            if (kiemTraKHTrung(kh.ds, cmnd) == 1)
            {
                system("cls");
                cout << "\nKhach hang da ton tai." << endl;
                cout << setw(10) << left << "CMND";
                cout << setw(10) << left << "Ho";
                cout << setw(10) << left << "Ten";
                cout << setw(4) << left << "Phai" << endl;
                cout << setfill('-');
                cout << setw(34) << "-" << endl;
                cout << setfill(' ');
                xuatHanhKhach(kh.ds, cmnd);
                themVe(ds, i, cmnd);
                return;
            }
            else if (kiemTraKHTrung(kh.ds, cmnd) == 0)
            {
                nhapHanhKhach(kh, cmnd);
                system("cls");
                themVe(ds, i, cmnd);
                return;
            }
        }
    }
    {
        cout << "\nKhong ton tai chuyen xe nhu tren.";
        return;
    }
}

void xuatDSHK(danhSachChuyenXe ds, danhSachKhachHang kh)
{
    string maChuyen;
    cout << "Nhap vao ma chuyen  : ";
    cin.ignore();
    getline(cin, maChuyen);
    system("cls");
    for (int i = 0; i <= ds.slChuyenXe; i++)
    {
        if (ds.node[i].maChuyen == maChuyen)
        {
            if (ds.node[i].trangThai == 0)
            {
                system("cls");
                cout << "Chuyen xe da bi huy.";
                return;
            }
            cout << "DANH SACH HANH KHACH THUOC CHUYEN XE " << ds.node[i].maChuyen;
            cout << "\nNgay gio khoi hanh: " << ds.node[i].dayTime << "\t"
                 << ".   Noi den: " << ds.node[i].noiDen << endl;
            cout << setw(4) << left << "STT";
            cout << setw(8) << left << "So ve";
            cout << setw(10) << left << "CMND";
            cout << setw(10) << left << "Ho";
            cout << setw(10) << left << "Ten";
            cout << setw(4) << left << "Phai" << endl;
            cout << setfill('-');
            cout << setw(46) << "-" << endl;

            // reset fill bằng ký tự ' '
            cout << setfill(' ');

            for (int j = 0; j < ds.node[i].danhSachVe.soLuongVe; j++)
            {

                cout << setw(4) << left << j + 1;
                cout << setw(8) << left << j + 1;
                xuatHanhKhach(kh.ds, ds.node[i].danhSachVe.danhsachve[j].cmnd);
                cout << endl;
            }
        }
    }
}

void xuatVeTrongDay(danhSachChuyenXe ds)
{
    cout << "Nhap ngay khoi hanh : ";
    cin.ignore();
    getline(cin, ds.duLieuChuyenXe.dayTime);
    system("cls");
    for (int i = 0; i <= ds.slChuyenXe; i++)
    {
        if (ds.node[i].dayTime == ds.duLieuChuyenXe.dayTime)
        {
            if (ds.node[i].trangThai == 1)
            {
                cout << "\nChuyen xe : " << ds.node[i].maChuyen << "\tNoi den : " << ds.node[i].noiDen;
                cout << "\ndanh sach cac ghe con trong : \n";
                for (int j = 0; j < ds.node[i].danhSachVe.soLuongVe; j++)
                {
                    for (int k = j + 4; j < k; j++)
                    {
                        if (ds.node[i].danhSachVe.danhsachve[j].cmnd == 0 && j < ds.node[i].danhSachVe.soLuongVe)
                        {
                            cout << "\t|Ghe : " << j + 1;
                        }
                    }
                    j--;
                    cout << endl;
                }
                cout << "\n------------------------------";
            }
        }
    }
}
void xuatVeTrongCX(danhSachChuyenXe ds)
{
    cout << "Nhap ma chuyen xe : ";
    cin.ignore();
    getline(cin, ds.duLieuChuyenXe.maChuyen);
    system("cls");
    for (int i = 0; i < ds.slChuyenXe; i++)
    {
        if (ds.node[i].maChuyen == ds.duLieuChuyenXe.maChuyen)
        {
            cout << "Chuyen xe : " << ds.node[i].maChuyen;
            if (ds.node[i].trangThai == 0)
            {
                system("cls");
                cout << "Chuyen xe da bi huy.";
                return;
            }
            else if (ds.node[i].trangThai == 2)
            {
                system("cls");
                cout << "Chuyen xe het ve.";
                return;
            }
            else if (ds.node[i].trangThai == 1)
            {
                cout << "\ndanh sach cac ghe con trong : \n";
                for (int j = 0; j < ds.node[i].danhSachVe.soLuongVe; j++)
                {
                    for (int k = j + 4; j < k;j++)
                    {
                        if (ds.node[i].danhSachVe.danhsachve[j].cmnd == 0 && j < ds.node[i].danhSachVe.soLuongVe)
                        {
                            cout << "\t|Ghe : " << j + 1;
                        }
                    }
                    j--;
                    cout << endl;
                }
            }
        }
    }
}

//===============end cau truc ve =================================================

int main()
{

    danhSachXe l;
    danhSachChuyenXe ds;
    danhSachKhachHang kh;
    danhSachVeXe vs;
    chuyenXe x;
    int luachon;
    string soXe;
    bool check;
    while (true)
    {
        cout << "\n===============================================================";
        cout << "\n\tCHUONNG TRINH QUAN LY XE KHACH LIEN TINH";
        cout << "\n\n\t\t1.Them xe";
        cout << "\n\t\t2.Xoa xe ra khoi danh sach.";
        cout << "\n\t\t3.Hieu chinh xe.";
        cout << "\n\t\t4.In danh sach cac xe hien co.";
        cout << "\n\t\t5.Lap chuyen xe moi.";
        cout << "\n\t\t6.Hieu chinh chuyen xe.";
        cout << "\n\t\t7.Huy chuyen xe.";
        cout << "\n\t\t8.In danh chuyen xe.";
        cout << "\n\t\t9.Dat ve xe.";
        cout << "\n\t\t10.In danh sach hanh khach theo ma chuyen. ";
        cout << "\n\t\t11.In danh sach chuyen xe con ve theo ngay.";
        cout << "\n\t\t12.In danh sach ve con trong theo ma chuyen";
        cout << "\n\t\t13.Thong ke luot thuc hien chuyen xe cua tung xe.";
        cout << endl;
        cout << "\nNhap vao 0 de thoat chuong trinh.";
        cout << "\n===============================================================";
        cout << "\nNhap lua chon cua ban : ";

        do
        {
            cin >> luachon;
            check = cin.fail();
            cin.clear();
            if (check == true)
            {
                cout << "Nhap sai! Nhap lai lua chon : ";
                cin.ignore(200, '\n');
            }
        } while (check == true);

        switch (luachon)
        {
        case 0:
            cout << "\nBan co chac chan muon thoat chuong trinh?";
            cout << "\nNhap 1.CO hoac 0.KHONG\n";
            int i;
            cin >> i;
            if (i == 1)
            {
                return 0;
            }
            else
            {
                system("cls");
            }

            break;
        case 1:
            nhapXe(l);
            break;
        case 2:
            cout << "\nNhap vao so xe can xoa : ";
            cin.ignore();
            getline(cin, soXe);
            system("cls");
            xoaXe(l, soXe);
            break;
        case 3:
            cout << "\nNhap so xe can hieu chinh : ";
            cin.ignore();
            getline(cin, soXe);
            hieuChinhXe(l, soXe);
            break;
        case 4:
            system("cls");
            xuatXe(l);
            break;
        case 5:
            themChuyenXe(ds, l);
            break;
        case 6:
            hieuChinhChuyenXe(ds, l);
            break;
        case 7:
            huyChuyenXe(ds, l);
            break;
        case 8:
            system("cls");
            xuatChuyenXe(ds);
            break;
        case 9:
            datVe(vs, ds, kh);
            break;
        case 10:
            xuatDSHK(ds, kh);
            break;
        case 11:
            xuatVeTrongDay(ds);
            break;
        case 12:
            xuatVeTrongCX(ds);
            break;
        case 13:
            luotThucHien(l);
            break;
        default:
            system("cls");
            cout << "Lua chon khong trung khop!";
            break;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}