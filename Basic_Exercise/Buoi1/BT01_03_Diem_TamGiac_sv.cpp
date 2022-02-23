//V01 -Tam Giac duoc tao boi 3 dinh A, B va C
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Diem
{
	private:
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
{
	protected:
		Diem A,B,C;
		float dt;
		float cv;
	public:
		TamGiac();
		void Nhap();
		void Xuat();
		//TamGiac(Diem d1, Diem d2, Diem d3);
		//..bo sung method	
	
};


int main()
{
	TamGiac tg;
	tg.Nhap();
	tg.Xuat();
	//cout<<"Co trong tam la "; tg.TrongTam().Xuat();
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

void TamGiac::Nhap()
{
	//...code?
}

void TamGiac::Xuat()
{
    cout<<"\nDinh thu nhat: "; A.Xuat();
    cout<<"\nDinh thu hai: "; B.Xuat();
    cout<<"\nDinh thu ba: "; C.Xuat();
	cout<<endl<<"Chu vi: "<<cv<<"  va dien tich= "<<dt<<endl;
}

float TamGiac::getDT()
{
	return dt;
}

float TamGiac::getCV()
{
	return cv;
}

