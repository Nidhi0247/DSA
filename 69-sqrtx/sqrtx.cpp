class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int start = 1, end = x;
        int mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            long long square = 1LL * mid * mid;

            if (square == x)
                return mid;
            else if (square < x)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return end;
    }
};