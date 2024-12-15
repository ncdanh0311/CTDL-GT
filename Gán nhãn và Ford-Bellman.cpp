//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTICES 100
//#define MAX_EDGES 1000
//#define INF 1000000000
//
//typedef struct {
//    int dinhnguon;
//    int dinhdich;
//    int trongso;
//} Edge;
//
//Edge edges[MAX_EDGES];
//int dinh, canh;
//int khoangcach[MAX_VERTICES];
//int truyvet[MAX_VERTICES];
//
//// Hàm in đường đi
//void printPath(int dinh_cha[], int dinh) {
//    if (dinh == -1) {
//        return;
//    }
//    printPath(dinh_cha, dinh_cha[dinh]);
//    printf("%d ", dinh);
//}
//
//// Hàm Bellman-Ford
//void bellmanFord(int dinhnguonthuattoan) {
//    for (int i = 0; i < dinh; i++) {
//        khoangcach[i] = INF;
//        truyvet[i] = -1;
//    }
//    khoangcach[dinhnguonthuattoan] = 0;
//
//    for (int i = 1; i <= dinh - 1; i++) {
//        for (int j = 0; j < canh; j++) {
//            int u = edges[j].dinhnguon;
//            int v = edges[j].dinhdich;
//            int w = edges[j].trongso;
//            if (khoangcach[u] != INF && khoangcach[u] + w < khoangcach[v]) {
//                khoangcach[v] = khoangcach[u] + w;
//                truyvet[v] = u;
//            }
//        }
//    }
//
//    // Kiểm tra chu trình âm
//    for (int j = 0; j < canh; j++) {
//        int u = edges[j].dinhnguon;
//        int v = edges[j].dinhdich;
//        int w = edges[j].trongso;
//        if (khoangcach[u] != INF && khoangcach[u] + w < khoangcach[v]) {
//            printf("Do thi co chu trinh am!\n");
//            return;
//        }
//    }
//
//    printf("\nKhoang cach ngan nhat tu dinh nguon:\n");
//    for (int i = 0; i < dinh; i++) {
//        printf("Dinh %d: %d\n", i, khoangcach[i]);
//    }
//
//    printf("\nDuong di ngan nhat:\n");
//    for (int i = 0; i < dinh; i++) {
//        if (khoangcach[i] != INF) {
//            printf("Duong di den dinh %d: ", i);
//            printPath(truyvet, i);
//            printf("\n");
//        }
//    }
//}
//
//// Hàm gán nhãn
//void shortestPathLabeling(int matran[][MAX_VERTICES], int n, int dinh_goc) {
//    int khoang_cach[MAX_VERTICES];
//    int da_gan_nhan[MAX_VERTICES];
//    int dinh_cha[MAX_VERTICES];
//
//    for (int i = 0; i < n; i++) {
//        khoang_cach[i] = INF;
//        da_gan_nhan[i] = 0;
//        dinh_cha[i] = -1;
//    }
//    khoang_cach[dinh_goc] = 0;
//
//    for (int count = 0; count < n - 1; count++) {
//        int min = INF, u = -1;
//
//        for (int i = 0; i < n; i++) {
//            if (!da_gan_nhan[i] && khoang_cach[i] < min) {
//                min = khoang_cach[i];
//                u = i;
//            }
//        }
//
//        if (u == -1) break;
//        da_gan_nhan[u] = 1;
//
//        for (int v = 0; v < n; v++) {
//            if (!da_gan_nhan[v] && matran[u][v] != 0 && khoang_cach[u] != INF &&
//                khoang_cach[u] + matran[u][v] < khoang_cach[v]) {
//                khoang_cach[v] = khoang_cach[u] + matran[u][v];
//                dinh_cha[v] = u;
//            }
//        }
//    }
//
//    printf("\nKet qua gan nhan:\n");
//    printf("Dinh \t Khoang cach \t Duong di\n");
//    for (int i = 0; i < n; i++) {
//        printf("%d \t %d \t \t ", i, khoang_cach[i]);
//        if (khoang_cach[i] != INF) {
//            printPath(dinh_cha, i);
//        }
//        else {
//            printf("Khong co duong di");
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    printf("Nhap so luong dinh (toi da %d): ", MAX_VERTICES);
//    scanf("%d", &dinh);
//    if (dinh > MAX_VERTICES) {
//        printf("So dinh qua lon!\n");
//        return 1;
//    }
//
//    printf("Nhap so luong canh (toi da %d): ", MAX_EDGES);
//    scanf("%d", &canh);
//    if (canh > MAX_EDGES) {
//        printf("So canh qua lon!\n");
//        return 1;
//    }
//
//    int matran[MAX_VERTICES][MAX_VERTICES] = { 0 };
//
//    for (int i = 0; i < canh; i++) {
//        printf("Nhap canh %d (dinh nguon, dinh dich, trong so): ", i + 1);
//        int u, v, w;
//        scanf("%d %d %d", &u, &v, &w);
//        matran[u][v] = w;
//        edges[i].dinhnguon = u;
//        edges[i].dinhdich = v;
//        edges[i].trongso = w;
//    }
//
//    int dinh_goc;
//    printf("Nhap dinh nguon: ");
//    scanf("%d", &dinh_goc);
//
//    int choice;
//    printf("\nChon thuat toan can chay:\n");
//    printf("1. Bellman-Ford\n");
//    printf("2. Gan nhan (Shortest Path Labeling)\n");
//    printf("Lua chon cua ban: ");
//    scanf("%d", &choice);
//
//    switch (choice) {
//    case 1:
//        printf("\nChay Bellman-Ford:\n");
//        bellmanFord(dinh_goc);
//        break;
//    case 2:
//        printf("\nChay gan nhan:\n");
//        shortestPathLabeling(matran, dinh, dinh_goc);
//        break;
//    default:
//        printf("Lua chon khong hop le!\n");
//    }
//
//    return 0;
//}
