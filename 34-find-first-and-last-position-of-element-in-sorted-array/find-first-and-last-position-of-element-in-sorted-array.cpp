class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};
       //ans.push_back({-1,-1});
        int sidx= -1, eidx = -1;
        //int j = nums.size()-1;
        if(nums.empty()) return ans;
        for(int i =0; i<nums.size();i++){
            if(nums[i]==target){
                sidx=i;
                break;
            }
            }
        for(int j = nums.size()-1;j>=0;j--){
            if(nums[j]==target){
                eidx = j;
                break;
            }
        }
        ans[0]=sidx;
        ans[1]= eidx;
        return ans ;
    }
        
};