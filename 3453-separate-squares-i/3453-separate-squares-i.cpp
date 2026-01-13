class Solution {
public:
    double total;

    double areaBelow(vector<vector<int>>& squares, double h) {
        double area = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];

            if (h <= y) {
                continue;
            } 
            else if (h >= y + l) {
                area += l * l;
            } 
            else {
                area += (h - y) * l;
            }
        }

        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        total = 0.0;

        // Compute total area
        for (auto &sq : squares) {
            total += (double)sq[2] * sq[2];
        }

        double low = 0.0;
        double high = 0.0;

        // Maximum possible height
        for (auto &sq : squares) {
            high = max(high, (double)sq[1] + sq[2]);
        }

        double eps = 1e-6;

        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            double below = areaBelow(squares, mid);

            if (below >= total / 2.0) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return (low + high) / 2.0;
    }
};
