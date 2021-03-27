#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* result) {
    while (result != NULL) {
        printf("%d\n", result->val);
        result = result->next;
    }
}


struct ListNode *rotateRight(struct ListNode *head, int k) {

    // 获取链表长度
    struct ListNode *temp = head;
    int len = 0;
    while(temp != NULL && ++len) {
        temp = temp->next;
    }

    if(len == 0) {
        return head;
    }

    // 移动k次，相当于把最后k个元素移到前面来
    k %= len;
    if(k == 0) {
        return head;
    }

    temp = head;
    while(--len > k) {
        temp = temp->next;
    }


    struct ListNode *current = temp->next;
    temp->next = NULL;
    struct ListNode *result = current;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = head;

    return result;
}

int main() {

    struct ListNode *head1 = malloc(sizeof(struct ListNode *));
    head1->val = 2;
    head1->next = NULL;
    struct ListNode *head2 = malloc(sizeof(struct ListNode *));
    head2->val = 1;
    head2->next = head1;
    struct ListNode *head3 = malloc(sizeof(struct ListNode *));
    head3->val = 0;
    head3->next = head2;

    struct ListNode *result = rotateRight(head3, 1);

//    printList(result);

    return 0;
}