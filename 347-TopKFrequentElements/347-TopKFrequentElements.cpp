// Last updated: 3/29/2026, 9:06:51 AM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<pair<int, int>> p;
        for(auto &v : freq){
            p.push_back({v.second, v.first});
        }
        sort(p.rbegin(), p.rend());
        vector<int> res;
        for(int i = 0 ; i < k ; i++){
            res.push_back(p[i].second);
        }
        return res;
    }
};