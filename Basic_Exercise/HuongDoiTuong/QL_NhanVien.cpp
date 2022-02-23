#include <iostream>

using namespace std;

class NhanVien
{
    protected:
        char maso[10];
        char hoten[30];
        float luong;
        bool kiemtra;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual void TinhLuong()=0;
        bool getter_kiemtra()
        {
        	return kiemtra;
		}
		bool setter_kiemtra(bool kt)
		{
			kiemtra = kt;
		}
		float getter_luong()
		{
			return luong;
		}
};

void NhanVien::Nhap()
{
    cout<<"\n\tNHAP MA SO NHAN VIEN: ";
    fflush(stdin);
    gets(maso);
    cout<<"\n\tNHAP HO TEN NHAN VIEN: ";
    fflush(stdin);
    gets(hoten);
}

void NhanVien::Xuat()
{
    cout<<"\n\tMA SO: "<<maso;
    cout<<"\n\tHO TEN: "<<hoten;
}

//============================================================================================

class NV_BienChe : public NhanVien
{
    private:
        float hesoluong;
        float phucap;
    public:
        void Nhap();
        void Xuat();
        void TinhLuong();
    
};

void NV_BienChe::Nhap()
{
	NhanVien::Nhap();
    cout<<"\n\tNHAP HE SO LUONG[0.0-13.0]: ";
    cin>>hesoluong;
    while(hesoluong<0 or hesoluong>13)
    {
        cout<<"\n\tNHAP LAI HE SO LUONG[0.0-13.0]: ";
        cin>>hesoluong;
    }
    cout<<"\n\tNHAP PHU CAP[0.0-2.0]: ";
    cin>>phucap;
    while (phucap<0 or phucap>2)
    {
        cout<<"\n\tNHAP LAI PHU CAP[0.0-2.0]: ";
        cin>>hesoluong;
    }
    TinhLuong();
}

void NV_BienChe::Xuat()
{
	NhanVien::Xuat();
    cout<<"\n\tHE SO LUONG: "<<hesoluong;
    cout<<"\n\tPHU CAP: "<<phucap;
    cout<<"\n\tLUONG: "<<size_t(luong);
}

void NV_BienChe::TinhLuong()
{
	luong = 1150000 * (hesoluong + phucap);
}

//============================================================================================

class NV_HopDong : public NhanVien
{
    private:
        float tiencongmotngay;
        float ngaylamviec;
    public:
        void Nhap();
        void Xuat();
        void TinhLuong();
};

void NV_HopDong::Nhap()
{
	NhanVien::Nhap();
    cout<<"\n\tNHAP TIEN CONG 1 NGAY[80.000-150.000]: ";
    cin>>tiencongmotngay;
    while (tiencongmotngay<80000 or tiencongmotngay>150000)
    {
        cout<<"\n\tNHAP LAI TIEN CONG 1 NGAY[80.000-150.000]: ";
        cin>>tiencongmotngay;
    }
    cout<<"\n\tNHAP NGAY LAM VIEC: ";
    cin>>ngaylamviec;
    TinhLuong();
}
void NV_HopDong::Xuat()
{
	NhanVien::Xuat();
    cout<<"\n\tTIEN CONG 1 NGAY: "<<tiencongmotngay;
    cout<<"\n\tNGAY LAM VIEC: "<<ngaylamviec;
    cout<<"\n\tLUONG: "<<size_t(luong);
}

void NV_HopDong::TinhLuong()
{
	if(ngaylamviec>24)
		luong  = 24 * tiencongmotngay + (tiencongmotngay * (ngaylamviec-24) * 1.2);
	else
		luong = tiencongmotngay * ngaylamviec;
}

//============================================================================================

class DanhSachNhanVien
{
    private:
        NhanVien *nv[100];
        int SLNV;
    public:
        void menu();
};

