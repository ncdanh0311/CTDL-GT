
#ifndef _CayNPTK_SoNguyen_h
#define CayNPTK_SoNguyen_h

/*
Họ và tên:Ngô Công Danh
Lớp:THCTDL&GT ST6
*/
// Khai báo thư viện
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
//================================================
//Khai bao kiểu dữ liệu
typedef int Itemtype;// Khai báo kiểu dữ liệu người dùng
struct AVLNode {
	Itemtype Info;// Lưu thông tin của nút
	AVLNode* Left;// Con trỏ chỉ đến node con trái(nếu có)
	AVLNode* Right;// con trỏ chỉ đến node con phải(nếu có)
};
struct AVLTree {
	AVLNode* Root;
};
//================================================
// Khai báo nguyên mẫu hàm

AVLNode* createAVLNode(Itemtype x);
void showBSTNode(AVLNode* p);
void initAVLTree(AVLTree& bst);
void showBSTNode(AVLNode* p);
void createAVLTree_ByHand(AVLTree& bst);
void createAVLTree_Random(AVLTree& bst);
int insertAVLNode(AVLNode*& root, AVLNode* p);
AVLNode* findAVLNode(AVLNode* root, Itemtype x);
void createAVLTree_FromArray(AVLTree& bst, Itemtype a[], int n);
void traverseLRN(AVLNode* root);
void traverseLNR(AVLNode* root);
void traverseNLR(AVLNode* root);
void traverseNRL(AVLNode* root);
void traverseRLN(AVLNode* root);
void traverseRNL(AVLNode* root);
void showNodeGreaterX(AVLNode* root,Itemtype x);
int countBSTNodeIsLeaf(AVLNode* root);
int countBSTNode(AVLNode* root);
int countBSTNodeHaveTwoChild(AVLNode* root);
int countBSTNodeHaveOneChild(AVLNode* root);
int sumBSTNode(AVLNode* root);
int sumBSTNodeIsLeaf(AVLNode* root);
int sumBSTNodeHaveOneChild(AVLNode* root);
int sumBSTNodeHaveTwoChild(AVLNode* root); 
int highTree(AVLNode* root);
#endif _CayNPTK_SoNguyen_h