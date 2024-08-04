#pragma once
#pragma once
#ifndef _AVL_PhanSo_h
#define AVL_PhanSo_h

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
#define LH -1 // Cây con trái cao hơn(lệch trái)
#define EH 0// Cây con trái bằng cây con phải(cân bằng)
#define RH 1// cây con phải cao hơn(lệch phải)
//================================================
//Khai bao kiểu dữ liệu
struct Phanso
{
	int tu, mau;
};
typedef Phanso Itemtype;// Khai báo kiểu dữ liệu người dùng
struct AVLNode {
	int balFactor; // chỉ số cân bằng
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
void initAVLTree(AVLTree& avl);
void showBSTNode(AVLNode* p);
void createAVLTree_ByHand(AVLTree& avl);
void createAVLTree_Random(AVLTree& avl);
int insertAVLNode(AVLNode*& T, AVLNode* p);
AVLNode* findAVLNode(AVLNode* T, Itemtype x);
void createAVLTree_FromArray(AVLTree& avl, Itemtype a[], int n);
void traverseLRN(AVLNode* T);
void traverseLNR(AVLNode* T);
void traverseNLR(AVLNode* T);
void traverseNRL(AVLNode* T);
void traverseRLN(AVLNode* T);
void traverseRNL(AVLNode* T);
void rotateLL(AVLNode*& T);
void rotateLR(AVLNode*& T);
void rotateRR(AVLNode*& T);
int balanceLeft(AVLNode*& T);
void deleteAVLTree(AVLNode*& root);
int deleteAVLNode(AVLNode*& T, Itemtype x);
int highTree(AVLNode* root);
int searchStandFor(AVLNode*& p, AVLNode*& q);
void kiemtraDoiDau(Phanso& x);
int UCLN(int x, int y);
void rutGon(Phanso& x);
#endif _AVL_PhanSo_h

