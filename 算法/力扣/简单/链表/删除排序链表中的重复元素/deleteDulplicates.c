#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *deleteDuplicates(struct ListNode *head) {

    if (!head) {
        return head;
    }

    struct ListNode *cur = head;
    while (cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}

int main() {

    struct ListNode *head1 = malloc(sizeof(struct ListNode *));
    head1->val = 2;
    head1->next = NULL;
    struct ListNode *head2 = malloc(sizeof(struct ListNode *));
    head2->val = 1;
    head2->next = head1;
    struct ListNode *head3 = malloc(sizeof(struct ListNode *));
    head3->val = 1;
    head3->next = head2;

    struct ListNode *result = deleteDuplicates(head3);

    while (result != NULL) {
        printf("%d\n", result->val);
        result = result->next;
    }

    return 0;
}