class Solution {
public:
    int maxDistance(vector<int>& num1, vector<int>& num2) {
        int i = 0;
        int j =0;
        int ans=0;
        while(i<num1.size() && j<num2.size()){
            if(num1[i]<=num2[j]){
                ans = max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};