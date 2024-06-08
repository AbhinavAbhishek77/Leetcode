class Solution {
public:
int tab(vector<int>&nums, int ind, vector<int>&dp)
{
    //TC:O(N)
    //SC:O(N)
    dp[0]=nums[0];
    // if(ind<0) return 0;
    // if(dp[ind]!=-1) return dp[ind];

   for(int i=1;i<=ind;i++)
   {
       int pick=nums[i];
     if (i - 2 >= 0) {
       pick = nums[i] + dp[i - 2];
     }

       int notpick=0+dp[i-1];

       dp[i]=max(pick,notpick);
   }
   return dp[ind];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return tab(nums,n-1,dp);
    }
};