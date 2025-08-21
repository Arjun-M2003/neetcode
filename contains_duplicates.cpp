#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> pmap;
        for(int num : nums){
            if(pmap.count(num)){
                return true;
            }
            pmap.insert(num);
        }

        return false;
    }
};