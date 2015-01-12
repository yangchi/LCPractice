class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            if (height.empty()) {
                return 0;
            }

            if (height.size() == 1) {
                return height[0];
            }
            stack<int> barstack;
            int maxarea = INT_MIN;
            int i = 0;
            while(i < height.size()) {
                if (barstack.empty()) {
                    barstack.push(i++);
                    continue;
                }
                int current_top = barstack.top();
                if (height[i] >= height[current_top]) {
                    barstack.push(i++);
                } else {
                    barstack.pop();
                    int area;
                    if (barstack.empty()) {
                        area = height[current_top] * i;
                    } else {
                        int last_lower = barstack.top();
                        area = height[current_top] * (i - last_lower - 1);
                    }
                    if (area > maxarea) {
                        maxarea = area;
                    }
                }
            }

            while(!barstack.empty()) {
                int current_top = barstack.top();
                int area;
                barstack.pop();
                if (barstack.empty()) {
                    area = height[current_top] * height.size();
                } else {
                    int next_top = barstack.top();
                    area = height[current_top] * (height.size() - 1 - next_top);
                }
                if (area > maxarea) {
                    maxarea = area;
                }
            }
            return maxarea;
        }
};
