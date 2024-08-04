//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    char TenBH[31];
//    char TenNS[31];
//    char TenCS[31];
//    float ThoiLuong;
//} ItemType;
//
//typedef struct QueueNode {
//    ItemType Info;
//    int priority;
//    struct QueueNode* Next;
//} QueueNode;
//
//typedef struct {
//    QueueNode* Head;
//    QueueNode* Tail;
//} PriorityQueue;
//
//QueueNode* createQueueNode(ItemType x, int priority) {
//    QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
//    if (p == NULL) {
//        printf("Khong the cap phat bo nho cho node moi");
//        exit(1);
//    }
//    p->Info = x;
//    p->priority = priority;
//    p->Next = NULL;
//    return p;
//}
//
//void initPriorityQueue(PriorityQueue* pq) {
//    pq->Head = NULL;
//    pq->Tail = NULL;
//}
//
//int isEmpty(PriorityQueue pq) {
//    return pq.Head == NULL;
//}
//
//void push(PriorityQueue* pq, ItemType x, int priority) {
//    QueueNode* p = createQueueNode(x, priority);
//    if (isEmpty(*pq) || priority < pq->Head->priority) {
//        p->Next = pq->Head;
//        pq->Head = p;
//    }
//    else {
//        QueueNode* current = pq->Head;
//        while (current->Next != NULL && current->Next->priority <= priority) {
//            current = current->Next;
//        }
//        p->Next = current->Next;
//        current->Next = p;
//    }
//    if (pq->Tail == NULL) {
//        pq->Tail = p;
//    }
//}
//
//ItemType pop(PriorityQueue* pq) {
//    if (isEmpty(*pq)) {
//        printf("Priority Queue is empty!\n");
//        exit(1);
//    }
//    QueueNode* temp = pq->Head;
//    ItemType item = temp->Info;
//    pq->Head = pq->Head->Next;
//    if (pq->Head == NULL) {
//        pq->Tail = NULL;
//    }
//    free(temp);
//    return item;
//}
//
//void display(PriorityQueue pq) {
//    QueueNode* temp = pq.Head;
//    printf("Priority Queue: \n");
//    while (temp != NULL) {
//        printf("(%s, %d) ", temp->Info.TenBH, temp->priority);
//        temp = temp->Next;
//    }
//    printf("\n");
//}
//
//int main() {
//    PriorityQueue pq;
//    initPriorityQueue(&pq);
//
//    ItemType item1 = { "Bai Hat 1", "Nghe Si 1", "Ca Si 1", 3.5 };
//    ItemType item2 = { "Bai Hat 2", "Nghe Si 2", "Ca Si 2", 4.2 };
//    ItemType item3 = { "Bai Hat 3", "Nghe Si 3", "Ca Si 3", 2.8 };
//
//    // Thêm các phần tử vào priority queue với độ ưu tiên tương ứng
//    push(&pq, item1, 2);
//    push(&pq, item2, 3);
//    push(&pq, item3, 1);
//
//    display(pq);
//
//    // Lấy và hiển thị phần tử có độ ưu tiên cao nhất
//    ItemType highest_priority_item = pop(&pq);
//    printf("Phan tu co do uu tien cao nhat: %s\n", highest_priority_item.TenBH);
//
//    display(pq);
//
//    return 0;
//}
