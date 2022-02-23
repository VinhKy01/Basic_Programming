#include<iostream>

using namespace std;

int main()
{
	int a = 2409;    // gi? s? d?a ch? ô nh? c?a a là 0x50
	int *ptr_a = &a; // tr? con tr? ptr_a t?i bi?n a
	*ptr_a = 2001;   // thay d?i giá tr? t?i ô nh? mà con tr? ptr_a dang gi?
	cout << a <<endl;
	cout<<ptr_a; 
		
}
