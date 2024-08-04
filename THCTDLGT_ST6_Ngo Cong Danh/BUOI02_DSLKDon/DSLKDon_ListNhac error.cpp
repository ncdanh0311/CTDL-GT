//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<math.h>
//#include<string.h>
////================================================
////Khai bao kiểu dữ liệu
//struct BaiHat {
//	char TenBH[31];
//	char TenNS[31];
//	char TenCS[31];
//	int ThoiLuong;
//};
//
//typedef BaiHat Itemtype;// Khai báo kiểu dữ liệu người dùng
//struct SNode {
//	Itemtype Info;// Lưu thông tin của nút
//	SNode* Next;// Con trỏ chỉ đên nút kế sau
//};
//struct SList {
//	SNode* Head;
//	SNode* Tail;
//};
////================================================
//// Khai báo nguyên mẫu hàm
//void Menu();
//void process();
//void nhapTBaiHat(Itemtype& x);
//void xuatTBaiHat(Itemtype x);
//SNode* createSNode(Itemtype x);
//void showSNode(SNode* p);
//void initSList(SList& sl);
//int isEmpty(SList sl);
//void showSlist(SList sl);
//void createSList_ByHand(SList& sl);
//void createSList_LoadFile(SList& sl, char tenFile[]);
//int insertHead(SList& sl, SNode* p);
//int insertTail(SList& sl, SNode* p);
//int insertAfter(SList& sl, SNode* p, SNode* q);
//SNode* findSNode(SList SL, Itemtype x);
//int Add_before_y(SList& sl, SNode* p, int y);
//int deleteHead(SList& sl, Itemtype& x);
//int deleteTail(SList& sl, Itemtype& x);
//int deleteAfter(SList& s1, SNode* q, Itemtype& x);
//void loadBaiHat(FILE* fi, Itemtype& x);
//
//
////================================================
//
////MENU
//void Menu() {
//	printf("\n*****************************************************************");
//	printf("\n                          MENU                                  *");
//	printf("\n* 1.Nhap Thong Tin Cua Bai Hat Moi:                             *");
//	printf("\n* 2.Tao danh sach bang tay (nhap lieu)                          *");
//	printf("\n* 3. Tao danh sach bang tay (ngau nhien)                        *");
//	printf("\n*****************************************************************");
//}
//void process()
//{
//	char tenFile[] = "dsbaihat.txt";
//	Itemtype X, Y;
//	SNode* P, * Q;
//	SList SL;
//	initSList(SL);
//	int choice, result;
//	do {
//		Menu();
//		printf("\n");
//		printf("\nChon mot chuc nang: ");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1: {
//			nhapTBaiHat(X);
//			P = createSNode(X);
//			printf("\nThong tin bai hat nay la: ");
//			showSNode(P);
//			break;
//		}
//		case 2:
//		{
//			createSList_ByHand(SL);
//			printf("Danh sach bai hat vua duoc nhap lieu la: ");
//			showSlist(SL);
//			break;
//		}
//
//		case 3:
//			createSList_LoadFile(SL, tenFile);
//			printf("Danh sach vua duoc load la: ");
//			showSlist(SL);
//
//			break;
//			//case 4:
//
//			//	printf("\nHay nhap gia tri nut muon them dau: ");
//			//	scanf("%d", &X);
//			//	P = createSNode(X);
//			//	result = insertHead(SL, P);
//			//	if (result == 0)
//			//		printf("\nKhong thuc hien duoc viec them dau:");
//			//	else
//			//		showSlist(SL);
//
//			//	break;
//
//			//case 5:
//			//	printf("\nHay nhap gia tri nut muon them cuoi: ");
//			//	scanf("%d", &X);
//			//	P = createSNode(X);
//			//	result = insertTail(SL, P);
//			//	if (result == 0)
//			//		printf("\nKhong thuc hien duoc viec them cuoi:");
//			//	else
//			//		showSlist(SL);
//
//			//	break;
//
//			//case 6:
//
//			//	printf("\n Nhap mot so nguyen x bat ky muon them: ");
//			//	scanf("%d", &X);
//			//	printf("Nhap mot gia tri nut ke truoc: ");
//			//	scanf("%d", &Y);
//			//	P = createSNode(X);// nút P mới chứa X
//			//	Q = findSNode(SL, Y);
//			//	result = insertAfter(SL, P, Q);
//			//	if (result == 0)
//			//		printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
//			//	else
//			//		showSlist(SL);
//
//			//	break;
//			//case 7:
//			//	printf("\n Nhap mot so nguyen x bat ky muon them: ");
//			//	scanf("%d", &X);
//			//	printf("Nhap mot gia tri nut ke truoc: ");
//			//	scanf("%d", &Y);
//			//	P = createSNode(X);// nút P mới chứa X
//			//	result = Add_before_y(SL, P, Y);
//			//	if (result == 0)
//			//		printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
//			//	else
//			//		showSlist(SL);
//
//			//	break;
//			//case 8:
//			//	Interchange_Sort_Tang(SL);
//			//	printf("Danh sach sau khi duoc sap xep tang dan: ");
//			//	showSlist(SL);
//
//			//	break;
//
//			//case 9:
//			//	Interchange_Sort_Giam(SL);
//			//	printf("Danh sach sau khi duoc sap xep giam dan: ");
//			//	showSlist(SL);
//			//	break;
//			//case 10:
//			//	result = deleteHead(SL, X);
//			//	if (result == 1) {
//			//		printf("Danh sach sau khi xoa node dau %d la: ", X);
//			//		showSlist(SL);
//			//	}
//			//	else {
//			//		printf("Khong the xoa dau danh sach");
//			//	}
//			//	break;
//			//case 11:
//			//	printf("Hay cho biet gia tri cua node ke truoc(node q): ");
//			//	scanf("%d", &X);
//			//	Q = findSNode(SL, X);
//			//	if (deleteAfter(SL, Q, Y) == 1)
//			//	{
//			//		printf("Danh sach sau khi xoa node %d ke sau %d la: ", Y, X);
//			//		showSlist(SL);
//
//			//	}
//			//	else
//			//		printf("Khong the xoa theo yeu cau");
//			//	break;
//		default:
//			break;
//		}
//	} while (choice != 0);
//
//}
//
//
////Chương trình chính(main)
//void main() {
//	process();
//
//}
////Viết hàm
//
////Tạo nút
//SNode* createSNode(Itemtype x) {
//	SNode* p = new SNode;
//	if (p == NULL) {
//		printf("Khong du bo nho cap phat!");
//		_getch();
//		return NULL;
//	}
//	p->Info = x;
//	p->Next = NULL;
//	return p;
//}
//
////Tìm nút
//SNode* findSNode(SList sl, Itemtype x) {
//	if (isEmpty(sl) == 1)
//		return NULL;
//	SNode* p = sl.Head;
//	/*while ((p != NULL) && (p->Info != x))*/
//	p = p->Next;
//	return p;
//}
//
////Khởi tạo danh sách rỗng
//void initSList(SList& sl) {
//	sl.Head = NULL;
//	sl.Tail = NULL;
//}
////Kiểm tra danh sách rỗng
//int isEmpty(SList sl) {
//	if (sl.Head = NULL)
//		return 1;
//	else
//		return 0;
//}
//
////Tạo danh sách bằng cách nhập liệu
//void createSList_ByHand(SList& sl) {
//	initSList(sl);
//	int n;
//
//	do {
//		printf("Nhap so phan tu cua danh sach: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		Itemtype x;
//		nhapTBaiHat(x);
//		SNode* p = createSNode(x);
//		if (insertHead(sl, p) == 0)
//			continue;
//	}
//
//}
////Tạo danh sách ngẫu nhiên
//void createSList_LoadFile(SList& sl, char tenFile[])
//{
//	FILE* fi = fopen(tenFile, "rt");
//	if (fi == NULL) {
//		printf("Loi doc file %s.", tenFile);
//		return;
//	}
//	initSList(sl);
//	int n;
//	fscanf(fi, "%d\n", &n);// đọc số lương bài hat
//	for (int i = 0; i < n; i++)
//	{
//		Itemtype x;
//		loadBaiHat(fi, x);
//		SNode* p = createSNode(x);
//		if (insertHead(sl, p) == 0)
//			continue;
//	}
//
//}
//
////initSList(sl);
////int n;
////do {
////	printf("\nNhap so phan tu cua danh sach: ");
////	scanf("%d", &n);
////} while (n <= 0);
////srand((unsigned)time(NULL));
////for (int i = 0; i < n; i++)
////{
////	Itemtype x;
////	x = rand() % 199 - 99;// random từ [-99;99]
////	SNode* p = createSNode(x);
////	if (insertHead(sl, p) == 0)
////		continue;
////}
//
//
////Hiển thị nội dung của danh sách sl lên màn hình
//void showSlist(SList sl) {
//	if (isEmpty(sl) == 1)
//	{
//		printf("\nDanh sach rong!");
//		return;
//	}
//	printf("\n%-5s%-31s%-26s%-26s%-10s", "STT", "TEN BAI HAT", "TEN NHAC SI", "TEN CA SI", "THOI LUONG");
//
//	int stt = 1;
//	SNode* p = sl.Head;
//	while (p != NULL) {
//		printf("\n%d ", stt++);
//		showSNode(p);
//		p = p->Next;
//	}
//}
////Xuất nội dung nút
//void showSNode(SNode* p) {
//	xuatTBaiHat(p->Info);
//}
////Thêm đầu
//int insertHead(SList& sl, SNode* p) {
//	if (p == NULL)
//		return 0;
//	if (isEmpty(sl) == 1) {
//		sl.Head = p;
//		sl.Tail = p;
//	}
//	else {
//		p->Next = sl.Head;
//		sl.Head = p;
//	}
//	return 1;
//}
////Thêm cuối
//int insertTail(SList& sl, SNode* p) {
//	if (p == NULL)
//		return 0;
//	if (isEmpty(sl) == 1) {
//		sl.Head = p;
//		sl.Tail = p;
//	}
//	else {
//		sl.Tail->Next = p;
//		sl.Tail = p;
//
//	}
//	return 1;
//}
////thêm bất kỳ
//int insertAfter(SList& sl, SNode* p, SNode* q) {
//	if (p == NULL || q == NULL)
//		return 0;
//	p->Next = q->Next;
//	q->Next = p;
//	if (sl.Tail == q)
//		sl.Tail = p;
//	return 1;
//}
//// THÊM TRƯỚC	
//int Add_before_y(SList& sl, SNode* p, int y) {
//	if (p == NULL || sl.Head == NULL)return 0;
//	/*if (sl.Head->Info == y)insertHead(sl, p);*/
//	else {
//		SNode* k = sl.Head;
//		for (; k != NULL; k = k->Next)
//		{
//			/*if (k->Next->Info == y)break;*/
//		}
//		p->Next = k->Next;
//		k->Next = p;
//	}
//	return 1;
//}
//// XOÁ ĐẦU
//int deleteHead(SList& sl, Itemtype& x) {
//	if (isEmpty(sl) == 1)
//		return 0;
//	SNode* p = sl.Head;
//	sl.Head = sl.Head->Next;
//	if (sl.Head == NULL)
//		sl.Tail = NULL;
//	x = p->Info;
//	delete p;
//	return 1;
//}
//// XOÁ SAU 1 PHẦN TỬ
//int deleteAfter(SList& sl, SNode* q, Itemtype& x) {
//	if (q == NULL || q->Next == NULL)
//		return 0;
//	SNode* p = q->Next;
//	q->Next = p->Next;
//	if (sl.Tail == p)
//		sl.Tail = q;
//	x = p->Info;
//	delete p;
//	return 1;
//}
//void nhapTBaiHat(Itemtype& x) {
//	printf("nhap thong tin bai hat: "); rewind(stdin); gets_s(x.TenBH);
//	printf("nhap thong tin ca si: "); rewind(stdin); gets_s(x.TenCS);
//	printf("nhap thong tin nhac si: "); rewind(stdin); gets_s(x.TenNS);
//	printf("nhap thoi luong bai hat: "); scanf_s("%d", &x.ThoiLuong);
//}
//
////===============================================================================================
//void xuatTBaiHat(Itemtype x) {
//	printf("%-31s%-26s%-26s%-10d", x.TenBH, x.TenCS, x.TenNS, x.ThoiLuong);
//}
//void loadBaiHat(FILE* fi, Itemtype& x)
//{
//	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.TenBH, &x.TenCS, &x.TenNS, &x.ThoiLuong);
//}