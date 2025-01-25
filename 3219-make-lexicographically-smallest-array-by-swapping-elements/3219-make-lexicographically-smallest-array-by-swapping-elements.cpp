class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
      vector<pair<int,int>>v;
      int n= nums.size();
      for(int i=0;i<n;i++){
        v.push_back({nums[i],i});
      }  

      sort(v.begin(),v.end());

      vector<vector<pair<int,int>>> help;
      help.push_back({v[0]});
      for(int i=1;i<n;i++){
        if(v[i].first - v[i-1].first <= limit){
            help.back().push_back(v[i]);
        }else{
            help.push_back({v[i]});
        }
      }

      for(auto h:help){
        vector<int>indices;
        for(auto y: h){
            indices.push_back(y.second);
        }
        sort(indices.begin(),indices.end());
        for(int i =0;i< indices.size();i++){
            nums[indices[i]] = h[i].first;
        }

      }
      return nums;
        
    }
};