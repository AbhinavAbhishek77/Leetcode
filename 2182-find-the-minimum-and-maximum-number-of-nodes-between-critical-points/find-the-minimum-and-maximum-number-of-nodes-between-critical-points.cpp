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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<pair<int, int>> ans;
        ListNode* temp = head;
       // Ensure there are at least three nodes
    if (!temp || !temp->next || !temp->next->next)
        return {-1, -1};


        int maxima = -1;
        int ind = 1;
        while (temp && temp->next && temp->next->next) {
            int a = temp->val;
            int b = temp->next->val;
            int c = temp->next->next->val;

            if (b > a && b > c) {
                ans.push_back({b, ind});
            }
            if (b < a && b < c)
                ans.push_back({b, ind});

            ind++;
            temp = temp->next;
        }

        // If there are fewer than two critical points
    if (ans.size() < 2)
        return {-1, -1};

        int minDistance = INT_MAX;
        int maxDistance = ans.back().second - ans.front().second;

        for (int i = 1; i < ans.size(); i++) {
            minDistance = min(minDistance, ans[i].second - ans[i - 1].second);
        }

        return {minDistance, maxDistance};
    }
};