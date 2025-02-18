class Solution {
public:
    string smallestNumber(string pattern) {
         int n= pattern.size();
        stack<int>st;
        string res = "";

        for(int i=1;i<=n+1;i++){
            st.push(i);
            char ch =  pattern[i-1];

            if(i==n+1 || ch=='I'){
                while(!st.empty())
                {
                    res.push_back(char('0'+st.top()));
                    st.pop();
                }
            }
        }
        return res;
        
    }
};