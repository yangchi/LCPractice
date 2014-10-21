class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    
    def searchBinary(self, A, target, low, high):
        if low == high:
            return low if A[low] == target else -1
        if A[low] < A[high]:
            if target < A[low] or target > A[high]:
                return -1
            else:
                mid = low + (high -low) / 2
                if target > A[mid]:
                    return self.searchBinary(A, target, mid + 1, high)
                else:
                    return self.searchBinary(A, target, low, mid)
        else:
            mid = low + (high - low) / 2
            if A[low] <= A[mid]:
                if target <= A[mid]:
                    if target >= A[low]:
                        return self.searchBinary(A, target, low, mid)
                    else:
                        return self.searchBinary(A, target, mid + 1, high)
                else:
                    return self.searchBinary(A, target, mid+1, high)
            else:
                if target > A[mid]:
                    if target <= A[high]:
                        return self.searchBinary(A, target, mid + 1, high)
                    else:
                        return self.searchBinary(A, target, low, mid)
                else:
                    return self.searchBinary(A, target, low, mid)
                    
                    
    def search(self, A, target):
        return self.searchBinary(A, target, 0, len(A) - 1)
    