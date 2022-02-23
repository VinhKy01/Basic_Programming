//V02 - Lop MangPhanSo co cac doi tuong la Phan so
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;
class PhanSo
{
	private:
		int Tuso;
		int Mauso;
	public:
		PhanSo();
		PhanSo(int, int);
		PhanSo(const PhanSo&);
		void Nhap();
		void Xuat();
		int XetDau();

		//int getMauso();
		//int getTuso();
		//void setTuso(int t);
		//void setMauso(int m);
	
		int Uscln(int a, int b);
		int Bscnn(int a, int b);
	
   		void RutGon();
		float GiatriPS();
	
		//Phuong thuc tinh toan
		PhanSo Cong(PhanSo ps);
		//PhanSo Tru(PhanSo ps);
		//PhanSo Nhan(PhanSo ps);
		//PhanSo Chia(PhanSo ps);
	
		//Nhap - Xuat bang luong
		//friend istream& operator >> (istream &is, PhanSo &p);
		//friend ostream& operator << (ostream &os, PhanSo &p);
	
		//Toan tu gan 
    	//PhanSo operator= (PhanSo &p);
	
		//Cac phep toan dung Toan tu
		//PhanSo operator+(PhanSo);
		//PhanSo operator-(PhanSo);
		//PhanSo operator*(PhanSo);
		//PhanSo operator/(PhanSo);
	
		//Toan tu So sanh
		//int operator > (PhanSo);
		//int operator < (PhanSo);
		//int operator >= (PhanSo);
		//int operator <= (PhanSo);
		//int operator == (PhanSo);
		//int operator != (PhanSo);

		//Cac phep toan dung Toan tu - Ham ban
		//friend PhanSo Cong (PhanSo p1,PhanSo p2);
		//friend PhanSo Tru (PhanSo p1,PhanSo p2);
		//friend PhanSo Nhan (PhanSo p1,PhanSo p2);
		//friend PhanSo Chia (PhanSo p1,PhanSo p2);
	
	
		int KtDuong();
};

class MangPhanSo
{
	private:
		PhanSo a[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		int DemDuong();
		//..cac phuong thuc con lai
		
};

int main()
{
	MangPhanSo x;
	PhanSo psmin, psmax;
	//Nhap danh sach
	
	cout<<"Nhap thong tin cac Phan so trong Mang: ";
	x.Nhap();
	cout<<"Thong tin cac Phan so trong Mang: ";
	x.Xuat();
	
	int kq = x.DemDuong();
	cout << "\n So luong phan so duong  " << kq;
	cout<<endl;
		
	//... Them code 
	
	getch();
	return 1;
}

PhanSo::PhanSo()
{
	Tuso = 0;	Mauso = 1;
}

PhanSo::PhanSo(const PhanSo &p)
{
	Tuso = p.Tuso;	Mauso = p.Mauso;
}

PhanSo::PhanSo(int t, int m)
{
	Tuso = t; Mauso = m;
}


void PhanSo::Nhap()
{
	cout<<"\n Nhap Tu so "; cin>>Tuso;
	cout<<"\n Nhap Mau so "; cin>>Mauso;
	while(Mauso==0)
	{
		cout<<"\n Mau so phai khac 0 - Nhap lai Mau so : ";cin>>Mauso;
	};
}

int PhanSo::XetDau()
{
	if(Tuso*Mauso>0)
		return 1;
	if(Tuso*Mauso<0)
		return -1;
	return 0;
}

void PhanSo::Xuat()
{
	if (XetDau()==-1 )
		if (Mauso<0) 
		{
			Tuso= Tuso*(-1); 
			Mauso=abs(Mauso);
		}
		if (XetDau()==1)
			if (Tuso<0)
			{
				Tuso= abs(Tuso);
				Mauso=abs(Mauso);
			}
	cout<<Tuso<<"/"<<Mauso<<" ";
}

//int k= Uscln(Tuso,Mauso);
int PhanSo::Uscln(int a, int b)
{
	a=abs(a);
	b=abs(b);
	if (a == b) return a;
	else
	{
		while(a!=0 && b!=0)
		{
			if (a>b) a-=b;
			else b-=a;
		}
		if(a==0) return b;
		else return a;
	}
}


int PhanSo::Bscnn(int a, int b)
{
	int k = Uscln(a,b);
	return a*b/k;
}

//b.RutGon(); b.Xuat();
void PhanSo::RutGon()
{
	int k = Uscln(Tuso,Mauso);
	Tuso = Tuso/k;
	Mauso = Mauso/k;
}


float PhanSo::GiatriPS()
{
	return (float) (Tuso)/(float)(Mauso);
}


int PhanSo::KtDuong()
{
	if (Tuso*Mauso > 0)
		return 1;
	return 0;
}

PhanSo PhanSo::Cong(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso+Mauso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	RutGon();
	return tam;
}


//Gan
/*
PhanSo PhanSo::operator= (PhanSo &p)
{	
	Tuso=p.Tuso;
	Mauso=p.Mauso;
	return *this;
}
*/


//CAC PHUONG THUC THUOC LOP MangPhanSo
void MangPhanSo::Nhap()
{
	cout <<"\n Nhap n : "; cin >> n;
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]: ";
		a[i].Nhap();
	}
}

void MangPhanSo::Xuat()
{
	for (int i=0;i<n;i++)
	{
		a[i].Xuat();
		cout << " ";
	}
}

