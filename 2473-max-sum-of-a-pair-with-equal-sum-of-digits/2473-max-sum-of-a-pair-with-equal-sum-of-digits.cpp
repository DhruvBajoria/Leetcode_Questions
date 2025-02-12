class Solution {
public:
    int maximumSum(vector<int>& nums) {
         unordered_map<int,priority_queue<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            int sum = 0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            mp[sum].push(nums[i]);
        }
        int ma=0;
        for(auto x:mp){
            int s = x.first;
            int n1=0,n2=0;
            if(x.second.size()>=2){
            n1 = x.second.top();
            x.second.pop();
            n2 = x.second.top();
            }

            int sum= n1+n2;
            ma=max(ma,sum);


        }
        return ma==0?-1:ma;
        
    }
};