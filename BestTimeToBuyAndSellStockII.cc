class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty())
            return 0;
        int profit = 0;
        for(size_t i = 0; i < prices.size()-1; i++)
        {
            if(prices[i] < prices[i+1])
                profit += prices[i+1] - prices[i];
        }
        return profit;
    }
};
