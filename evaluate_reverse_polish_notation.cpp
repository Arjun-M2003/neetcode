#include <string>
#include <stack>
#include <vector>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for(const std::string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                int output = 0;
                if(token == "+") output = a + b;
                else if(token == "-") output = a - b;
                else if(token == "*") output = a * b;
                else if(token == "/") output = a / b;
                stack.push(output);
            } else{
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    
    }
};
