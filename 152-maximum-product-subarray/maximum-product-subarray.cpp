class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (product == 0)
                product = 1;
            product *= nums[i];

            maxi = max(maxi, product);
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (product == 0)
                product = 1;
            product *= nums[i];
            maxi = max(maxi, product);
        }
        return maxi;
    }
};