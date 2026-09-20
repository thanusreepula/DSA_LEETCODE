/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
 if (listsSize == 0) {
        return NULL;
    }

    for (int gap = 1; gap < listsSize; gap *= 2) {
        for (int i = 0; i + gap < listsSize; i += 2 * gap) {
            struct ListNode dummy;
            struct ListNode *tail = &dummy;
            struct ListNode *a = lists[i];
            struct ListNode *b = lists[i + gap];

            while (a && b) {
                if (a->val <= b->val) {
                    tail->next = a;
                    a = a->next;
                } else {
                    tail->next = b;
                    b = b->next;
                }
                tail = tail->next;
            }

            tail->next = a ? a : b;
            lists[i] = dummy.next;
        }
    }

    return lists[0];    
}