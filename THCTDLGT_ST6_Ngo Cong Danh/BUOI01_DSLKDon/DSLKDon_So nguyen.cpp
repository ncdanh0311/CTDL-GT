/*
Họ và tên:Ngô Công Danh
Lớp:THCTDL&GT ST6
*/
// Khai báo thư viện
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
//================================================
//Khai bao kiểu dữ liệu
typedef int Itemtype;// Khai báo kiểu dữ liệu người dùng
struct SNode{
	Itemtype Info;// Lưu thông tin của nút
	SNode *Next;// Con trỏ chỉ đên nút kế sau
};
struct SList{
	SNode *Head;
	SNode *Tail;
};
//================================================
// Khai báo nguyên mẫu hàm
void Menu();
void process();
SNode*createSNode(Itemtype x);
void showSNode(SNode *p);
void initSList(SList &sl);
int isEmpty(SList sl);
void showSlist(SList sl);
void createSList_ByHand(SList &sl);
void createSList_Random(SList &sl);
int insertHead(SList &sl,SNode *p);
int insertTail(SList &sl, SNode* p);
int insertAfter(SList &sl, SNode *p,SNode *q);
SNode* findSNode(SList SL, Itemtype x);
void Swap(Itemtype& a, Itemtype& b);
void Interchange_Sort_Tang(SList& sl);
void Interchange_Sort_Giam(SList& sl);
int Add_before_y(SList& sl, SNode* p, int y);
bool checkPrime(int n);
int countPrime(SList& sl);
int checkChinhPhuong(int n);
int sumChinhPhuong(SList sl);
int Max(SList sl);
int Min(SList sl);
int countDouble(SList sl);
void create_SL1_SL2(SList sl);


//================================================

