class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //first remove all negatives, also record min and max
        int min = A[0];
        int max = A[0];
        unordered_set<int> positives;
        for(int i = 0; i < n; i++)
        {
            if(A[i] > 0)
                positives.insert(A[i]);
            if(A[i] > max)
                max = A[i];
            if(min < 0 || A[i] > 0 && A[i] < min)
                min = A[i];
        }
        int lookfor = 1;
        while(lookfor < max)
            if(positives.find(lookfor) == positives.end())
                return lookfor;
            else
                lookfor++;
        return max+1;
    }
};
