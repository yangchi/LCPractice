class Solution {
    public:
        int maxArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int max = 0;
            for(int i = 0; i < height.size();)
            {
                for(int j = height.size()-1; j >=0;)
                {
                    if(i == j)
                        return max;
                    int area = 0;
                    if(height[i] < height[j])
                        area = (j-i)*height[i++];
                    else
                        area = (j-i)*height[j--];
                    if(area > max)
                        max = area;
                }
            }
            return max;
        }
};
