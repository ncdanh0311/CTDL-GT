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
//typedef char Itemtype;// Khai báo kiểu dữ liệu người dùng
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
//bool stack_CheckBracket(char strCheckBracket[]);
//
//
//
//
////================================================
////Chương trình chính(main)
//void main() {
//	char bieuthuc[100] = "()[(()){[[()]]}";
//	//char bieuthuc[100] = "()(()){([()])}";
//	//char bieuthuc[100] = ")(())";
//	bool kq = stack_CheckBracket(bieuthuc);
//	if (kq == true)
//		printf("\nBieu thuc dung!");
//	else
//		printf("\nBieu thuc sai!");
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
//// kiểm tra dấu ngoặc
//bool stack_CheckBracket(char strCheckBracket[])
//{
//	char x, y;
//	StackNode* p;
//	Stack stack;
//	initStack(stack);
//	int n = strlen(strCheckBracket);
//	for (int i = 0; i < n; i++)
//	{
//		x = strCheckBracket[i];
//		if (x == '(' || x == '[' || x == '{')
//		{
//			p = createStackNode(x);
//
//			push(stack, p);
//		}
//		else if (x == ')' || x == ']' || x == '}')
//		{
//			if (pop(stack, y) == 1)
//			{
//				if (x == ')' && y != '(')
//					return false;
//				else if (x == ']' && y != '[')
//					return false;
//				if (x == '}' && y != '{')
//					return false;
//			}
//			else
//				return false;
//		}
//	}
//	if (isEmpty(stack) == 1)
//		return true;
//	else
//		return false;
//}
// 
// 
// Ký pháp BA LAN
//void convertInfixToPostfix(char* P, char* Q)//((6+4)/2+7)/3-(1+2)*2)
//{											//1*2+3*((4-5)+6)/7
//											//3*(2+6*2/3–1)–2*3/2+1
//	Stack<char> s;
//	char tmp;
//	int j = 0;
//	initStack(s);
//	push(s, '(');//Them ( vao stack
//	showStack(s);
//	for (int i = 0; i < strlen(P); i++)
//	{
//		//p = createNode(P[i]);
//		if (P[i] >= '0' && P[i] <= '9')//Neu P la toan hang
//		{
//			Q[j++] = P[i];
//		}
//		else
//		{
//			if (P[i] == '(')//Neu P la dau ( thi day vao stack
//			{
//				push(s, P[i]);
//				showStack(s);
//			}
//			else
//			{
//				if (P[i] == '^' || P[i] == '*' || P[i] == '/' || P[i] == '+' || P[i] == '-')//Neu P la toan tu 
//				{
//					while (s.top != NULL && checkPriority(P[i]) <= checkPriority(s.top->info) && s.top->info != '(')//Kiem tra do uu tien
//					{
//						Q[j++] = pop(s);
//					}
//					push(s, P[i]);
//					showStack(s);
//				}
//				else
//				{
//					if (P[i] == ')')
//					{
//						while (s.top != NULL && s.top->info != '(')
//						{
//							Q[j++] = pop(s);
//							showStack(s);
//						}
//						pop(s);
//						showStack(s);
//					}
//				}
//			}
//		}
//	}
//	while (s.top != NULL && s.top->info != '(')
//	{
//		Q[j++] = pop(s);
//		showStack(s);
//	}
//	showStack(s);
//	Q[j] = '\0';
//}
//int calc(char op, int x, int y)
//{
//	switch (op)
//	{
//	case '+': return x + y;
//	case '-': return x - y;
//	case '*': return x * y;
//	case '/': return x / y;
//	}
//}
//int calculateInfix(char* Q)
//{
//	int x, y, result;
//	Stack<int> s;
//	initStack(s);
//	for (int i = 0; i < strlen(Q); i++)
//	{
//		if (Q[i] >= '0' && Q[i] <= '9')
//		{
//			push(s, Q[i] - 48);
//		}
//		else
//		{
//			if (Q[i] == '^' || Q[i] == '*' || Q[i] == '/' || Q[i] == '+' || Q[i] == '-')
//			{
//				x = pop(s);
//				y = pop(s);
//				result = calc(Q[i], y, x);
//				push(s, result);
//			}
//		}
//	}
//	return pop(s);
