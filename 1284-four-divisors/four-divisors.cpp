class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;
        for(int num:nums){
            int count =0, local_sum =0;
            for(int j =2;j<=sqrt(num);j++){
                if(num%j==0){
                    count++;
                    local_sum+=j;
                    //count++;
                    if(j!=num/j){
                        count++;
                        local_sum+=num/j;
                    }
                }
                if (count>2) break;
            }
            if(count==2) {
                total_sum += 1+local_sum+num;
            }
        }
        return total_sum;
    }
};