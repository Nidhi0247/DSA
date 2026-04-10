class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int ans = INT_MAX;

        // Store indices
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        for (auto &p : pos) {
            auto &list = p.second;

            if (list.size() < 3) continue;
            for (int j = 0; j + 2 < list.size(); j++) {
                int i = list[j];
                int k = list[j + 2];

                ans = min(ans, 2 * (k - i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};