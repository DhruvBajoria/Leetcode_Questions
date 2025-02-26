class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ma=0,mi=0,ans=0;
        for(auto x:nums){
            ma=max(ma+x,0);
            mi=min(mi+x,0);
            ans=max(ans,ma-mi);
        }
        return ans;

        
    }
};