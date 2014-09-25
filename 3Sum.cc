class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty() || num.size() < 3)
            return vector<vector<int> > ();
        sort(num.begin(), num.end());
        set<vector<int> > results;
        for(int first = 0; first < num.size()-2; first++)
        {
            int head = first + 1;
            int tail = num.size()-1;
            while(tail > head)
            {
                if(0 == num[first] + num[head] + num[tail])
                {
                    int array[] = {num[first], num[head], num[tail]};
                    vector<int> result(array, array+sizeof(array)/sizeof(array[0]));
                    results.insert(result);
                    tail--;
                    head++;
                }
                while(0 < num[first] + num[head] + num[tail] && tail > head)
                    tail--;
                while(0 > num[first] + num[head] + num[tail] && tail > head)
                    head++;
            }
        }
        if(results.empty())
            return vector<vector<int> > ();
        vector<vector<int> > result_v(results.begin(), results.end());
        return result_v;
    }
};
