#include <vector>
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> pmap;
        for(auto& string : words){
            pmap[string]++;
        }

        auto cmp = [&pmap](const string& a,const string& b){
            auto iter1 = pmap.find(a);
            auto iter2 = pmap.find(b);
            if(iter1->second == iter2->second){
                return a < b;
            }else{
                return iter1->second > iter2->second;
            }
        };

        priority_queue<string,vector<string>,decltype(cmp)> pq(cmp);

        for(auto& ele : pmap){
            pq.push(ele.first);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> result;
        for(int i = 0;i < k;i++){
            result.push_back(pq.top());
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};