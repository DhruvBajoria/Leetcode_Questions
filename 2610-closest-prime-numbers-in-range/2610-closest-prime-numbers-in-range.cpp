class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(right+1, true);
        v[0] = false;
        v[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (v[i] == true) {
                for (int j = i * i; j <= right; j += i) {
                    v[j] = false;
                }
            }
        }
        int help = INT_MAX;
        vector<int> helper;
        for (int i = left; i <= right; i++) {
            if (v[i] == true)
                helper.push_back(i);
        }
        vector<int> ans(2, -1);
        for (int i = 1; i < helper.size(); i++) {
            if (helper[i] - helper[i - 1] < help) {
                ans[0] = helper[i - 1];
                ans[1] = helper[i];
                help = helper[i] - helper[i - 1];
            }
        }
        return ans;
    }
};