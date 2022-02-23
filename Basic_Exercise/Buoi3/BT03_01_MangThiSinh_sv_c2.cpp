//Mang cac doi tuong 
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class Thisinh
{
	private:
		char Maso[12];
		char Hoten[40];
		float Diemlt, Diemth, Dtb;
		char Ketqua[20];
	public:
		Thisinh(); 
		void Nhap();
		void TinhDTB();
		void Xuat();
		
		//.. bo sung code
		
};


int main()
{
	Thisinh mts[100];
	int n;
	char masoct[12];
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac Thi sinh: ";
	cout <<"\nSo luong Thi sinh : "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap Thi sinh thu "<<i+1<<" : "<<endl;
		mts[i].Nhap();
	}
	
	cout<<"Thong tin cac Thi sinh: ";
	for (int i=0;i<n;i++)
	{
		mts[i].Xuat();
		cout <<endl;
	}
	
	


	//..Them code 
	
	getch();
	return 1;

}


//Cac phuong thuc lop Thisinh
Thisinh::Thisinh()
{
	strcpy(Maso,"");
	strcpy(Hoten,"");
	Diemlt=Diemth=Dtb=0;
	
}

void Thisinh::Nhap()
{
	cout<<"Ma so thi sinh: "; gets(Maso);
	cout<<"Ho ten thi sinh: "; gets(Hoten);
	cout<<"Diem ly thuyet: "; cin>>Diemlt;
	cout<<"Diem thuc hanh: "; cin>>Diemth;
	cin.ignore();
}

void Thisinh::Xuat()
{
	cout<<endl<<"Ma so: "<<Maso;
	cout<<" - Ho ten: "<<Hoten; 
	cout<<" - Diem LT : "<<Diemlt;
	cout<<" - Diem TH: "<<Diemth;
	cout<<" - DTB = "<<Dtb;
}

void Thisinh::TinhDTB()
{
	Dtb= (Diemlt + Diemth*2)/3;
}




