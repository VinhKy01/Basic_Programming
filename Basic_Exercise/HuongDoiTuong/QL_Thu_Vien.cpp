#include <iostream>

using namespace std;
class DocGia
{
protected:
    char hoten[30];
    char ngaymothe[20];
    int sothanghieuluc;
    float tinhtien;
    bool ktr;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhTienLamThe()=0;
    
    bool get_ktr()
    {
        return ktr;
    }
    bool set_ktr(bool kt)
    {
        ktr = kt;
    }
};



void DocGia::Nhap()
{
    cout<<"\n\tNHAP VAO HO TEN: ";
    fflush(stdin);
    gets(hoten);
    cout<<"\n\tNHAP NGAY MO THE: ";
    fflush(stdin);
    gets(ngaymothe);
    cout<<"\n\tNHAP SO THANG CO HIEU LUC: ";
    cin>>sothanghieuluc;
}
void DocGia::Xuat()
{
    cout<<"\n\tHO TEN: "<<hoten;
    cout<<"\n\tNGAY MO THE: "<<ngaymothe;
    cout<<"\n\tSO THANG CON HIEU LUC: "<<sothanghieuluc;
}

//====================================================================================

class DocGiaTreEm : public DocGia
{
private:
    char nguoidaidien[30];
public:
    void Nhap();
    void Xuat();
    void TinhTienLamThe();
};

void DocGiaTreEm::Nhap()
{
    DocGia::Nhap();
    cout<<"\n\tNHAP TEN NGUOI DAI DIEN: ";
    fflush(stdin);
    gets(nguoidaidien);
    DocGiaTreEm::TinhTienLamThe();
}

void DocGiaTreEm::Xuat()
{
    DocGia::Xuat();
    cout<<"\n\tNGUOI DAI DIEN: "<<nguoidaidien;
    cout<<"\n\tTIEN LAM THE: "<<tinhtien<<" VND";
}
void DocGiaTreEm::TinhTienLamThe()
{
    tinhtien = sothanghieuluc * 5000;
}

//====================================================================================

class DocGiaNguoiLon : public DocGia
{
private:
    double cmnd;
public:
    void Nhap();
    void Xuat();
    void TinhTienLamThe();
};

void DocGiaNguoiLon::Nhap()
{
    DocGia::Nhap();
    cout<<"\n\tNHAP VAO CMND: ";
    cin>>cmnd;
    DocGiaNguoiLon::TinhTienLamThe();
}
void DocGiaNguoiLon::Xuat()
{
    DocGia::Xuat();
    cout<<"\n\tCMND: "<<cmnd;
    cout<<"\n\tTIEN LAM THE: "<<tinhtien<<" VND";
}
void DocGiaNguoiLon::TinhTienLamThe()
{
    tinhtien = sothanghieuluc * 10000;
}

//====================================================================================

int main()
{
    DocGia *dg[100];
    int SoLuong;
    int chon;
    do
    {
        cout<<"\n\t\t\t======================MENU======================";
        cout<<"\n\t\t\t1.NHAP THONG TIN DOC GIA TRE EM";
        cout<<"\n\t\t\t2.NHAP THONG TIN DOC GIA NGUOI LON";
        cout<<"\n\t\t\t3.XUAT THONG TIN DOC GIA TRE EM";
        cout<<"\n\t\t\tNHAP VAO BAT KI DE THOAT CHUONG TRINH: ";
        cout<<"\n\t\t\tNHAP VAO LUA CHON CAU BAN: ";
        cin>>chon;
        cout<<"\t\t\t======================END======================";
        switch (chon)
        {
        case 1:
            dg[SoLuong] = new DocGiaTreEm;
            cout<<"\n\t\tNHAP THONG TIN DOC GIA";
            dg[SoLuong]->Nhap();
            dg[SoLuong]->set_ktr(true);
            SoLuong++;
            system("pause");
			system("cls");
            break;
        case 2:
            dg[SoLuong] = new DocGiaNguoiLon;
            cout<<"\n\t\tNHAP THONG TIN DOC GIA";
            dg[SoLuong]->Nhap();
            dg[SoLuong]->set_ktr(false);
            SoLuong++;
            system("pause");
			system("cls");
            break;
        case 3:
            for (int  i = 0; i < SoLuong; i++)
            {
                if (dg[i]->get_ktr()==true)
                {
                    cout<<"\n\t===========================";
                    cout<<"\n\t\tDOC GIA THU TRE EM THU "<<(i+1);
                    dg[i]->Xuat(); 
                    cout<<"\n";
                }
                else
                {
                    cout<<"\n\t===========================";
                    cout<<"\n\t\tDOC GIA THU NGUOI LON THU "<<(i+1);
                    dg[i]->Xuat();
                    cout<<"\n";
                }
            }
            system("pause");
			system("cls");
            break;
        default:
            cout<<"\n\t\t================KET THUC CHUONG TRINH================";
            break;
        }  
    } while (chon>=1 and chon<=3);
    return 0;
}