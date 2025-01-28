class Solution {
public:
int n,m;
int solve(int i,int j,vector<vector<int>>&grid, vector<vector<bool>>&vis){
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || !grid[i][j]){
        return 0;
    }
    int temp = grid[i][j];
    vis[i][j]=1;
    temp+=solve(i+1,j,grid,vis);
    temp+=solve(i-1,j,grid,vis);
    temp+=solve(i,j+1,grid,vis);
    temp+=solve(i,j-1,grid,vis);
    return temp;

}
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m=grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    ans=max(ans,solve(i,j,grid,vis));
                }
            }
        }
        return ans;

        
    }
};