// Last updated: 1/16/2026, 8:19:39 PM
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string , long long> freq;
        for(const string &s : words){
            string key = "";
            int base = s[0] - 'a';
            for(char c : s){
                int d  = (c -'a' - base+26)%26;
                key.push_back('a'+ d);
                
            }
            freq[key]++;
        }long long a = 0 ;
        for(auto &it:freq){
            long long  k = it.second;
            a+=(k*(k-1))/2;
        }
        return a;
    }
};