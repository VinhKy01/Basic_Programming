#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	for(int i=1;i<30;i++)
	{
		int res = rand()%(11);
		cout<<"	"<<res;
	}
	
	system("pause");
	return 0;
}
