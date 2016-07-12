
#include <stdio.h>
#include "comm.h"

void remove_node(LinkNode **head, int target) {
    if (NULL == head || NULL == *head)  return;
    LinkNode *pre = NULL;
    LinkNode *p = *head;
    while (p != NULL) {
        if (p->data == target) {
            break;
        }
        pre = p;
        p = p->next;
    }

    if (NULL == p)  return;

    if (NULL == pre) {
        *head = p->next;
        delete p;
    } else {
        pre->next = p->next;
        delete p;
    }
    return;
}

int main() {

    return 0;
}
