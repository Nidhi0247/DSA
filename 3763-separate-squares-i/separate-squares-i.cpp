class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = 0;
        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + sq[2]);
        }

        auto areaAbove = [&](double yLine) {
            double area = 0;
            for (auto &sq : squares) {
                double bottom = sq[1], top = sq[1] + sq[2];
                if (top <= yLine) continue; 
                double height = top - max(bottom, yLine);
                area += height * sq[2];
            }
            return area;
        };

        auto areaBelow = [&](double yLine) {
            double area = 0;
            for (auto &sq : squares) {
                double bottom = sq[1], top = sq[1] + sq[2];
                if (bottom >= yLine) continue; 
                double height = min(top, yLine) - bottom;
                area += height * sq[2];
            }
            return area;
        };

        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2.0;
            double above = areaAbove(mid);
            double below = areaBelow(mid);
            if (above > below) low = mid;
            else high = mid;
        }
        return low;
    }
};