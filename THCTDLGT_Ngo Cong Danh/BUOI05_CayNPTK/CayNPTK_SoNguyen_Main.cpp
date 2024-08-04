//#include"ASCII_Node.h"
//#define _CRT_SECURE_NO_WARNINGS
//
//void Menu();
//void process();
////Chương trình chính(main)
//void main() {
//	process();
//
//}
////================================================
////MENU
//void Menu() {
//	printf("\n************************************************************************");
//	printf("\n*                                MENU                                  *");
//	printf("\n************************************************************************");
//	printf("\n* 1. Tao nut moi va xuat noi dung                                      *");
//	printf("\n* 2. Tao cay NPTK bang tay (nhap lieu)                                 *");
//	printf("\n* 3. Tao cay NPTK bang tay (ngau nhien)                                *");
//	printf("\n* 4. Tao cay NPTK tu mang a co san                                     *");
//	printf("\n* 5. Tim kiem node trong cay                                           *");
//	printf("\n* 6. Dem so node,node la, node co 1 node con, node co 2 node con       *");                                
//	printf("\n* 7. Liet ke cac node lon hon X                                        *");
//	printf("\n* 8. Tinh tong node, node la, node co 1 node con, node co 2 node con   *");
//	printf("\n* 9. Chieu cao cua cay NPTK                                            *");
//	printf("\n* 10. Xoa 1 node trong cay                                             *");
//	printf("\n* 11. Xoa toan bo cay                                                  *");
//	printf("\n* 12. Xuat noi dung cay                                                *");
//	printf("\n* 13. Xem noi dung cua node o muc k bat ky                             *");
//	printf("\n************************************************************************");
//}
//void process()
//{
//	Itemtype X,Y,K;
//	BSTNode* P, * Q;
//	BSTree bst;
//	initBSTree(bst);
//	Itemtype A[] = { 45,32,22,38,73,56,89,93,35 };
//	int N = 9;
//	int result, choice;
//	do {
//		printf("\n");
//		Menu();
//		printf("\n");
//		printf("\nChon mot chuc nang: ");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			printf("Ban hay nhap gia tri node moi: ");
//			scanf("%d", &X);
//			P = createBSTNode(X);
//			insertBSTNode(bst.Root, P);
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			printf("Cay NPTK vua duoc nhap lieu la: ");
//			printf("\nLRN: ");
//			traverseLNR(bst.Root);
//			printf("\nLRN: ");
//			traverseLRN(bst.Root);
//			printf("\nNLR: ");
//			traverseNLR(bst.Root);
//			printf("\nNRL: ");
//			traverseNRL(bst.Root);
//			printf("\nRLN: ");
//			traverseRLN(bst.Root);
//			printf("\nRNL: ");
//			traverseRNL(bst.Root);
//			break;
//		case 2:
//			initBSTree(bst);
//			createBSTree_ByHand(bst);
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			printf("Cay NPTK vua duoc nhap lieu la: ");
//			printf("\nLRN: ");
//			traverseLNR(bst.Root);
//			printf("\nLRN: ");
//			traverseLRN(bst.Root);
//			printf("\nNLR: ");
//			traverseNLR(bst.Root); printf("\nNRL: ");
//			traverseNRL(bst.Root);
//			printf("\nRLN: ");
//			traverseRLN(bst.Root);
//			printf("\nRNL: ");
//			traverseRNL(bst.Root);
//			break;
//		case 3:
//			initBSTree(bst);
//			createBSTree_Random(bst);
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			printf("Cay NPTK vua tao la: ");
//			printf("\nLRN: ");
//			traverseLNR(bst.Root);
//			printf("\nLRN: ");
//			traverseLRN(bst.Root);
//			printf("\nNLR: ");
//			traverseNLR(bst.Root); printf("\nNRL: ");
//			traverseNRL(bst.Root);
//			printf("\nRLN: ");
//			traverseRLN(bst.Root);
//			printf("\nRNL: ");
//			traverseRNL(bst.Root);
//			break;
//		case 4:
//			initBSTree(bst);
//			createBSTree_FromArray(bst, A, N);
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			printf("Cay NPTK vua tao la: ");
//			printf("\nLRN: ");
//			traverseLNR(bst.Root);
//			printf("\nLRN: ");
//			traverseLRN(bst.Root);
//			printf("\nNLR: ");
//			traverseNLR(bst.Root); printf("\nNRL: ");
//			traverseNRL(bst.Root);
//			printf("\nRLN: ");
//			traverseRLN(bst.Root);
//			printf("\nRNL: ");
//			traverseRNL(bst.Root);
//			break;
//		case 5:
//			printf("Ban hay cho biet gia tri muon tim ");
//			scanf("%d", &X);
//			P = findBSTNode(bst.Root, X);
//			if (P != NULL)
//				printf("Tim thay %d trong Cay NPTK.", X); 
//			else
//				printf("Khong tim thay %d trong Cay NPTK.", X);
//			break;
//		case 6:
//			printf("\nSo node tren cay la: %d", countBSTNode(bst.Root));
//			printf("\nSo node la tren cay la: %d", countBSTNodeIsLeaf(bst.Root));
//			printf("\nSo node co dung 1 node con tren cay la: %d", countBSTNodeHaveOneChild(bst.Root));
//			printf("\nSo node co dung 2 node con tren cay la: %d", countBSTNodeHaveTwoChild(bst.Root));
//			break;
//		case 7:
//			printf("Hay nhap gia tri X: ");
//			scanf("%d", &X);
//			printf("Danh sach cac node lon hon X: ");
//			showNodeGreaterX(bst.Root, X);
//			break;
//		case 8:
//			printf("\nTong cac node tren cay la: %d", sumBSTNode(bst.Root));
//			printf("\nTong cac node la tren cay la: %d", sumBSTNodeIsLeaf(bst.Root));
//			printf("\nTong cac node co dung 1 node con tren cay la: %d", sumBSTNodeHaveOneChild(bst.Root));
//			printf("\nTong cac node co dung 2 node con tren cay la: %d", sumBSTNodeHaveTwoChild(bst.Root));
//			break;
//		case 9:
//			printf("Chieu cao cua cay la: %d", highTree(bst.Root));
//			break;
//		case 10:
//			printf("Nhap gia tri node muon xoa: ");
//			scanf("%d", &X);
//			if (deleteBSTNodeX(bst.Root, X) == 0)
//				printf("Khong the xoa node co gia tri %d", X);
//			else
//			{
//				printf("Noi dung sau khi xoa node %d la:", X);
//				printf("\nVE CAY\n");
//				print_ascii_tree(bst.Root);
//			}
//			break;
//		case 11:
//			deleteBSTree(bst.Root);
//			printf("Xoa thanh cong!");
//			break;
//		case 12:
//			if (!bst.Root) {
//				printf("CAY RONG!");
//				break;
//			}
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			break;
//		case 13:
//			printf("\nVE CAY\n");
//			print_ascii_tree(bst.Root);
//			printf("\nBan hay cho biet muc k muon xem noi dung: ");
//			scanf("%d", &K);
//			showBSTNodeOfLevelK(bst.Root, K);
//			break;
//
//		default:
//			break;
//		}
//	} while (choice != 0);
//
//}