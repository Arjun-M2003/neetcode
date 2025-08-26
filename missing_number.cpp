#include <vector>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // xor cancels out any number seen twice
        
        int n = nums.size();
        int xr = 0;

        // introduce every number first
        for(int i = 0; i <= n; i++){
            xr ^= i;
        }

        // loop through nums to find the missing one
        for(int num : nums){
            xr ^= num;
        }

        return xr;
    }
};