class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        
        for (int mask = 0; mask < (1 << n); mask++) {
            string candidate = "";
            for (int i = n - 1; i >= 0; i--) {
                candidate.push_back((mask & (1 << i)) ? '1' : '0');
            }
            if (!st.count(candidate)) return candidate;
        }
        return "";
    }
};