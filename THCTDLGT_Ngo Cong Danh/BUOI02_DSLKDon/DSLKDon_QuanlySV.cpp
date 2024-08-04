////==========================================================================
//////Họ và tên:Ngô Công Danh
//////Lớp:THCTDL&GT ST6
//////
////==========================================================================*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Windows.h>
//#include<conio.h>
//#include<string.h>
//#include<math.h>
//struct KetQua
//{
//	char Ma_mon[20], Ten_Mon[25];
//	int tinchi;
//	float DTL, DCK, DMH;
//};
//struct KQNODE
//{
//	KetQua Info;
//	KQNODE* Next;
//};
//struct KQList
//{
//	KQNODE* Head;
//	KQNODE* Tail;
//};
////
//struct SinhVien
//{
//	char mssv[20], ho_dem[25], ten[10];
//	int namsinh;
//	KQList KQ;
//};
//struct SNODE
//{
//	SinhVien Info;
//	SNODE* Next;
//};
//struct SList
//{
//	SNODE* Head;
//	SNODE* Tail;
//};
//void Create_KQlist(KQList& l);
//void Create_Slist(SList& l);
//int ReadKQList(KQList& kq, FILE* L);
//SNODE* ReadSlist(SList& l, char MSSV[], FILE* L);
//int insertHead(SList& l, SNODE* p);
//int insertTail(SList& l, SNODE* p);
//int insertTail_KQ(KQList& kq, KQNODE* P);
//void Input_File(SList& l);
//void Print_Slist(SList l);
//void Print_KQList(KQList kq);
//void Menu();
//void Print_MSSV_X(SList l);
//void Print_Name_X(SList l);
//void Print_1_Slist(SNODE* i);
//void Sort_NAME(SList& l);
//void Sort_MSSV(SList& l);
//int Remove_Node_Name(SList& l, char String[]);
//int Remove_Node_MSSV(SList& l, char String[]);
//int deleteHead(SList& l, char String[]);
//int Remove_Tail(SList& l, char String[]);
//float calculator_score(KQList l);
//void create_NewList(SList l, SList& New);
//void Print_Kha(SList l);
//void Max_score(SList l);
//void Min_score(SList l);
//void gan_x(SList l, float x);
//void Min_gioi(SList l);
//int main() {
//	SList SL;
//	Create_Slist(SL);
//
//	int choice = -1;
//	do
//	{
//		Menu();
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1: {
//			Input_File(SL);
//			printf("nhap thanh cong");
//			_getch();
//			break;
//		}
//		case 2: {
//			Print_Slist(SL);
//			_getch();
//			break;
//		}
//		case 3: {
//			Print_MSSV_X(SL);
//			_getch();
//			break;
//		}
//		case 4: {
//			Print_Name_X(SL);
//			_getch();
//			break;
//		}
//		case 5: {
//			Sort_MSSV(SL);
//			printf("sort thanh cong");
//			_getch();
//			break;
//		}
//		case 6: {
//			Sort_NAME(SL);
//			printf("sort thanh cong");
//			_getch();
//			break;
//		}
//		case 8: {
//			char Name[20];
//			printf("nhap mssv x: ");
//			rewind(stdin);
//			gets_s(Name);
//			if (Remove_Node_MSSV(SL, Name))printf("xoa done");
//			else printf("xoa ko thanh cong");
//			_getch();
//			break;
//		}
//		case 9: {
//			char Name[20];
//			printf("nhap mssv x: ");
//			rewind(stdin);
//			gets_s(Name);
//			if (Remove_Node_Name(SL, Name))printf("xoa done");
//			else printf("xoa ko thanh cong");
//			_getch();
//			break;
//		}
//		case 10: {
//			SList New;
//			Create_Slist(New);
//			create_NewList(SL, New);
//			printf("chuyen qua thanh cong\nlist moi la:\n");
//			Print_Slist(New);
//			_getch();
//			break;
//		}
//		case 11: {
//			Print_Kha(SL);
//			_getch();
//			break;
//		}
//		case 12: {
//			Max_score(SL);
//			_getch();
//			break;
//		}
//		case 13: {
//			Min_score(SL);
//			_getch();
//			break;
//		}
//		case 14: {
//			Min_gioi(SL);
//			_getch();
//			break;
//		}
//		case 15: {
//			printf("nhap x: ");
//			float x;
//			scanf("%f", &x);
//			gan_x(SL, x);
//			_getch();
//			break;
//		}
//		default:
//			break;
//		}
//		system("cls");
//	} while (choice!=0);
//	return 0;
//}
//void Menu() {
//	printf("=============Menu=====================");
//	printf("\n1.nhap tu file\n2.in ra thong tin\n3.in sinh vien co ma x \n4.in sinh vien co ten x\n5.sort tang dan theo ma\n6.sort tang dan theo ten\n");
//	printf("7.them 1 sinh vien van giu nguyen thu tu tang dan\n8.xoa sinh vien co mssv x\n9.xoa sinh vien co ten x\n10.tao danh sach moi va diem giam dan \n");
//	printf("11.in ds sinh vien loai kha\n12.sinh vien co diem cao\n13.sinh vien co diem thap nhat\n14.diem thap nhat trong loai gioi\n15.cho biet sinh vien co diem gan x nhat\n");
//	printf("moi nhap lua chon cua ban: ");
//}
////
//void Create_Slist(SList& l) {
//	l.Head = NULL;
//	l.Tail = NULL;
//}
//void Create_KQlist(KQList& l) {
//	l.Head = NULL;
//	l.Tail = NULL;
//}
//void Input_File(SList& l) {
//	FILE* L = fopen("sv.txt", "r");
//	char MSSV[20];
//	while (fscanf(L,"%[^#]s",MSSV)!=EOF)
//	{
//		insertTail(l,ReadSlist(l,MSSV,L));
//	}
//	fclose(L);
//}
//SNODE*ReadSlist(SList& l, char MSSV[],FILE*L) {
//	char c;
//	SNODE* p = new SNODE;
//	p->Next = NULL;
//	fscanf(L,"%c", &c);
//	strcpy(p->Info.mssv, MSSV);
//	fscanf(L, "%[^#]s", p->Info.ho_dem);
//	fscanf(L,"%c", &c);
//	fscanf(L, "%[^#]s", p->Info.ten);
//	fscanf(L,"%c", &c);
//	fscanf(L, "%d", &p->Info.namsinh);
//	Create_KQlist(p->Info.KQ);
//	while (ReadKQList(p->Info.KQ, L));
//	return p;
//}
//int ReadKQList(KQList& kq, FILE* L) {
//	char c;
//	KQNODE* P = new KQNODE;
//	P->Next = NULL;
//	fscanf(L, "%c", &c);
//	if (c== '\n')return 0;
//	fscanf(L, "%[^#]s",P->Info.Ma_mon);
//	fscanf(L, "%c", &c);
//	fscanf(L, "%[^#]s", P->Info.Ten_Mon);
//	fscanf(L, "%c", &c);
//	fscanf(L, "%d", &P->Info.tinchi);
//	fscanf(L, "%c", &c);
//	fscanf(L, "%f", &P->Info.DTL);
//	fscanf(L, "%c", &c);
//	fscanf(L, "%f", &P->Info.DCK);
//	P->Info.DMH = P->Info.DTL * 0.3 + P->Info.DTL * 0.7;
//	insertTail_KQ(kq, P);
//	return 1;
//}
//int insertHead(SList& l, SNODE* p) {
//	if (p == NULL)return 0;//p trong thi ko add dc
//	if (l.Head == NULL) //dau trong thi gan thang
//	{
//		l.Head = p;
//		l.Tail = p;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		p->Next = l.Head;
//		l.Head = p;
//		return 1;
//	}
//}
//int insertTail(SList& l, SNODE* p) {
//	if (p == NULL)return 0;//p trong thi ko add dc
//	if (l.Head == NULL) //dau trong thi gan thang
//	{
//		l.Head = p;
//		l.Tail = p;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		l.Tail->Next = p;
//		l.Tail = p;
//		return 1;
//	}
//}
//int insertTail_KQ(KQList& kq, KQNODE*P) {
//	if (P == NULL)return 0;//p trong thi ko add dc
//	if (kq.Head == NULL) //dau trong thi gan thang
//	{
//		kq.Head = P;
//		kq.Tail = P;
//		return 1;
//	}
//	else {
//		//gan nhu bth
//		kq.Tail->Next = P;
//		kq.Tail = P;
//		return 1;
//	}
//}
////
//void Print_1_Slist(SNODE* i) {
//	printf("%-20s %-20s %-20s %-10s\n", "MA SINH VIEN", "HO DEM", "TEN SINH VIEN", "NAM SINH");
//	printf("%-20s %-20s %-20s %-10d\n", i->Info.mssv, i->Info.ho_dem, i->Info.ten, i->Info.namsinh);
//}
//void Print_Slist(SList l) {
//
//	for (SNODE* i = l.Head; i !=NULL ; i=i->Next)
//	{
//		Print_1_Slist(i);
//		printf("====================================================================================================\n");
//		Print_KQList(i->Info.KQ);
//		printf("====================================================================================================\n");
//	}
//}
//void Print_KQList(KQList kq) {
//	printf("%-20s %-20s %-10s %-10s %-10s %-10s\n", "MA MON", "TEN MON", "TIN CHI", "TIEU LUAN", "CUOI KI", "TONG MON HOC");
//	for (KQNODE* i = kq.Head; i != NULL ; i=i->Next)
//	{
//		printf("%-20s %-20s %-10d %-10.2f %-10.2f %-10.2f\n", i->Info.Ma_mon, i->Info.Ten_Mon, i->Info.tinchi, i->Info.DTL, i->Info.DCK, i->Info.DMH);
//	}
//}
//void Print_MSSV_X(SList l) {
//	char MSSV[20];
//	printf("nhap MSSV: ");
//	rewind(stdin);
//	gets_s(MSSV);
//	int flag = 1;
//	for (SNODE* i = l.Head; i !=NULL ; i=i->Next)
//	{
//		if (_strcmpi(i->Info.mssv, MSSV) == 0) {
//			Print_1_Slist(i);
//			flag = 0;
//		}
//			
//	}
//	if (flag)printf("ko thay sinh vien X");
//}
//void Print_Name_X(SList l) {
//	char NAME[20];
//	printf("nhap ten: ");
//	rewind(stdin);
//	gets_s(NAME);
//	int flag = 1;
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		if (_strcmpi(i->Info.ten, NAME) == 0) {
//			Print_1_Slist(i);
//			flag = 0;
//		}
//	}
//	if (flag)printf("ko thay sinh vien X");
//}
//void Sort_MSSV(SList& l) {
//	for (SNODE* i = l.Head; i !=NULL ; i=i->Next)
//	{
//		for (SNODE* j = i->Next; j !=NULL ; j=j->Next)
//		{
//			if (_strcmpi(i->Info.mssv, j->Info.mssv) > 0) {
//				SNODE* temp = new SNODE;
//				temp->Info = i->Info;
//				i->Info = j->Info;
//				j->Info = temp->Info;
//			}
//		}
//	}
//}
//void Sort_NAME(SList& l) {
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		for (SNODE* j = i->Next; j != NULL; j = j->Next)
//		{
//			if (_strcmpi(i->Info.ten, j->Info.ten) > 0) {
//				SNODE* temp = new SNODE;
//				temp->Info = i->Info;
//				i->Info = j->Info;
//				j->Info = temp->Info;
//			}
//		}
//	}
//}
//
//int deleteHead(SList& l)
//{
//	if (l.Head == NULL) //list trong
//	{
//		return 0;
//	}
//	else {
//		SNODE* p = l.Head;
//		l.Head = p->Next;
//		delete p;
//		return 1;
//	}
//}
//int deleteTail(SList& l)
//{
//	if (l.Head == NULL) //list trong
//	{
//		return 0;
//	}
//	else {
//		SNODE* p = l.Head;
//		//cho chay den vi tri gan cuoi cua list
//		for (; p != NULL; p = p->Next)
//		{
//			if (_strcmpi(p->Next->Info.mssv,l.Tail->Info.mssv)==0)break;
//		}
//		delete p->Next;
//		p->Next = NULL;
//		return 1;
//	}
//}
//int Remove_Node_MSSV(SList& l, char String[])
//{
//	if (l.Head == NULL) //list trong
//	{
//		return 0;
//	}
//	else {
//
//
//		SNODE* child = l.Head, * Parent = child;
//		for (; child != NULL; child = child->Next)
//		{
//			if (_strcmpi(child->Info.mssv,String)==0)break;
//			Parent = child;
//		}
//		//xu ly 2 truong hop roi vao head va tail
//		if (_strcmpi(child->Info.mssv, l.Head->Info.mssv) == 0) {
//			deleteHead(l);
//			return 1;
//		}
//		else if (_strcmpi(child->Info.mssv, l.Tail->Info.mssv) == 0) {
//			deleteTail(l);
//			return 1;
//		}
//		Parent->Next = child->Next;
//		child->Next = NULL;
//		delete child;
//		return 1;
//	}
//}
//int Remove_Node_Name(SList& l, char String[])
//{
//	if (l.Head == NULL) //list trong
//	{
//		return 0;
//	}
//	else {
//
//
//		SNODE* child = l.Head, * Parent = child;
//		for (; child != NULL; child = child->Next)
//		{
//			if (_strcmpi(child->Info.ten, String) == 0)break;
//			Parent = child;
//		}
//		//xu ly 2 truong hop roi vao head va tail
//		if (_strcmpi(child->Info.ten, l.Head->Info.ten) == 0) {
//			deleteHead(l);
//			return 1;
//		}
//		else if (_strcmpi(child->Info.ten, l.Tail->Info.ten) == 0) {
//			deleteTail(l);
//			return 1;
//		}
//		Parent->Next = child->Next;
//		child->Next = NULL;
//		delete child;
//		return 1;
//	}
//}
//float calculator_score(KQList l) {
//	float sum = 0;
//	int count = 0;
//	for (KQNODE* i = l.Head; i != NULL; i=i->Next)
//	{
//		sum += i->Info.DMH * i->Info.tinchi;
//		count += i->Info.tinchi;
//	}
//	return 1.0*sum / count;
//}
//void create_NewList(SList l , SList&New) {
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		for (SNODE* j = i->Next; j != NULL; j = j->Next)
//		{
//			if (calculator_score(i->Info.KQ) < calculator_score(j->Info.KQ)) {
//				SNODE* temp = new SNODE;
//				temp->Info = i->Info;
//				i->Info = j->Info;
//				j->Info = temp->Info;
//			}
//		}
//	}
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		SNODE* temp = new SNODE;
//		temp->Next = NULL;
//		temp->Info = i->Info;
//		insertTail(New, temp);
//	}
//}
//void Print_Kha(SList l) {
//	printf("danh sach sinh vien loai kha\n");
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		if (calculator_score(i->Info.KQ) < 8.5 && calculator_score(i->Info.KQ)>7.5) {
//			Print_1_Slist(i);
//			printf("====================================================================================================\n");
//			Print_KQList(i->Info.KQ);
//			printf("====================================================================================================\n");
//		}	
//	}
//}
//void Max_score(SList l) {
//	printf("danh sach sinh vien loai kha\n");
//	SNODE* k = l.Head;
//	for (SNODE* i = l.Head->Next; i != NULL; i = i->Next)
//	{
//		if (calculator_score(k->Info.KQ) <  calculator_score(i->Info.KQ)) {
//			k = i;
//		}
//	}
//	printf("hoc sinh cao diem nhat la\n");
//	Print_1_Slist(k);
//	printf("====================================================================================================\n");
//	Print_KQList(k->Info.KQ);
//	printf("====================================================================================================\n");
//}
//void Min_score(SList l) {
//	printf("danh sach sinh vien loai kha\n");
//	SNODE* k = l.Head;
//	for (SNODE* i = l.Head->Next; i != NULL; i = i->Next)
//	{
//		if (calculator_score(k->Info.KQ) > calculator_score(i->Info.KQ)) {
//			k = i;
//		}
//	}
//	printf("hoc sinh cao thap nhat la\n");
//	Print_1_Slist(k);
//	printf("====================================================================================================\n");
//	Print_KQList(k->Info.KQ);
//	printf("====================================================================================================\n");
//}
//void Min_gioi(SList l) {
//	SNODE* k = l.Head;
//	int flag = 0;
//	for (SNODE* i = l.Head; i !=NULL ; i=i->Next)
//	{
//		if (calculator_score(i->Info.KQ) >= 8.5 ) {
//			flag = 1;
//			if (calculator_score(i->Info.KQ) < calculator_score(k->Info.KQ))k = i;
//		}
//	}
//	if (flag) {
//		printf("hoc sinh gioi thap nhat la\n");
//		Print_1_Slist(k);
//		printf("====================================================================================================\n");
//		Print_KQList(k->Info.KQ);
//		printf("====================================================================================================\n");
//	}
//	else printf("ko co hsg");
//	
//}
//void gan_x(SList l,float x) {
//	SNODE* k = l.Head;
//	for (SNODE* i = l.Head; i != NULL; i = i->Next)
//	{
//		if (fabs(calculator_score(i->Info.KQ)-x)< fabs(calculator_score(k->Info.KQ) - x)) {
//			k = i;
//		}
//	}
//	printf("hoc sinh gan voi %.2f nhat la\n",x);
//	Print_1_Slist(k);
//	printf("====================================================================================================\n");
//	Print_KQList(k->Info.KQ);
//	printf("====================================================================================================\n");
//}