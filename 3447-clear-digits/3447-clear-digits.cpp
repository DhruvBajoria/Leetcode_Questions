class Solution {
public:
    string clearDigits(string s) {
        string ans;
        stack<char>st;
        for(auto x:s){
            if(x>='a' && x<='z'){
                st.push(x);
            }else{
                if(!st.empty())
                st.pop();
            }
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
     reverse(ans.begin(),ans.end());
     return ans;
        
    }
};