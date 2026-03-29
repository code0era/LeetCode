// Last updated: 3/29/2026, 4:08:13 PM
class Solution {
public:
    int firstMatchingIndex(string s) {
        for( int i = 0 ; i< s.size(); i++){
            if(s[i] == s[s.size() -i-1]) return i;
        }
        return -1;
    }
};