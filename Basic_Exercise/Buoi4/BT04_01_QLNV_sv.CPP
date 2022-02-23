//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_TEN		50
#define MAX_MASO	10
#define LCB     1150000 
//Class Nhanvien
class NhanVien
{	protected: //private:
		char HoTen[MAX_TEN];
		char MaSo[MAX_MASO];
		float Luong;
	public:
		NhanVien();
		virtual float TinhLuong()=0; 
		void Xuat(); 
		virtual void Nhap();
		//...bo sung code
};

	
//Class Bien che
class BienChe: public NhanVien
{	protected: //private:
		float HeSoLuong;
		float HeSoPhuCap;
	public:
		BienChe();
		float TinhLuong();
		void Nhap();
		//...bo sung code
};

//Dinh nghia lop HopDong
class HopDong : public NhanVien
{	protected: //private:
		float TienCong; // 1 ngay
		float NgayCong; // lon hon 24 ngay thi tinh 1.2
	public:
		HopDong();
		float TinhLuong();
		void Nhap();
		//...bo sung code
};

//Dinh nghia ham thanh vien cho lop NhanVien
NhanVien::NhanVien()
{
	strcpy(HoTen,""); 
	strcpy(MaSo,"");
	Luong=0;
}

void NhanVien::Nhap()
{
	cout<<"Ma so:";	cin>>MaSo;
	cin.ignore(); //xoa dau Enter trong buffer
	cout<<"Ho va ten:"; 
	cin.getline(HoTen,MAX_TEN);
	//cin>>HoTen;
}

void NhanVien::Xuat() 
{	//setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Ma so:"<<MaSo<<",Ho va ten:"<<HoTen
		 <<",Luong:"<<Luong<<endl;
}
	

//Dinh nghia ham thanh vien cho lop BienChe
BienChe::BienChe()
{
	HeSoLuong=HeSoPhuCap=0;
}

void BienChe::Nhap()
{	
//...bo sung code
}

float BienChe::TinhLuong()
{
	return Luong=LCB*(HeSoLuong+HeSoPhuCap);
}

//Cac ham thanh vien trong lop HopDong
HopDong::HopDong()
{
	TienCong=NgayCong=0;
}

void HopDong::Nhap()
{
	
	//...bo sung code
}

float HopDong::TinhLuong()
{
	//...bo sung code
}

int main()
{
	NhanVien *Nv[100];	int N=0;
	char Chon,Loai;
	cout<<"Nhap thong tin cho cac Nhan vien"<<endl;
	do
	{	cout<<"Bien che hay Hop dong (B/H)? ";
		cin>>Loai; 	Loai=toupper(Loai);
		if (Loai=='B')
			Nv[N]=new BienChe;
		else
			Nv[N]=new HopDong;
		Nv[N++]->Nhap();
		cout<<"Tiep tuc (C/K)? ";	cin>>Chon;
		Chon=toupper(Chon);
		if ((N==100)||(Chon=='K'))
			break;
	}
	while (1);
	cout<<"Thong tin cua cac nhan vien vua nhap"<<endl;
	
	//...bo sung code
	getch();
	return 1;
}
