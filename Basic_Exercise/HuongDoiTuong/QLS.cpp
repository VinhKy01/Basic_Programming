#include <iostream>
#include <string.h>

using namespace std;

class Sach
{
protected:
    char masach[15];
    char ngaynhap[15];
    float dongia;
    int soluong;
    char nxb[50];
    float thanhtien;
    bool kiemtra;
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhTien()=0;
    bool getter_kiemtra()
    {
        return kiemtra;
    }
    bool setter_kiemtra(bool kt)
    {
        kiemtra = kt;
    }
    float getter_thanhtien()
    {
        return thanhtien;
    }
    float getter_dongia()
    {
        return dongia;
    }

};

void Sach::Nhap()
{
    cout<<"\nNHAP VAO MA SACH: ";
    fflush(stdin);
    gets(masach);
    cout<<"\nNHAP VAO NGAY NHAP: ";
    fflush(stdin);
    gets(ngaynhap);
    cout<<"\nNHAP VAO DON GIA: ";
    cin>>dongia;
    cout<<"\nNHAP VAO SO LUONG: ";
    cin>>soluong;
    cout<<"\nNHAP VAO NHA XUAT BAN: ";
    cin>>nxb;
}
void Sach::Xuat()
{
    cout<<"\nMA SACH: "<<masach;
    cout<<"\nNGAY NHAP: "<<ngaynhap;
    cout<<"\nDON GIA: "<<dongia;
    cout<<"\nSO LUONG: "<<soluong;
    cout<<"\nNHA XUAT BAN: "<<nxb;
}

//====================================================================

class SachGK : public Sach
{
private:
    char tinhtrang[3];
public:
    void Nhap();
    void Xuat();
    void TinhTien();
};

void SachGK::Nhap()
{
    Sach::Nhap();
    cout<<"\nNHAP VAO TINH TRANG: ";
    fflush(stdin);
    gets(tinhtrang);
    TinhTien();
}

void SachGK::Xuat()
{
    Sach::Xuat();
    cout<<"\nTINH TRANG: "<<tinhtrang;
    cout<<"\nTHANH TIEN: "<<size_t(thanhtien);
}

void SachGK::TinhTien()
{
    if(stricmp(tinhtrang,"Moi")==0)
        thanhtien = soluong * dongia;
    else
        thanhtien = soluong * dongia / 2;
}

//====================================================================

class SachTK : public Sach
{
private:
    float thue;
public:
    void Nhap();
    void Xuat();
    void TinhTien();
    float setter_thue(float t)
    {
        thue = t / 10;
    }
};

void SachTK::Nhap()
{
    Sach::Nhap();
    TinhTien();
}

void SachTK::Xuat()
{
    Sach::Xuat();
    cout<<"\nTHUE: "<<size_t(thanhtien);
}

void SachTK::TinhTien()
{
    thanhtien = soluong * dongia + setter_thue(dongia);
}

class DanhSachSach
{
private:
    Sach *s[100];
    int sl;
public:
    void menu();
};
 
void DanhSachSach::menu()
{
    int chon;
    do
    {
        cout<<"\n\t\t\t======================MENU======================";
        cout<<"\n\t\t\tPHIM 1.NHAP SACH GIAO KHOA";
        cout<<"\n\t\t\tPHIM 2.NHAP SACH THAM KHAO";
        cout<<"\n\t\t\tPHIM 3.XUAT THONG TIN SACH";
        cout<<"\n\t\t\tPHIM 4.TINH TONG THANH TIEN TUNG LOAI SACH";
        cout<<"\n\t\t\tPHIM 5.TINH TRUNG BINH DON GIA SACH THAM KHAO";
        cout<<"\n\t\t\tPHIM 6.TIM KIEM NHA SAN XUAT";
        cout<<"\n\t\t\t======================END======================";
        cout<<"\n\t\t\tNHAP VAO LUA CHON CUA BAN: ";
        cin>>chon;
        switch (chon)
        {
        case 1:
            s[sl] = new SachGK;
            cout<<"\n\tNHAP THONG TIN SACH";
            s[sl]->Nhap();
            s[sl]->setter_kiemtra(true);
            sl++;
            system("pause");
				system("cls");
            break;
        case 2:
            s[sl] = new SachTK;
            cout<<"\n\tNHAP THONG TIN SACH";
            s[sl]->Nhap();
            s[sl]->setter_kiemtra(false);
            sl++;
            system("pause");
				system("cls");
            break;
        case 3:
            {
	            for (int i = 0; i < sl; i++)
	            {
	                cout<<"\n============================================";
	                if (s[i]->getter_kiemtra()==true)
	                {
	                    cout<<"\nTHONG TIN SACH GIAO KHOA THU "<<(i+1);
	                    s[i]->Xuat();
	                }
	                else
	                {
	                    cout<<"\nTHONG TIN SACH THAM KHAO THU "<<(i+1);
	                    s[i]->Xuat();
	                }   
	            }
	            system("pause");
				system("cls");
	            break;
			}
        case 4:
            	{
            		float tonggk = 0;
	                float tongtk = 0;
	                for (int i = 0; i < sl; i++)
	                {
	                    if (s[i]->getter_kiemtra()==true)
	                    {
	                        tonggk += s[i]->getter_thanhtien();
	                    }
	                    else
	                    {
	                        tongtk += s[i]->getter_thanhtien();
	                    }
	                }
	                cout<<"\nTONG THANH TIEN SACH GIAO KHOA: "<<size_t(tonggk);
	                cout<<"\nTONG THANH TIEN SACH THAM KHAO: "<<size_t(tongtk);
	                system("pause");
				system("cls");
	                break;
				}
        case 5:
                 {
                    float tong,trungbinh;
                    int count=0;
                    for (int i = 0; i < sl; i++)
                        {
                            if(s[i]->getter_kiemtra()==true)
                            {
                                tong += s[i]->getter_dongia();
                                count++;
                            }
                        }
                    trungbinh = tong / count;
                    cout<<"\nTRUNG BINH DON GIA SACH THAM KHAO: "<<trungbinh;
                    system("pause");
				system("cls");
				break;
                 }
        default:
            cout<<"\n\t\t==================== KET THUC CHUONG TRINH ====================";
            break;
        }


    } while (chon>=1 and chon<=5);
    
}


int main()
{
    DanhSachSach *dss = new DanhSachSach;
    dss->menu();
    return 0;
}
