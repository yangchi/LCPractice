class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        if len(s) == 0:
            if "" in dict:
                return [""]
            else:
                return []
        booleans = [False for i in range(len(s))]
        sentences = [set() for i in range(len(s))]
        if s[0] in dict:
            booleans[0] = True
            sentences[0].add(s[0])
        for pos in range(1, len(s)):
            if s[:pos+1] in dict:
                booleans[pos] = True
                sentences[pos].add(s[:pos+1])
            for sub in range(0, pos):
                if booleans[sub] and s[sub+1:pos+1] in dict:
                    booleans[pos] = True
                    for substr in sentences[sub]:
                        if substr != "":
                            sentences[pos].add(substr + " " + s[sub+1:pos+1])
                        else:
                            sentences[pos].add(s[sub+1 : pos+1])
        return list(sentences[len(s)-1])