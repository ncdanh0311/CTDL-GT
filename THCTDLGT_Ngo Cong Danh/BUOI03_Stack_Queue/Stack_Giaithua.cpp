///*
//Họ và tên:Ngô Công Danh
//Lớp:THCTDL&GT ST6
//*/
//// Khai báo thư viện
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
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
//void initStack(Stack& st);
//int isEmpty(Stack st);
//int push(Stack& st, StackNode* p);
//int pop(Stack& st, Itemtype& x);
//StackNode* findSNode(Stack st, Itemtype x);
//long int stack_TinhGiaiThua(int n);
//int giai_thua_khong_de_quy(int n);
//
//
//
//
////================================================
////Chương trình chính(main)
//void main() {
//	int n;
//	long int gt;
//	do {
//		printf("Nhap mot so nguyen duong: ");
//		scanf("%d", &n);
//	} while (n < 0);
//	gt = stack_TinhGiaiThua(n);
//	printf("%d! = %ld", n, gt);
//	_getch();
//
//}
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
//// Tìm nút
//StackNode* findSNode(Stack st, Itemtype x) {
//	if (isEmpty(st) == 1)
//		return NULL;
//	StackNode* p = st.Top;
//	while ((p != NULL) && (p->Info != x))
//		p = p->Next;
//	return p;
//}
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
//// Thêm đầu
//int push(Stack& st, StackNode* p) {
//	if (p == NULL)
//		return 0;
//	if (isEmpty(st) == 1) 
//		st.Top = p;
//	
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
//// Khử đệ qui Giai thừa
//long int stack_TinhGiaiThua(int n) {
//	
//	Itemtype x;
//	StackNode* p;
//	Stack stack;
//	initStack(stack);
//	while (n > 0)
//	{
//		p = createStackNode(n);
//		if (push(stack, p) == 0)
//			break;
//		n--;
//	}
//
//	long int result = 1;
//	while (1) {
//		if (pop(stack, x) == 0) 
//			break;
//		
//		result *= x;
//	}
//	return result;
//}
//int giai_thua_khong_de_quy(int n) {
//	int giai_thua = 1;
//	while (n > 1) {
//		giai_thua *= n;
//		n--;
//	}
//	return giai_thua;
//}