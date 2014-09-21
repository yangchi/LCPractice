class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        result = [1 for i in range(len(ratings))]
        i = 1
        while i < len(ratings):
            if ratings[i] > ratings[i - 1]:
                result[i] = result[i - 1] + 1
            '''
            elif ratings[i] == ratings[i - 1]:
                result[i] = 1
            else:
                j = i
                result[j] = 1
                while j >=0 and not result[j] < result[j - 1] and ratings[j] < ratings[j - 1]:
                    result[j - 1]  = max(result[j - 1] + 1, result[j] + 1)
                    j -= 1
            '''
            i += 1
        i = len(ratings) - 1
        while i > 0:
            if ratings[i] < ratings[i - 1] and not result[i] < result[i - 1]:
                result[i - 1] = result[i] + 1
            i -= 1
        return sum(result)