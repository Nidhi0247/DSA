class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long a = 6, b = 6; // a = Type A, b = Type B for n=1
        for(int i = 2; i <= n; i++) {
            long newA = (a * 2 + b * 2) % MOD;
            long newB = (a * 2 + b * 3) % MOD;
            a = newA;
            b = newB;
        }
        return (a + b) % MOD;
    }
};