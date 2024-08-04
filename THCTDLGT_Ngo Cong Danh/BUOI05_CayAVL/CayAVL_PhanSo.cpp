#include"AVL_PhanSo.h"
#include"ASCII_PhanSo.h"
// Viết hàm
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996)
//Tạo nút
AVLNode* createAVLNode(Itemtype x) {
	AVLNode* p = new AVLNode;
	if (p == NULL) {
		printf("Khong du bo nho de cap phat nut moi!");
		getch();
		return NULL;
	}
	p->balFactor = EH; // Initialize balance factor as EH
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}

void showavlNode(AVLNode* p) {
	printf("(%d/%d)", p->Info.tu, p->Info.mau);
}

void initAVLTree(AVLTree& avl) {
	avl.Root = NULL;
}




void createAVLTree_ByHand(AVLTree& avl) {
	initAVLTree(avl);
	int n;
	Itemtype x;
	do {
		printf("\nNhap so phan tu cua cay: ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		printf("Nhap tu so thu %d: ", i + 1);
		scanf("%d", &x.tu);
		printf("Nhap mau so thu %d: ", i + 1);
		scanf("%d", &x.mau);
		AVLNode* p = createAVLNode(x);
		insertAVLNode(avl.Root, p);
	}
}

void kiemtraDoiDau(Phanso& x)
{
	if (x.mau < 0)
	{
		x.tu *= -1;
		x.mau *= -1;
	}
}
int UCLN(int x, int y) {
	if (x == 0 || y == 0)
		return 1;
	x = abs(x);
	y = abs(y);
}

void rutGon(Phanso& x){
	kiemtraDoiDau(x);
	int gcd = UCLN(x.tu, x.mau);
	x.tu /= gcd;
	x.mau /= gcd;
}

// Tạo danh sách ngẫu nhiên
void createAVLTree_Random(AVLTree& avl)
{
	initAVLTree(avl);
	int n;
	do {
		printf("\nNhap so phan tu cua cay: ");
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		Itemtype x;
		x.tu = rand() % 199 - 99;// random từ [-99;99] cho tử số
		x.mau = rand() % 199 - 99;// random từ [-99;99] cho mẫu số
		// Đảm bảo mẫu số không bằng 0
		while (x.mau == 0) {
			x.mau = rand() % 199 - 99;
		}
		AVLNode* p = createAVLNode(x);
		if (insertAVLNode(avl.Root, p) == 0)continue;
		printf("Them %d vao cay - VE CAY AVL:\n", x);
		print_ascii_tree(avl.Root);
		getch();
	}
}
void createAVLTree_FromArray(AVLTree& avl, Itemtype a[], int n)
{
	initAVLTree(avl);
	for (int i = 0; i < n; i++)
	{
		Itemtype x;
		x = a[i];
		AVLNode* p = createAVLNode(a[i]);
		insertAVLNode(avl.Root, p);
		printf("Them %d vao cay - VE CAY AVL:\n", x);
		print_ascii_tree(avl.Root);
		getch();
	}
}


// Cân bằng lại cây TH LL
void rotateLL(AVLNode*& T) {
	// xoay Left-Left (xoay đơn: xoay 1 lần,con thay cha)
	AVLNode* T1 = T->Left;
	T->Left = T1->Right;
	T1->Right = T;
	switch (T1->balFactor)
	{
	case LH:// T1 lệch trái
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:// T1 cân bằng
		T->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
}
void rotateLR(AVLNode*& T)
{
	// xoay Left-Right (xoay kép:xoay 2 lần, Cháu thay Ông)
	AVLNode* T1 = T->Left;
	AVLNode* T2 = T->Right;
	T1->Right = T2->Left;
	T2->Left = T1;
	T->Left = T2->Right;
	T2->Right = T;
	switch (T2->balFactor)
	{
	case LH:
		T->balFactor = RH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH:
		T->balFactor = EH;
		T1->balFactor = LH;
		break;

	}
	T2->balFactor = EH;
	T = T2;
}
// cân bằng TH: Right-Right
void rotateRR(AVLNode*& T)
{
	// xoay Right-Right (xoay đơn: xoay 1 lần,con thay cha)
	AVLNode* T1 = T->Right;
	T->Right = T1->Left;
	T1->Left = T;
	switch (T1->balFactor)
	{
	case RH:// cây T1 lệch phải
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:// T1 cân bằng
		T->balFactor = RH;
		T1->balFactor = LH;
		break;
	}
	T = T1;
}
void rotateRL(AVLNode*& T)
{
	// xoay Right-Left(xoay kép:xoay 2 lần, Cháu thay Ông)
	AVLNode* T1 = T->Left;
	AVLNode* T2 = T->Right;
	T1->Left = T2->Right;
	T2->Right = T1;
	T->Right = T2->Left;
	T2->Left = T;
	switch (T2->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = RH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH:
		T->balFactor = LH;
		T1->balFactor = EH;
		break;

	}
	T2->balFactor = EH;
	T = T2;
}


//cân bằng khi lệch trái
int balanceLeft(AVLNode*& T) {
	AVLNode* T1 = T->Left;
	switch (T1->balFactor)
	{
	case LH:
		rotateLL(T);
		return 2;
	case EH:
		rotateLL(T);
		return 1;
	case RH:
		rotateLR(T);
		return 2;
	}
	return 0;
}
int balanceRight(AVLNode*& T) {
	AVLNode* T1 = T->Right;
	switch (T1->balFactor)
	{
	case LH:
		rotateRL(T);
		return 2;
	case EH:
		rotateRR(T);
		return 1;
	case RH:
		rotateRR(T);
		return 2;
	}
	return 0;
}


// Thêm nút p vào cây
int insertAVLNode(AVLNode*& T, AVLNode* p) {
	if (!p)
		return -1; // Nút mới p cần được thêm không tồn tại
	if (!T) {
		// Cây rỗng, thêm nút p vào gốc
		T = p;
		return 2; // Chiều cao của cây tăng lên
	}

	// Cây không rỗng
	int result;
	if (T->Info.tu == p->Info.tu && T->Info.mau == p->Info.mau)
		return 0; // Không thể thêm nút trùng lặp
	if (T->Info.tu > p->Info.tu) {
		result = insertAVLNode(T->Left, p);
		if (result < 2)
			return result;

		// Cập nhật chỉ số cân bằng và thực hiện quay nếu cần
		switch (T->balFactor) {
		case RH:
			T->balFactor = EH;
			return 1; // Chiều cao của cây không thay đổi
		case EH:
			T->balFactor = LH;
			return 2; // Chiều cao của cây tăng lên
		case LH:
			balanceLeft(T);
			return 1; // Chiều cao của cây không thay đổi
		}
	}
	else {
		result = insertAVLNode(T->Right, p);
		if (result < 2)
			return result;

		// Cập nhật chỉ số cân bằng và thực hiện quay nếu cần
		switch (T->balFactor) {
		case LH:
			T->balFactor = EH;
			return 1; // Chiều cao của cây không thay đổi
		case EH:
			T->balFactor = RH;
			return 2; // Chiều cao của cây tăng lên
		case RH:
			balanceRight(T);
			return 1; // Chiều cao của cây không thay đổi
		}
	}
}

int searchStandFor(AVLNode*& p, AVLNode*& q)
{
	int result;
	if (q->Left)
	{
		result = searchStandFor(p, q->Left);
		if (result < 2)
			return result;
		switch (q->balFactor)
		{
		case LH:
			q->balFactor = EH;
			return 2;
		case EH:
			q->balFactor = RH;
			return 1;
		case RH:
			return balanceRight(q);
		}
	}
	else
	{
		p->Info = q->Info;
		p = q;
		q = q->Right;
	}
	return 2;
}
int deleteAVLNode(AVLNode*& T, Itemtype x) {
	if (T == NULL)
		return 0; // Cây rỗng, không thể xóa
	int kq;
	if (T->Info.tu > x.tu) {
		kq = deleteAVLNode(T->Left, x);
		if (kq < 2)
			return kq;
		switch (T->balFactor) {
		case LH:
			T->balFactor = EH;
			return 2; // Chiều cao của cây tăng lên
		case EH:
			T->balFactor = RH;
			return 1; // Chiều cao của cây không thay đổi
		case RH:
			return balanceRight(T);
		}
	}
	else if (T->Info.tu < x.tu) {
		kq = deleteAVLNode(T->Right, x);
		if (kq < 2)
			return kq;
		switch (T->balFactor) {
		case RH:
			T->balFactor = EH;
			return 2; // Chiều cao của cây tăng lên
		case EH:
			T->balFactor = LH;
			return 1; // Chiều cao của cây không thay đổi
		case LH:
			return balanceLeft(T);
		}
	}
	else {
		AVLNode* p = T;
		if (T->Left == NULL) {
			T = T->Right;
			kq = 2; // Chiều cao của cây tăng lên
		}
		else {
			if (T->Right == NULL) {
				T = T->Left;
				kq = 2; // Chiều cao của cây tăng lên
			}
			else {
				kq = searchStandFor(p, T->Right);
				if (kq < 2)
					return kq;
				switch (T->balFactor) {
				case RH:
					T->balFactor = EH;
					return 2; // Chiều cao của cây tăng lên
				case EH:
					T->balFactor = LH;
					return 1; // Chiều cao của cây không thay đổi
				case LH:
					return balanceLeft(T);
				}
			}
		}
		delete p;
		return kq;
	}
	return 0; // Trường hợp mặc định, không thể xảy ra
}


void traverseNLR(AVLNode* T)
{
	if (!T)
		return;
	showavlNode(T);
	traverseNLR(T->Left);
	traverseNLR(T->Right);
}
void traverseLRN(AVLNode* T)
{
	if (!T)
		return;
	traverseLRN(T->Left);
	traverseLRN(T->Right);
	showavlNode(T);
}
void traverseLNR(AVLNode* T)
{
	if (!T)
		return;
	traverseLNR(T->Left);
	showavlNode(T);
	traverseLNR(T->Right);
}
void traverseNRL(AVLNode* T) {
	if (!T)
		return;
	showavlNode(T);
	traverseNRL(T->Right);
	traverseNRL(T->Left);

}
void traverseRLN(AVLNode* T) {
	if (!T)
		return;
	traverseRLN(T->Right);
	traverseRLN(T->Left);
	showavlNode(T);

}
void traverseRNL(AVLNode* T) {
	if (!T)
		return;
	traverseRNL(T->Right);
	showavlNode(T);
	traverseRNL(T->Left);
}
AVLNode* findAVLNode(AVLNode* root, Itemtype x) {
	if (root == NULL)
		return NULL;
	if (root->Info.tu == x.tu && root->Info.mau == x.mau)
		return root;
	else if (root->Info.tu > x.tu)
		return findAVLNode(root->Left, x);
	else
		return findAVLNode(root->Right, x);
}

int highTree(AVLNode* T)
{
	if (!T)
		return 0;
	int hl = highTree(T->Left);//chiều cao nhánh trái
	int hr = highTree(T->Right);
	if (hl > hr)
		return (1 + hl);
	else
		return (1 + hr);
}

AVLNode* findavlNodeReplace(AVLNode*& p) {
	AVLNode* f = p;
	AVLNode* q = p->Right;
	while (q->Left != NULL) {
		f = q; // Lưu nút cha q
		q = q->Left; // Di chuyển sang nút lá trái của cây con phải của nút p
	}
	p->Info = q->Info; // Thay thế giá trị của nút p bằng giá trị của nút lá q
	if (f == p)
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
}


void deleteAVLTree(AVLNode*& root)
{
	if (!root)return;
	deleteAVLTree(root->Left);
	deleteAVLTree(root->Right);
	delete root;
	root = NULL;
}

void showavlNodeOfLevelK(AVLNode* T, int k) {
	if (!T)
		return;
	if (k == 0) // Đã đến mức cần tìm
		printf("%4d/%-4d", T->Info.tu, T->Info.mau); // In ra giá trị của nút dưới dạng phân số
	else {
		// Nếu chưa đến mức cần tìm, tiếp tục đi xuống cây con trái và cây con phải
		showavlNodeOfLevelK(T->Left, k - 1);
		showavlNodeOfLevelK(T->Right, k - 1);
	}
}


