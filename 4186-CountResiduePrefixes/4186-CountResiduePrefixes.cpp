// Last updated: 1/16/2026, 8:19:37 PM
class Solution {
public:
    int residuePrefixes(string s) {
        vector<bool> seen (26, false);
        int distinct  = 0  ;
        int ans =0;
        for(int i  = 0 ; i < s.length(); i++){
            int id = s[i] - 'a';
            if(!seen[id]){
                seen[id] =true;
                distinct++;
            }
            if(distinct == (i+1)%3){
                ans++;
            }
        }
        return ans;
    }
    
};