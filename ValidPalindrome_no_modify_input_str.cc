class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) {
            return true;
        }

        int left = 0, right = s.size() - 1;
        while(left < right) {
            while (!isNumeric(s[left]) && !isAlphabet(s[left])) {
                left++;
            }

            while(!isNumeric(s[right]) && !isAlphabet(s[right])) {
                right--;
            }

            if (left >= right) {
                return true;
            }

            if (isNumeric(s[left]) && isNumeric(s[right])) {
                if (s[left] != s[right]) {
                    return false;
                } else {
                    left++; right--;
                }
            } else if (isAlphabet(s[left]) && isAlphabet(s[right])) {
                if (isSameLetter(s[left], s[right])) {
                    left++; right--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

    bool isNumeric(char c) {
        return c >= '0' && c <= '9';
    }

    bool isAlphabet(char c) {
        return c >= 'a' && c<= 'z' || c >= 'A' && c <= 'Z';
    }

    bool isSameLetter(char a, char b) {
        if (a >= 'A' && a <= 'Z') {
            a = 'a' + (a - 'A');
        }

        if (b >= 'A' && b <= 'Z') {
            b = 'a' + (b - 'A');
        }

        return a == b;
    }
};
