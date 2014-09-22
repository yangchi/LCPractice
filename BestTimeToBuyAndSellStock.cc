class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.empty() || prices.size() == 1)
            return 0;
        vector<int> profits(prices.size(), 0);
        profitByFar(prices, profits);
        return vecmax(profits);
    }
    
    int vecmax(const vector<int> & vec)
    {
        int max = vec[0];
        for(auto value: vec)
            if(value > max)
                max = value;
        return max;
    }
    
    void profitByFar(const vector<int> & prices, vector<int> & profits)
    {
        int min = prices[0];
        profits[0] = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(min > prices[i])
            {
                profits[i] = 0;
                min = prices[i];
            }
            else
                profits[i] = prices[i] - min;
        }
    }
};
