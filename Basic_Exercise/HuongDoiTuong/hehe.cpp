#include	<iostream>
#include	<math.h>
#include	<conio.h>

#define pi 3.14

using namespace std;

class Diem{
	private:
		float x, y;
	public:
		Diem();
		Diem(float a, float b);
		Diem(const Diem &s);
		void Nhap();
		void Xuat();
		float getX();
		float getY();
};

class Elip{
	private:
		Diem tam;
		float a, b, cv, dt;
	public:
		Elip();
		Elip(Diem tam, float a, float b);
		Elip(const Elip &x);
		void Nhap();
		void Xuat();
		Diem getTam();
		float getA();
		float getB();
		float getCV();
		float getDT();
		void TinhCV();
		void TinhDT();
};

class MangElip{
	private: 
		Elip a[100];
		int n;
	public:
		MangElip();
		void Nhap();
		void Xuat();
		// de le
		float TongDTCacHinhElipCoChuViLonHon9();
		void LietKeCacHinhElipCoHoanhDoTungDoLonHon0();
		void SapXepTangDanTheoBanKinhNgan();
		
		//de chan
		void LietKeCacHinhElipCoDienTichHon10();
		float TinhTrungBinhCacCHuViCoTamNamTrenTrucHoanh();
		void SapXepTangDanTheoDienTich();

};

int main(){
	MangElip ds;
	ds.Nhap();
	ds.Xuat();
////	de le
//	cout << "\nTong dien tich cac elip co chu vi lon hon 9 = " << ds.TongDTCacHinhElipCoChuViLonHon9();
//	
//	ds.LietKeCacHinhElipCoHoanhDoTungDoLonHon0();
//	
//	ds.SapXepTangDanTheoBanKinhNgan();
//	cout << "\nMang sau sap xep theo ban kinh ngan: " << endl;
//	ds.Xuat();
//	
	
	// de chan
	ds.LietKeCacHinhElipCoDienTichHon10();
	
	if(ds.TinhTrungBinhCacCHuViCoTamNamTrenTrucHoanh() == 0)
		cout << "\nKhong co elip nao co tam tren tru hoanh";
	else
		cout << "\nTrung binh chu vi cac elip co tam tren truc hoanh = "<< ds.TinhTrungBinhCacCHuViCoTamNamTrenTrucHoanh() << endl;
	
	ds.SapXepTangDanTheoDienTich();
	cout << "\nMang sau sap xep theo dien tich: " << endl;
	ds.Xuat();
	getch();
	return 0;
}

//----------------------Diem--------------------------
Diem::Diem(){
	x= y= 0;
} 
Diem::Diem(float a, float b){
	x = a;
	y = b;
}
Diem::Diem(const Diem &s){
	x = s.x;
	y = s.y;
}
void Diem::Nhap(){
	cout << "\nNhap x: ";
	cin >> x;
	cout << "\nNhap y: ";
	cin >> y;
}

void Diem::Xuat(){
	cout << "  (" << x << ";" << y << ")  " ;
}

float Diem::getX(){
	return x;
}

float Diem::getY(){
	return y;
}

//----------------------------------Hinh elip-----------------------------
Elip::Elip(){
	tam = Diem();
	a = b = 0;
}

Elip::Elip(Diem x, float a, float b){
	tam = x;
	a=a;
	b=b;
}

Elip::Elip(const Elip &x){
	tam = x.tam;
	a = x.a;
	b = x.b;
}

void Elip::Nhap(){
	cout << "\nNhap tam: ";
	tam.Nhap();
	cout << "Nhap 2 ban kinh: ";
	cin >> a >> b;
	if( a > b){
		float t = a;
		a = b;
		b = t;
	}
	TinhCV();
	TinhDT();
}

void Elip::Xuat(){
	cout << "\nTam: ";
	tam.Xuat();
	cout << "\nBan kinh: a = " << a << ", b = " << b;
	cout << "\nChu vi = " << cv << ", Dien tich = " << dt << endl;
}

Diem Elip::getTam(){
	return tam;
}

float Elip::getA(){
	return a;
}

float Elip::getB(){
	return b;
}

float Elip::getCV(){
	return cv;
}

float Elip::getDT(){
	return dt;
} 

void Elip::TinhCV(){
	cv = 2*pi*(sqrt(a*a + b*b)/2);
}

void Elip::TinhDT(){
	dt =pi*a*b;
}

//--------------------------Mang Elip-------------------------------
MangElip::MangElip(){}

void MangElip::Nhap(){
	cout << "\nNhap so elip: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "\nNhap elip thu " << i + 1<< endl;
		a[i].Nhap();
	}
}

void MangElip::Xuat(){
	for(int i = 0; i < n; i++){
		cout << "\nElip thu " << i + 1<< endl;
		a[i].Xuat();
	}
}

float MangElip::TongDTCacHinhElipCoChuViLonHon9(){
	float tong = 0;
	for(int i = 0; i < n; i++){
		if(a[i].getCV() > 9){
			tong = tong + a[i].getDT();
		}
	}
	return tong;
}

void MangElip::SapXepTangDanTheoBanKinhNgan(){
	Elip t;
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i].getA() > a[j].getA())
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

void MangElip::LietKeCacHinhElipCoHoanhDoTungDoLonHon0(){
	cout << "\nCac elip co hoanh do va tung do lon > 0: " << endl;
	for(int i = 0; i < n; i++)
		if(a[i].getTam().getX() > 0 && a[i].getTam().getY() > 0 )
			a[i].Xuat();
}

void MangElip::LietKeCacHinhElipCoDienTichHon10(){
	cout << "\nCac elip co dien tih > 10: " << endl;
	for(int i = 0; i < n; i++)
		if(a[i].getDT() > 10 )
			a[i].Xuat();
}

float MangElip::TinhTrungBinhCacCHuViCoTamNamTrenTrucHoanh(){
	float tong = 0;
	int dem = 0; 
	for(int i = 0; i < n; i++){
		if(a[i].getTam().getY() == 0){
			tong = tong + a[i].getCV();
			dem ++;
		}
	}
	if(dem == 0)
		return 0;
	return tong/dem;
}

void MangElip::SapXepTangDanTheoDienTich(){
	Elip t;
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i].getDT() > a[j].getDT())
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}






