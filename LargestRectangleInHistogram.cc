class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            if (height.empty()) {
                return 0;
            }

            stack<int> maxes;
            int largest = INT_MIN;
            int i = 0;
            while(i < height.size()) {
                if (maxes.empty() || height[i] >= height[maxes.top()]) {
                    maxes.push(i);
                    i++;
                } else {
                    int curr_top_index = maxes.top();
                    maxes.pop();
                    int area;
                    if (maxes.empty()) {
                        area = height[maxes.top()] * i;
                    } else {
                        area = height[curr_top_index] * (i - 1 - maxes.top());
                    }
                    if (area > largest) {
                        largest = area;
                    }
                }
            }

            while(!maxes.empty()) {
                int curr_top_index = maxes.top();
                maxes.pop();
                int area;
                if (maxes.empty()) {
                    area = height[curr_top_index] * height.size();
                } else {
                    area = height[curr_top_index] * (height.size() - maxes.top() - 1);
                }
                if (area > largest) {
                    largest = area;
                }
            }

            return largest;
        }
};
