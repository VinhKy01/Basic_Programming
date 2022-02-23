#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class HoTen{
	private:
		char ho[10];
		char tenlot[10];
		char ten[10];
	public:
		void Nhap();
		void Xuat();
		char* getter_ten()
		{
			return this->ten;
		}
};

void HoTen::Nhap()
{
	cout<<"\nNHAP VAO HO: ";
	fflush(stdin);
	gets(ho);
	cout<<"\nNHAP VAO TEN LOT: ";
	fflush(stdin);
	gets(tenlot);
	cout<<"\nNHAP VAO TEN: ";
	fflush(stdin);
	gets(ten);
}

void HoTen::Xuat()
{
	cout<<"\nHO VA TEN: "<<ho<<" "<<tenlot<<" "<<ten;
}

//=======================================================================================

class CanBo{
	protected:
		HoTen hoten;
		int tuoi;
		char gioitinh[3];
		char diachi[40];
		int kiemtra;
	public:
		virtual void Nhap();
		virtual void Xuat();
		int getter_kiemtra(){
			return kiemtra;
		}
		void setter_kiemtra(int ktr){
			kiemtra = ktr;
		}
		HoTen get_hoten()
		{
			return hoten;
		}
};

void CanBo::Nhap()
{
	cout<<"\nNHAP HO VA TEN: "<<endl<<"\t";
	hoten.Nhap();
	cout<<"\nNHAP TUOI: ";
	cin>>tuoi;
	cout<<"\nNHAP GIOI TINH: ";
	fflush(stdin);
	gets(gioitinh);
	cout<<"\nNHAP DIA CHI: ";
	fflush(stdin);
	gets(diachi);
}

void CanBo::Xuat()
{
	hoten.Xuat();
	cout<<"\nTUOI: "<<tuoi;
	cout<<"\nGIOI TINH: "<<gioitinh;
	cout<<"\nDIA CHI: "<<diachi;
}

//=======================================================================================

class CongNhan : public CanBo{
	private:
		int capbac;
	public:
		void Nhap();
		void Xuat();
};

void CongNhan::Nhap()
{
	CanBo::Nhap();
	cout<<"\nNHAP CAP BAC: ";
	cin>>capbac;
}

void CongNhan::Xuat()
{
	CanBo::Xuat();
	cout<<"\nCAP BAC: "<<capbac;
}

//=======================================================================================

class KySu : public CanBo{
	private:
		char nganhdaotao[30];
	public:
		void Nhap();
		void Xuat();
};

void KySu::Nhap()
{
	CanBo::Nhap();
	cout<<"\nNHAP NGANH DAO TAO: ";
	fflush(stdin);
	gets(nganhdaotao);
}

void KySu::Xuat()
{
	CanBo::Xuat();
	cout<<"\nNGANH DAO TAO: "<<nganhdaotao;
}

//=======================================================================================

class NhanVien : public CanBo{
	private:
		char congviec[30];
	public:
		void Nhap();
		void Xuat();
};

void NhanVien::Nhap()
{
	CanBo::Nhap();
	cout<<"\nNHAP CONG VIEC: ";
	fflush(stdin);
	gets(congviec);
}

void NhanVien::Xuat()
{
	CanBo::Xuat();
	cout<<"\nCONG VIEC: "<<congviec;
}

//=======================================================================================

class DanhSachCanBo{
	private:
		CanBo *cb[100];
		int soluong;
	public:
		void menu();
};

void DanhSachCanBo::menu()
{
	int chon;
	do
	{
		cout<<"\n\t\t\t============== MENU ==============";
		cout<<"\n\t\t\t1.NHAP VAO THONG TIN CONG NHAN";
		cout<<"\n\t\t\t2.NHAP VAO THONG TIN KY SU";
		cout<<"\n\t\t\t3.NHAP VAO THONG TIN NHAN VIEN";
		cout<<"\n\t\t\t4.XUAT DANH SACH CAC CAN BO";
		cout<<"\n\t\t\t============== END ==============";
		cout<<"\n\t\t\tNHAP VAO LUA CHON: ";
		cin>>chon;
		switch(chon){
			case 1:{
				cb[soluong] = new CongNhan;
				cout<<"\n\tNHAP VAO THONG TIN CONG NHAN";
				cb[soluong]->Nhap();
				cb[soluong]->setter_kiemtra(19);
				soluong++;
				break;
			}
			case 2:{
				cb[soluong] = new KySu;
				cout<<"\n\tNHAP VAO THONG TIN KY SU";
				cb[soluong]->Nhap();
				cb[soluong]->setter_kiemtra(25);
				soluong++;
				break;
			}
			case 3:{
				cb[soluong] = new NhanVien;
				cout<<"\n\tNHAP VAO THONG TIN NHAN VIEN";
				cb[soluong]->Nhap();
				cb[soluong]->setter_kiemtra(77);
				soluong++;
				break;
			}
			case 4:{
				cout<<"\n\t================ DANH SACH CAN BO ================";
				for(int i=0;i<soluong;i++)
				{
					cout<<"\n\tTHONG TIN CAN BO THU "<<(i+1);
					cb[i]->Xuat();
				}
				break;
			}
			case 5:{
				char timkiemten[10];
				cout<<"\nNHAP VAO TEN CAN TIM: ";
				fflush(stdin);
				gets(timkiemten);
				for(int i=0;i<soluong;i++)
				{
					if(stricmp(cb[i]->get_hoten().getter_ten(),timkiemten)==0)
						cb[i]->Xuat();
				}
				break;
			}
		}
	}while(chon>=0 and chon<=5);
}

int main()
{
	DanhSachCanBo *dscb = new DanhSachCanBo;
	dscb->menu();
	return 0;
}

















