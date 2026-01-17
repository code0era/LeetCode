// Last updated: 1/17/2026, 6:54:24 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans  = "";
        int d = 0 ;
        for(char c: s){
            if(c =='('){
                if(d>0){ans+=c;}
                d++;
            }else{
                d--;
                if(d>0)ans+=c;
            }
        }
        return ans;
    }
};