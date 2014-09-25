class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int sum = accumulate(num.begin(), num.begin()+3, 0);
        int mindiff = abs(sum-target);
        int closest = sum;
        for(int first = 0; first < num.size(); first++)
        {
            int second = first+1;
            int third = num.size()-1;
            while(second < third)
            {
                sum = num[first]+num[second]+num[third];
                if(sum == target)
                    return sum;
                if(abs(sum-target) < mindiff)
                {
                    closest = sum;
                    mindiff = abs(sum-target);
                }
                if(sum > target && third > second)
                    third--;
                if(sum < target && third > second)
                    second++;
            }
        }
        return closest;
    }
};