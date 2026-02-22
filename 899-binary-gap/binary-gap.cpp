class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1, pos = 0, maxGap = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                if (lastPos != -1) {
                    maxGap = max(maxGap, pos - lastPos);
                }
                lastPos = pos;
            }
            n /= 2;
            pos++;
        }
        return maxGap;
    }
};