#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <math.h>
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
		
		void Nhap();  //Nhap so phuc
		void Xuat(); // Hien thi so phuc
		float Module(); // Giá tri tuyet doi cua so phuc		
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
		
		int LonHon(SoPhuc Z);  
    	//int NhoHon(SoPhuc Z);  
	   	//int Bang(SoPhuc Z);  
	   	
	   	int operator > (SoPhuc Z);
		
};




int main()
{
	SoPhuc sp1, sp2, sp3;
    
    cout <<"\n 2 so phuc: "; 
    sp1.Nhap();
    sp2.Nhap();
    
    cout <<"\n thong tin 2 so phuc: "; 
    sp1.Xuat();
    sp2.Xuat();
    cout <<"\n Module cua 2 so phuc vua nhap: ";
    cout<<"\n Module sp1 = "<<sp1.Module();
    cout<<"\n Module sp2 = "<<sp2.Module();

    cout<<"\n Thuc hien cac phep toan bang ham thanh vien"<<endl;
    sp3 = sp1.Cong(sp2);
    cout<<"\n Tong 2 so phuc "; sp3.Xuat();
    
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


void SoPhuc::Nhap()
{
	cout<<"\n Nhap phan thuc "; cin>>Thuc;
	cout<<"\n Nhap phan ao "; cin>>Ao;

}

void SoPhuc::Xuat()
{
	cout<<"(" << Thuc << " + " << Ao << "i) ";
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

int SoPhuc::LonHon(SoPhuc Z)
{
	return Module() > Z.Module();
}


int SoPhuc::operator > (SoPhuc Z)
{
	return Module() > Z.Module();
}


SoPhuc SoPhuc::operator + (SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc + Z.Thuc;
	Tmp.Ao = Ao + Z.Ao;
	return Tmp;
}
