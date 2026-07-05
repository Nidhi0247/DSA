class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int i = 0; i < piles.size(); i++){
            high= max(high, piles[i]);
        }
        int low = 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalHours = 0;
            for(int i = 0; i < piles.size(); i++){
                if(piles[i] % mid == 0){
                    totalHours += piles[i]/mid;
                }
                else{
                    totalHours+= piles[i]/mid + 1;
                }
            }
            if(totalHours <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        
        }
        return ans;
    }
};