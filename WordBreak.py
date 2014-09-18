class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        if len(s) == 0:
            if "" in dict:
                return True
            else:
                return False
        booleans = [False for i in range(len(s))]
        if s[0] in dict:
            booleans[0] = True
        for pos in range(1, len(s)):
            if s[:pos+1] in dict:
                booleans[pos] = True
                continue
            for sub in range(0, pos):
                if booleans[sub] and s[sub+1:pos+1] in dict:
                    booleans[pos] = True
                    break
        return booleans[len(s)-1]

            