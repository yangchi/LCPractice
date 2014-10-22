class Solution:
    # @return a string
    def countAndSay(self, n):
        if n == 1:
            return "1"
        last_str = self.countAndSay(n - 1)
        result = 0
        count = 0
        index = 0
        while index < len(last_str):
            if index == len(last_str) - 1:
                count += 1
                result *= 10
                result += count
                result *= 10
                result += int(last_str[index])
                break
            if last_str[index] == last_str[index + 1]:
                count += 1
                index += 1
            else:
                count += 1
                result *= 10
                result += count
                count = 0
                result *= 10
                result += int(last_str[index])
                index += 1
        return str(result)
                