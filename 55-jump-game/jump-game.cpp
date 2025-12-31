class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int n = nums.size();
        int goal = n-1;
        for(int i =n-1;i>=0;i--){
            if(i+nums[i]>=goal){
                goal =i;
            }
        }
        if(goal==0) return true;
        else{
            return false;
        }
    }
};