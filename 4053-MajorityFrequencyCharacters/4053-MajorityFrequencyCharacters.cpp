// Last updated: 1/16/2026, 8:19:53 PM
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char , int > freq;
        for(char c: s ){
            freq[c]++;
        }
        unordered_map<int, vector<char>> groups;
        for(auto &p: freq){
        groups[p.second].push_back(p.first);
        }
        int max = -1 ;
        int best = -1;
        vector<char> result;
        for(auto &g : groups){
            int a = g.first;
            int size = g.second.size();
            if(size> max || (size == max && a > best)){
                max = size;
                best = a;
                result = g.second;
            }
        }
        string ans(result.begin() , result.end());
        return ans;
    }
};