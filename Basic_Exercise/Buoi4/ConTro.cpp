#include<iostream>

using namespace std;

int main()
{
	int a = 2409;    // gi? s? d?a ch? � nh? c?a a l� 0x50
	int *ptr_a = &a; // tr? con tr? ptr_a t?i bi?n a
	*ptr_a = 2001;   // thay d?i gi� tr? t?i � nh? m� con tr? ptr_a dang gi?
	cout << a <<endl;
	cout<<ptr_a; 
		
}
