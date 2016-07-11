

#include <stdio.h>
#include "comm.h"

LinkNode *partition(LinkNode *head, int target) {
    LinkNode fake_head;
    fake_head.data = 0;
    fake_head.next = head;
    head = &fake_head;


    // first big number pointer
    LinkNode *pos = NULL;
    for (LinkNode *p = head; p != NULL && p->next != NULL; ) {
        if (pos == NULL && p->next->data >= target) {
            pos = p;
            p = p->next;
            printf("init pos == %d\n", pos->data);
            continue;
        }
        if (pos != NULL && p->next->data < target) {
            LinkNode * temp = p->next;
            p->next = temp->next;
            temp->next = pos->next;
            pos->next = temp;
            pos = temp;
            continue;
        }
        p = p->next;
    }
    return fake_head.next;
}

int main(const int argc, const char *argv[])
{
    int A[] = {2, 4, 8, 3, 1};
    LinkNode *head;
    LinkNode *last = NULL;
    for (int i = sizeof(A)/sizeof(A[0]) - 1; i >= 0; --i) {
        LinkNode *temp = new LinkNode;
        temp->data = A[i];
        temp->next = last;
        last = temp;
        if (i == 0)  head = temp;
    }

    LinkNode *p = head;
    while (NULL != p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");

    p = partition(head, 0);
    while (NULL != p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");

    p = partition(head, 7);
    while (NULL != p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");


    return 0;
}
