//
//#ifndef _CayNPTK_SoNguyen_h
//#define CayNPTK_SoNguyen_h
//
///*
//Họ và tên:Ngô Công Danh
//Lớp:THCTDL&GT ST6
//*/
//// Khai báo thư viện
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<math.h>
////================================================
////Khai bao kiểu dữ liệu
//typedef int Itemtype;// Khai báo kiểu dữ liệu người dùng
//struct BSTNode {
//	Itemtype Info;// Lưu thông tin của nút
//	BSTNode* Left;// Con trỏ chỉ đến node con trái(nếu có)
//	BSTNode* Right;// con trỏ chỉ đến node con phải(nếu có)
//};
//struct BSTree {
//	BSTNode* Root;
//};
////================================================
//// Khai báo nguyên mẫu hàm
//
//BSTNode* createBSTNode(Itemtype x);
//void showBSTNode(BSTNode* p);
//void initBSTree(BSTree& bst);
//void showBSTNode(BSTNode* p);
//void createBSTree_ByHand(BSTree& bst);
//void createBSTree_Random(BSTree& bst);
//int insertBSTNode(BSTNode*& root, BSTNode* p);
//BSTNode* findBSTNode(BSTNode* root, Itemtype x);
//void createBSTree_FromArray(BSTree& bst, Itemtype a[], int n);
//void traverseLRN(BSTNode* root);
//void traverseLNR(BSTNode* root);
//void traverseNLR(BSTNode* root);
//void traverseNRL(BSTNode* root);
//void traverseRLN(BSTNode* root);
//void traverseRNL(BSTNode* root);
//void showNodeGreaterX(BSTNode* root,Itemtype x);
//int countBSTNodeIsLeaf(BSTNode* root);
//int countBSTNode(BSTNode* root);
//int countBSTNodeHaveTwoChild(BSTNode* root);
//int countBSTNodeHaveOneChild(BSTNode* root);
//int sumBSTNode(BSTNode* root);
//int sumBSTNodeIsLeaf(BSTNode* root);
//int sumBSTNodeHaveOneChild(BSTNode* root);
//int sumBSTNodeHaveTwoChild(BSTNode* root); 
//int highTree(BSTNode* root);
//BSTNode* findBSTNodeReplace(BSTNode*& p);
//int deleteBSTNodeX(BSTNode*& root, Itemtype& x);
//void deleteBSTree(BSTNode*& root);
//void showBSTNodeOfLevelK(BSTNode* root, int k);
//#endif _CayNPTK_SoNguyen_h