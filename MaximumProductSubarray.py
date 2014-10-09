class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        if len(A) == 1:
            return A[0]
        maxsofar = A[0]
        minsofar = A[0]
        maxprd = A[0]
        for i in range(1, len(A)):
            new_maxsofar = max(maxsofar * A[i], minsofar * A[i])
            new_maxsofar = max(new_maxsofar, A[i])
            minsofar = min(maxsofar * A[i], minsofar * A[i])
            minsofar = min(minsofar, A[i])
            maxsofar = new_maxsofar
            maxprd = max(maxsofar, maxprd)
        return maxprd