class Solution {
public:
    bool solve(int n,int k,vector<int>&nums)
    {
        vector<vector<bool>>dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
            
        }
        if(nums[0]<=k){
             dp[0][nums[0]]=true;
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int tgt=1;tgt<=k;tgt++)
            {
                bool nonpick=dp[i-1][tgt];
                bool pick=false;
                if(tgt>=nums[i])
                {
                    pick=dp[i-1][tgt-nums[i]];
                }
                dp[i][tgt]=pick | nonpick;
            }
        }
        return dp[n-1][k];
       
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        
        int n=nums.size();
        if(n==1)
            return false;
        for(auto x:nums)
        {
            s+=x;
        }
        if(s%2)
            return false;
        int t=s/2;
       
        return solve(n,t,nums);
           
    }
};