class Solution {
public:
int mem(vector<int>&nums, int ind, vector<int>&dp)
{
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int pick=nums[ind]+mem(nums,ind-2,dp);
    int notpick=0+mem(nums,ind-1,dp);

    return dp[ind]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);

        vector<int>temp1(nums.begin(),nums.end()-1), temp2(nums.begin()+1,nums.end());

        return max(mem(temp1,temp1.size()-1,dp1), mem(temp2,temp2.size()-1,dp2));
    }
};