// Last updated: 5/23/2026, 10:04:47 PM
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(  int i =0; i < s.length() - 1 ; ++i){
            if(abs(s[i] - s[i+1]) >2){
                return false;
            }
        }   
        return true;
    }
};