/////*
////Họ và tên:Ngô Công Danh
////Lớp:THCTDL&GT ST6
////*/
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<conio.h>
//#include<Windows.h>
//#include<time.h>
//////Khai bao kiểu dữ liệu
//struct Phanso
//{
//	int tu, mau;
//};
//typedef Phanso itemtype;
//struct Snode {
//	itemtype Info;
//	Snode* next;
//};
//struct SList
//{
//	Snode* Head;
//	Snode* Tail;
//};
//
////// Khai báo nguyên mẫu hàm
//int isEmpty(SList sl);
//void showSNode(Snode* p);
//void showSlist(SList sl);
//void initSList(SList& sl);
//Snode* createSNode(itemtype x);
//Snode* createSNode(itemtype x);
//int UCLN(int x, int y);
//void kiemtraDoiDau(Phanso& x);
//void rutGon(Phanso& x);
//void xuatPhanSo(itemtype x);
//void createSList_ByHand(SList& sl, itemtype& x);
//void createSList_Random(SList& sl);
//int insertTail(SList& sl, Snode* p);
//float Sum(SList l);
//float Tich(SList l);
//void Print_morethan1(SList l);
//void Tang1(SList& sl);
//int sosanhPhanSo(itemtype x, itemtype y);
//void Swap(itemtype& a, itemtype& b);
//void Interchange_Sort_Tang(SList& sl);
//Snode* FindP(SList sl, int tu, int mau);
//void Menu();
//int main() {
//	SList l;
//	itemtype x;
//	Snode* P, * Q;
//	initSList(l);
//	int choice = -1;
//	do
//	{
//		system("cls");
//		Menu();
//		scanf("%d", &choice);
//		switch (choice)
//		{
//
//		case 1:
//			initSList(l);
//			createSList_ByHand(l, x);
//			printf("Danh sach vua duoc nhap lieu la: ");
//			showSlist(l);
//
//			break;
//		case 2:
//
//			initSList(l);
//			createSList_Random(l);
//			printf("Danh sach vua duoc tao tu dong la: ");
//			showSlist(l);
//			break;
//		case 3:
//			showSlist(l);
//			getch();
//			break;
//		case 4:printf("Tong cac phan so la: %.2f", Sum(l));
//			_getch();
//			break;
//		case 5:
//			printf("Tich cac phan so la: %.2f", Tich(l));
//			_getch();
//			break;
//		case 6:Print_morethan1(l);
//			_getch();
//			break;
//		case 7:
//			Tang1(l);
//			printf("tang thanh cong");
//			_getch();
//			break;
//
//		case 8:
//			int n, tu, mau;
//			printf("nhap tu: ");
//			scanf("%d", &tu);
//			printf("nhap mau: ");
//			scanf("%d", &mau);
//			if (FindP(l, tu, mau) == NULL)printf("ko co va tra ve NULL");
//			else printf("co phan so P");
//			_getch();
//			break;
//		}
//	} while (choice != 0);
//}
//void Menu() {
//	printf("\n********************************************");
//	printf("\n                  MENU                     *");
//	printf("\n* 1. Tao danh sach phan so (nhap)          *");
//	printf("\n* 2. Tao danh sach phan so (random)        *");
//	printf("\n* 3. Xuat danh sach phan so                *");
//	printf("\n* 3. Rut gon phan so                       *");
//	printf("\n* 4. Tong cac phan so                      *");
//	printf("\n* 5. Tich cac phan so                      *");
//	printf("\n* 6. Xuat cac so lon hon 1                 *");
//	printf("\n* 7. tang 1 lên cac phan so                *");
//	printf("\n* 8. Viet ham tra ve SNode chua phan so p  *");
//	printf("\n* 9. Sap xep danh sach phan so tang dan    *");
//	printf("\n********************************************");
//}
//int isEmpty(SList sl){
//	if (sl.Head = NULL)
//		return 1;
//	else
//		return 0;
//}
//void showSNode(Snode *p){
//	xuatPhanSo(p->Info);
//}
//void showSlist(SList sl) {
//		if (isEmpty(sl) == 1)
//		{
//			printf("\nDanh sach rong!");
//			return;
//		}
//		Snode *p = sl.Head;
//		while (p != NULL){
//			showSNode(p);
//			p = p->next;
//		}
//	}
//Snode*createSNode(itemtype x){
//	Snode *p = new Snode;
//	if (p == NULL){
//		printf("Khong du bo nho cap phat!");
//		getch();
//		return NULL;
//	}
//	p->Info = x;
//	p->next = NULL;
//	return p;
//}
//void initSList(SList& sl) {
//	sl.Head = NULL;
//	sl.Tail = NULL;
//}
//void kiemtraDoiDau(Phanso& x)
//{
//	if (x.mau < 0)
//	{
//		x.tu *= -1;
//		x.mau *= -1;
//	}
//}
//int UCLN(int x, int y) {
//	if (x == 0 || y == 0)
//		return 1;
//	x = abs(x);
//	y = abs(y);
//}
//void rutGon(Phanso& x) {
//	kiemtraDoiDau(x);
//	int gcd = UCLN(x.tu, x.mau);
//	x.tu /= gcd;
//	x.mau /= gcd;
//}
//void xuatPhanSo(itemtype x)
//{
//	printf("%d/%d", x.tu, x.mau);
//}
//void createSList_ByHand(SList &sl, itemtype& x) {
//	initSList(sl);
//	int n;
//	do {
//		printf("\nNhap so phan tu cua danh sach: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		printf("\nNhap tu so: ");
//		scanf("%d" ,& x.tu);
//		printf("\n Nhap mau so: ");
//		scanf("%d", &x.mau);
//		if (insertTail(sl, createSNode(x)) == 0)
//			continue;
//	}
//
//}
//void createSList_Random(SList &sl )
//{
//	initSList(sl);
//	int n;
//	do {
//		printf("\nNhap so phan tu cua danh sach: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		itemtype ps;
//		int x, kq;
//		do {
//			x = rand() % 199 - 99;
//		} while (x == 0);// random từ [-99;99]
//			ps.tu = x;
//		do {
//			x = rand() % 199 - 99;
//
//
//		} while (x == 0);
//		ps.mau = x;
//		rutGon(ps);
//		if (insertTail(sl, createSNode(ps)) == 0)
//			printf("\nKhong the them phan so: ");
//		xuatPhanSo(createSNode(ps)->Info);
//
//
//	}
//}
//int insertTail(SList& sl, Snode* p){
//	if (p == NULL)return 0;//p trong thi ko add dc
//	if (sl.Head == NULL) //dau trong thi gan thang
//	{
//		sl.Head = p;
//		sl.Tail = p;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		sl.Tail->next = p;
//		sl.Tail = p;
//		return 1;
//	}
//}
//
//
//
//float Sum(SList l ) {
//	float temp, sum = 0;
//	int x;
//	for (Snode* p = l.Head; p != NULL; p = p->next)
//	{
//		x = p->Info.tu % p->Info.mau;
//		temp = (p->Info.tu / p->Info.mau) + ((1.0*x) / p->Info.mau);
//		sum += temp;
//	}
//	return sum;
//
//}
//float Tich(SList sl) {
//	float temp, Tich = 0;
//	int x;
//	for (Snode* p = sl.Head; p != NULL; p = p->next)
//	{
//		x = p->Info.tu % p->Info.mau;
//		temp = (p->Info.tu / p->Info.mau) + ((1.0 *  x) / p->Info.mau);
//		Tich *= temp;
//	}
//	return Tich;
//}
//void Print_morethan1(SList l) {
//	float temp;
//	for (Snode* p = l.Head; p != NULL; p = p->next)
//	{
//		temp = (p->Info.tu / p->Info.mau) ;
//		if(temp>=1)printf("%d/%d  ", p->Info.tu, p->Info.mau);
//	}
//}
//void Tang1(SList& sl) {
//	for (Snode* p = sl.Head; p != NULL; p = p->next)
//	{
//		p->Info.tu += p->Info.mau;
//	}
//}
//int sosanhPhanSo(itemtype x,itemtype y)
//
//{
//	float tmp = (x.tu * y.mau - x.mau * y.tu) / (x.mau * y.mau);
//	if (tmp > 0)
//		return 1;//x>y
//	else if (tmp < 0)
//		return -1;//x<y
//	else
//		return 0;
//
//}
//void Swap(itemtype & a, itemtype& b) {
//	itemtype tmp;
//	a = b;
//	b = tmp;
//}
//// sắp xếp tăng
//void Interchange_Sort_Tang(SList&sl) {
//	for (Snode* p = sl.Head; p->next != NULL; p = p->next)
//	{
//		for (Snode* q = p->next; q != NULL; q = q->next)
//		{
//			if (sosanhPhanSo(p->Info, q->Info) > 0)
//				Swap(p->Info, q->Info);
//		}
//	}
//}
//Snode* FindP(SList sl,int tu,int mau) {
//	Snode* P = new Snode;
//	for (Snode* i = sl.Head; i != NULL; i = i->next)
//	{
//		if (i->Info.tu == tu && i->Info.mau == mau) {
//			P = i;
//				return P;
//		}
//	}
//	return NULL;
//}