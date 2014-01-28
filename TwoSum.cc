//Two pointers won't pass the large cases.  Use Binary Search passes everything:
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if(numbers.empty())
            return result;
        vector<int> sorted{numbers};
        sort(sorted.begin(), sorted.end());
        int index1, index2;
        for(index1 = 0; index1 < sorted.size(); index1++)
        {
            if(sorted[index1] > target)
                return result;
            int index2 = BinarySearch(sorted, index1+1, sorted.size()-1, target - sorted[index1]);
            if(index2 != -1)
            {
                int ind1, ind2;
                ind1 = find(numbers.begin(), numbers.end(), sorted[index1]) - numbers.begin() + 1;
                if(sorted[index1] == sorted[index2])
                    ind2 = find(numbers.begin() + ind1, numbers.end(), sorted[index2]) - numbers.begin() + 1;
                else
                    ind2 = find(numbers.begin(), numbers.end(), sorted[index2]) - numbers.begin() + 1;
                result.push_back(ind1);
                result.push_back(ind2);
                sort(result.begin(), result.end());
                return result;
            }
        }
        return result;
    }
    
    int BinarySearch(vector<int> & numbers, int begin, int end, int target)
    {
        if(begin > end || numbers.size() < end)
            return -1;
        if(begin == end && begin < numbers.size())
            if(numbers[begin] == target)
                return begin;
            else
                return -1;
        while(begin <= end && begin < numbers.size() && end < numbers.size())
        {
            int mid = (end - begin)/2 + begin;
            if(numbers[mid] == target)
                return mid;
            if(numbers[mid] < target)
                begin = mid + 1;
            if(numbers[mid] > target)
                end = mid - 1;
        }
        return -1;
    }
};

