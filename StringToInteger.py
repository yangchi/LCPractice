class Solution:
    # @return an integer
    def atoi(self, str):
        str = str.strip()
        if str == "":
            return 0
        negative = False
        index = 0
        if str[index] == "+" or str[index] == "-":
            if str[index + 1] == "+" or str[index + 1] == "-":
                return 0
            if str[index] == "-":
                negative = True
            index += 1
        result = 0
        factor = 1
        while index < len(str):
            if str[index] == ".":
                factor = 0.1
                index += 1
                continue
            if not str[index].isdigit():
                break
            result *= 10
            result += int(str[index]) * factor
            factor *= factor
            index += 1
        if result > 2147483647 and not negative: #this is stupid, LC
            result = 2147483647
        if result > 2147483648 and negative:
            result = 2147483648
        if negative:
            return ( 0 - result)
        return result
