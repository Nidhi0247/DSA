class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int index, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};