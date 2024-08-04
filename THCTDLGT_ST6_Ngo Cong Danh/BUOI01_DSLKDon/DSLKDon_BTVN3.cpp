///*
//Họ và tên:Ngô Công Danh
//Lớp:THCTDL&GT ST6
//*/



//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<conio.h>
//#include<Windows.h>
//typedef int itemtype;
//struct SNODE
//{
//	itemtype Info;
//	SNODE* next;
//};
//struct SList
//{
//	SNODE* head;
//	SNODE* tail;
//};
//void Menu();
//void Add_X(SList& l, int x);
//int Add_Head(SList& l, SNODE* p);
//int Add_Tail(SList& l, SNODE* p);
//void initSList(SList& l);
//SNODE* Create_Node(itemtype x);
//void Print(SList l);
//void Interchange_Sort_Giam(SList& l);
//void Swap(itemtype& a, itemtype& b);
//
//
//int main() {
//	SList sl, sl2;
//	initSList(sl);
//	initSList(sl2);
//	int choice = -1;
//	do
//	{
//		system("cls");
//		Menu();
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1: {
//			int n, x;
//			printf("nhap so luong: ");
//			scanf("%d", &n);
//			for (int i = 0; i < n; i++)
//			{
//				printf("nhap gia tri: ");
//				scanf("%d", &x);
//				if (Add_Tail(sl, Create_Node(x)))printf("Add thanh cong\n");
//				else printf("Add ko thanh cong\n");
//			}
//			_getch();
//		}break;
//		case 2: {
//			int x;
//			printf("nhap x: ");
//			scanf("%d", &x);
//			Add_X(sl, x);
//			printf("add thanh cong");
//			_getch();
//		}break;
//		case 3:Print(sl);
//			_getch();
//			break;
//		case 4:Interchange_Sort_Giam(sl);
//			Print(sl);
//			_getch();
//			break;
//		}
//	} while (choice != 0);
//}
//void Menu() {
//	printf("\n1.tao danh sach sl\n2.chen x ma van tang\n3.in danh sach\n4.in danh sach giam dan\n");
//	printf("5.noi sl2 vao sau x\n");
//	printf("moi ban nhap lua chon cua minh: ");
//}
//void Add_X(SList& l, int x) {
//	if (l.head == NULL) {
//		l.head = Create_Node(x);
//		l.tail = Create_Node(x);
//	}
//	else
//	{
//		SNODE* i = l.head;
//		for (; i != NULL; i = i->next)
//		{
//			if (i->next == NULL) {
//				Add_Tail(l, Create_Node(x));
//				break;
//			}
//			else if (i->Info < x && (i->next->Info > x || i->next == NULL)) {
//				SNODE* k = Create_Node(x);
//				k->next = i->next;
//				i->next = k;
//				break;
//			}
//		}
//	}
//}
//int Add_Head(SList& l, SNODE* p) {
//	if (p == NULL)return 0;//p trong thi ko add dc
//	if (l.head == NULL) //dau trong thi gan thang
//	{
//		l.head = p;
//		l.tail = p;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		p->next = l.head;
//		l.head = p;
//		return 1;
//	}
//}
//int Add_Tail(SList& l, SNODE* p) {
//	if (p == NULL)return 0;//p trong thi ko add dc
//	if (l.head == NULL) //dau trong thi gan thang
//	{
//		l.head = p;
//		l.tail = p;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		l.tail->next = p;
//		l.tail = p;
//		return 1;
//	}
//}
//void initSList(SList& l)
//{
//	l.head = NULL;
//	l.tail = NULL;
//}
//SNODE* Create_Node(itemtype x) {
//	SNODE* p = new SNODE;
//	if (p == NULL) {
//		printf("Khong du bo nho cap phat!");
//		getch();
//		return NULL;
//	}
//	p->Info = x;
//	p->next = NULL;
//	return p;
//}
//void Print(SList l) {
//	if (l.head == NULL)return;
//	SNODE* p = l.head;
//	while (p != NULL) {
//		printf("%d ", p->Info);
//		p = p->next;
//	}
//}
//void Interchange_Sort_Giam(SList& l) {
//	for (SNODE* i = l.head; i != NULL; i = i->next)
//	{
//		for (SNODE* j = i->next; j != NULL; j = j->next)
//		{
//			if (i->Info < j->Info)Swap(i->Info, j->Info);
//		}
//	}
//}
//void Swap(itemtype& a, itemtype& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}