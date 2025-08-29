#include <vector>
#include <stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::stack<int> stk;
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int pindex = stk.top();
                stk.pop();
                result[pindex] = i - pindex;
            }
            stk.push(i);
        }

        return result;

    }
};
