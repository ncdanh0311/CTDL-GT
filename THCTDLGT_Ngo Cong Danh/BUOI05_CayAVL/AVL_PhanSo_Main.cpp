#include"ASCII_PhanSo.h"
#define _CRT_SECURE_NO_WARNINGS

void Menu();
void process();
//Chương trình chính(main)
void main() {
	process();

}
//================================================
//MENU
void Menu() {
	printf("\n************************************************************************");
	printf("\n*                                MENU                                  *");
	printf("\n************************************************************************");
	printf("\n* 1. Tao nut moi va xuat noi dung                                      *");
	printf("\n* 2. Tao cay AVL bang tay (nhap lieu)                                  *");
	printf("\n* 3. Tao cay AVL  (ngau nhien)                                         *");
	printf("\n* 4. Tao cay AVL tu mang a co san                                      *");
	printf("\n* 5. Tim kiem node trong cay                                           *");
	printf("\n* 6. Them nut co gia tri bat ky vao cay                                *");
	printf("\n* 7. Xoa nut co gia tri bat ky vao cay                                 *");
	printf("\n* 8. Chieu cao cay                                                     *");
	printf("\n* 9. Xoa toan bo cay                                                   *");
	printf("\n* 10. Kiem tra xem cay rong chua                                       *");

	printf("\n************************************************************************");
}
void process()
{
	Itemtype X, Y, K;
	AVLNode* P, * Q;
	AVLTree avl;
	initAVLTree(avl);
	Itemtype A[] = { 5/3,7/2, 11/4,8/5,9/7,13/6,17/9,10/11,15/8 };

	int N = 9;
	int result, choice;
	do {
		printf("\n");
		Menu();
		printf("\n");
		printf("\nChon mot chuc nang: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Ban hay nhap gia tri node moi: ");
			scanf("%d", &X);
			P = createAVLNode(X);
			insertAVLNode(avl.Root, P);
			printf("\nVE CAY\n");
			print_ascii_tree(avl.Root);
			printf("Cay AVL vua duoc nhap lieu la: ");
			printf("\nLRN: ");
			traverseLNR(avl.Root);
			printf("\nLRN: ");
			traverseLRN(avl.Root);
			printf("\nNLR: ");
			traverseNLR(avl.Root);
			printf("\nNRL: ");
			traverseNRL(avl.Root);
			printf("\nRLN: ");
			traverseRLN(avl.Root);
			printf("\nRNL: ");
			traverseRNL(avl.Root);
			break;
		case 2:
			initAVLTree(avl);
			createAVLTree_ByHand(avl);
			printf("\nVE CAY\n");
			print_ascii_tree(avl.Root);
			printf("Cay AVL vua duoc nhap lieu la: ");
			printf("\nLRN: ");
			traverseLNR(avl.Root);
			printf("\nLRN: ");
			traverseLRN(avl.Root);
			printf("\nNLR: ");
			traverseNLR(avl.Root); printf("\nNRL: ");
			traverseNRL(avl.Root);
			printf("\nRLN: ");
			traverseRLN(avl.Root);
			printf("\nRNL: ");
			traverseRNL(avl.Root);
			break;
		case 3:
			initAVLTree(avl);
			createAVLTree_Random(avl);
			printf("\nVE CAY\n");
			print_ascii_tree(avl.Root);
			printf("Cay AVL vua tao la: ");
			printf("\nLRN: ");
			traverseLNR(avl.Root);
			printf("\nLRN: ");
			traverseLRN(avl.Root);
			printf("\nNLR: ");
			traverseNLR(avl.Root); printf("\nNRL: ");
			traverseNRL(avl.Root);
			printf("\nRLN: ");
			traverseRLN(avl.Root);
			printf("\nRNL: ");
			traverseRNL(avl.Root);
			break;
		case 4:
			initAVLTree(avl);
			createAVLTree_FromArray(avl, A, N);
			printf("\nVE CAY\n");
			print_ascii_tree(avl.Root);
			printf("Cay AVL vua tao la: ");
			printf("\nLRN: ");
			traverseLNR(avl.Root);
			printf("\nLRN: ");
			traverseLRN(avl.Root);
			printf("\nNLR: ");
			traverseNLR(avl.Root); printf("\nNRL: ");
			traverseNRL(avl.Root);
			printf("\nRLN: ");
			traverseRLN(avl.Root);
			printf("\nRNL: ");
			traverseRNL(avl.Root);
			break;
		case 5:
			printf("Ban hay cho biet gia tri muon tim ");
			scanf("%d", &X);
			P = findAVLNode(avl.Root, X);
			if (P != NULL)
				printf("Tim thay %d trong Cay AVL.", X);
			else
				printf("Khong tim thay %d trong Cay AVL.", X);
			break;
		case 6:
			printf("Nhap gia tri muon them: ");
			scanf("%d", &X);
			result = insertAVLNode(avl.Root, createAVLNode(X));
			if (result <= 0)
				printf("\nKhong the them nut %d", X);
			else
			{
				printf("\nVE CAY\n");
				print_ascii_tree(avl.Root);
				traverseNLR(avl.Root);
			}
		case 7:
			printf("Nhap gia tri muon xoa: ");
			scanf("%d", &X);
			result = deleteAVLNode(avl.Root, X);
			if (result == 0)
				printf("\nKhong the them nut %d", X);
			else
			{
				if (avl.Root = NULL)
					printf("\n Cay Rong!");
				else
				{
					printf("\n Noi dung sau khi xoa nut %d la: ", X);
					printf("\nVE CAY\n");
					print_ascii_tree(avl.Root);
					traverseNLR(avl.Root);
				}
			}
		case 8:
			printf("Chieu cao cua cay la: %d", highTree(avl.Root));
			break;
		case 9:
			deleteAVLTree(avl.Root);
			printf("Xoa thanh cong!");
			break;
		case 10:
			if (!avl.Root) {
				printf("CAY RONG!");
				break;
			}
			printf("\nVE CAY\n");
			print_ascii_tree(avl.Root);


		default:
			break;
		}
	} while (choice != 0);
}