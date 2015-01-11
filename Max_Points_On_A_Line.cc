/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/

typedef pair<double, double> Line;

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() < 3) {
            return points.size();
        }
        int max_points_online = INT_MIN;
        for(int i = 0; i < points.size(); i++) {
            Point first = points[i];
            map<Line, int> line_counter;
            int colocate = 0;
            for(int j = i + 1; j < points.size(); j++) {
                Point second = points[j];
                if (first.x == second.x && first.y == second.y) {
                    colocate++;
                } else {
                    double y = (double)(first.y - second.y);
                    double x = (double)(first.x - second.x);
                    double slope = 0;
                    if (x != 0) {
                        slope = y / x;
                    }
                    double intercept = first.y - slope * first.x;
                    line_counter[pair<double, double>(slope, intercept)]++;
                }
            }
            if (line_counter.empty()) {
                max_points_online = max(max_points_online, colocate + 1);
            }
            for(auto line : line_counter) {
                if (line.second + colocate + 1 > max_points_online) {
                    max_points_online = line.second + colocate + 1;
                }
            }

        }
        return max_points_online;
    }
};
