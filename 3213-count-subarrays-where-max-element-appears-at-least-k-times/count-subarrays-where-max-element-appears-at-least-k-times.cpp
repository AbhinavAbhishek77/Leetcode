class Solution {
public:
//TC==>O(n)
//SC==>O(1)
    long long countSubarrays(vector<int>& nums, int k) {
//APPROACH 1
        // int n = nums.size();
        // long long maxi = *max_element(nums.begin(), nums.end());
        // long long cnt = 0, ans = 0;
        // int i = 0, j = 0;
        // while (j < n) {
        //     if (nums[j] == maxi) {
        //         cnt++;
        //     }

        //     if (cnt >= k) {
        //         ans += (1 + n - 1 - j);//n-j
        //         if (nums[i] == maxi) {
        //             cnt--;
        //         }
        //         i++;
        //         cnt--;
        //         continue;
        //     }
        //     j++;
        // }
        // return ans;


        //APPROACH 2

        int n = nums.size();
        long long maxi = *max_element(nums.begin(), nums.end());
        long long cnt = 0, ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] == maxi) {
                cnt++;
            }

            while (cnt >= k) {
                ans += (n-j);
                if (nums[i] == maxi) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;


    }
};