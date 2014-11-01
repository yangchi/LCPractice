class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            string temp;
            vector<string> result;
            generateParenthesisRecur(n, 0, 0, temp, result);
            return result;
        }

        void generateParenthesisRecur(int n, int left_so_far, int right_so_far, string current_string, vector<string> & result) {
            if(left_so_far == n && right_so_far == n) {
                result.push_back(current_string);
            }
            if (left_so_far < n)
                generateParenthesisRecur(n , left_so_far + 1, right_so_far, current_string + "(", result);
            if (right_so_far < left_so_far)
                generateParenthesisRecur(n, left_so_far, right_so_far + 1, current_string + ")", result);
        }

};
