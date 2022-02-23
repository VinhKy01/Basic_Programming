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

#define Pi 3.14
//Class Eclipse
class Eclipse 
{
	private:
		float r1;
		float r2;
		float dt;  
		float cv;
	public:
		Eclipse();
		Eclipse(float r1, float r2);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		//float getCV();
		//float getDT();
		//float getR1();
		//float getR2();
		//..cac phuong thuc khac
};


//Hinh vuong
class Circle:public Eclipse
{
	private: 
		float r;
		//ke thua dt, cv tu HCN

	public:
		Circle();
		Circle(float r);
		void Nhap();
		void Xuat();
		//void TinhDT();
		//void TinhCV();
		//float getCV();
		//float getDT();
		//float getr();
};

int main()
{
	Eclipse	he[50];
	//Circle hc[50];
	int n,m;
	cout<<"So luong Hinh Eclipse: "; cin>>n;
	for(int i=0; i<n;i++)
		he[i].Nhap();
		
		cout<<"Thong tin cac  Hinh Eclipse: "<<endl;
	for(int i=0; i<n;i++)
		he[i].Xuat();
	//bo sung code	
	
	getch();
	return 1;
}

//Cac phuong thuc Hinh CN
Eclipse::Eclipse()
{
	r1 = r2 = dt=cv=0;
}
Eclipse::Eclipse(float d,float r)
{
	r1=d; r2=r;
}

void Eclipse::Nhap()
{
	cout<<"nhap do r1 r r1: "; cin>>r1;
	cout<<"nhap do r1 r r2: "; cin>>r2;
	//..Them code
}
void Eclipse::Xuat()
{
	cout<<"r1: "<<r1<<" r2: "<<r2;
	cout<<" CV: "<<cv<<" DT: "<<dt<<endl;
}

void Eclipse::TinhDT()
{
	dt= Pi* r1 *r2;
}

void Eclipse::TinhCV()
{
	cv= (sqrt((r1*r1+r2*r2)/2));
}



//Cac phuong thuc Hinh Tron




