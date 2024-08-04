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
//struct StackNode {
//	Itemtype Info;// Lưu thông tin của nút
//	StackNode* Next;// Con trỏ chỉ đên nút kế sau
//};
//struct Stack {
//	StackNode* Top;
//};
////================================================
//// Khai báo nguyên mẫu hàm
//StackNode* createStackNode(Itemtype x);
//void showStackNode(StackNode* p);
//void initStack(Stack& st);
//int isEmpty(Stack st);
//void showStackNode(Stack st);
//void createstist_ByHand(Stack& st);
//void createstist_Random(Stack& st);
//int push(Stack& st, StackNode* p);
//StackNode* findSNode(Stack st, Itemtype x);
//int pop(Stack& st, Itemtype& x);
//void stack_DoiCoSo(int n, int a);
//
//void Menu();
//void process();
//
//
//
////================================================
////Chương trình chính(main)
//void main() {
//	process();
//
//}
////MENU
//void Menu() {
//	printf("\n*********************************************************");
//	printf("\n                      MENU                              *");
//	printf("\n* 1. Tao nut moi va xuat noi dung                       *");
//	printf("\n* 2. Tao Ngan xep bang tay (nhap lieu)                  *");
//	printf("\n* 3. Tao Ngan xep bang tay (ngau nhien)                 *");
//	printf("\n* 4. Them nut vao dau Ngan xep                          *");
//	printf("\n* 5. Xoa node dau cua Ngan xep                          *");
//	printf("\n* 6. Doi co so tu he 10 sang he a(a>=2)                 *");
//	printf("\n*********************************************************");
//}
//void process()
//{
//	Itemtype X, Y;
//	int N, A;
//	StackNode* P, * Q;
//	Stack st;
//	initStack(st);
//	int choice, result;
//	do {
//		Menu();
//		printf("\nChon mot chuc nang: ");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Ban hay nhap gia tri node moi: ");
//			scanf("%d", &X);
//			P = createStackNode(X);
//			printf("\nNoi dung nut moi vua tao la: ");
//			showStackNode(P);
//			break;
//		case 2:
//			initStack(st);
//			createstist_ByHand(st);
//			printf("Ngan xep vua duoc nhap lieu la: ");
//			showStackNode(st);
//			break;
//		case 3:
//
//			initStack(st);
//			createstist_Random(st);
//			printf("Ngan xep vua duoc tao tu dong la: ");
//			showStackNode(st);
//
//			break;
//		case 4:
//			printf("\nHay nhap gia tri nut muon them dau: ");
//			scanf("%d", &X);
//			P = createStackNode(X);
//			result = push(st, P);
//			if (result == 0)
//				printf("\nKhong thuc hien duoc viec them dau:");
//			else
//				showStackNode(st);
//			break;
//		case 5:
//			result = pop(st, X);
//			if (result == 1) {
//				printf("Ngan xep sau khi xoa node dau %d la: ", X);
//				showStackNode(st);
//			}
//			else 
//				printf("Khong the xoa dau Ngan xep");
//			
//			break;
//		case 6:
//			do {
//				printf("Hay nhap so nguyen duong n: ");
//				scanf("%d", &N);
//			} while (N <= 0);
//			do {
//				printf("Hay nhap co so a = ");
//				scanf("%d", &A);
//			} while (A <= 1);
//			stack_DoiCoSo(N, A);
//			break;
//		}
//	} while (choice != 0);
//
//}
//
//// Viết hàm
//
////Tạo nút
//StackNode* createStackNode(Itemtype x) {
//	StackNode* p = new StackNode;
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
//void showStackNode(StackNode* p) {
//	printf("%4d\n", p->Info);
//}
//
//// Tìm nút
//StackNode* findSNode(Stack st, Itemtype x) {
//	if (isEmpty(st) == 1)
//		return NULL;
//	StackNode* p = st.Top;
//	while ((p != NULL) && (p->Info != x))
//		p = p->Next;
//	return p;
//}
//
////Khởi tạo danh sách rỗng
//void initStack(Stack& st) {
//	st.Top = NULL;
//}
////Kiểm tra danh sách rỗng
//int isEmpty(Stack st) {
//	if (st.Top = NULL)
//		return 1;
//	else
//		return 0;
//}
//
////Tạo danh sách bằng cách nhập liệu
//void createstist_ByHand(Stack& st) {
//	initStack(st);
//	int n;
//	Itemtype x;
//	do {
//		printf("\nNhap so phan tu cua Ngan xep: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan tu thu %d la: ", i + 1);
//		scanf("%d", &x);
//		StackNode* p = createStackNode(x);
//		if (push(st, p) == 0)
//			continue;
//	}
//
//}
//// Tạo danh sách ngẫu nhiên
//void createstist_Random(Stack& st)
//{
//	initStack(st);
//	int n;
//	do {
//		printf("\nNhap so phan tu cua Ngan xep: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		Itemtype x;
//		x = rand() % 199 - 99;// random từ [-99;99]
//		StackNode* p = createStackNode(x);
//		if (push(st, p) == 0)
//			continue;
//	}
//}
//
//// Hiển thị nội dung của danh sách st lên màn hình
//void showStackNode(Stack st) {
//	if (isEmpty(st) == 1)
//	{
//		printf("\nNgan xep rong!");
//		return;
//	}
//	StackNode* p = st.Top;
//	while (p != NULL) {
//		showStackNode(p);
//		p = p->Next;
//	}
//}
//
//// Thêm đầu
//int push(Stack& st, StackNode* p) {
//	if (p == NULL)
//		return 0;
//	if (isEmpty(st) == 1) {
//		st.Top = p;
//	}
//	else {
//		p->Next = st.Top;
//		st.Top = p;
//	}
//	return 1;
//}
//
////XOÁ ĐẦU
//int pop(Stack& st, Itemtype& x) {
//	if (isEmpty(st) == 1)
//		return 0;
//	StackNode* p = st.Top;
//	st.Top = st.Top->Next;
//	x = p->Info;
//	delete p;
//	return 1;
//}
//// đổi cơ số
//void stack_DoiCoSo(int n, int a) {
//	Stack st;
//	initStack(st);
//	Itemtype x;// lưu tạm các số dư
//	int tmp = n;// dùng bản sao của n
//	//Giai đoạn 1: đưa các số dư vào stack
//	while (tmp > 0)
//	{
//		x = tmp % a;
//		StackNode *p = createStackNode(x);
//		push(st, p);
//		tmp /= a;
//
//	}
//	// giai đoạn 2: lần lượt đưa các số dư ra từ stack
//	printf("\nKet qua doi %d tu he 10 sang he %d la: ", n, a);
//	while (true)
//	{
//		if (pop(st, x) == 0)
//			break;
//
//		if (x < 10)
//			printf("%d", x);
//		else
//		{
//			switch (x)
//			{
//			case 10:printf("A"); break;
//			case 11:printf("B"); break;
//			case 12:printf("C"); break;
//			case 13:printf("D"); break;
//			case 14:printf("E"); break;
//			case 15:printf("F"); break;
//			default:
//				break;
//			}
//		}
//	}
//}
