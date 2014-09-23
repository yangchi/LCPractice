class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> translator = {{'M', 1000}, {'D' , 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5},{'I', 1}};
        return recursiveTranslate(s, 0, translator);
    }
    
    int recursiveTranslate(string s, int pos, map<char, int> & translator)
    {
        int number;
        if(pos == s.size())
            return 0;
        if(pos == s.size()-1)
            return translator[s[pos]];
        if(s[pos] == 'I')
        {
            if(s[pos+1] == 'V')
            {
                number = 4;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else if(s[pos+1] == 'X')
            {
                number = 9;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else
            {
                number = 1;
                number += recursiveTranslate(s, pos+1, translator);
            }
        }
        else if(s[pos] == 'X')
        {
            if(s[pos+1] == 'L')
            {
                number = 40;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else if(s[pos+1] == 'C')
            {
                number = 90;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else
            {
                number = 10;
                number += recursiveTranslate(s, pos+1, translator);
            }
            
        }
        else if(s[pos] == 'C')
        {
            if(s[pos+1] == 'D')
            {
                number = 400;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else if(s[pos+1] == 'M')
            {
                number = 900;
                number += recursiveTranslate(s, pos+2, translator);
            }
            else
            {
                number = 100;
                number += recursiveTranslate(s, pos+1, translator);
            }
        }
        else
        {
            number = translator[s[pos]];
            number += recursiveTranslate(s, pos+1, translator);
        }
        return number;
    }
};
