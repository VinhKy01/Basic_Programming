#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void NhapSN(int &a)
{
	cout<<"Nhap vao 1 so nguyen: ";
	cin>>a;
}
void XuatSN(int a)
{
	cout<<"So nguyen vua nhap la: "<<a;
}

//=============================================================

void NhapST(float &a)
{
	cout<<"\nNhap vao 1 so thuc: ";
	cin>>a;
}
void XuatST(float a)
{
	cout<<"So thuc vua nhap la: "<<a;
}

int main()
{
	int a;
	float k;
	NhapSN(a);
	XuatSN(a);
	NhapST(k);
	XuatST(k);
	return 0;
}
