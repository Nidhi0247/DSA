class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int value = nums[0];
        sort(nums.begin()+1,nums.end());
        int min_sum = value + nums[1]+nums[2];
        return min_sum;
    }
};