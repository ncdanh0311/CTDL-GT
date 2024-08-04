///*
//Họ và tên:Ngô Công Danh
//Lớp:THCTDL&GT ST6
//*/
//// Khai báo thư viện
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<string.h>
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
//void stack_Daochuoi(char* str);
//int push(Stack& st, StackNode* p);
//int pop(Stack& st, Itemtype& x);
//StackNode* findSNode(Stack st, Itemtype x);
//
//
//
//
//
////================================================
////Chương trình chính(main)
//void main() {
//	char str[100];
//	printf("Hay nhap mot chuoi: ");
//	gets_s(str);
//	stack_Daochuoi(str);
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
////Tạo danh sách bằng cách nhập liệu
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
//// đảo chuỗi
//void stack_Daochuoi(char *str)
//{
//	StackNode* p;
//	Stack stack;
//	initStack(stack);
//	int n = strlen(str);
//	for (int i = 0; i < n; i++) {
//		p = createStackNode(str[i]);
//		push(stack, p);
//	}
//	printf("Chuoi dao nguoc la: ");
//	while (!isEmpty(stack))
//	{
//		Itemtype ch;
//		pop(stack, ch);
//		printf("%c", ch);
//	}
//}