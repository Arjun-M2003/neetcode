#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[index][can buy]
        int n = prices.size();
        vector<vector<int>> mem(n, vector<int>(2, -1));

        return dp(mem, 0, 1, prices);
    }

    int dp(vector<vector<int>>& mem, int index, bool canBuy, vector<int>& prices){
        if(index >= prices.size()) return 0;
        
        if(mem[index][canBuy] != -1){
            return mem[index][canBuy];
        }

        int result = 0;
        if(canBuy == 1){
            int buy = -prices[index] + dp(mem, index + 1, 0, prices);
            int skip = dp(mem, index + 1, 1, prices);
            result = max(buy, skip);
        } else {
            int sell = prices[index] + dp(mem, index + 2, 1, prices);
            int skip = dp(mem, index + 1, 0, prices);
            result = max(sell, skip);
        }

        mem[index][canBuy] = result;
        return mem[index][canBuy];
    }
};
