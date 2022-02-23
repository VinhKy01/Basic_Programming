#include<iostream>

using namespace std;

//khai bao cau truc NODE
struct Node
{
	int data;
	struct Node* pNext;
};

typedef struct Node NODE; // Thay the struct Node thanh NODE
	//khai bao cau tru danh sach lien ket
struct List
{
	NODE* pHead;
	NODE* pTail;
};

typedef struct List LIST; // Thay the struct Node thanh NODE
void Create(LIST &l)
{
	//tro den null vi danh sach lien ket chua co pha tu
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* CreateNode(int x)
{
	NODE* p = new NODE;// cap phat bo nho cho NODE p
	if(p==NULL)
	{
		cout<<"\nBo nho may tinh cua ban da day";
		return NULL;
	}
	p->data = x; // truyen du lieu x vao data
	p->pNext = NULL; // node chua co lien ket nen = NULL
	return p;
}

void ThemVaoDauDS(LIST &l, NODE *p)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=p;// do danh sach rong
	}
	else
	{
		p->pNext = l.pHead; // 
		l.pHead = p; // cap nhat lai pHead vi them vao dau danh sach
	}
}
void ThemVaoCuoiDS(LIST &l, NODE *p)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=p;// do danh sach rong
	}
	else
	{
		l.pTail->pNext = p; // 
		l.pTail = p; // cap nhat lai pHead vi them vao dau danh sach
	}
}

void XuatDanhSachLK(LIST l)
{
	for(NODE* k = l.pHead; k!=NULL; k = k->pNext)
	{
		cout<<k->data<<"    ";
	}
}


int main()
{
	LIST l;
	Create(l);
	
	int n;
	cout<<"Nhap vao so luong NODE can them: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cout <<"Nhap vao gia tri so nguyen: ";
		cin>>x;
		NODE *p = CreateNode(x);
		ThemVaoDauDS(l,p);
	}
	XuatDanhSachLK(l);
	
	
	system("pause");
	return 0;
}
