// Last updated: 1/17/2026, 6:56:02 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        for(int i = 0 ; i <strs[0].size(); i++){
            char c = strs[0][i];
            for( int j = 0 ; j <strs.size() ; j++){
                if(i>=strs[j].size()|| strs[j][i]!=c){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0]; //  first whole string got matched 
    }
};