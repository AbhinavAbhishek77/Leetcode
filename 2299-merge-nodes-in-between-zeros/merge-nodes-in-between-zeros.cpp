/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while (temp) {
            c++;
            temp = temp->next;
        }
        return c;
    }
    void print(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
    }
    ListNode* mergeNodes(ListNode* head) {
        int len = getlen(head);
        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;
        ListNode* curr = head;
        curr = curr->next;
        int sum = 0;
        for (int i = 0; i < len - 1; i++) {
            if (curr->val == 0) {
                d->next = new ListNode(sum);
                d = d->next;
                sum = 0;
            }
            sum += curr->val;
            curr = curr->next;
        }

        dummy = dummy->next;
        print(dummy);
        return dummy;
    }
};