/*==========================================================================
////Họ và tên:Ngô Công Danh
////Lớp:THCTDL&GT ST6
==========================================================================*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
struct BaiHat
{
	char tenBH[50], tenNS[40],tenCS[30];
	int time;
};
typedef BaiHat Itemtype;
struct SNode
{
	BaiHat Info;
	SNode* Next;
};
struct SList
{
	SNode* Head;
	SNode* Tail;
};
//tao list
void initSList(SList& l);
//add
int InsertHead(SList& l, SNode* p);
int InsertTail(SList& l, SNode* p);
//tao node;
SNode* Create_NODE( char name[50], char TG[40], char Singel[30], int time);
//doc tu file
void Input_File(SList& l, char tenFile[]);
//menu
void Menu();
//in 
void xuatTBaiHat(Itemtype x);
void showSlist(SList l);
//thời luong nghe
void Time_listen(SList l);
//add 1 bai
void Add_1baihat(SList& l);
//xoa
int deleteTail(SList& l);
int deleteHead(SList& l);
int Remove(SList& l, char Name[]);
//tim x
int Find_X(SList l, char Name[]);
//sort
void Sort_Ten_BH(SList& l);
void Sort_Ten_NS(SList& l);
//
int ADD_X_lendau(SList& l, char tenBH[]);
void loadBaiHat(FILE* fi, Itemtype& x);
SNode* createQueueNode(Itemtype x);
int isEmpty(SList l);

int main() {
	SList l;
	char tenFile[] = "dsbaihat.txt";
	initSList(l);
	int choice = -1;
	do
	{
		system("cls");
		Menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Input_File(l,tenFile);
			printf("doc thanh cong");
			_getch();
			break;
		case 2:
			showSlist(l);
			_getch();
			break;
		case 3:
			Time_listen(l);
			_getch();
			break;
		case 4:
			Add_1baihat(l);
			_getch();
			break;
		case 5: {
			char name[50];
			printf("nhap ten bai hat: ");
			rewind(stdin);
			gets_s(name);
			if (Remove(l, name))printf("xoa thanh cong");
			else printf("xoa khong thanh cong");
			_getch();
		}
			break;
		case 6: {
			char name[50];
			printf("nhap ten bai hat: ");
			rewind(stdin);
			gets_s(name);
			if (Find_X(l, name))printf("co trong danh sach");
			else printf("ko co trong danh sach");
				_getch();
		}break;
		case 7: {
			Sort_Ten_BH(l);
			printf("sort thanh cong");
			_getch();
		}  break;
		case 8: {
			Sort_Ten_NS(l);
			printf("sort thanh cong");
			_getch();
		}  break;
		case 9: {
			char name[50];
			printf("nhap ten bai hat: ");
			rewind(stdin);
			gets_s(name);
			if (ADD_X_lendau(l, name))printf("dua len dau thanh cong");
			else printf("dua len dau ko thanh cong");
			_getch();
		}break;
		default:
			break;
		}
	} while (choice!=0);
	return 0;
}
//menu
void Menu() {
	printf("====menu===");
	printf("\n1.Doc File\n2.in danh sach\n3.de nghe het nhac trong list can bn time\n4.them nhac vao dau/cuoi list\n");
	printf("5.xoa 1 bai ra khoi list\n6.kiem tra xem bai nhac X co trong list ko\n7.sap xep theo ten\n8.sap xep giam theo ten nghe si\n9.dua 1 bai hat trong list len dau\n");
	printf("\nvui long nhap lua chon cua ban: ");
}
//tao danh sach
void initSList(SList& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}
void showSNode(SNode* p) {
	xuatTBaiHat(p->Info);
}
//tao node
SNode* Create_NODE( char name[50],char TG[40],char Singel[30],int time) {
	SNode* temp = new SNode;
	strcpy(temp->Info.tenBH, name);
	strcpy(temp->Info.tenNS, TG);
	strcpy(temp->Info.tenCS, Singel);
	temp->Info.time = time;
	temp->Next = NULL;
	return temp;

}
SNode* createQueueNode(Itemtype x) {
	SNode* p = new SNode;
	if (p == NULL) {
		printf("Khong du bo nho cap phat!");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//doc tu file
void Input_File(SList& l, char tenFile[]) {
	FILE* fi = fopen(tenFile, "rt");
	if (fi == NULL) {
		printf("Loi doc file %s.", tenFile);
		return;
	}
	initSList(l);
	int n;
	fscanf(fi, "%d\n", &n);// đọc số lương bài hat
	for (int i = 0; i < n; i++)
	{
		Itemtype x;
		loadBaiHat(fi, x);
		SNode* p = createQueueNode(x);
		if (InsertHead(l, p) == 0)
			continue;
	}

	//char c;
	//char tenBH[50], TenNS[40], tenCS[30];
	//int time;
	////dieu kien den khi nao gap EOF(END OF FILE)=> nghia la chay den cuoi file ko co j de doc nua
	//while (fscanf(fi, "%[^#]s ", tenBH)!=EOF)
	//{
	//	
	//	//%c lay dau #
	//	fscanf(fi, "%c ", &c);
	//	fscanf(fi, "%[^#]s ", TenNS);
	//	fscanf(fi, "%c ", &c);
	//	fscanf(fi, "%[^#]s ", tenCS);
	//	fscanf(fi, "%c ", &c);
	//	fscanf(fi, "%d\n", &time);
	//	//add vao duoi
	//	InsertTail(l, Create_NODE(tenBH, TenNS, tenCS, time));
	//}
}
int isEmpty(SList l) {
	if (l.Head = NULL)
		return 1;
	else
		return 0;
}
//add
int InsertHead(SList& l, SNode* p) {
		if (p == NULL)
		return 0;
	if (isEmpty(l) == 1) {
		l.Head = p;
		l.Tail = p;
	}
	else {
		p->Next = l.Head;
		l.Head = p;
	}
	return 1;
}
int InsertTail(SList& l, SNode* p) {
	if (p == NULL)
		return 0;
	if (isEmpty(l) == 1) {
		l.Head = p;
		l.Tail = p;
	}
	else {
		l.Tail->Next = p;
		l.Tail = p;

	}
	return 1;
}
void loadBaiHat(FILE* fi, Itemtype& x)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.tenBH, &x.tenCS, &x.tenNS, &x.time);
}
//in
void xuatTBaiHat(Itemtype x)
{
	printf("%-31s%-26s%-26s%-10d", x.tenBH, x.tenNS, x.tenCS, x.time);
}
void showSlist(SList l) {
	if (isEmpty(l) == 1)
	{
		printf("\nDanh sach rong!");
		return;
	}
	printf("\n%-5s%-31s%-26s%-26s%-10s", "STT", "TEN BAI HAT", "TEN NHAC SI", "TEN CA SI", "THOI LUONG");

	int stt = 1;
	SNode* p = l.Head;
	while (p != NULL) {
		printf("\n%d ", stt++);
		showSNode(p);
		p = p->Next;
	}
}
//time nghe all list
void Time_listen(SList l) {
	if (l.Head == NULL)return;
	int sum = 0;
	for (SNode* p = l.Head; p !=NULL ; p=p->Next)
	{
		sum += p->Info.time;
	}
	printf("%d Hours:%d Minute:%d Seconds", sum / 3600, (sum%3600)/ 60 , sum % 60);
}
void Add_1baihat(SList& l) {
	char name[50], TG[40], Singel[30];
	int time;
	printf("nhap ten bai hat: ");rewind(stdin);gets_s(name);
	printf("nhap ten tac gia: ");rewind(stdin);gets_s(TG);
	printf("nhap ten Nghe Si: ");rewind(stdin);gets_s(Singel);
	printf("nhap thoi luong (so s): ");scanf("%d", &time);
	int choice = -1;
	do
	{
		printf("1.add dau\n2.add cuoi\n");
		printf("nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: {
			if (InsertHead(l, Create_NODE(name, TG, Singel, time)))printf("add thanh cong");
			else printf("add ko thanh cong");
			_getch();
			break;
		}
		case 2: {
			if (InsertTail(l, Create_NODE(name, TG, Singel, time)))printf("add thanh cong");
			else printf("add ko thanh cong");
			_getch();
			break;
		}
		default:
			break;
		}
	} while (choice!=1&&choice!=2);
	
}

int deleteHead(SList& l)
{
	if (l.Head == NULL) //list trong
	{
		return 0;
	}
	else {
		SNode* p = l.Head;
		l.Head = p->Next;
		delete p;
		return 1;
	}
}
int deleteTail(SList& l)
{
	if (l.Head == NULL) //list trong
	{
		return 0;
	}
	else {
		SNode* p = l.Head;
		//cho chay den vi tri gan cuoi cua list
		for (; p != NULL; p = p->Next)
		{
			if (_strcmpi(p->Next->Info.tenBH,l.Tail->Info.tenBH)==0)break;
		}
		delete p->Next;
		p->Next = NULL;
		return 1;
	}
}
int Remove(SList& l, char Name[]) {// stricmp và strcmpi là tương đương nhau tuỳ vào phiên bản hỗ trợ
	if (l.Head == NULL)return 0;
	SNode* child = l.Head, *parent = child;
	for (child; child != NULL; child = child->Next)
	{
		if (_stricmp(child->Info.tenBH, Name) == 0)break;
		parent = child;
	}
	if (_stricmp(child->Info.tenBH, l.Head->Info.tenBH) == 0) {
		deleteHead(l);
		return 1;
	}
	if (_stricmp(child->Info.tenBH, l.Tail->Info.tenBH) == 0) {
		deleteTail(l);
		return 1;
	}
	parent->Next = child->Next;
	delete child;
	return 1;
}
int Find_X(SList l, char Name[]) {
	if (l.Head == NULL)return 0;
	for (SNode* i = l.Head; i !=NULL ; i=i->Next)
	{
		if (_strcmpi(Name, i->Info.tenBH) == 0)return 1;
	}
	return 0;
}
//sort
void Sort_Ten_BH(SList& l) {
	if (l.Head == NULL)return;
	for (SNode* i = l.Head; i !=NULL ; i=i->Next)
	{
		for (SNode* j = i->Next; j !=NULL ; j=j->Next)
		{
			if (_strcmpi(i->Info.tenBH, j->Info.tenBH) > 0) {
				SNode* temp = new SNode;
				temp->Info = i->Info;
				i->Info = j->Info;
				j->Info = temp->Info;
			}
		}
	}
}
void Sort_Ten_NS(SList& l) {
	if (l.Head == NULL)return;
	for (SNode* i = l.Head; i != NULL; i = i->Next)
	{
		for (SNode* j = i->Next; j != NULL; j=j->Next)
		{
			if (_strcmpi(i->Info.tenCS, j->Info.tenCS) < 0) {
				SNode* temp = new SNode;
				temp->Info = i->Info;
				i->Info = j->Info;
				j->Info = temp->Info;
			}
		}
	}
}
//
int ADD_X_lendau(SList& l, char tenBH[]) {
	if (l.Head == NULL || _strcmpi(tenBH, l.Head->Info.tenBH) == 0)return 0;
	SNode* Parent = l.Head;
	SNode* p = l.Head->Next;
	int flag = 0;
	for (; p != NULL; p = p->Next)
	{
		if (_strcmpi(tenBH, p->Info.tenBH) == 0) {
			flag = 1;
			break;

		}
		Parent = p;
	}
	if (flag) {
		InsertHead(l, Create_NODE(p->Info.tenBH, p->Info.tenNS, p->Info.tenCS, p->Info.time));
		if (_strcmpi(tenBH, l.Tail->Info.tenBH) == 0)deleteTail(l);
		else
		{
			Parent->Next = p->Next;
		}
		return 1;
	}
	return 0;

}