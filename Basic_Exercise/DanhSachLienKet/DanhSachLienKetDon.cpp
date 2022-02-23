#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *pNext;
};
typedef struct Node NODE;

struct List{
	Node *pHead;
	Node *pTail;
};

typedef struct List LIST;

void CreateLinkNode(LIST &l){
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *CreateNode(int x){
	NODE *p = new NODE;
	p->data=x;
	p->pNext=NULL;
	return p;
}

void ThemNodeDau(LIST &l, NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=NULL;
	}
	else{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}



int main(){
	
	NODE *p;
	
	
	return 0;
}
