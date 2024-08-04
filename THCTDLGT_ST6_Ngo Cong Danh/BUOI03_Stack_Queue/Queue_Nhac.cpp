/*
Họ và tên:Ngô Công Danh
Lớp:THCTDL&GT ST6
*/
// =======================================================================================
// Library:
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Variables: ----------------------------------------------------------------------------
struct BaiHat
{
	char TenBH[31];
	char TenNS[26];
	char TenCS[26];
	int ThoiLuong;
};

typedef BaiHat ItemType;

struct QueueNode {
	ItemType Info;
	QueueNode* Next;
};

struct Queue
{
	QueueNode* Head;
	QueueNode* Tail;
};

// Funtions: -----------------------------------------------------------------------------
QueueNode* createQueueNode(ItemType x);
void showQueueNode(QueueNode* p);

void initSList(Queue& qu);
int isEmpty(Queue qu);
void showSList(Queue s1);
int insert(Queue& qu, QueueNode* p);

void createSList_ByHand(Queue& qu);
void createSList_Random(Queue& qu);

void showMenu();
void process();

QueueNode* findQueueNode_theoTenBH(Queue qu, char tenBH[]);
int remove(Queue& qu, ItemType& x);

void nhapTTBaiHat(ItemType& x);
void xuatTTBaiHat(ItemType x);
void loadTTBaiHat(FILE* fi, ItemType& x);
void createSList_LoadTextFile(Queue& qu, char tenFile[]);

int listenTime(Queue qu);
void moveToHead(Queue& qu, char tenBH[], ItemType& x);

// =======================================================================================
// Main:
void main()
{
	process();
	_getch();
}

// =======================================================================================
// Define:

// Menu:
void showMenu()
{
	printf("\n****************************************************************");
	printf("\n*                                MENU                          *");
	printf("\n****************************************************************");
	printf("\n* 0. Thoat chuong trinh                                        *");
	printf("\n* 1. Nhap thong tin bai hat moi                                *");
	printf("\n* 2. Tao mot hang doi (Nhap truc tiep tu ban phim)             *");
	printf("\n* 3. Tao mot hang doi (Doc tu File)                            *");
	printf("\n* 4. Tim kiem mot bai hat trong hang doi                       *");
	printf("\n* 5. Xem noi dung hang doi                                     *");
	printf("\n* 6. Xoa node dau hang doi                                     *");
	printf("\n****************************************************************");
}

// Xu li:
void process()
{
	char tenFile[] = "baihat.txt";
	int kq;
	char tenBH[31];
	ItemType X, Y;
	QueueNode* P, * Q;
	Queue SL;
	initSList(SL);

	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf_s("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
		{
			nhapTTBaiHat(X);
			P = createQueueNode(X);
			printf("\nTHONG TIN BAI HAT MOI VUA NHAP LA: \n");
			showQueueNode(P);
			break;
		}
		case 2:
		{
			createSList_ByHand(SL);
			printf("\nNOI DUNG CUA HANG DOI VUA NHAP LIEU LA: ");
			showSList(SL);
			break;
		}
		case 3:
		{
			createSList_LoadTextFile(SL, tenFile);
			printf("\nDANH SACH VUA LOA TU FILE LA: ");
			showSList(SL);
			break;
		}
		case 4:
		{
			rewind(stdin);
			printf("Nhap ten bai hat muon tim: "); fflush(stdin); gets_s(tenBH);
			P = findQueueNode_theoTenBH(SL, tenBH);
			if (P != NULL)
			{
				printf("Tim thay %s trong hang doi.", tenBH);
			}
			else
			{
				printf("Khong tim thay %s trong hang doi.", tenBH);
			}
			break;
		}
		case 5:
		{
			printf("\nNOI DUNG HANG DOI LA: ");
			break;
		}
		case 6:
		{
			kq = remove(SL, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG CUA HANG DOI SAU KHI XOA NODE DAU LA: ");
				showSList(SL);
			}
			else
			{
				printf("Khong the xoa node dau hang doi.");
			}
			break;
		}
		}
	} while (luaChon != 0);
}

