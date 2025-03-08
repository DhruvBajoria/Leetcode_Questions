class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wcnt = 0;
        int n=blocks.length();
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')
            wcnt++;
        }
        int ans=wcnt;
        for(int i=k;i<n;i++){
            if(blocks[i-k]=='W')
            wcnt--;
            if(blocks[i]=='W')
            wcnt++;
            ans=min(ans,wcnt);
        }
        return ans;
    }
};