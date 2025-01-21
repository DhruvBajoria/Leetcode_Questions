class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       int m = grid[0].size();
        long long sum = 0;
        for(int j=0;j<m;j++){
            sum += grid[0][j];
        }
        long long secondsum =0;
        long long mi = LLONG_MAX;
        for(int i=0;i<m;i++){
            sum-=grid[0][i];
            mi = min(mi,max(sum,secondsum));
            secondsum += grid[1][i];
        }
        return mi;
       

        
    }
};