void DanhSachNhanVien::menu()
{
	int chon;
	do
	{
		cout<<"\n\t\t\t====================== MENU ======================";
        cout<<"\n\t\t\t1.NHAP THONG TIN NHAN VIEN BIEN CHE";
        cout<<"\n\t\t\t2.NHAP THONG TIN NHAN VIEN HOP DONG";
        cout<<"\n\t\t\t3.XUAT THONG TIN NHAN VIEN";
        cout<<"\n\t\t\t4.TINH TONG LUONG CAC NHAN VIEN";
        cout<<"\n\t\t\t5.TINH TRUNG BINH LUONG CAC NHAN VIEN";
        cout<<"\n\t\t\t6.LIET KE DANH SACH NHUNG NHAN VIEN CO LUONG HON 5 TRIEU";
        cout<<"\n\t\t\tNHAP VAO BAT KI DE THOAT CHUONG TRINH: ";
        cout<<"\n\t\t\t======================= END =======================";
        cout<<"\n\t\t\tNHAP VAO LUA CHON CUA BAN: ";
        cin>>chon;
        switch(chon)
        {
        	case 1:{
        		nv[SLNV] = new NV_BienChe;
        		cout<<"\n\t\tNHAP THONG TIN NHAN VIEN";
        		nv[SLNV]->Nhap();
        		nv[SLNV]->setter_kiemtra(true);
        		SLNV++;
        		system("pause");
				system("cls");
				break;
			}
			case 2:{
				nv[SLNV] = new NV_HopDong;
        		cout<<"\n\t\tNHAP THONG TIN NHAN VIEN";
        		nv[SLNV]->Nhap();
        		nv[SLNV]->setter_kiemtra(false);
        		SLNV++;
        		system("pause");
				system("cls");
				break;
				
			}
			case 3:{
				cout<<"\n\t\tDANH SACH NHAN VIEN BIEN CHE\n";
				int dem1 = 1;
				int kiemtrabiemche=0,kiemtrahopdong=0;
				for(int i=0;i<SLNV;i++)
				{
					if(nv[i]->getter_kiemtra()==true)
					{
						cout<<"\n\t---NHAN VIEN BIEN CHE THU "<<dem1<<"---";
						nv[i]->Xuat();
						dem1++;
						cout<<"\n";
						kiemtrabiemche=1;
					}
				}
				if(kiemtrabiemche==0)
					cout<<"\n\tCHUA CO NHAN VIEN TRONG DANH SACH"<<endl;
				cout<<"\n\t\t=======================================";
				cout<<"\n\t\tDANH SACH NHAN VIEN HOP DONG\n";
				int dem2 = 1;
				for(int i=0;i<SLNV;i++)
				{
					if(nv[i]->getter_kiemtra()==false)
					{
						cout<<"\n\t---NHAN VIEN HOP DONG THU "<<dem2<<"---";
						nv[i]->Xuat();
						dem2++;
						kiemtrahopdong=1;
						cout<<"\n";
					}
				}
				if(kiemtrahopdong==0)
					cout<<"\n\tCHUA CO NHAN VIEN TRONG DANH SACH"<<endl;
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				float tong=0;
				for(int i=0;i<SLNV;i++)
				{
					tong = tong + nv[i]->getter_luong();
				}
				cout<<"\n\t\tTONG LUONG CAC NHAN VIEN: "<<size_t(tong)<<endl;
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				float tongtb=0;
				int count=0;
				for(int i=0;i<SLNV;i++)
				{
					tongtb = tongtb + nv[i]->getter_luong();
					count++;
				}
				cout<<"\n\t\tTRUNG BINH LUONG CAC NHAN VIEN: "<<size_t(tongtb)/count<<endl;
				system("pause");
				system("cls");
				break;
			}
			case 6:{
				int ktra=0;
				cout<<"\n\t\tDANH SACH NHAN VIEN CO LUONG HON 5 TRIEU";
				for(int i=0;i<SLNV;i++)
				{
					if(nv[i]->getter_luong()>5000000)
					{
						nv[i]->Xuat();
						ktra=1;
					}	
				}
				if(ktra==0)
					cout<<"\n\t\tKHONG CO NHAN VIEN NAO"<<endl;
				
				system("pause");
				system("cls");
				break;
			}
			default:
            	cout<<"\n\t\t================KET THUC CHUONG TRINH================";
            	break;   
		}
	}while(chon>=1 and chon<=6);
}

int main()
{
    DanhSachNhanVien *ds = new DanhSachNhanVien;
    ds->menu();

    return 0;
}
