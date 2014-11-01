class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
        if needle == "":
            return haystack
        first = 0
        second = 0
        if len(haystack) == len(needle):
            for i in range(len(needle)):
                if needle[i] != haystack[i]:
                    return None
            return haystack
        while first < len(haystack) - len(needle):
            while haystack[first + second] == needle[second]:
                second += 1
                if second == len(needle):
                    return haystack[first: ]
            first += 1
            second = 0
        return None
        