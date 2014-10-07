class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> previous;
            vector<int> current(1, 1);
            if(rowIndex == 0) {
                return current;
            }
            while(rowIndex--) {
                previous = current;
                current.clear();
                current.push_back(1);
                for(int i = 1; i < previous.size(); i++) {
                    current.push_back(previous[i - 1] + previous[i]);
                }
                current.push_back(1);
            }
            return current;
        }
};
