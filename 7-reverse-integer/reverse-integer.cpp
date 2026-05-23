class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x!=0){
            int digit = x % 10;
            ans = (ans * 10) + digit;
            x = x/10;
        }
        if(ans>=-pow(2,31) && ans<=pow(2,31)-1){
            return ans;
        }
        else{
            return 0;
        }
    }
};