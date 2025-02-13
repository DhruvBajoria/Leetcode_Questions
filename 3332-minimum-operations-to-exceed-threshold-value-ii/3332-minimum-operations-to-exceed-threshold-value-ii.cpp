class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        int n= nums.size();
        for(auto x:nums){
            pq.push(x);
        }
        int ans=0;
        while(pq.size()>=2&&pq.top()<k){
            ans++;
            long long a= pq.top();
            pq.pop();
            long long b= pq.top();
            pq.pop();
            long long help = min(a,b)*2 + max(a,b);
            pq.push(help);
        }
        return ans;
        
    }
};