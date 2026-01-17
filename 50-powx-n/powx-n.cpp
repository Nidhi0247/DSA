class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if(n<0){
           // double m = 1/abs(n);
            ans= pow(x,n);
        }
        else{
            ans = pow(x,n);
        }
        return ans;
    }
};