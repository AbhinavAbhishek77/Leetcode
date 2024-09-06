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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr = head;
        unordered_map<int, int> mp;

        for (auto v : nums)
            mp[v]++;

        while (curr) {
            if (mp.find(curr->val) != mp.end()) {
                curr = curr->next;
            } else {
                break;
            }
        }

        head = curr;
        if (head == NULL)
            return head;
        curr = head;
        while (curr && curr->next) {
            if (mp.find(curr->next->val) != mp.end()) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};