
#include <stdio.h>
#include "comm.h"

void add_to_tail(LinkNode** p_head, int value) {
    LinkNode *p_new = new LinkNode;
    p_new->data = value;
    p_new->next = NULL;
    if (*p_head == NULL) {
        *p_head = p_new;
        return;
    }
    LinkNode *p = *p_head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = p_new;
    return;
}

void print_link(LinkNode *head) {
    while (NULL != head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {

    LinkNode *head = NULL;
    add_to_tail(&head, 2);
    print_link(head);
    add_to_tail(&head, 10);
    add_to_tail(&head, -9);
    add_to_tail(&head, 19);
    print_link(head);

    return 0;
}
