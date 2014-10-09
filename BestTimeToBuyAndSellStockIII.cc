class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty() || prices.size() == 1)
            return 0;
        int position1 = 0, position2 = 0;
        int section2_profit = maximize(prices, 0, prices.size(), &position1, &position2);
        int section1_pos1 = 0, section1_pos2 = 0;
        int section1_profit = maximize(prices, 0, position1 + 1, &section1_pos1, &section1_pos2);
        int section3_pos1 = position2, section3_pos2 = position2;
        int section3_profit = maximize(prices, position2, prices.size(), &section3_pos1, &section3_pos2);
        int section2_pos1 = position1, section2_pos2 = position1;
        minimize(prices, position1, position2 + 1, &section2_pos1, &section2_pos2);
        return max((prices[section2_pos1] - prices[position1] + prices[position2] - prices[section2_pos2]),
                   (max(section1_profit, section3_profit) + section2_profit));
    }
    
    int minimize(vector<int> & prices, int low, int high, int *position1, int *position2) {
        if(low >= high - 1)
            return 0;
        vector<int>  lossByFar(high - low, 0);
        int maxprice = prices[low];
        int max_pos = low;
        int minProfit = 0;
        for(int i = low + 1; i < high; i++) {
            if(prices[i] > maxprice) {
                maxprice = prices[i];
                max_pos = i;
                lossByFar[i] = 0;
            } else {
                lossByFar[i] = prices[i] - maxprice;
            }
            if(lossByFar[i] < minProfit) {
                minProfit = lossByFar[i];
                *position1 = max_pos;
                *position2 = i;
            }
        }
        return minProfit;
    }
    
    int maximize(vector<int> & prices, int low, int high, int *position1, int *position2) {
        if(low >= high - 1)
            return 0;
        vector<int> profitsByFar(high - low, 0);
        int mini = prices[low];
        int mini_pos = low;
        int maxprofit = 0;
        for(int i = low + 1; i < high; i++) {
            if(prices[i] < mini) {
                mini = prices[i];
                mini_pos = i;
                profitsByFar[i] = 0;
            } else {
                profitsByFar[i] = prices[i] - mini;
            }
            if(profitsByFar[i] > maxprofit) {
                *position2 = i;
                *position1 = mini_pos;
                maxprofit = profitsByFar[i];
            }
        }
        return maxprofit;
    }
};