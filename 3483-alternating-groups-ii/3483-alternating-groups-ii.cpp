class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& ans, int k) {
        for(int i=0;i<k-1;i++){
            ans.push_back(ans[i]);
        }
        int cnt=0;
        int len =1;
        for(int i=1;i<ans.size();i++){
            // cout<<ans[i]<<endl;
            if(ans[i]!=ans[i-1]){
                len++;
            }else{
                len=1;
            }
            cnt+=(len>=k?1:0);
        }
        return cnt;
    }
};