#include<iostream>

using namespace std;

//Nhap danh sach lien ket don so nguyen
//==================KHAI BAO CAU TRUC DANH SACH LIEN LET DON==================
struct Node
{
	int data;
	struct Node *pNext;
};

typedef struct Node NODE;

struct List
{
	NODE *pHead;
	Node *pTail;
};

typedef struct List LIST;

//==================HAM KHOI TAO DANH SACH LIEN KET DON==================
void CreateLinkList(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

//KHOI TAO NODE
NODE  *CreateNode(int x)
{
	NODE *p = new NODE;
	if(p==NULL){
		cout<<"\nKhong du dung luong de tao Node";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//HAM THEM NODE P VAO DAU DANH SACH
void AddFirstList(LIST &l, NODE *p)
{
	if(l.pHead==NULL){
		l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
//HAM THEM NODE P VAO CUOI DANH SACH
void AddEndList(LIST &l,NODE *p)
{
	if(l.pHead==NULL){
		l.pHead = l.pTail = p;
	}
	else{
		
	}
}


int main()
{
	
	
	system("pause");
	return 0;
}
