#include<stdio.h>
#include<stdlib.h>
//de`: viet chuong trinh nhap va duyet cay nhi phan. 5	3	7	1	9	4	6	2	8

//buoc 1: khoi tao cau truc cay nhi phan

struct NODE{
	int data;	//Kieu du lieu cua cay nhi phan
	struct NODE* pLeft;//cau' tao cua~ 1 node trong ca^y nhi pha^n go^m`: data va` 2 con tro~ trai', phai~
	struct NODE* pRight;// 2 con tro~ trai',phai~ con` duoc goi la` con trai' con phai~
};
typedef struct NODE node;//doi~ te^n kieu~ du~ lie^u struct NODE thanh` node
typedef node* tree;//doi~ te^n kie^u~ du~ lie^u node* (con tro~ kie^u~ node) thanh` tree
				   //TREE : trong tieng' anh nghia~ la` Ca^y

//buoc 2: khoi~ tao ra mot cay rong~
void khoiTaoTree(tree &t); //dau' & de luu lai thay doi~
//buoc 3: Them node vao cay.
void themNodeVaoCay(tree &t,int giaTriNode);
//buoc 4: duye^t ca^y
void duyetNLR(tree t);
void duyetNRL(tree t);
void duyetLNR(tree t);
void duyetRNL(tree t);
void duyetLRN(tree t);
void duyetRLN(tree t); 
//buoc 5: menu nha^p xua^t': ham` nay` kho^ng co' gi` hot' lam` ra chi~ de~ chay. ma^y' ham` kia thoi
void menu(tree &t);

