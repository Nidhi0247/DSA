class Solution {
public:
int daysRequire(vector<int>weights,int cap){
    int days=1, load=0;
    for(int i = 0;i<weights.size();i++){
        if(load+weights[i]>cap){
            days++;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high=0,ans;
        for(int i =0;i<weights.size();i++){
             high += weights[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(daysRequire(weights,mid)<=days){
                ans=mid;
                high= mid-1;
            }
            else low =mid+1;
        }
        return ans;
    }
};