//MENU
void Menu(){
	printf("\n*****************************************************************");
	printf("\n                          MENU                                  *");
	printf("\n* 1. Tao nut moi va xuat noi dung                               *");
	printf("\n* 2. Tao danh sach bang tay (nhap lieu)                         *");
	printf("\n* 3. Tao danh sach bang tay (ngau nhien)                        *");
	printf("\n* 4. Them nut vao dau danh sach                                 *");
	printf("\n* 5. Them nut vao cuoi danh sach                                *");
	printf("\n* 6. Chen them phan tu x sau phan tu y                          *");
	printf("\n* 7. Chen them phan tu x truoc phan tu y                        *");
	printf("\n* 8. Sap xep danh sach tang dan                                 *");
	printf("\n* 9. Sap xep danh sach giam dan                                 *");
	printf("\n* 10.So luong so nguyen to trong danh sach                      *");
	printf("\n* 11.Tong cac so chinh phuong trong danh sach                   *");
	printf("\n* 12.Phan tu min trong dslk                                     *");
	printf("\n* 13.Phan tu max trong dslk                                     *");
	printf("\n* 14.Co bao nhieu phan tu dap doi phan tu phia sau no           *");
	printf("\n* 15.Tao sl1(so chan), sl2(so le)                               *");
	printf("\n*****************************************************************");
}
void process()
{
	Itemtype X, Y;
	SNode* P, * Q;
	SList SL;
	initSList(SL);
	int choice, result;
	do {
		Menu();
		printf("\n");
		printf("\nChon mot chuc nang: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: 
			printf("Ban hay nhap gia tri node moi: ");
			scanf("%d", &X);
			P = createSNode(X);
			printf("\nNoi dung nut moi vua tao la: ");
			showSNode(P);
			break;
		
		case 2: 
			initSList(SL);
			createSList_ByHand(SL);
			printf("Danh sach vua duoc nhap lieu la: ");
			showSlist(SL);
		
			  break;
		case 3:
		
			initSList(SL);
			createSList_Random(SL);
			printf("Danh sach vua duoc tao tu dong la: ");
			showSlist(SL);
		
		break;
		case 4:
		
			printf("\nHay nhap gia tri nut muon them dau: ");
			scanf("%d", &X);
			P = createSNode(X);
			result = insertHead(SL, P);
			if (result == 0)
				printf("\nKhong thuc hien duoc viec them dau:");
			else
				showSlist(SL);
		
			break;

		case 5: 
			printf("\nHay nhap gia tri nut muon them cuoi: ");
			scanf("%d", &X);
			P = createSNode(X);
			result = insertTail(SL, P);
			if (result == 0)
				printf("\nKhong thuc hien duoc viec them cuoi:");
			else
				showSlist(SL);
		
			break;

		case 6: 

			printf("\n Nhap mot so nguyen x bat ky muon them: ");
			scanf("%d", &X);
			printf("Nhap mot gia tri nut ke truoc: ");
			scanf("%d", &Y);
			P = createSNode(X);// nút P mới chứa X
			Q = findSNode(SL, Y);
			result = insertAfter(SL, P, Q);
			if (result == 0)
				printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
			else
				showSlist(SL);
		
			break;
		case 7:
			printf("\n Nhap mot so nguyen x bat ky muon them: ");
			scanf("%d", &X);
			printf("Nhap mot gia tri nut ke truoc: ");
			scanf("%d", &Y);
			P = createSNode(X);// nút P mới chứa X
			result = Add_before_y(SL, P, Y);
			if (result == 0)
				printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
			else
				showSlist(SL);
		
			break;
		case 8:
			Interchange_Sort_Tang(SL);
			printf("Danh sach sau khi duoc sap xep tang dan: ");
			showSlist(SL);
		
			break;

		case 9: 
			Interchange_Sort_Giam(SL);
			printf("Danh sach sau khi duoc sap xep giam dan: ");
			showSlist(SL);
		
			break;
		case 10: 
			printf("co %d so nguyen to trong DSLK", countPrime(SL));
			getch();
		
			break;
		case 11:
			printf("Tong cac so chinh phuong trong danh sach la %d: ", sumChinhPhuong(SL));
			getch();
			break;

		case 12:
			printf("Phan tu nho nhat trong danh sach la %d: ", Min(SL));
			getch();
			break;
		case 13:
			printf("Phan tu lon nhat trong danh sach la %d: ", Max(SL));
			getch();
			break;
		case 14: 
			printf("So phan tu gap doi phan tu phia sau no la %d", countDouble(SL));
			getch();
	
			break;
		case 15:
			create_SL1_SL2(SL);
			getch();
		default:
			break;
		}
	} while (choice != 0);
	
}


//Chương trình chính(main)
int main(){
	process();
    return 0;

}
// Viết hàm

