//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//struct lophoc {
//    char malop[10];
//    char tenlop[21];
//    char ho_gv[10];
//    char dem_gv[21];
//    char ten_gv[10];
//};
//
//typedef struct lophoc lophoc;
//
//struct dstre {
//    char matre[10];
//    char holot[21];
//    char ten[10];
//    int ngay;
//    int thang;
//    int nam;
//    char phuhuynh[30];
//    double sdt;
//    char mqh[6];
//    char malop[10];
//};
//
//typedef struct dstre dstre;
//
//struct node {
//    dstre data;
//    struct node* next;
//};
//typedef struct node node;
//
//node* makedata(dstre x) {
//    node* newdata = (node*)malloc(sizeof(node));
//    newdata->data = x;
//    newdata->next = NULL;
//    return newdata;
//}
//
//void pushback(node** head, dstre x) {
//    node* newdata = makedata(x);
//    if (*head == NULL) {
//        *head = newdata;
//        return;
//    }
//    node* temp = *head;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//    temp->next = newdata;
//}
//
//struct node1 {
//    lophoc data;
//    struct node1* next;
//};
//
//typedef struct node1 node1;
//
//node1* makedata1(lophoc x) {
//    node1* newdata = (node1*)malloc(sizeof(node1));
//    newdata->data = x;
//    newdata->next = NULL;
//    return newdata;
//}
//
//
//void pushback1(node1** head1, lophoc x) {
//    node1* newdata = makedata1(x);
//    if (*head1 == NULL) {
//        *head1 = newdata;
//        return;
//    }
//    node1* temp = *head1;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//    temp->next = newdata;
//}
//
//void xoacach(char x[]) {
//    size_t len = strlen(x);
//    if (x[len - 1] == '\n') x[len - 1] = '\0';
//}
//
//void themtre(dstre x[]) {
//    printf("Nhap ma tre: ");
//    scanf("%s", x->matre);
//    getchar();
//    printf("Nhap ho va dem: ");
//    fgets(x->holot, 20, stdin);
//    xoacach(x->holot);
//    printf("Nhap ten: ");
//    scanf("%s", x->ten);
//    xoacach(x->ten);
//    printf("Nhap ngay sinh: ");
//    scanf("%d", &x->ngay);
//    getchar();
//    printf("Nhap thang sinh: ");
//    scanf("%d", &x->thang);
//    getchar();
//    printf("Nhap nam sinh: ");
//    scanf("%d", &x->nam);
//    getchar();
//    printf("Nhap ho ten cua phu huynh: ");
//    fgets(x->phuhuynh, 30, stdin);
//    xoacach(x->phuhuynh);
//    printf("Nhap so dien thoai: ");
//    scanf("%lf", &x->sdt);
//    getchar();
//    printf("Nhap moi quan he (CON,CHAU,...): ");
//    scanf("%s", x->mqh);
//    xoacach(x->mqh);
//    printf("Nhap ma lop: ");
//    scanf("%s", x->malop);
//    getchar();
//}
//
//// HIỂN THỊ CỘT DACH SÁCH LỚP
//void hien_thi_cot1() {
//    printf("-----------------------------------------------------"
//        "----------------------------------------------------------------\n");
//    printf("%-10s %-20s %-10s %-20s %-10s\n",
//        "Ma lop", "Ten mon hoc", "Ho", "Chu lot", "Ten giao vien");
//}
//
//// HIỂN THỊ CỘT DANH SÁCH TRẺ
//void hien_thi_cot2() {
//    printf("-----------------------------------------------------"
//        "----------------------------------------------------------------\n");
//    printf("%-10s %-20s %-10s %-5s %-5s %-5s %-30s %-15s %-6s %-10s\n",
//        "Ma tre", "Ho va dem", "Ten", "NS", "TS", "NS",
//        "Phu huynh", "SDT", "MQH", "MA LOP");
//}
//
//
//// ĐỌC FILE DANH SÁCH TRẺ
//void docf_dstre(node** head) {
//    FILE* f = fopen("D:\\tre.txt", "r");
//    if (f == NULL) {
//        printf("KHONG THE MO FILE\n");
//        return;
//    }
//    while (!feof(f)) {
//        dstre hs;
//        fscanf(f, "%10s %20[^\n] %10s %5d %5d %5d %30[^\n] %15lf %6s %10s\n",
//            hs.matre, hs.holot, hs.ten, &hs.ngay, &hs.thang, &hs.nam, hs.phuhuynh, &hs.sdt, hs.mqh, hs.malop);
//        pushback(head, hs);
//    }
//    fclose(f);
//}
//
//// ĐỌC FILE LỚP HỌC
//void docf_lophoc(node1** head1) {
//    FILE* f = fopen("D:\\lophoc.txt", "r");
//    if (f == NULL) {
//        printf("KHONG THE MO FILE !\n");
//        return;
//    }
//    while (!feof(f)) {
//        lophoc gv;
//        fscanf(f, "%10s %20[^\n] %10s %20[^\n] %10s\n", gv.malop, gv.tenlop, gv.ho_gv, gv.dem_gv, gv.ten_gv);
//        pushback1(head1, gv);
//    }
//    fclose(f);
//}
//
//
//// GHI FILE DANH SÁCH TRẺ
//void ghif_dstre(node** head, dstre hs) {
//    FILE* f = fopen("D:\\tre.txt", "w");
//    if (f == NULL) {
//        printf("KHONG THE MO FILE !\n");
//        return;
//    }
//    node* temp = *head;
//    while (temp != NULL) {
//        printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//            temp->data.matre, temp->data.holot, temp->data.ten, temp->data.ngay, temp->data.thang, temp->data.nam, temp->data.phuhuynh, temp->data.sdt, temp->data.mqh, temp->data.malop);
//        fprintf(f, "%-10s%-20s%-10s%-5d%-5d%-5d%-30s%-15.0lf%-6s%-10s\n",
//            temp->data.matre, temp->data.holot, temp->data.ten, temp->data.ngay, temp->data.thang, temp->data.nam, temp->data.phuhuynh, temp->data.sdt, temp->data.mqh, temp->data.malop);
//        temp = temp->next;
//    }
//    fclose(f);
//}
//
//// DUYỆT DANH SÁCH LỚP HỌC
//void check_lophoc(node1* head1) {
//    while (head1 != NULL) {
//        printf("%-10s %-20s %-10s %-20s %-10s\n", head1->data.malop, head1->data.tenlop, head1->data.ho_gv, head1->data.dem_gv, head1->data.ten_gv);
//        head1 = head1->next;
//    }
//}
//
//// DUYỆT DANH SÁCH TRẺ
//void check_dstre(node* head) {
//    while (head != NULL) {
//        printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//            head->data.matre, head->data.holot, head->data.ten, head->data.ngay, head->data.thang, head->data.nam, head->data.phuhuynh, head->data.sdt, head->data.mqh, head->data.malop);
//        head = head->next;
//    }
//}
//
////TÌM KIẾM TRẺ THEO MÃ TRẺ
//void search_matre(node** head) {
//    int dem = 0;
//    char c[10];
//    printf("Nhap ma tre muon tim: ");
//    scanf("%s", c);
//    node* temp = *head;
//    while (temp != NULL) {
//        if (stricmp(temp->data.matre, c) == 0)
//        {
//            hien_thi_cot2();
//            printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//                temp->data.matre, temp->data.holot, temp->data.ten, temp->data.ngay, temp->data.thang, temp->data.nam, temp->data.phuhuynh, temp->data.sdt, temp->data.mqh, temp->data.malop);
//            dem += 1;
//        }
//        temp = temp->next;
//    }
//    if (dem == 0) printf("KHONG TIM THAY DU LIEU !\n");
//}
//
//// TÌM KIẾM TRẺ THEO MÃ LỚP
//void in_tre2(node* head, char c[]) {
//    int check = 0;
//    while (head != NULL) {
//        if (stricmp(head->data.malop, c) == 0) {
//            check++;
//            printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//                head->data.matre, head->data.holot, head->data.ten, head->data.ngay, head->data.thang, head->data.nam, head->data.phuhuynh, head->data.sdt, head->data.mqh, head->data.malop);
//        }
//        head = head->next;
//    }
//    if (check == 0) printf("Khong tim thay tre hoc lop %s\n\n", c);
//}
//
//// TÌM KIẾM TRẺ HỌC LỚP CỦA GIÁO VIÊN CÓ HỌ "TRẦN"
//void in_tre_1(node1* head1, node* head) {
//    hien_thi_cot2();
//    int check = 0;
//    char a[10];
//    while (head1 != NULL) {
//        if (stricmp(head1->data.ho_gv, "TRAN") == 0) {
//            check++;
//            in_tre2(head, head1->data.malop);
//        }
//        head1 = head1->next;
//    }
//    if (check == 0) printf("KHONG TIM THAY GIAO VIEN TREN !\n");
//}
//
//// TÌM KIẾM TRẺ CÓ THÁNG SINH LÀ THÁNG 12
//void in_tre_3(node* head) {
//    hien_thi_cot2();
//    int check = 0;
//    while (head != NULL) {
//        if (head->data.thang == 12) {
//            check++;
//            printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//                head->data.matre, head->data.holot, head->data.ten, head->data.ngay, head->data.thang, head->data.nam, head->data.phuhuynh, head->data.sdt, head->data.mqh, head->data.malop);
//        }
//        head = head->next;
//    }
//    if (check == 0) printf("KHONG TIM THAY TRE TREN !\n");
//}
//
//// IN SANH SÁCH PHỤ HUYNH CÓ 2 TRẺ HỌC TẠI TRƯỜNG
//void in_dsph(node* head) {
//    int check = 0;
//    int check_all = 0;
//    printf("DANH SACH CAC PHU HUYNH CO 2 CON HOC TAI TRUONG MAM NON\n");
//    for (node* i = head; i != NULL; i = i->next) {
//        node* sx = i;
//        for (node* j = i->next; j != NULL; j = j->next) {
//            if ((stricmp(j->data.phuhuynh, sx->data.phuhuynh) == 0)) check++;
//        }
//        if (check == 1) {
//            check_all++;
//            check--;
//            printf("%-30s %-15.0lf\n", sx->data.phuhuynh, sx->data.sdt);
//        }
//    }
//    if (check_all == 0) printf("KHONG CO DU LIEU CAN TIM !\n");
//}
//
//
//// TÌM KIẾM VÀ IN RA LỚP CÓ SỐ LƯỢNG TRẺ HỌC NHIỀU NHẤT
//void class_max(node* head, node1* head1) {
//    int class_1 = 0;
//    int class_2 = 0;
//    int class_3 = 0;
//    int class_4 = 0;
//    int max;
//    for (node* i = head; i != NULL; i = i->next) {
//        node* sx = i;
//        for (node* j = i->next; j != NULL; j = j->next) {
//            if ((strcmp(j->data.malop, "MN01") == 0)) class_1++;
//            else if ((strcmp(j->data.malop, "MN02") == 0)) class_2++;
//            if ((strcmp(j->data.malop, "MN03") == 0)) class_3++;
//            if ((strcmp(j->data.malop, "MN04") == 0)) class_4++;
//        }
//    }
//    if (fmax(class_1, class_2) > fmax(class_3, class_4)) {
//        if (class_1 > class_2) printf("Lop hoc co so luong tre nhieu nhat la lop co ma lop MN01\n");
//        else if (class_1 < class_2) printf("Lop hoc co so luong tre nhieu nhat la lop co ma lop MN02\n");
//        else if (class_1 == class_2) printf("2 lop co ma lop : MN01 va MN02 la hai lop co so luong tre hoc nhieu nhat\n");
//    }
//    else if (fmax(class_1, class_2) < fmax(class_3, class_4)) {
//        if (class_3 > class_4) printf("Lop hoc co so luong tre nhieu nhat la lop co ma lop MN03\n");
//        else if (class_3 < class_4) printf("Lop hoc co so luong tre nhieu nhat la lop co ma lop MN04\n");
//        else if (class_3 == class_4) printf("2 lop co ma lop : MN03 va MN04 la hai lop co so luong tre hoc nhieu nhat\n");
//    }
//    else printf("Ca 4 lop deu co so luong hoc sinh nhu nhau!\n");
//}
//
////TÌM KIẾM TRẺ THEO MÃ MÔN HỌC
//void search_malop(node** head, char a[]) {
//    int dem = 0;
//    node* temp = *head;
//    hien_thi_cot2();
//    while (temp != NULL) {
//        if (stricmp(temp->data.malop, a) == 0)
//        {
//            printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//                temp->data.matre, temp->data.holot, temp->data.ten, temp->data.ngay, temp->data.thang, temp->data.nam, temp->data.phuhuynh, temp->data.sdt, temp->data.mqh, temp->data.malop);
//            dem += 1;
//        }
//        temp = temp->next;
//    }
//    if (dem == 0) printf("KHONG TIM THAY DU LIEU !\n");
//}
//
//// TÌM KIẾM TRẺ THEO HỌ VÀ TÊN GV 
//void search_GV(node1** head1, node** head) {
//    int check = 0;
//    char ho[10];
//    char dem[20];
//    char ten[10];
//    printf("VUI LONG NHAP THEO YEU CAU DE THUC HIEN TIM KIEM !!! \n");
//    printf("Vui long nhap 'Ho' cua giao vien: ");
//    scanf("%s", ho);
//    printf("VUI long nhap 'Ten' cua giao vien: ");
//    scanf("%s", ten);
//    node1* temp = *head1;
//    printf("Danh sach giao vien duoc tim thay theo yeu cau: \n");
//    hien_thi_cot1();
//    while (temp != NULL) {
//        if ((stricmp(temp->data.ten_gv, ten) == 0) && (stricmp(temp->data.ho_gv, ho) == 0))
//        {
//            check++;
//            printf("%-10s %-20s %-10s %-20s %-10s\n", temp->data.malop, temp->data.tenlop, temp->data.ho_gv, temp->data.dem_gv, temp->data.ten_gv);
//            search_malop(head, temp->data.malop);
//        }
//        temp = temp->next;
//    }
//    if (check == 0) printf("KHONG TIM THAY DU LIEU !\n");
//}
//
//// SẮP XẾP THEO LỚP VÀ THEO TÊN
//void selection_sort_class(node** head) {
//    for (node* i = *head; i != NULL; i = i->next) {
//        node* sx = i;
//        for (node* j = i->next; j != NULL; j = j->next) {
//            if (stricmp(j->data.malop, sx->data.malop) < 0) sx = j;
//            if (stricmp(j->data.malop, sx->data.malop) == 0) {
//                if (stricmp(j->data.ten, sx->data.ten) < 0) sx = j;
//            }
//        }
//        dstre temp = sx->data;
//        sx->data = i->data;
//        i->data = temp;
//    }
//}
//
//// CẬP NHẬT FILE KHI BIẾT MÃ TRẺ ( KO CẬP NHẬT MÃ TRẺ)
//void ghif_UPDATE(dstre hs) {
//    FILE* f = fopen("D:\\log.txt", "a");
//    if (f == NULL) {
//        printf("KHONG THE MO FILE\n");
//        return;
//    }
//    printf("%-10s %-20s %-10s %-5d %-5d %-5d %-30s %-15.0lf %-6s %-10s\n",
//        hs.matre, hs.holot, hs.ten, hs.ngay, hs.thang, hs.nam, hs.phuhuynh, hs.sdt, hs.mqh, hs.malop);
//    fprintf(f, "%-10s%-20s%-10s%-5d%-5d%-5d%-30s%-15.0lf%-6s%-10s\n",
//        hs.matre, hs.holot, hs.ten, hs.ngay, hs.thang, hs.nam, hs.phuhuynh, hs.sdt, hs.mqh, hs.malop);
//    fclose(f);
//}
//
//// CẬP NHẬT THÔNG TIN KHI BIẾT MÃ TRẺ
//int update(node** head) {
//    int dem = 0;
//    char c[10];
//    printf("Nhap ma tre cua tre ma ban muon cap nhat: ");
//    scanf("%s", c);
//    for (node* temp = *head; temp != NULL; temp = temp->next) {
//        if (stricmp(c, temp->data.matre) == 0) {
//            printf("Da tim thay tre ! Hay chon 1 trong cac tieu chi sau de cap nhat !!! \n");
//            printf("1. HO VA DEM\n");
//            printf("2. TEN\n");
//            printf("3. NGAY SINH\n");
//            printf("4. THANG SINH\n");
//            printf("5. NAM SINH\n");
//            printf("6. HO VA TEN PHU HUYNH\n");
//            printf("7. SO DIEN THOAI CUA PHU HUYNH\n");
//            printf("8. MOI QUAN HE CUA TRE VA PHU HUYNH\n");
//            printf("9. MA LOP\n");
//            printf("Moi chon: ");
//            int chon;
//            scanf("%d", &chon);
//            switch (chon) {
//            case 1: {
//                fflush(stdin);
//                char a[20];
//                printf("Cap nhat ho va dem cua tre: ");
//                gets(a);
//                fflush(stdin);
//                strcpy(temp->data.holot, a);
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 2: {
//                fflush(stdin);
//                char a[20];
//                printf("Cap nhat ten cua tre thanh: ");
//                gets(a);
//                fflush(stdin);
//                strcpy(temp->data.ten, a);
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 3: {
//                int day;
//                printf("Cap nhat ngay sinh cua tre thanh: ");
//                scanf("%d", &day);
//                temp->data.ngay = day;
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 4: {
//                int month;
//                printf("Cap nhat thang sinh cua tre thanh: ");
//                scanf("%d", &month);
//                temp->data.thang = month;
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 5: {
//                int year;
//                printf("Cap nhat ngay sinh cua tre thanh: ");
//                scanf("%d", &year);
//                temp->data.nam = year;
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 6: {
//                fflush(stdin);
//                char a[30];
//                printf("Cap nhat ten cua cua phu huynh thanh: ");
//                gets(a);
//                fflush(stdin);
//                strcpy(temp->data.phuhuynh, a);
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 7: {
//                double phone;
//                printf("Cap nhat so dien thoai lien he thanh: ");
//                printf("%lf", &phone);
//                temp->data.sdt = phone;
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 8: {
//                fflush(stdin);
//                char a[20];
//                printf("Cap nhat moi quan cua tre  voi phu hyunh thanh: ");
//                gets(a);
//                fflush(stdin);
//                strcpy(temp->data.mqh, a);
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            case 9: {
//                fflush(stdin);
//                char a[20];
//                printf("Cap nhat ma lop cua tre thanh: ");
//                gets(a);
//                fflush(stdin);
//                strcpy(temp->data.malop, a);
//                printf("Cap nhat thanh cong !\n");
//                dem++;
//            }; break;
//            default: printf("Lua chon khong hop le!\n");
//            }
//            ghif_UPDATE(temp->data);
//        }
//    }
//    return dem;
//}
//
//
//
//void menu() {
//    printf("\n======================>>>&--MENU--&<<<========================\n");
//    printf("CHUC NANG HIEN THI DANH SACH\n\n");
//    printf("1  - Hien thi danh sach tre\n");
//    printf("--------------------------------------------------------------\n\n");
//    printf("CHUC NANG THEM DU LIEU\n\n");
//    printf("2  - Them mot tre\n");
//    printf("--------------------------------------------------------------\n\n");
//    printf("CHUC NANG TIM KIEM\n\n");
//    printf("3  - Tim kiem tre theo ma tre\n");
//    printf("4  - Tim kiem tre theo ho va ten giao vien\n");
//    printf("5  - Tim kiem tre theo ten lop\n");
//    printf("6  - Tim kiem lop hoc co tre hoc nhieu nhat\n");
//    printf("--------------------------------------------------------------\n\n");
//    printf("CHUC NANG SAP XEP\n\n");
//    printf("7  - Sap xep tre theo lop \n");
//    printf("---------------------------------------------------------------\n\n");
//    printf("CHUC NANG IN RA MAN HINH\n\n");
//    printf("8  - In thong tin tre theo lop do giao vien ho TRAN day\n");
//    printf("9  - In thong tin tre co sinh nhat vao thang 12\n");
//    printf("10 - In thong tin phu huynh co 2 tre hoc tai truong\n");
//    printf("--------------------------------------------------------------\n\n");
//    printf("CHUC NANG CAP NHAT\n\n");
//    printf("11 - Cap nhat\n");
//    printf("--------------------------------------------------------------\n\n");
//    printf("CHUC NANG THOAT KHOI CHUONG TRINH\n\n");
//    printf("0 - Exit\n");
//    printf("\n======================>>>&--END--&<<<=======================\n\n");
//}
//
//int main() {
//    node* head = NULL;
//    node1* head1 = NULL;
//    hien_thi_cot1();
//    docf_lophoc(&head1);
//    check_lophoc(head1);
//    docf_dstre(&head);
//    hien_thi_cot2();
//    check_dstre(head);
//    while (1) {
//        menu();
//        int chon;
//        printf("Vui long nhap tinh nang: ");
//        scanf("%d", &chon);
//        switch (chon) {
//        case 1: {
//            printf("Danh sach hien thoi: \n");
//            hien_thi_cot2();
//            check_dstre(head);
//        }; break;
//        case 2: {
//            printf("Luu y:\n");
//            printf("1. Toan bo du lieu deu phai ghi in hoa\n");
//            printf("2. Khong nhap trung ma tre\n");
//            printf("3. Sua loi do nhap nham bang cach chon 11 sau khi hoan tat dien thong tin\n");
//            dstre tre;
//            themtre(&tre);
//            pushback(&head, tre);
//            printf("Danh sach hien thoi: \n");
//            hien_thi_cot2();
//            check_dstre(head);
//            printf("Ban co muon them tre vao file de luu tru lau dai khong: \n");
//            printf("1. CO           2. KHONG   \n");
//            printf("Nhap lua chon: ");
//            int n;
//            scanf("%d", &n);
//            if (n == 1) ghif_dstre(&head, tre);
//            else printf("Hoan tat them tre nhung cap nhat vao file !!!\n");
//        }; break;
//        case 3: {
//            search_matre(&head);
//        }; break;
//        case 4: {
//            search_GV(&head1, &head);
//        }; break;
//        case 5: {
//            printf("Danh sach mon hoc va ma lop hien thoi: \n");
//            int stt = 0;
//            while (head1 != NULL) {
//                stt++;
//                printf("%d. %s - Ma lop: %s\n", stt, head1->data.tenlop, head1->data.malop);
//                head1 = head1->next;
//            }
//            fflush(stdin);
//            char a[10];
//            printf("Vui long nhap ma lop tuong ung mon hoc ma ban muon tim kiem: ");
//            gets(a);
//            search_malop(&head, a);
//        }; break;
//        case 6: class_max(head, head1); break;
//        case 7: {
//            selection_sort_class(&head);
//        }; break; ;
//        case 8: in_tre_1(head1, head); break;
//        case 9: in_tre_3(head); break;
//        case 10: {
//            in_dsph(head);
//        }; break;
//        case 11: {
//            dstre tre;
//            if (update(&head)) {
//                printf("Danh sach sau khi cap nhat!!!\n");
//                hien_thi_cot2();
//                ghif_dstre(&head, tre);
//                printf("Vui long thoat khoi dong lai chuong trinh de hoan tat cap nhat!!!\n");
//            }
//        }; break;
//        case 0: exit(0);
//        }
//    }
//    return 0;
//}
