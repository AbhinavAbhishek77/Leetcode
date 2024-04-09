class Solution {
public:
    int solve(vector<int>& tickets, int k) {
        int cnt = 0, i = 0;
        int n = tickets.size();
        while (tickets[k] > 0) {
            if (tickets[i] > 0) {
                tickets[i]--;
                cnt++;
            }
            i++;
            if (i == n) {
                i = 0;
            }
        }
        return cnt;
    }
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        return solve(tickets, k);
    }
};