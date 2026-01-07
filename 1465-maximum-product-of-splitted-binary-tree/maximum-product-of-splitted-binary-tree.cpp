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
    int totalSum = 0;
    long long best = 0;   
    const int MOD = 1e9 + 7;
    int getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val 
             + getTotalSum(root->left) 
             + getTotalSum(root->right);
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int subSum = root->val + left + right;
        long long product = 1LL * subSum * (totalSum - subSum);
        best = max(best, product);

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return best % MOD;
    }
};
