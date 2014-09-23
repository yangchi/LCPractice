class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int apos = 0;
        int alength = m;
        int bpos = 0;
        for(bpos =0 ; bpos < n; bpos++)
        {
            while(B[bpos] > A[apos] && apos < alength)
                apos++;
            if(apos >= alength)
                break;
            moveback(A, apos, alength);
            alength++;
            A[apos++] = B[bpos];
        }
        while(bpos < n)
            A[alength++] = B[bpos++];
    }
    
    void moveback(int A[], int start, int end)
    {
        for(int i = end; i > start; i--)
            A[i] = A[i-1];
    }
};