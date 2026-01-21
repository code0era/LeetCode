// Last updated: 1/21/2026, 3:20:34 PM
#include <algorithm>
class Solution {
public:
    int maxDepth(string s) {
        int d = 0 ;
        int a= 0;
        for(auto  c: s){
            if(c=='('){
                d++;
                a = max(d,a);
            }
            else if (c==')'){

                d--;
            }
            
        }
        return a;
    }
};