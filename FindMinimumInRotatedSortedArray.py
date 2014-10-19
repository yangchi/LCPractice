class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        for i in range(1, len(num)):
            if num[i] < num[i - 1]:
                return num[i]
        return num[0]
