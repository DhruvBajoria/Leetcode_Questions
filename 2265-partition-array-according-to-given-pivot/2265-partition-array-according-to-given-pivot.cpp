class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // queue<int>s,e,g;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]<pivot)
        //     s.push(nums[i]);
        //     else if(nums[i]==pivot)
        //     e.push(nums[i]);
        //     else{
        //         g.push(nums[i]);
        //     }
        // }
        // vector<int>ans;
        // while(!s.empty()){
        //     ans.push_back(s.front());
        //     s.pop();
        // }
        //   while(!e.empty()){
        //     ans.push_back(e.front());
        //     e.pop();
        // }
        //   while(!g.empty()){
        //     ans.push_back(g.front());
        //     g.pop();
        // }
        // return ans;
        vector<int>ans;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)
            ans.push_back(nums[i]);
        }
         for(int i=0;i<n;i++){
            if(nums[i]==pivot)
            ans.push_back(nums[i]);
        }
         for(int i=0;i<n;i++){
            if(nums[i]>pivot)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};