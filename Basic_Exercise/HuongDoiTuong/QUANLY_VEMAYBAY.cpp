#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class date{
	private:
		int day,month,year;
	public:
		void input();
		void output();
};

void date::input()
{
	cout<<"\nNHAP VAO NGAY: ";
	cin>>day;
	cout<<"\nNHAP VAO THANG: ";
	cin>>month;
	cout<<"\nNHAP VAO NAM: ";
	cin>>year;
}

void date::output()
{
	cout<<"Ngay/Thang/Nam: "<<day<<"/"<<month<<"/"<<year;
}

//============================================================================

class VeMayBay{
	protected:
		char tenchuyen[20];
		date ngaybay;
		float giave;
		int sl;
	public:
		void Nhap();
		void Xuat();
		void NhapDanhSachVe();
		void XuatDanhSachVe();
};

void VeMayBay::Nhap()
{
	cout<<"\nNHAP VAO TEN CHUYEN BAY: ";
	fflush(stdin);
	gets(tenchuyen);
	cout<<"\nNHAP VAO NGAY BAY: ";
	ngaybay.input();
	cout<<"\nNHAP VAO GIA VE: ";
	cin>>giave;
}

void VeMayBay::Xuat()
{
	cout<<"\nTEN CHUYEN BAY: "<<tenchuyen;
	cout<<"\nNGAY BAY: "<<endl<<"\t";
	ngaybay.output();
	cout<<"\nGIA VE: "<<giave;
}

void VeMayBay::NhapDanhSachVe()
{
	cout<<"\nNHAP VAO SO LUONG VE: ";
	cin>>sl;
	for(int i=0;i<sl;i++)
	{
		cout<<"\nNHAP VAO THONG TIN VE THU "<<(i+1);
		VeMayBay::Nhap();
	}
}

void VeMayBay::XuatDanhSachVe()
{
	for(int i=0;i<sl;i++)
	{
		cout<<"\nTHONG TIN VE THU "<<(i+1);
		VeMayBay::Xuat();
	}
}
//============================================================================

class Nguoi{
	protected:
		char hoten[30];
		char gioitinh[3];
		int tuoi;
	public:
		virtual void Nhap();
		virtual void Xuat();
};

void Nguoi::Nhap()
{
	cout<<"\nNHAP VAO HO TEN: ";
	fflush(stdin);
	gets(hoten);
	cout<<"\nNHAP VAO GIOI TINH: ";
	fflush(stdin);
	gets(gioitinh);
	cout<<"\nNHAP VAO TUOI: ";
	cin>>tuoi;
}

void Nguoi::Xuat()
{
	cout<<"\nHO TEN: "<<hoten;
	cout<<"\nGIOI TINH: "<<gioitinh;
	cout<<"\nTUOI: "<<tuoi;
}

//============================================================================

class HanhKhach : public Nguoi{
	private:
		VeMayBay ve[100];
		char cmnd[10];
	public:
		void Nhap();
		void Xuat();
};

void HanhKhach::Nhap()
{
	Nguoi::Nhap();
	cout<<"\nNHAP VAO CMND: ";
	fflush(stdin);
	gets(cmnd);
	cout<<"\n\tNHAP VAO THONG TIN CHUYEN BAY";
	ve->NhapDanhSachVe();
}

void HanhKhach::Xuat()
{
	Nguoi::Xuat();
	cout<<"\nCMND: "<<cmnd;
	cout<<"\n\tTHONG TIN CHUYEN BAY";
	ve->XuatDanhSachVe();
}

class DanhSachHanhKhach{
	private:
		Nguoi *N[100];
		int soluong;
	public:
		void menu();
};

void DanhSachHanhKhach::menu()
{
	int chon;
	do
	{
		cout<<"\n\t\t\t============ MENU ============";
		cout<<"\n\t\t\t1.NHAP VAO MOT HANH KHACH";
		cout<<"\n\t\t\t2.XUAT DANH SACH HANH KHACH";
		cout<<"\n\t\t\t============ END ============";
		cout<<"\n\t\t\tNHAP VAO LUA CHON: ";
		cin>>chon;
		switch(chon)
		{
			case 1:{
				N[soluong] = new HanhKhach;
				cout<<"\n\t\tNHAP THONG TIN HANH KHACH";
				N[soluong]->Nhap();
				soluong++;
				break;
			}
			case 2:{
				for(int i=0;i<soluong;i++)
				{
					cout<<"\n\t\tTHONG TIN HANH KHACH THU "<<(i+1);
					N[i]->Xuat();
				}
				break;
			}
		}
	}while(chon>=1 and chon<=5);
}


int main()
{
	DanhSachHanhKhach *dshk = new DanhSachHanhKhach;
	dshk->menu();
	
	return 0;
}
