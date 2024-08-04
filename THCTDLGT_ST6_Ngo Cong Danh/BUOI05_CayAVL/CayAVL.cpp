//#include"CayAVL_SoNguyen.h"
//#include"ASCII_Node.h"
//// Viết hàm
//#define _CRT_SECURE_NO_WARNINGS 
//#pragma warning(disable : 4996)
////Tạo nút
//AVLNode* createAVLNode(Itemtype x)
//{
//	AVLNode* p = new AVLNode;
//	if (p == NULL)
//	{
//		printf("Khong du bo nho de cap phat nut moi!");
//		getch();
//		return NULL;
//	}
//	p->balFactor = 0; // Hoàn toàn cân bằng
//	p->Info = x;
//	p->Left = NULL;
//	p->Right = NULL;
//	return p;
//}
//// Xuất nội dung nút
//void showBSTNode(AVLNode* p) {
//	printf("%4d", p->Info);
//}
////Khởi tạo danh sách rỗng
//void initAVLTree(AVLTree& avl) {
//	avl.Root = NULL;
//}
//void deleteAVLNode(AVLNode*& p) {
//	// hàm xoá 1 nút ra khỏi bộ nhợ
//	p->Left = NULL;
//	p->Right = NULL;
//	delete p;
//}
////Tạo danh sách bằng cách nhập liệu
//void createAVLTree_ByHand(AVLTree& avl) {
//	initAVLTree(avl);
//	int n;
//	Itemtype x;
//	do {
//		printf("\nNhap so phan tu cua cay: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan tu thu %d la: ", i + 1);
//		scanf("%d", &x);
//		AVLNode* p = createAVLNode(x);
//		if (insertAVLNode(avl.Root, p) == 0)
//			continue;
//	}
//
//}
//// Tạo danh sách ngẫu nhiên
//void createAVLTree_Random(AVLTree& avl)
//{
//	int n;
//	do {
//		printf("\nNhap so phan tu cua cay: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	initAVLTree(avl);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		Itemtype x;
//		x = rand() % 199 - 99;// random từ [-99;99]
//		AVLNode* p = createAVLNode(x);
//		if (insertAVLNode(avl.Root, p) == 0)continue;
//		/*printf("Them %d vao cay - VE CAY AVL:\n", x);
//		print_ascii_tree(avl.Root);
//		getch()*/;
//	}
//}
//// TẠO CÂY TỪ MẢNG A CÓ SẴN DỮ LIỆU
//void createAVLTree_FromArray(AVLTree& avl, Itemtype a[], int n)
//{
//	initAVLTree(avl);
//	for (int i = 0; i < n; i++)
//	{
//		Itemtype x;
//		x = a[i];
//		AVLNode* p = createAVLNode(a[i]);
//		insertAVLNode(avl.Root, p);
//		printf("Them %d vao cay - VE CAY AVL:\n", x);
//		print_ascii_tree(avl.Root);
//		getch();
//	}
//}
//// Cân bằng lại cây TH LL
//void rotateLL(AVLNode*& T) {
//	// xoay Left-Left (xoay đơn: xoay 1 lần,con thay cha)
//	AVLNode* T1 = T->Left;
//	T->Left = T1->Right;
//	T1->Right = T;
//	switch (T1->balFactor)
//	{
//	case LH:// T1 lệch trái
//		T->balFactor = EH;
//		T1->balFactor = EH;
//		break;
//	case EH:// T1 cân bằng
//		T->balFactor = LH;
//		T1->balFactor = RH;
//		break;
//	}
//}
//void rotateLR(AVLNode*& T)
//{
//	// xoay Left-Right (xoay kép:xoay 2 lần, Cháu thay Ông)
//	AVLNode* T1 = T->Left;
//	AVLNode* T2 = T->Right;
//	T1->Right = T2->Left;
//	T2->Left = T1;
//	T->Left = T2->Right;
//	T2->Right = T;
//	switch (T2->balFactor)
//	{
//	case LH:
//		T->balFactor = RH;
//		T1->balFactor = EH;
//		break;
//	case EH:
//		T->balFactor = EH;
//		T1->balFactor = EH;
//		break;
//	case RH:
//		T->balFactor = EH;
//		T1->balFactor = LH;
//		break;
//
//	}
//	T2->balFactor = EH;
//	T = T2;
//}
//// cân bằng TH: Right-Right
//void rotateRR(AVLNode*& T)
//{
//	// xoay Right-Right (xoay đơn: xoay 1 lần,con thay cha)
//	AVLNode* T1 = T->Right;
//	T->Right = T1->Left;
//	T1->Left = T;
//	switch (T1->balFactor)
//	{
//	case RH:// cây T1 lệch phải
//		T->balFactor = EH;
//		T1->balFactor = EH;
//		break;
//	case EH:// T1 cân bằng
//		T->balFactor = RH;
//		T1->balFactor = LH;
//		break;
//	}
//	T = T1;
//}
//void rotateRL(AVLNode*& T)
//{
//	// xoay Right-Left(xoay kép:xoay 2 lần, Cháu thay Ông)
//	AVLNode* T1 = T->Left;
//	AVLNode* T2 = T->Right;
//	T1->Left = T2->Right;
//	T2->Right = T1;
//	T->Right = T2->Left;
//	T2->Left = T;
//	switch (T2->balFactor)
//	{
//	case LH:
//		T->balFactor = EH;
//		T1->balFactor = RH;
//		break;
//	case EH:
//		T->balFactor = EH;
//		T1->balFactor = EH;
//		break;
//	case RH:
//		T->balFactor = LH;
//		T1->balFactor = EH;
//		break;
//
//	}
//	T2->balFactor = EH;
//	T = T2;
//}
//
//
////cân bằng khi lệch trái
//int balanceLeft(AVLNode*& T) {
//	AVLNode* T1 = T->Left;
//	switch (T1->balFactor)
//	{
//	case LH:
//		rotateLL(T);
//		return 2;
//	case EH:
//		rotateLL(T);
//		return 1;
//	case RH:
//		rotateLR(T);
//		return 2;
//	}
//	return 0;
//}
//int balanceRight(AVLNode*& T) {
//	AVLNode* T1 = T->Right;
//	switch (T1->balFactor)
//	{
//	case LH:
//		rotateRL(T);
//		return 2;
//	case EH:
//		rotateRR(T);
//		return 1;
//	case RH:
//		rotateRR(T);
//		return 2;
//	}
//	return 0;
//}
//
//
//// Thêm nút p vào cây
//int insertAVLNode(AVLNode*& T, AVLNode* p) {
//	if (!p)
//		return -1;// nút mới p muốn thêm ko tồn tại
//	if (!T) {
//		// cây rỗng, thêm nút p vào gốc
//		T = p;
//		return 2;
//	}
//	// Cây ko rỗng
//	int result;
//	if (T->Info == p->Info)
//		return 0;// ko thêm dc vì tồn tại nút gtri = x
//	if (T->Info > p->Info) {
//		result = insertAVLNode(T->Left, p);
//		if (result < 2)
//			return result;
//		switch (T->balFactor)
//		{
//		case RH:
//			T->balFactor = EH;
//			return 1;
//		case EH:
//			T->balFactor = LH;
//			return 2;
//		case LH:
//			balanceLeft(T);
//			return 1;
//		}
//	}
//	else
//	{
//		result = insertAVLNode(T->Right, p);
//		if (result < 2)
//			return result;
//		switch (T->balFactor)
//		{
//		case LH:
//			T->balFactor = EH;
//			return 1;
//		case EH:
//			T->balFactor = RH;
//			return 2;
//		case RH:
//			balanceRight(T);
//			return 1;
//		}
//	}
//}
//int searchStandFor(AVLNode*& p, AVLNode*& q)
//{
//	int result;
//	if (q->Left)
//	{
//		result = searchStandFor(p, q->Left);
//		if (result < 2)
//			return result;
//		switch (q->balFactor)
//		{
//		case LH:
//			q->balFactor = EH;
//			return 2;
//		case EH:
//			q->balFactor = RH;
//			return 1;
//		case RH:
//			return balanceRight(q);
//		}
//	}
//	else
//	{
//		p->Info = q->Info;
//		p = q;
//		q = q->Right;
//	}
//	return 2;
//}
//int deleteAVLNode(AVLNode*& T, Itemtype x) {
//	int kq;
//	if (T == NULL)
//		return 0;
//	if (T->Info > x)
//	{
//		kq = deleteAVLNode(T->Left, x);
//		if (kq < 2)
//			return kq;
//		switch (T->balFactor)
//		{
//		case LH:
//			T->balFactor = EH;
//			return 2;
//		case RH:
//			return balanceRight(T);
//		case EH:
//			T->balFactor = LH;
//			return 1;
//
//		}
//	}
//	else if (T->Info < x)
//	{
//		kq = deleteAVLNode(T->Right, x);
//		if (kq < 2)
//			return kq;
//		switch (T->balFactor)
//		{
//		case RH:
//			T->balFactor = EH;
//			return 2;
//		case EH:
//			T->balFactor = LH;
//			return 1;
//		case LH:
//			return balanceLeft(T);
//		}
//	}
//	else
//	{
//		AVLNode* p = T;
//		if (T->Left == NULL)
//		{
//			T = T->Right;
//			kq = 2;
//
//		}
//		else
//		{
//			if (T->Right == NULL) {
//				T = T->Left;
//				kq = 2;
//			}
//			else {
//				kq = searchStandFor(p, T->Right);
//				if (kq < 2)
//					return kq;
//				switch (T->balFactor)
//				{
//				case RH:
//					T->balFactor = EH;
//					return 2;
//				case EH:
//					T->balFactor = LH;
//					return 1;
//				case LH:
//					return balanceLeft(T);
//				}
//			}
//		}
//		delete p;
//		return kq;
//	}
//	return kq;
//}
//
//
//void traverseNLR(AVLNode* T)
//{
//	if (!T)
//		return;
//	showBSTNode(T);
//	traverseNLR(T->Left);
//	traverseNLR(T->Right);
//}
//void traverseLRN(AVLNode* T)
//{
//	if (!T)
//		return;
//	traverseLRN(T->Left);
//	traverseLRN(T->Right);
//	showBSTNode(T);
//}
//void traverseLNR(AVLNode* T)
//{
//	if (!T)
//		return;
//	traverseLNR(T->Left);
//	showBSTNode(T);
//	traverseLNR(T->Right);
//}
//void traverseNRL(AVLNode* T) {
//	if (!T)
//		return;
//	showBSTNode(T);
//	traverseNRL(T->Right);
//	traverseNRL(T->Left);
//
//}
//void traverseRLN(AVLNode* T) {
//	if (!T)
//		return;
//	traverseRLN(T->Right);
//	traverseRLN(T->Left);
//	showBSTNode(T);
//
//}
//void traverseRNL(AVLNode* T) {
//	if (!T)
//		return;
//	traverseRNL(T->Right);
//	showBSTNode(T);
//	traverseRNL(T->Left);
//}
//AVLNode* findAVLNode(AVLNode* root, Itemtype x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->Info == x)
//		return root;
//	else if (root->Info > x)
//		return findAVLNode(root->Left, x);
//	else
//		return findAVLNode(root->Right, x);
//}
//int highTree(AVLNode* T)
//{
//	if (!T)
//		return 0;
//	int hl = highTree(T->Left);//chiều cao nhánh trái
//	int hr = highTree(T->Right);
//	if (hl > hr)
//		return (1 + hl);
//	else
//		return (1 + hr);
//}
//AVLNode* findBSTNodeReplace(AVLNode*& p)
//{
//	AVLNode* f = p;
//	AVLNode* q = p->Right;
//	while (q->Left != NULL)
//	{
//		f = q;// lưu nút cha q
//		q = q->Left;// q qua bên trái
//	}
//	p->Info = q->Info; // q thế mạng cho p
//	if (f == p)
//		f->Right = q->Right;
//	else
//		f->Left = q->Right;
//	return q;
//
//}
//
//void deleteAVLTree(AVLNode*& root)
//{
//	if (!root)return;
//	deleteAVLTree(root->Left);
//	deleteAVLTree(root->Right);
//	delete root;
//	root = NULL;
//}
//
//void showBSTNodeOfLevelK(AVLNode* T, int k)
//{
//	if (!T)
//		return;
//	if (k == 0)// đến mức cần tìm
//		printf("%4d", T->Info);
//	k--;//mức k giảm về 0
//	showBSTNodeOfLevelK(T->Left, k);
//	showBSTNodeOfLevelK(T->Right, k);
//}
//
