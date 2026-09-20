/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
 struct ListNode dummy;
    dummy.next = head;

    struct ListNode *groupPrev = &dummy;

    while (1) {
        struct ListNode *kth = groupPrev;

        for (int i = 0; i < k; i++) {
            kth = kth->next;

            if (kth == NULL) {
                return dummy.next;
            }
        }

        struct ListNode *groupNext = kth->next;
        struct ListNode *prev = groupNext;
        struct ListNode *current = groupPrev->next;

        while (current != groupNext) {
            struct ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        struct ListNode *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }   
}