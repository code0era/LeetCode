// Last updated: 1/16/2026, 8:21:30 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string s0 = s;
        vector<char> s1 ;
        for(int i = 0 ; i< s.size(); i++){
            if((s[i]>64  && s[i]<91)  ){
                s1.push_back(s[i]+32);
            }
            else if((s[i]>96  && s[i]<123) ){
                s1.push_back(s[i]);
            }
            else if((s[i]>47  && s[i]<58) ){
                s1.push_back(s[i]);
            }
           
           
        }
        
        vector<char> s2 = s1 ;
        reverse(s1.begin(), s1.end());

        if(s1==s2 ){
            return true;
        }
        else return false;

    }
};
