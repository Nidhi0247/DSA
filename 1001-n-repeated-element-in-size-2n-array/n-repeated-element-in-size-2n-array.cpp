class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i = nums.size()-3 ;i>=0; i--){
            if (nums[i]== nums[i+1]|| nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums.back();
    }
};