//Tạo nút
SNode*createSNode(Itemtype x){
	SNode *p = new SNode;
	if (p == NULL){
		printf("Khong du bo nho cap phat!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

// Xuất nội dung nút
void showSNode(SNode *p){
	printf("%4d", p->Info);
}

// Tìm nút
SNode *findSNode(SList sl, Itemtype x) {
	if (isEmpty(sl) == 1)
		return NULL;
	SNode* p = sl.Head;
	while ((p != NULL) && (p->Info != x))
		p = p->Next;
	return p;
}

//Khởi tạo danh sách rỗng
void initSList(SList&sl){
	sl.Head = NULL;
	sl.Tail = NULL;
}
//Kiểm tra danh sách rỗng
int isEmpty(SList sl){
	if (sl.Head = NULL)
		return 1;
	else
		return 0;
}

//Tạo danh sách bằng cách nhập liệu
void createSList_ByHand(SList &sl) {
	initSList(sl);
	int n;
	Itemtype x;
	do {
		printf("\nNhap so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d la: ", i+1);
		scanf("%d", &x);
		SNode* p = createSNode(x);
		if (insertHead(sl, p) == 0)
			continue;
	}

}
// Tạo danh sách ngẫu nhiên
void createSList_Random(SList &sl)
{
	initSList(sl);
	int n;
	do {
		printf("\nNhap so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		Itemtype x;
		x = rand() % 199 - 99;// random từ [-99;99]
		SNode *p = createSNode(x);
		if (insertHead(sl, p) == 0)
			continue;
	}
}

// Hiển thị nội dung của danh sách sl lên màn hình
void showSlist(SList sl){
	if (isEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	SNode *p = sl.Head;
	while (p != NULL){
		showSNode(p);
		p = p->Next;
	}
}

// Thêm đầu
int insertHead(SList &sl, SNode *p) {
	if (p == NULL)
		return 0;
	if (isEmpty(sl) == 1) {
		sl.Head = p;
		sl.Tail = p;
	}
	else {
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}
// Thêm cuối
int insertTail(SList &sl, SNode *p) {
	if (p == NULL)
		return 0;
	if (isEmpty(sl) == 1) {
		sl.Head = p;
		sl.Tail = p;
	}
	else {
		sl.Tail->Next = p;
		sl.Tail = p;
		
	}
	return 1;
}
// thêm bất kỳ
int insertAfter(SList& sl, SNode* p, SNode* q) {
	if (p == NULL || q == NULL)
		return 0;
	p->Next = q->Next;
	q->Next = p;
	if (sl.Tail == q)
		sl.Tail = p;
	return 1;
}
// THÊM TRƯỚC
int Add_before_y(SList& sl, SNode* p, int y) {
	if (p == NULL || sl.Head == NULL)return 0;
	if (sl.Head->Info == y)insertHead(sl, p);
	else {
		SNode* k = sl.Head;
		for (; k != NULL; k = k->Next)
		{
			if (k->Next->Info == y)break;
		}
		p->Next = k->Next;
		k->Next = p;
	}
	return 1;
}
// hoán đổi
void Swap(Itemtype &a,Itemtype &b) {
	int temp = a;
	a = b;
	b = temp;
}
// sắp xếp tăng
void Interchange_Sort_Tang(SList &sl) {
	for (SNode  *p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode *q = p->Next; q != NULL; q = q->Next)
		{
			if (p->Info > q->Info)
				Swap(p->Info, q->Info);
		}
	}
}
// sắp xếp giảm
void Interchange_Sort_Giam(SList &sl) {
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (p->Info < q->Info)
				Swap(p->Info, q->Info);
		}
	}
}
// ktra số nguyên
bool checkPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
// 
int countPrime(SList& sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return 0;
	}
	else {
		int count = 0;
		for (SNode* p = sl.Head; p != NULL; p = p->Next)
		{
			if (checkPrime(p->Info))
				count++;
		}
		return count;
	}
}
// ktra chính phương
int checkChinhPhuong(int n)
{
	return (sqrt(n) * sqrt(n) == n) ? 1 : 0;
}
// tính tổng các số chính phương
int sumChinhPhuong(SList sl) {
	int sum = 0;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (checkChinhPhuong(p->Info))
			sum += p->Info;
	}
	return sum;
}
int Max(SList sl)
{
	int max = sl.Head->Info;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (p->Info > max)
		{
			max = p->Info;
		}
	}
	return max;
}
int Min(SList sl) {
	int min = sl.Head->Info;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (p->Info < min)
		{
			min = p->Info;
		}
	}
	return min;
}
// đếm bn phan tu gap doi phan tu phía sau
int countDouble(SList sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("\nDanh sach rong!");
		return 0;
	}
	else {
		int count = 0;
		for (SNode* p = sl.Head; p!= NULL; p = p->Next)
			if (p->Info > (p->Info * 2))
				count++;
		return count;
	}
}
// tạo sl1,sl2
void create_SL1_SL2(SList sl)
{
	SList sl1, sl2;
	initSList(sl1);
	initSList(sl2);
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{ 
		if (p->Info % 2 == 0) 
			insertHead(sl1, createSNode(p->Info));
	
		else
			insertHead(sl2, createSNode(p->Info));
	}
	printf("DSLK sl1: ");
	showSlist(sl1);
	printf("\nDSLK sl2: ");
	showSlist(sl2);
}

	


