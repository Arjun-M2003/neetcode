#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;

        if(nums.size() == 1) return {};

        csum(nums, target, 0, subset, result);
        return result;
    }

private:
    void csum(vector<int>& nums, int target, int i, vector<int> subset,vector<vector<int>>& result){
        int current_sum = accumulate(subset.begin(), subset.end(), 0);
        if(current_sum == target){
            result.push_back(subset);
            return;
        }

        if(i >= nums.size() || current_sum > target) return;
        
        subset.push_back(nums[i]);

        // repeated numbers are allowed so it is i instead of i + 1
        csum(nums, target, i, subset, result);
        subset.pop_back();
        csum(nums, target, i + 1, subset, result);
    }
};