bool kiemTraSNT(int x);
void demVaLietKeSNT(tree t,int &count);
void timKiem(tree t,int giaTriCanTim);
void lietKeCacNutCo2Con(tree t);
void lietKeCacNutCo1Con(tree t);
void lietKeCacNutCo0Con(tree t);
void timMin(tree t);
void timMax(tree t);
void xoaNodeBatKy(tree &t,int giaTriCuaNodeCanXoa);
void hamTimNodeBeNhatBenPhaiDeXoa(node* &nodeTheMang,node* &nhanhPhai);
void hamTimNodeLonNhatBenTraiDeXoa(node* &nodeTheMang,node* &nhanhTrai);
int main()
{
	tree t;
	khoiTaoTree(t);//co' ham` nay` moi' bie^t' duoc ca^y ban da^u` rong~ de~ thao tac'
	menu(t);
	return 0;
}
//buoc 5: menu nha^p xua^t' ham` nay` kho^ng co' gi` hot' lam` ra chi~ de~ chay. ma^y' ham` kia thoi
void menu(tree &t)
{
	int luaChon;
	while(true)
	{
		printf("\n\n\t==================== MENU ====================");
		printf("\n\t\tphim 1:The^m node vao` ca^y nhi pha^n");
		printf("\n\t\tphim 2:Duye^t theo kie^u~ node left right(tien` tu).");
		printf("\n\t\tphim 3:Duyet theo kieu~ node right left(tien` tu).");
		printf("\n\t\tphim 4:Duyet theo kieu left node right(trung tu).");
		printf("\n\t\tphim 5:Duyet theo kieu right node left(trung tu).");
		printf("\n\t\tphim 6:Duyet theo kieu left right node(hau tu).");
		printf("\n\t\tphim 7:Duyet theo kieu right left node(hau tu).");
		printf("\n\t\tphim ");
		printf("\n\t\tphim 8:Dem va liet ke so nguyen to co trong cay..");
		printf("\n\t\tphim 9:Tim kiem gia tri bat bi trong cay nhi phan.");
		printf("\n\t\tphim 10:Liet cac cac gia tri cua nut co 2 con");
		printf("\n\t\tphim 11:Liet cac cac gia tri cua nut co 1 con");
		printf("\n\t\tphim 12:Liet cac cac gia tri cua nut co 0 con");
		printf("\n\t\tphim 13:Tim min.");
		printf("\n\t\tphim 14:Tim max");
		printf("\n\t\tphim 15:Xoa node bat ki");
		printf("\n\t\tphim 0: ke^t thuc chuong trinh`");
		printf("\n\n\t==============================================");
		printf("\nNhap vao lua chon cua ban: ");
		scanf("%d",&luaChon);
		if(luaChon==1)
		{
			int giaTri;
			printf("\nNhap gia tri cho node can them: ");
			scanf("%d",&giaTri);
			themNodeVaoCay(t,giaTri);
		}
		else if(luaChon==2)
		{
			duyetNLR(t);
		}
		else if(luaChon==3)
		{
			duyetNRL(t);
		}
		else if(luaChon==4)
			duyetLNR(t);
		else if(luaChon==5)
			duyetRNL(t);
		else if(luaChon==6)
			duyetLRN(t);
		else if(luaChon==7)
			duyetRLN(t);
		else if(luaChon==8)
		{
			int count=0;
			printf("\ncac so nguyen to co trong cay nhi phan la: ");
			demVaLietKeSNT(t,count);
			printf("\nso luong so nguyen to la: %d",count);
		}
		else if(luaChon==9)
		{
			int x;
			printf("\nNhap gia tri can tim trong cay nhi phan: ");
			scanf("%d",&x);
			timKiem(t,x);
		}
		else if(luaChon==10)
		{
			printf("\nCac gia tri co 2 con trong cay nhi phan la: ");
			lietKeCacNutCo2Con(t);
		}
		else if(luaChon==11)
		{
			printf("\nCac gia tri cua nut co 1 con la: ");
			lietKeCacNutCo1Con(t);
		}
		else if(luaChon==12)
		{
			printf("\nCac gia tri cua nut co 0 con la: ");
			lietKeCacNutCo0Con(t);
		}
		else if(luaChon==13)
			timMin(t);
		else if(luaChon==14)
			timMax(t);
		else if(luaChon==15)
		{
			int x;
			printf("\nNhap vao gia tri cua node can xoa: ");
			scanf("%d",&x);
			xoaNodeBatKy(t,x);
		}
		else
			break;
	}
}
void hamTimNodeBeNhatBenPhaiDeXoa(node* &nodeTheMang,node* &nhanhPhai)//vi ham nay thay doi su lien ket cua cac con tro thi ta phai tham chieu de luu
{
	if(nhanhPhai->pLeft!=NULL)
		hamTimNodeBeNhatBenPhaiDeXoa(nodeTheMang,nhanhPhai->pLeft);
	else
	{
		nodeTheMang->data = nhanhPhai->data; // cap nhat gia tri node CAN XOA voi node be nhat ben
											 // phai~
											 // cap nhat duoc vi nodeTheMang->data la gia tri
											 // cua con tro
		nodeTheMang=nhanhPhai; // cho node the mang tro den node be nhat ben phai
		nhanhPhai=nhanhPhai->pRight; // cap nhat lai lien ket
									 // cap nhat duoc la vi tham so truyen vao cua ham nay 
									 // la gia tri cua con tro
	}
}
void hamTimNodeLonNhatBenTraiDeXoa(node* &nodeTheMang,node* &nhanhTrai) //vi ham nay thay doi su lien ket cua cac con tro thi ta phai tham chieu de luu
{// nhu ham kia khoi cmt
	if(nhanhTrai->pRight!=NULL)
		hamTimNodeLonNhatBenTraiDeXoa(nodeTheMang,nhanhTrai->pRight);
	else
	{
		nodeTheMang->data=nhanhTrai->data; 
		nodeTheMang=nhanhTrai;
		nhanhTrai=nhanhTrai->pLeft;
	}
}
void xoaNodeBatKy(tree &t,int giaTriCuaNodeCanXoa)
{
	if(t==NULL)
		return;
	if(giaTriCuaNodeCanXoa > t->data)
		xoaNodeBatKy(t->pRight,giaTriCuaNodeCanXoa);
	else if(giaTriCuaNodeCanXoa < t->data)
		xoaNodeBatKy(t->pLeft,giaTriCuaNodeCanXoa);
	else// da tim duoc node can xoa
	{
		node *x=t;//node x la node the mang
		if(t->pLeft==NULL)//day la nut la' hoac nut co 1 con phai~
		{
			t=t->pRight;// cap nhat lien ket
						// cap nhat duoc vi tham so truyen vao ham nay la gia tri cua con
						// nhu da biet thi cac con tro co su lien ket voi nhau
						// neu ta thay doi gia tri cua mot trong so chung thi tat ca deu 
						// thay doi
		}
		else if(t->pRight==NULL)//day la nut la' hoac nut co 1 con trai'
		{
			t=t->pLeft;// cap nhat lien ket
					   // giai thich: nhu tren
		}
		else // day la nut co 2 con
		{
			hamTimNodeBeNhatBenPhaiDeXoa(x,t->pRight); // cach 1 chon nut thay the la nut
													   // BE nhat ben phai
//			hamTimNodeLonNhatBenTraiDeXoa(x,t->pLeft); // cach 2 chon nut thay the la nut
													   // LON nhat ben trai
		}
		free(x);// sau khi da cap nhat lai lien ket thi xoa node the mang thoi
	}
}
void timMin(tree t)
{
	if(t==NULL)
	{
		printf("\nCay rong~");
		return;
	}
	if(t->pLeft!=NULL)
	{
		timMin(t->pLeft);
	}
	else
		printf("\nGia tri nho nhat cua cay la: %d",t->data);
}
void timMax(tree t)
{
	if(t==NULL)
	{
		printf("\nCay rong~");
		return;
	}
	if(t->pRight!=NULL)
	{
		timMax(t->pRight);
	}
	else
		printf("\nGia tri lon nhat cua cay la: %d",t->data);
}
void lietKeCacNutCo1Con(tree t)
{
	if(t!=NULL)
	{
		if((t->pLeft!=NULL && t->pRight==NULL) || (t->pLeft==NULL && t->pRight!=NULL))
			printf("%5d",t->data);
		lietKeCacNutCo1Con(t->pLeft);
		lietKeCacNutCo1Con(t->pRight);
	}
}
void lietKeCacNutCo0Con(tree t)
{
	if(t!=NULL)
	{
		if((t->pLeft==NULL && t->pRight==NULL))
			printf("%5d",t->data);
		lietKeCacNutCo0Con(t->pLeft);
		lietKeCacNutCo0Con(t->pRight);
	}
}
void lietKeCacNutCo2Con(tree t)
{
	if(t!=NULL)
	{
		if(t->pLeft!=NULL && t->pRight!=NULL)
			printf("%5d",t->data);
		lietKeCacNutCo2Con(t->pLeft);
		lietKeCacNutCo2Con(t->pRight);
	}
}
void timKiem(tree t,int giaTriCanTim)
{
	if(t==NULL)
	{
		printf("\nGia tri can tim khong co trong cay.");
	}
	else if(giaTriCanTim < t->data)
	{
		timKiem(t->pLeft,giaTriCanTim);
	}
	else if(giaTriCanTim > t->data)
	{
		timKiem(t->pRight,giaTriCanTim);
	}
	else 
	{
		printf("\nGia tri can tim la: %d", t->data);
	}
}
bool kiemTraSNT(int x)
{
	int count=0;
	for(int i=1;i<=x/2;i++)
		if(x%i==0)
			count++;
	if(count==1)
		return true;
	return false;
		
}
void demVaLietKeSNT(tree t,int &count)
{
	if(t!=NULL)
	{
		if(kiemTraSNT(t->data)==true)
		{
			printf("%5d",t->data);
			count++;
		}
		demVaLietKeSNT(t->pLeft,count);
		demVaLietKeSNT(t->pRight,count);
	}
}
//buoc 4: duye^t ca^y
void duyetLRN(tree t)//uu tien thang cuoi cung nhanh ben trai sau do' toi' phan tu cuoi cung` nhanh ben phai~ dai` len
{
	if(t!=NULL)
	{
		duyetLRN(t->pLeft);
		duyetLRN(t->pRight);
		printf("%5d",t->data);
	}
}
void duyetRLN(tree t)
{
	if(t!=NULL)
	{
		duyetRLN(t->pRight);
		duyetRLN(t->pLeft);
		printf("%5d",t->data);
	}
}
void duyetLNR(tree t)//uu tien thang be nhat cay.
{
	if(t!=NULL)
	{
		duyetLNR(t->pLeft);
		printf("%5d",t->data);
		duyetLNR(t->pRight);
	}
}
void duyetRNL(tree t)
{
	if(t!=NULL)
	{
		duyetRNL(t->pRight);
		printf("%5d",t->data);
		duyetRNL(t->pLeft);
	}
}
void duyetNRL(tree t)//uu tien node va cac nut ben phai.
{
	if(t!=NULL)
	{
		printf("%5d",t->data);
		duyetNRL(t->pRight);
		duyetNRL(t->pLeft);
	}
}
void duyetNLR(tree t)//ham` nay` ma` cmt ky~ thi` khoc' luo^n
					 //muo^n' hie^u~ thi` tu chay tay, de^. quy la` ez a`
					 //luc' dang viet cai' cmt nay` thi` tao da hie^u~ roi` hihi
{
	if(t!=NULL)
	{
		printf("%5d",t->data);
		duyetNLR(t->pLeft);
		duyetNLR(t->pRight);
	}
}
//buoc 3: Them node vao cay.
void themNodeVaoCay(tree &t,int giaTriNode)
{
	//cau hoi~ dat ra:
	// vi` sao bie^t' t==NULL hay kho^ng
	// vi` o ham` khoi~ tao. ca^y ta da~ cho tree = NULL
	if(t==NULL)
	{
		node *p=(node*)realloc(NULL,1*sizeof(node*));//cap phat vung nho cho con tro
													 //truong` hop nay` chi~ cap' phat' vung` nho' cho
													 //mo^t con tro~ thoi nen khoi~ ghi 1* cung~ duoc.
													 //tham so truyen vao "NULL" o ham` reallloc co
													 //nghia~ la` con tro~ chua co' vung` nho' chung ta 
													 //cap' phat' vung` nho' moi' cho no'
													 //con` ne^u' truyen` vao` te^n mo^t con tro~ thi
													 //con tro~ do' da~ co gia' tri va` chung' ta cap phat'
													 //vung` nho khac cho no'
													 //dong` thoi` xoa vung` nho' cu~
		// sai` ham` realloc de nho lai thoi that ra ta sai ham cap phat nao cung duoc
//cach 2		//node *p=(node*)malloc(soLuongPhanTuCapPhat*sizeof(node*));
//cach 3		//node *p=(node*)calloc(soLuongPhanTuCapPhat,sizeof(node*));
		p->data = giaTriNode;//gan' gia' tri vao` cho node p
		p->pLeft=NULL;	//vi` moi' the^m vao` ne^n node chua co' con nao` ca~ ne^n
						//con tro~ left va right deu`   = NULL; 
		p->pRight=NULL;
		t=p; // cho con tro~ t tro~ de^n' con tro~ p
			 //co' nghia~ la` 2 con tro~ nay da~ lie^n ke^t' voi' nhau
			 //va` giong' nhau tat ca moi thu' tru` dia chi~	
	}
	else if(giaTriNode < t->data)// nêu' node khác NULL và giaTriNode bé hon t->data
	{
		themNodeVaoCay(t->pLeft,giaTriNode);//goi dê quy dê~ xet' node con trai' cua t ban dau` xem 
											//co rong~ hay khong de them vao
											//cu. the~ thi` xem trong file word 
											//kiem' file word trong thu muc ghi chu' hoc ki` 1
	}
	else if(giaTriNode > t->data)
	{
		themNodeVaoCay(t->pRight,giaTriNode);//tuong tu nhu tre^n nhung ta the^m o~ con ben phai~	
	}
}
//buoc 2: khoi~ tao ra mot cay rong~
void khoiTaoTree(tree &t)
{
	t=NULL;//khi moi' khoi~ tao ra thi` ca^y dang rong~ nen t=NULL;
}
