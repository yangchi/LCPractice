class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        word_list = s.split()
        reverse_list = [word for word in reversed(word_list)]
        ret_str = ""
        for word in reverse_list:
            ret_str += word + " "
        ret_str = ret_str[:len(ret_str)-1]
        return ret_str
