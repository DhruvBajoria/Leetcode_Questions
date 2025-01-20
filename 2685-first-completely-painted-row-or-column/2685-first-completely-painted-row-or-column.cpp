class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>row,col;
        int n= mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[mat[i][j]] = i;//{i,j}
                col[mat[i][j]] = j;
            }
        }
     
        vector<int>r(n),c(m);
        int n1=arr.size();
        for(int i=0;i<n1;i++){
            r[row[arr[i]]]++;
            c[col[arr[i]]]++;
            if(r[row[arr[i]]] == m || c[col[arr[i]]] == n)
            return i;
        }
        return -1;
    }
};