
#include <stdio.h>
#include "comm.h"

void delete_node(ListNode **head, ListNode *to_be_delete) {
    if (NULL == head || NULL == *head || NULL == to_be_delete) {
        return;
    }
    if (to_be_delete->next != NULL) {
        ListNode *p = to_be_delete->next;
        to_be_delete->data = p->data;
        to_be_delete->next = p->next;
        delete p;
        p = NULL;
    } else if (*head == to_be_delete) {
        delete to_be_delete;
        *head = NULL;
        head = NULL;
        to_be_delete = NULL;
    } else {
        ListNode *p = *head;
        while (NULL != p && p->next != to_be_delete) {
            p = p->next;
        }
        if (NULL == p)  return;
        p->next = NULL;
        delete to_be_delete;
        to_be_delete = NULL;
    }
}
int main() {
    return 0;
}
