#include <string>
#include <vector>
#include <stack>
class Solution {
private:
    struct State{
        string current;
        int open;
        int close;
    };

public:
    vector<string> generateParenthesis(int n) {
        std::stack<State> stk;
        std::vector<string> output;

        stk.push({"", 0, 0});
        while(!stk.empty()){
            State state = stk.top();
            stk.pop();

            if(state.open == n && state.close == n){
                output.push_back(state.current);
                continue;
            }

            if(state.open < n){
                stk.push({state.current + "(", state.open + 1, state.close});
            }
            if(state.close < state.open){
                stk.push({state.current + ")", state.open, state.close + 1});
            }
        }

        return output;
    }
};
