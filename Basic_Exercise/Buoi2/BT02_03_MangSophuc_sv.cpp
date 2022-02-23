#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class SoPhuc
{
	private:
		float Thuc, Ao;
	public:
		SoPhuc(); // Constructor mac dinh
		SoPhuc(float R,float I);
		SoPhuc (const SoPhuc & Z); // Constructor sao chep
		SoPhuc (float R); // Constructor chuyen doi
		void Nhap();  //Nhap so phuc
		void Xuat(); // Hien thi so phuc
		//float getThuc();
		//float getAo();
		//void setThuc(int t);
		//void setAo(int a);
		
		// Cac tinh toan 
		SoPhuc operator + (SoPhuc Z);
		//SoPhuc operator - (SoPhuc Z);
		//SoPhuc operator * (SoPhuc Z);
		//SoPhuc operator / (SoPhuc Z);
		
		//Ham tinh toan 
		SoPhuc Cong(SoPhuc Z);
		//SoPhuc Tru(SoPhuc Z);
		//SoPhuc Nhan(SoPhuc Z);
		//SoPhuc Chia(SoPhuc Z);
		
		//int LonHon(SoPhuc Z);  
    	//int NhoHon(SoPhuc Z);  
	   	//int Bang(SoPhuc Z);  
		
		// Cac tinh toan so sanh
		////int operator == (SoPhuc Z);
		//int operator != (SoPhuc Z);
		//int operator > (SoPhuc Z);
		//int operator >= (SoPhuc Z);
		//int operator < (SoPhuc Z);
		//int operator <= (SoPhuc Z);
	
		float Module(); // Giá tri tuyet doi cua so phuc
		
		//Cac ham kiem tra
		//int ThuanAo();
		//int ThuanThuc();
		
		
};

class MangSoPhuc
{
	private:
		SoPhuc a[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		
		//..cac phuong thuc cn lai
		
};


int main()
{
	MangSoPhuc x;
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac So phuc trong Mang: ";
	x.Nhap();
	cout<<"Thong tin cac So phuc trong Mang: ";
	x.Xuat();
	
	//..Them code 
	
	getch();
	return 1;

}


SoPhuc::SoPhuc()
{
	Thuc = 0.0;
	Ao = 0.0;
}

SoPhuc::SoPhuc(float R,float I)
{
	Thuc = R;
	Ao = I;
}

SoPhuc::SoPhuc(const SoPhuc & Z)  //Ham dung sao chep
{
	Thuc = Z.Thuc;
	Ao = Z.Ao;
}

SoPhuc::SoPhuc(float R) 
{
	Thuc = R;
	Ao = 0.0;
}

void SoPhuc::Nhap()
{
	cout<<"\n Nhap phan thuc "; cin>>Thuc;
	cout<<"\n Nhap phan ao "; cin>>Ao;

}


void SoPhuc::Xuat()
{
	cout<<"(" << Thuc << " + " << Ao << "i)";
}



/*
Cho hai so phuc z = a + bi và w = c + di.
Phep Cong:  z+w  = (a +c) + (b+d)i
Phep Tru:  z-w  = (a +c) - (b+d)i
Phep Nhan:  z.w  = (a * c - b * d) + (a * d + b * c)i
Phep Chia:  z/w   = [(a * c + b * d) / (c * c + d * d)] + (b * c - a * d)i
*/

SoPhuc SoPhuc::Cong(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc + Z.Thuc;
	Tmp.Ao = Ao + Z.Ao;
	return Tmp;
}


float SoPhuc::Module()
{
	return sqrt(Thuc*Thuc+Ao*Ao);
}



//CAC PHUONG THUC THUOC LOP MangSoPhuc
void MangSoPhuc::Nhap()
{
	cout <<"\n Nhap n : "; cin >> n;
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]: ";
		a[i].Nhap();
	}
}

void MangSoPhuc::Xuat()
{
	for (int i=0;i<n;i++)
	{
		a[i].Xuat();
		cout << " ";
	}
}


		
