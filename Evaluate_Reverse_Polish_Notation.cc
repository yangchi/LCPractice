class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            set<string> ops = {"+", "-", "*", "/"};
            stack<string> mystack;
            for(string word: tokens)
            {
                if(ops.find(word) == ops.end())
                {
                    mystack.push(word);
                }
                else
                {
                    int op2 = atoi(mystack.top().c_str());
                    mystack.pop();
                    int op1 = atoi(mystack.top().c_str());
                    mystack.pop();
                    if(word == "+")
                        mystack.push(to_string(op1+op2));
                    else if(word == "-")
                        mystack.push(to_string(op1-op2));
                    else if(word == "*")
                        mystack.push(to_string(op1*op2));
                    else if(word == "/")
                        mystack.push(to_string(op1/op2));
                }
            }
            return atoi(mystack.top().c_str());
        }
};
