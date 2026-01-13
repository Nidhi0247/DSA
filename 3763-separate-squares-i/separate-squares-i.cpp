class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = 0;

        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + sq[2]);
        }

        auto areaDiff = [&](double y) {
            double diff = 0;
            for (auto &sq : squares) {
                double bottom = sq[1];
                double top = sq[1] + sq[2];
                double side = sq[2];
                if (top > y)
                    diff += max(0.0, top - max(bottom, y)) * side;
                if (bottom < y)
                    diff -= max(0.0, min(top, y) - bottom) * side;
            }
            return diff;
        };
        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2.0;
            if (areaDiff(mid) > 0)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};
