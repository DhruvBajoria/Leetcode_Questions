/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> st;
        for (int i = 0, level, val; i < traversal.length();) {
            for (level = 0; traversal[i] == '-'; i++)
                level++;
            for (val = 0; i < traversal.length() && traversal[i] != '-'; i++)
                val = val * 10 + traversal[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (st.size() > level) st.pop_back();
            if (!st.empty())
                if (!st.back()->left) st.back()->left = node;
                else st.back()->right = node;
            st.push_back(node);
        }
        return st[0];
    }
};