class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        sentences = {}
        for letter in s:
            if letter in dict:
                if letter in sentences.keys():
                    sentences[letter].append((letter))
                else:
                    sentences[letter] = [(letter)]
        for length in range(2, len(s)+1):
            for start in range(0, len(s)):
                end = start + length
                if end <= len(s):
                    for mid in range(start, end + 1):
                        if s[start:mid+1] in sentences.keys() and s[mid + 1:end] in sentences.keys():
                            if s[start:end] in sentences.keys():
                                sentences[s[start:end]].append((s[start:mid+1], s[mid+1:end]))
                            else:
                                sentences[s[start:end]] = [(s[start:mid], s[mid + 1:end])]
        if s not in sentences.keys():
            return []
        else:
            ret = []
            for combo in sentences[s]:
                str_repr = ""
                for word in combo:
                    str_repr += word + " "
                ret.append(str_repr[:-1])
            return ret

        