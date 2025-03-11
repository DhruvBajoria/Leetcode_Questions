class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left =0;
        int ans=0;
        unordered_map<char,int>mp={{'a', 0},{'b', 0},{'c', 0}};
        for(int right =0;right<n;right++){
            mp[s[right]]++;
            while(mp['a']>0 && mp['b'] && mp['c']){
                ans += n-right;
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};