// Tao node:
QueueNode* createQueueNode(ItemType x)
{
	QueueNode* p = new QueueNode;
	if (p == NULL)
	{
		printf("Khong the cap phat node moi");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

// In ra node:
void showQueueNode(QueueNode* p)
{
	xuatTTBaiHat(p->Info);
}

// Khoi tao ds rong:
void initSList(Queue& qu)
{
	qu.Head = NULL;
	qu.Tail = NULL;
}

// Kiem tra rong:
int isEmpty(Queue qu)
{
	if (qu.Head == NULL)
	{
		return 1;
	}
	else {
		return 0;
	}
}

// In ra Queue:
void showSList(Queue qu)
{
	if (isEmpty(qu) == 1)
	{
		printf("Danh sach rong.");
		return;
	}
	printf("\n%-5s%-31s%-26s%-26s%-10s", "STT", "TEN BAI HAT", "TEN NHAC SI", "TEN CA SI", "THOI LUONG");
	int stt = 1;
	QueueNode* p = qu.Head;
	while (p != NULL)
	{
		printf("\n%-5d", stt++);
		showQueueNode(p);
		p = p->Next;
	}
}

// Them node Head:
int insert(Queue& qu, QueueNode* p)
{
	if (p == NULL)
	{
		return 0;
	}
	if (isEmpty(qu) == 1)
	{
		qu.Head = p;
		qu.Tail = p;
	}
	else
	{
		qu.Tail->Next = p;
		qu.Tail = p;
	}
	return 1;
}

// Tao dslk don bang tay:
void createSList_ByHand(Queue& qu)
{
	initSList(qu);
	int n;
	do
	{
		printf("Cho biet so node can tao: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		nhapTTBaiHat(x);

		QueueNode* p = createQueueNode(x);
		if (insert(qu, p) == 0) continue;
	}
}

// Tao dslk don tu dong:
void createSList_LoadTextFile(Queue& qu, char tenFile[])
{
	FILE* fi = fopen(tenFile, "rt");
	if (fi == NULL)
	{
		printf("Loi doc file %s.", tenFile);
		return;
	}
	initSList(qu);
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		ItemType x;
		loadTTBaiHat(fi, x);
		QueueNode* p = createQueueNode(x);
		if (insert(qu, p) == 0) continue;
	}
}

// Tim kiem mot node:
QueueNode* findQueueNode_theoTenBH(Queue qu, char tenBH[])
{
	QueueNode* p = qu.Head;
	while (p != NULL)
	{
		if (_strcmpi(p->Info.TenBH, tenBH) == 0)
		{
			return p;
		}
		p = p->Next;
	}
	return NULL;
}

// Xoa dau:
int remove(Queue& qu, ItemType& x)
{
	if (isEmpty(qu) == 1)
	{
		return 0;
	}
	QueueNode* p = qu.Head;
	qu.Head = qu.Head->Next;
	if (qu.Head == NULL)
	{
		qu.Tail = NULL;
	}
	x = p->Info;
	delete p;
	return 1;
}

// Nhap thong tin bai hat:
void nhapTTBaiHat(ItemType& x)
{
	rewind(stdin);
	printf("Nhap ten bai hat: "); fflush(stdin); gets_s(x.TenBH);
	printf("Nhap ten nhac si: "); fflush(stdin); gets_s(x.TenNS);
	printf("Nhap ten ca si: "); fflush(stdin); gets_s(x.TenCS);
	printf("Nhap thoi luong: "); scanf_s("%d", &x.ThoiLuong);
}

//  Xuat thong tin bai hat:
void xuatTTBaiHat(ItemType x)
{
	printf("%-31s%-26s%-26s%-10d", x.TenBH, x.TenNS, x.TenCS, x.ThoiLuong);
}

// Nhap thong tin tu file:
void loadTTBaiHat(FILE* fi, ItemType& x)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.TenBH, &x.TenNS, &x.TenCS, &x.ThoiLuong);
}

// Tinh thoi luong nghe het playlist:
int listenTime(Queue qu)
{
	int kq = 0;
	QueueNode* p = qu.Head;
	while (p != NULL)
	{
		kq += p->Info.ThoiLuong;
		p = p->Next;
	}
	return kq;
}

