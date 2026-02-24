// Last updated: 2/24/2026, 10:55:21 AM
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int >f= {1,1,2,6,24,120,720,5040,40320,362880};
        string s = to_string(n);
        sort(s.begin(), s.end());
        do{
            if(s[0] =='0')continue;
            long long sum = 0 ;
            for(char c:s) sum+=f[c-'0'];
            if(sum == stoll(s)) return true;
         }
        while(next_permutation(s.begin() , s.end()));
        return false ;
    }
};