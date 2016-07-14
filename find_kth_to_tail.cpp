

#include <stdio.h>
#include "comm.h"

ListNode *FindKth(ListNode *head, int k) {
    if (NULL == head || k <= 0)  return NULL;
    ListNode *p = head;
    for (int i = 1; i < k; ++i) {
        if (p->next == NULL)  return NULL;
        p = p->next;
    }

    ListNode *q = head;
    while (p->next != NULL) {
        p = p->next;
        q = q->next;
    }
    return q;
}

int main() {
    return 0;
}
