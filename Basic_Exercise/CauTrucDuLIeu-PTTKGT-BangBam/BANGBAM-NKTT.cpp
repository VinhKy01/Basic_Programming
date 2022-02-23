#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//=========================KET NOI TRUC TIEP=============================

int n=10;
struct Node{
	int key;
	struct Node *next;
};
typedef struct Node node;

node *t[10];

int has(int x){
	return (x%n);
}

void XuatGiaTri(void){
	node *p;
	for(int i=0;i<n;i++){
		{
			p=t[i];
			cout<<"\nKhoa Muc: "<<i<<"  ";
		}
		if(p==NULL) cout<<" [NULL]";
		while(p!=NULL){
			cout<<"["<<p->key<<"] -> ";
			p=p->next;
		}
	}
}


int TimKiem(int x){
	node *p;
	int isFind;
	p=t[has(x)];
	isFind=0;
	while(p!=NULL){
		if(p->key==x){
			isFind=1;
			break;
		}else{
			p=p->next;
		}
	}
	return isFind;
}


void SapXepDanhSach(int i)
{
	node *P,*Q ;
	int Temp;
	{
		P=t[i];
		while(P!=NULL)
		{
			Q=P->next;
			while(Q!=NULL)
			{
				if(P->key > Q->key)
				{
					Temp =P->key;
					P->key = Q->key ;
					Q->key  = Temp;
				}
				Q=Q->next;
			}
			P=P->next;
		}
	}
	
}

void ThemGiaTri(int x){
	node *p;
	if(!TimKiem(x)){
		p=(node*)malloc(sizeof(node));
		p->key=x;
		p->next=t[has(x)];
		t[has(x)]=p;
	}
	else{
		cout<<x<<" da co trong danh sach!!!"<<endl;
	}
}

void XoaGiaTri(int x){
	int i,isFind;node *p,*q;
	i=has(x);
	if(t[i]==NULL or !TimKiem(x)) 
		cout<<x<<" ko duoc tim thay trong ds"<<endl;
	else 
		cout<<x<<" duoc tim thay va xoa thanh cong khoi ds "<<endl;
	

	if(t[i]!=NULL)
	{
		if(t[i]->key==x) {
			p=t[i];
			t[i]=t[i]->next;
			free(p);
		}
	else
	{
			q=t[i];p=q->next;isFind=0;
			while(p!=NULL&&!isFind){
				if(p->key==x){
					q->next=p->next;
					free(p);
					isFind=1;
				}
				else{
					q=q->next;
					p=p->next;
				}
			}
		}
	}
	
}


int main(){
	int i,luachon,x;
	for(int i=0;i<n;i++) 
		t[i]=NULL;
	
	do{
		cout<<"\n=========================MENU=========================";
		cout<<"\n\t\t1.CHEN VAO MOT SO";
		cout<<"\n\t\t2.NHAP VAO SO CAN XOA";
		cout<<"\n\t\t3.NHAP VAO SO CAN TIM";
		cout<<"\n\t\t4.XUAT GIA TRI";
		cout<<"\n\t\t5.KET THUC CHUONG TRINH";
		cout<<"\n\t\tNHAP VAO LUA CHON CUA BAN: ";
		cin>>luachon;
		cout<<"=========================END=========================";
		
		switch (luachon)
		{
			case 1:{
				cout<<"\nNhap: ";
				cin>>x;ThemGiaTri(x);
				break;
			}
			case 2:{
				cout<<"\nXoa: ";
				cin>>x;XoaGiaTri(x);
				break;
			}
			case 3:{
				cout<<"\nTim: ";
				cin>>x;
				if(TimKiem(x))
					cout<<x<<" tim thay trong danh sach";
				else
					cout<<x<<" khong tim thay trong danh sach";
				break;
			}
			case 4:{
				for(int i=0;i<n;i++)
				SapXepDanhSach(i);
				XuatGiaTri();
				break;
			}
			default:{
				cout<<"\n-------------KET THUC CHUONG TRINH-------------";
				break;
			}
		}	
	}while(luachon>=1 and luachon<=4);
	return 0;
}
