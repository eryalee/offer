
#include <stdio.h>
#include <stack>

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
void reverse_print_linklist(LinkNode *head) {
    std::stack<LinkNode *> nodes;
    while (NULL != head) {
        nodes.push(head);
        head = head->next;
    }

    while (!nodes.empty()) {
        LinkNode *temp = nodes.top();
        nodes.pop();
        printf("%d-->", temp->data);
    }
    printf("\n");
    return;
}

int main() {

    LinkNode *head = NULL;
    add_to_tail(&head, 3);
    add_to_tail(&head, 5);
    add_to_tail(&head, -2);
    add_to_tail(&head, 10);
    print_link(head);
    reverse_print_linklist(head);
    LinkNode *null = NULL;
    reverse_print_linklist(null);
    return 0;
}
