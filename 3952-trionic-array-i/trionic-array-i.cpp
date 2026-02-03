class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        int q = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        return p > 0 && q > p && q < n - 1 && i == n - 1;
    }
};