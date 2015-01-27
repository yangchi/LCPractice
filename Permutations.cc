class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        permuteDFS(num, 0, result);
        return result;
    }

    void permuteDFS(vector<int> & num, int position, vector<vector<int>> & result) {
        if (position == num.size()) {
            result.push_back(num);
        }

        for(int i = position; i < num.size(); i++) {
            swap(num, position, i);
            permuteDFS(num, position + 1, result);
            swap(num, position, i);
        }
    }

    void swap(vector<int> & num, int first, int second) {
        int temp = num[first];
        num[first] = num[second];
        num[second] = temp;
    }
};
