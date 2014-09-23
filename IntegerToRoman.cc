class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string numeral;
        map<int, string> translator = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        map<int, string>::reverse_iterator iter = translator.rbegin();
        while(iter != translator.rend() && num > 0)
        {
            if(num >= iter->first)
            {
                num -= iter->first;
                numeral += iter->second;
            }
            else
                iter++;
        }
        return numeral;
    }
};