#pragma once

#ifndef _CayNPTK_PhanSo_h
#define CayNPTK_PhanSo_h

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
struct Phanso
{
	int tu, mau;
};
typedef Phanso Itemtype;// Khai báo kiểu dữ liệu người dùng
struct BSNode {
	Itemtype Info;// Lưu thông tin của nút
	BSNode* Left;// Con trỏ chỉ đến node con trái(nếu có)
	BSNode* Right;// con trỏ chỉ đến node con phải(nếu có)
};
struct AVLTree {
	BSNode* Root;
};
//================================================
// Khai báo nguyên mẫu hàm

BSNode* createBSTNode(Itemtype x);
void showBSTNode(BSNode* p);
void initBSTree(AVLTree& bst);
void showBSTNode(BSNode* p);
void createBSTree_ByHand(AVLTree& bst);
void createBSTree_Random(AVLTree& bst);
int insertBSNode(BSNode*& root, BSNode* p);
BSNode* findBSTNode(BSNode* root, Itemtype x);
void createBSTree_FromArray(AVLTree& bst, Itemtype a[], int n);
void traverseLRN(BSNode* root);
void traverseLNR(BSNode* root);
void traverseNLR(BSNode* root);
void traverseNRL(BSNode* root);
void traverseRLN(BSNode* root);
void traverseRNL(BSNode* root);
void showNodeGreaterX(BSNode* root, Itemtype x);
int countBSTNodeIsLeaf(BSNode* root);
int countBSTNode(BSNode* root);
int countBSTNodeHaveTwoChild(BSNode* root);
int countBSTNodeHaveOneChild(BSNode* root);
int sumBSTNode(BSNode* root);
int sumBSTNodeIsLeaf(BSNode* root);
int sumBSTNodeHaveOneChild(BSNode* root);
int sumBSTNodeHaveTwoChild(BSNode* root);
int highTree(BSNode* root);
void kiemtraDoiDau(Phanso& x);
void rutGon(Phanso& x);
int UCLN(int x, int y);
#endif _CayNPTK_PhanSo_h
