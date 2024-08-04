//#include"CayNPTK_SoNguyen.h"
//// Viết hàm
//#define _CRT_SECURE_NO_WARNINGS
////Tạo nút
//BSTNode* createBSTNode(Itemtype x) {
//	BSTNode* p = new BSTNode;
//	if (p == NULL) {
//		printf("Khong du bo nho cap phat!");
//		_getch();
//		return NULL;
//	}
//	p->Info = x;
//	p->Left = NULL;
//	p->Right = NULL;
//	return p;
//}
//
//// Xuất nội dung nút
//void showBSTNode(BSTNode* p) {
//	printf("%4d", p->Info);
//}
////Khởi tạo danh sách rỗng
//void initBSTree(BSTree& bst) {
//	bst.Root = NULL;
//}
//
//
////Tạo danh sách bằng cách nhập liệu
//void createBSTree_ByHand(BSTree& bst) {
//	initBSTree(bst);
//	int n;
//	Itemtype x;
//	do {
//		printf("\nNhap so phan tu cua cay: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	for (int i = 0; i < n; i++) {
//		printf("Nhap phan tu thu %d la: ", i + 1);
//		scanf("%d", &x);
//		BSTNode* p = createBSTNode(x);
//		if (insertBSTNode(bst.Root, p) == 0)
//			continue;
//	}
//
//}
//// Tạo danh sách ngẫu nhiên
//void createBSTree_Random(BSTree& bst)
//{
//	initBSTree(bst);
//	int n;
//	do {
//		printf("\nNhap so phan tu cua cay: ");
//		scanf("%d", &n);
//	} while (n <= 0);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		Itemtype x;
//		x = rand() % 199 - 99;// random từ [-99;99]
//		BSTNode* p = createBSTNode(x);
//		if (insertBSTNode(bst.Root, p) == 0)continue;
//	}
//}
//// TẠO CÂY TỪ MẢNG A CÓ SẴN DỮ LIỆU
//void createBSTree_FromArray(BSTree& bst, Itemtype a[], int n)
//{
//	initBSTree(bst);
//	for (int i = 0; i < n; i++)
//	{
//		BSTNode* p = createBSTNode(a[i]);
//		insertBSTNode(bst.Root, p);
//	}
//}
//
//
//// Thêm nút p vào cây
//int insertBSTNode(BSTNode*& root, BSTNode* p) {
//	if (!p)
//		return 0;
//	if (!root)// TH1: Cây NPTK rỗng
//	{
//		root = p;// thêm vào gốc
//		return 1;
//	}
//	if (root->Info == p->Info)// TH2:Cây NPTK ko rỗng, bị trùng khoá
//		return 0;
//	else if (root->Info > p->Info)
//		//TH3:Cây NPTK ko rỗng, thêm p vào nhánh trái
//		return insertBSTNode(root->Left, p);
//	else//TH4:Cây NPTK ko rỗng, thêm p vào nhánh phải
//		return insertBSTNode(root->Right, p);
//	return 1;
//}
//void traverseNLR(BSTNode* root)
//{
//	if (!root)
//		return;
//	showBSTNode(root);
//	traverseNLR(root->Left);
//	traverseNLR(root->Right);
//}
//void traverseLRN(BSTNode* root)
//{
//	if (!root)
//		return;
//	traverseLRN(root->Left);
//	traverseLRN(root->Right);
//	showBSTNode(root);
//}
//void traverseLNR(BSTNode* root)
//{
//	if (!root)
//		return;
//	traverseLNR(root->Left);
//	showBSTNode(root);
//	traverseLNR(root->Right);
//}
//void traverseNRL(BSTNode* root) {
//	if (!root)
//		return;
//	showBSTNode(root);
//	traverseNRL(root->Right);
//	traverseNRL(root->Left);
//
//}
//void traverseRLN(BSTNode* root) {
//	if (!root)
//		return;
//	traverseRLN(root->Right);
//	traverseRLN(root->Left);
//	showBSTNode(root);
//
//}
//void traverseRNL(BSTNode* root) {
//	if (!root)
//		return;
//	traverseRNL(root->Right);
//	showBSTNode(root);
//	traverseRNL(root->Left);
//}
//BSTNode* findBSTNode(BSTNode* root, Itemtype x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->Info == x)
//		return root;
//	else if (root->Info > x)
//		return findBSTNode(root->Left, x);
//	else
//		return findBSTNode(root->Right, x);
//}
//void showNodeGreaterX(BSTNode* root, Itemtype x) {
//	if (!root)
//		return;
//	// Nếu giá trị của nút lớn hơn x, in giá trị và tiếp tục với nút con bên trái
//	if (root->Info > x) {
//		printf("%d ", root->Info);
//		showNodeGreaterX(root->Left, x);
//		showNodeGreaterX(root->Right, x);
//	}
//	 //Nếu giá trị của nút nhỏ hơn hoặc bằng x, tiếp tục với nút con bên phải
//	else {
//		showNodeGreaterX(root->Right, x);
//	}
//}
//// đếm số nút của cây
//int countBSTNode(BSTNode* root)
//{
//	if (!root)
//		return 0;
//	int nLeft = countBSTNode(root->Left);// đếm số node bên nhánh trái
//	int nRight = countBSTNode(root->Right);// đếm số node bên nhánh phải
//	return 1 + nRight + nLeft;
//}
//// đếm số lá của cây
//int countBSTNodeIsLeaf(BSTNode* root) {
//	if (!root)
//		return 0;
//	if (!root->Left && !root->Right)
//		return 1;
//	int cnl = countBSTNodeIsLeaf(root->Left);
//	int cnr = countBSTNodeIsLeaf(root->Right);
//	return (cnl + cnr);
//}
//// đếm số nút có đúng 1 nút con của cây
//int countBSTNodeHaveOneChild(BSTNode* root)
//{
//	// duyệt cây theo LRN
//	if (!root)
//		return 0;
//	int cnl = countBSTNodeHaveOneChild(root->Left);
//	int cnr = countBSTNodeHaveOneChild(root->Right);
//	if (root->Left != NULL && root->Right == NULL)
//		return cnl + cnr + 1;
//	else
//		return cnl + cnr;
//}
//int countBSTNodeHaveTwoChild(BSTNode* root)
//{
//	// duyệt cây theo LRN
//	if (!root)
//		return 0;
//	int cnl = countBSTNodeHaveTwoChild(root->Left);
//	int cnr = countBSTNodeHaveTwoChild(root->Right);
//	if (root->Left != NULL && root->Right != NULL)
//		return cnl + cnr + 1;
//	else
//		return cnl + cnr;
//
//}
//// tổng các nút trên cây
//int sumBSTNode(BSTNode* root)
//{
//	if (!root)
//		return 0;
//	else {
//		int lc = sumBSTNode(root->Left);
//		int rc = sumBSTNode(root->Right);
//		return lc + rc + root->Info;
//	}
//}
//// tổng nút lá trên cây
//int sumBSTNodeIsLeaf(BSTNode* root)
//{
//	if (!root)
//		return 0;
//	else if (root->Left == NULL && root->Right == NULL)
//		return root->Info;
//	else {
//		int lc = sumBSTNodeIsLeaf(root->Left);
//		int rc = sumBSTNodeIsLeaf(root->Right);
//		return lc + rc;
//	}
//}
//int sumBSTNodeHaveOneChild(BSTNode* root)
//{
//	if (root == NULL || (root->Left == NULL && root->Right == NULL)) 
//		return 0; // Trường hợp cơ sở: nút là NULL hoặc là nút lá
//	
//	if ((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL)) 
//		// Nếu nút chỉ có một nút con, tính tổng của nút đó và tiếp tục đệ quy với nút con
//		return root->Info+ sumBSTNodeHaveOneChild(root->Left) + sumBSTNodeHaveOneChild(root->Right);
//	else
//	// Nếu nút có cả hai nút con, tiếp tục đệ quy với cả hai nút con
//	return sumBSTNodeHaveOneChild(root->Left) + sumBSTNodeHaveOneChild(root->Right);
//}
//
//int sumBSTNodeHaveTwoChild(BSTNode* root)
//{
//	if (root == NULL || (root->Left == NULL && root->Right == NULL))
//		return 0; //  nút là NULL hoặc là nút lá
//
//	if ((root->Left != NULL && root->Right == NULL) || (root->Left == NULL && root->Right != NULL))
//		// chỉ có một nút con, tính tổng của nút đó và tiếp tục đệ quy với nút con
//		return root->Info + sumBSTNodeHaveTwoChild(root->Left) + sumBSTNodeHaveTwoChild(root->Right);
//	else
//		// có cả hai nút con, tiếp tục đệ quy với cả hai nút con
//		return sumBSTNodeHaveTwoChild(root->Left) + sumBSTNodeHaveTwoChild(root->Right);
//}
//int highTree(BSTNode* root)
//{
//	if (!root)
//		return 0;
//	int hl = highTree(root->Left);//chiều cao nhánh trái
//	int hr = highTree(root->Right);
//	if (hl > hr)
//		return (1 + hl);
//	else
//		return (1 + hr);
//}