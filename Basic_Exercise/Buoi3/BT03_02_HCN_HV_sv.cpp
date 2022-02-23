//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace  std;

//Class Hinh chu nhat
class HinhCN 
{
	private:
		float dai;
		float rong;
		float dt;  
		float cv;
	public:
		HinhCN();
		HinhCN(float d, float r);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		//float getCV();
		//float getDT();
		//float getDai();
		//float getRong();
		//..cac phuong thuc khac
};


//Hinh vuong
class HinhVuong:public HinhCN
{
	private: 
		float canh;
		//ke thua dt, cv tu HCN

	public:
		HinhVuong();
		HinhVuong(float c);
		void Nhap();
		void Xuat();
		//void TinhDT();
		//void TinhCV();
		//float getCV();
		//float getDT();
		float getCanh();
};

int main()
{
	HinhCN	hcn[50];
	//HinhVuong hv[50];
	int n,m;
	cout<<"So luong Hinh CN: "; cin>>n;
	for(int i=0; i<n;i++)
		hcn[i].Nhap();
		
	cout<<"Thong tin cac  Hinh CN: "<<endl;
	for(int i=0; i<n;i++)
		hcn[i].Xuat();
	
	//..Them code
	
	
	getch();
	return 1;
}

//Cac phuong thuc Hinh CN
HinhCN::HinhCN()
{
	dai = rong = dt=cv=0;
}
HinhCN::HinhCN(float d,float r)
{
	dai=d; rong=r;
}

void HinhCN::Nhap()
{
	cout<<"nhap do dai canh dai: "; cin>>dai;
	cout<<"nhap do dai canh rong: "; cin>>rong;
	//..Them code
}
void HinhCN::Xuat()
{
	cout<<"canh dai: "<<dai<<" canh rong: "<<rong;
	cout<<" Chu vi: "<<cv<<" Dien tich: "<<dt<<endl;
}

void HinhCN::TinhDT()
{
	dt=(dai*rong);
}

void HinhCN::TinhCV()
{
	cv= (dai+rong)*2;
}


//Cac phuong thuc cua Hinh Vuong


