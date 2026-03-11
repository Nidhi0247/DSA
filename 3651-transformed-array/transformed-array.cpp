class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            } else {
                int steps = nums[i];
                int newIndex = ((i + steps) % n + n) % n; 
                result[i] = nums[newIndex];
            }
        }
        return result;
    }
};