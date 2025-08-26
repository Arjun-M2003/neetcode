#include <string>
#include <vector>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>> longestSub(s1, vector<int>(s2, -1));

        int result = dp(longestSub, 0, 0, s1, s2, text1, text2);
        return result;
    }

    int dp(vector<vector<int>>& longestSub, int ind1, int ind2, int s1, int s2, const string& text1, const string& text2){
        if(ind1 >= s1 || ind2 >= s2) return 0;
        if(text1[ind1] == text2[ind2]) {
            return 1 + dp(longestSub, ind1 + 1, ind2 + 1, s1, s2, text1, text2);
        }

        if(longestSub[ind1][ind2] != -1){
            return longestSub[ind1][ind2];
        }

        int sub1 = dp(longestSub, ind1 + 1, ind2, s1, s2, text1, text2);
        int sub2 = dp(longestSub, ind1, ind2 + 1, s1, s2, text1, text2);

        int total = max(sub1, sub2);
        longestSub[ind1][ind2] = total;
        return total;
    }
};
