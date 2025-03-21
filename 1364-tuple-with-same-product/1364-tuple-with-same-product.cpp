class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        // Step 1: Count the frequency of each product of pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }

        // Step 2: Calculate the number of valid tuples
        int result = 0;
        for (const auto& x : mp) {
            int count = x.second;
            if (count > 1) {
                result += count * (count - 1) * 4; // Each pair contributes 8 tuples
            }
        }

        return result;
    }
};