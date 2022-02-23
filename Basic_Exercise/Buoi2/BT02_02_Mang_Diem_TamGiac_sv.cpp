//V01 -Tam Giac duoc tao boi 3 dinh A, B va C
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Diem
{	private:
		int x;
		int y;
	public:
		Diem();
		Diem(int h, int t);
		void Nhap();
		void Xuat();
		int getX();
		int getY();
		float KhoangCach(Diem);
};

class TamGiac 
{	protected:
		Diem A,B,C;		float dt;
		float cv;
	public:
		TamGiac();
		TamGiac(Diem d1, Diem d2, Diem d3);
		void Nhap();		
		void Xuat();
		int KiemTra();
		//void TinhDT();		
		//void TinhCV();
		float getDT();		
		float getCV();
		
};

class MangTamGiac
{	private:
		TamGiac a[100];
		int n;
	public:
		void Nhap();
		void Xuat();

};



int main()
{
	MangTamGiac mtg;
	//Nhap danh sach
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cac Tam giac trong Mang: "<<endl;
	mtg.Nhap();
	cout<<"Thong tin cac Tam giac trong Mang: ";
	mtg.Xuat();
	
	//..bo sung code 
	
	getch(); //Dung xem KQ
	return 1; //hoac return 0;
}

Diem::Diem()
{
	x=y=0;
}
Diem::Diem(int h, int t)
{
	x=h; y=t;
}

void Diem::Nhap()
{
	cout<<("\nNhap hoanh do x:"); cin>>x;
	cout<<("Nhap tung do y: "); cin>>y;
}

void Diem::Xuat()
{
	cout<<"("<<x<<","<<y<<")"; //(3,5)
}

float Diem::KhoangCach(Diem P)
{
	return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
}

int Diem::getX()
{
	return x;
}

int Diem::getY()
{
	return y;
}


//Tam giac
TamGiac::TamGiac()
{
	Diem A(0,0), B(0,0), C(0,0);
	dt=cv=0;
}

int TamGiac::KiemTra()
{
	int Kq=1; //Gia su 3 dinh bat ky deu tao thanh tam giac
    if ((A.getX()-B.getX())*(C.getY()-B.getY()) == 
       (C.getX()-B.getX())*( A.getY()-B.getY()))
      Kq=0;
    return Kq;
}


//Tam Giac
TamGiac::TamGiac(Diem d1, Diem d2, Diem d3)
{
	A=d1;
	B=d2;
	C=d3;
	//..bo sung code de kiem tra 3 dinh vua nhap co tao thanh tam giac?
}



void TamGiac::Nhap()
{
	cout<<"Nhap vao 3 dinh cua tam giac"<<endl; 
    cout<<"Nhap dinh thu nhat: "; A.Nhap();
    cout<<"Nhap dinh thu hai: "; B.Nhap();
    cout<<"Nhap dinh thu ba: "; C.Nhap();
	
	//..bo sung code de kiem tra co tao thanh tam giac?
}

void TamGiac::Xuat()
{
    cout<<"{"; A.Xuat();
    cout<<","; B.Xuat();
    cout<<","; C.Xuat();
	cout<<"}";
	cout<<" CV= "<<cv<<" va DT= "<<dt<<endl;
}



float TamGiac::getDT()
{
	return dt;
}

float TamGiac::getCV()
{
	return cv;
}


//Cac phuong thuc lop MangTamGiac

void MangTamGiac::Nhap()
{
	cout<<"Nhap so tam giac ="; cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"\nNhap tam giac thu "<<i+1<<" : \n";
		a[i].Nhap();
	}
}

void MangTamGiac::Xuat()
{
	for (int i=0;i<n;i++)
	{
		cout<<endl<<"Tam giac thu "<<i+1<<" : ";
		a[i].Xuat();
	}
	cout<<endl;
}

