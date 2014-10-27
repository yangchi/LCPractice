import sys

class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        steps = [0 for i in range(len(A))]
        #steps[len(A) - 1] = 1 if A[len(A) - 1] > 0 else 0
        for i in range(len(A) - 2, -1, -1):
            min = sys.maxsize
            for j in range(A[i]):
                if i + j + 1 < len(A):
                    if steps[i + j + 1] + 1 < min:
                        min = steps[i + j + 1] + 1
                        print("Updateing " + str(i) + " with " + str(i + j + 1))
            steps[i] = min
            print("i becomes: " + str(steps[i]))
            print(steps)
        return steps[0]

sol = Solution()
print(sol.jump([2, 3, 1, 1, 4]))