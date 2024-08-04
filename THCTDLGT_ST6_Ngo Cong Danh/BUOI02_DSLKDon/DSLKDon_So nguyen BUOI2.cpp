///*
//Họ và tên:Ngô Công Danh
//Lớp:THCTDL&GT ST6
//*/
//// Khai báo thư viện
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<math.h>
////================================================
////Khai bao kiểu dữ liệu
//typedef int Itemtype;// Khai báo kiểu dữ liệu người dùng
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
//SNode* createSNode(Itemtype x);
//void showSNode(SNode* p);
//void initSList(SList& sl);
//int isEmpty(SList sl);
//void showSlist(SList sl);
//void createSList_ByHand(SList& sl);
//void createSList_Random(SList& sl);
//int insertHead(SList& sl, SNode* p);
//int insertTail(SList& sl, SNode* p);
//int insertAfter(SList& sl, SNode* p, SNode* q);
//SNode* findSNode(SList SL, Itemtype x);
//int Add_before_y(SList& sl, SNode* p, int y);
//int deleteHead(SList& sl, Itemtype& x);
//int deleteTail(SList& sl, Itemtype& x);
//int deleteAfter(SList& s1, SNode* q, Itemtype& x);
//int deleteBefore(SList& sl, SNode* q, Itemtype y);
//int deleteSList(SList& sl);
//int deleteEven(SList& sl);
//int deleteSNodeX(SList& sl, Itemtype x);
//
//
////================================================
//
////MENU
//void Menu() {
//	printf("\n*********************************************************");
//	printf("\n                      MENU                              *");
//	printf("\n* 1. Tao nut moi va xuat noi dung                       *");
//	printf("\n* 2. Tao danh sach bang tay (nhap lieu)                 *");
//	printf("\n* 3. Tao danh sach bang tay (ngau nhien)                *");
//	printf("\n* 4. Them nut vao dau danh sach                         *");
//	printf("\n* 5. Them nut vao cuoi danh sach                        *");
//	printf("\n* 6. Chen them phan tu x sau phan tu y                  *");
//	printf("\n* 7. Chen them phan tu x truoc phan tu y                *");
//	printf("\n* 8.Xoa node dau cua danh sach                          *");
//	printf("\n* 9.Xoa node cuoi danh sach                             *");
//	printf("\n* 10.Xoa node ke sau node p                             *");
//	printf("\n* 11.Xoa node truoc node da cho                         *");
//	printf("\n* 12.Xoa node co gia tri x                              *");
//	printf("\n* 13.Xoa tat ca phan tu chan                            *");
//	printf("\n* 13.Xoa toan bo danh sach                              *");
//	printf("\n*********************************************************");
//}
//void process()
//{
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
//		case 1:
//			printf("Ban hay nhap gia tri node moi: ");
//			scanf("%d", &X);
//			P = createSNode(X);
//			printf("\nNoi dung nut moi vua tao la: ");
//			showSNode(P);
//			break;
//
//		case 2:
//			initSList(SL);
//			createSList_ByHand(SL);
//			printf("Danh sach vua duoc nhap lieu la: ");
//			showSlist(SL);
//
//			break;
//		case 3:
//
//			initSList(SL);
//			createSList_Random(SL);
//			printf("Danh sach vua duoc tao tu dong la: ");
//			showSlist(SL);
//
//			break;
//		case 4:
//
//			printf("\nHay nhap gia tri nut muon them dau: ");
//			scanf("%d", &X);
//			P = createSNode(X);
//			result = insertHead(SL, P);
//			if (result == 0)
//				printf("\nKhong thuc hien duoc viec them dau:");
//			else
//				showSlist(SL);
//
//			break;
//
//		case 5:
//			printf("\nHay nhap gia tri nut muon them cuoi: ");
//			scanf("%d", &X);
//			P = createSNode(X);
//			result = insertTail(SL, P);
//			if (result == 0)
//				printf("\nKhong thuc hien duoc viec them cuoi:");
//			else
//				showSlist(SL);
//
//			break;
//
//		case 6:
//
//			printf("\n Nhap mot so nguyen x bat ky muon them: ");
//			scanf("%d", &X);
//			printf("Nhap mot gia tri nut ke truoc: ");
//			scanf("%d", &Y);
//			P = createSNode(X);// nút P mới chứa X
//			Q = findSNode(SL, Y);
//			result = insertAfter(SL, P, Q);
//			if (result == 0)
//				printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
//			else
//				showSlist(SL);
//
//			break;
//		case 7:
//			printf("\n Nhap mot so nguyen x bat ky muon them: ");
//			scanf("%d", &X);
//			printf("Nhap mot gia tri nut ke truoc: ");
//			scanf("%d", &Y);
//			P = createSNode(X);// nút P mới chứa X
//			result = Add_before_y(SL, P, Y);
//			if (result == 0)
//				printf("\nKhong thuc hien duoc viec them %d sau %d", X, Y);
//			else
//				showSlist(SL);
//
//			break;
//
//
//		case 8:
//			result = deleteHead(SL, X);
//			if (result == 1) {
//				printf("Danh sach sau khi xoa node dau %d la: ", X);
//				showSlist(SL);
//			}
//			else {
//				printf("Khong the xoa dau danh sach");
//			}
//			break;
//		case 9:
//			result = deleteTail(SL, X);
//			if (result == 1) {
//				printf("Danh sach sau khi xoa node sau %d la: ", X);
//				showSlist(SL);
//			}
//			else {
//				printf("Khong the xoa sau danh sach");
//			}
//			break;
//		case 10:
//			printf("Hay cho biet gia tri cua node ke truoc(node q): ");
//			scanf("%d", &X);
//			Q = findSNode(SL, X);
//			if (deleteAfter(SL, Q, Y) == 1)
//			{
//				printf("Danh sach sau khi xoa node %d ke sau %d la: ", Y, X);
//				showSlist(SL);
//
//			}
//			else
//				printf("Khong the xoa theo yeu cau");
//			break;
//		case 11:
//			printf("\nNhap gia tri cua node muon xoa phia truoc: ");
//			scanf("%d", &X);
//			if (deleteBefore(SL, findSNode(SL, X), X) == 1) {
//				printf("Xoa thanh cong!\n");
//				showSlist(SL);
//			}
//			else {
//				printf("\nKhong the xoa phan tu truoc phan tu co gia tri %d", X);
//			}
//			break;
//		case 12:
//			printf("\nNhap gia tri cua x muon xoa: ");
//			scanf("%d", &X);
//			if (deleteSNodeX(SL, X) == 1) {
//				printf("Xoa thanh cong\n");
//				showSlist(SL);
//			}
//			else
//				printf("\nKhong the xoa phan tu co gia tri %d", X);
//			break;
//		case 13:
//			if (deleteEven(SL))printf("xoa thanh cong");
//			else printf("xoa ko thanh cong");
//			_getch();
//			break;
//
//		case 14:
//			if (deleteSList(SL))printf("xoa thanh cong");
//			else printf("xoa ko thanh cong");
//			_getch();
//			break;
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
//// Viết hàm
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
//// Xuất nội dung nút
//void showSNode(SNode* p) {
//	printf("%4d", p->Info);
//}
//
//// Tìm nút
//SNode* findSNode(SList sl, Itemtype x) {
//	if (isEmpty(sl) == 1)
//		return NULL;
//	SNode* p = sl.Head;
//	while ((p != NULL) && (p->Info != x))
//		p = p->Next;
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
//	Itemtype x;
//	do {
//		printf("\nNhap so phan tu cua danh sach: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan tu thu %d la: ", i + 1);
//		scanf("%d", &x);
//		SNode* p = createSNode(x);
//		if (insertHead(sl, p) == 0)
//			continue;
//	}
//
//}
//// Tạo danh sách ngẫu nhiên
//void createSList_Random(SList& sl)
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
//		Itemtype x;
//		x = rand() % 199 - 99;// random từ [-99;99]
//		SNode* p = createSNode(x);
//		if (insertHead(sl, p) == 0)
//			continue;
//	}
//}
//
//// Hiển thị nội dung của danh sách sl lên màn hình
//void showSlist(SList sl) {
//	if (isEmpty(sl) == 1)
//	{
//		printf("\nDanh sach rong!");
//		return;
//	}
//	SNode* p = sl.Head;
//	while (p != NULL) {
//		showSNode(p);
//		p = p->Next;
//	}
//}
//
//// Thêm đầu
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
//// Thêm cuối
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
//// thêm bất kỳ
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
//int Add_before_y(SList& sl, SNode* q, Itemtype y) {
//	if (q == NULL || sl.Head == NULL)return 0;
//	if (sl.Head->Info == y)insertHead(sl, q);
//	else {
//		SNode* k = sl.Head;
//		for (; k != NULL; k = k->Next)
//		{
//			if (k->Next->Info == y)break;
//		}
//		q->Next = k->Next;
//		k->Next = q;
//	}
//	return 1;
//}
// //XOÁ ĐẦU
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
//// XOÁ ĐUÔI
//int deleteTail(SList& sl, Itemtype& x) {
//	if (isEmpty(sl) == 1)
//		return 0;
//	SNode* q = sl.Head;
//	SNode* p = sl.Tail;
//	if (p == q)//TH1: Nếu ds có 1 node
//		sl.Head = sl.Tail = NULL;
//	else {
//		// th2: Ds có 2 node trở lên
//		while (q->Next != p)
//			q = q->Next;
//		sl.Tail = q;
//		q->Next = NULL;
//	}
//	x = p->Info;
//	delete p;
//	return 1;
//}
//int deleteBefore(SList& sl, SNode* q, Itemtype y) {
//	if (q == NULL || sl.Head == NULL || sl.Head->Next == NULL)
//		return 0; // Không thể xoá phần tử trước nếu danh sách rỗng hoặc chỉ có 1 phần tử hoặc q là phần tử đầu tiên
//	if (sl.Head->Next == q) {
//		deleteHead(sl, y); // Xoá phần tử đầu nếu q là phần tử thứ hai trong danh sách
//		return 1;
//	}
//	SNode* p = sl.Head;
//	while (p->Next != NULL && p->Next->Next != q) {
//		p = p->Next; // Tìm phần tử trước q
//	}
//	if (p->Next == NULL) {
//		return 0; // Không tìm thấy phần tử trước q trong danh sách
//	}
//	SNode* temp = p->Next; // Lưu trữ phần tử trước q vào biến tạm
//	p->Next = q; // Cập nhật con trỏ của phần tử trước q để trỏ đến q
//	delete temp; // Xoá phần tử trước q
//	return 1;
//}
//// xoá giá trị x
//int deleteSNodeX(SList& sl, Itemtype x)
//{
//	if (isEmpty(sl) == 1)
//		return 0;
//	SNode* p = sl.Head;
//	SNode* q = NULL;
//	while ((p != NULL) && (p->Info != x))
//	{
//		q = p;
//		p = p->Next;
//	}
//	if (p == NULL)
//		return 0;
//	if (p == sl.Head)
//		deleteHead(sl, x);
//	else
//		deleteAfter(sl, q, x);
//	return 1;
//}
////xoá tất cả các phần tử chẵn
//int deleteEven(SList& sl) {
//	if (sl.Head == NULL)return 0;
//	for (SNode* p = sl.Head; p != NULL; p = p->Next)
//	{
//		if (p->Info % 2 == 0) {
//			int k = p->Info;
//			deleteSNodeX(sl, k);
//			p = sl.Head;
//		}
//	}
//	return 1;
//}
//// xoá toàn bộ danh sách
//int deleteSList(SList& sl) {
//	if (isEmpty(sl) == 1)
//		return 0;
//	while (sl.Head != NULL)
//	{
//		SNode* p = sl.Head;
//		sl.Head = sl.Head->Next;
//		delete p;
//	}
//	sl.Tail = NULL;
//	return 1;
//}
