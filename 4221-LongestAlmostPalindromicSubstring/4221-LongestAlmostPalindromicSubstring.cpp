// Last updated: 2/15/2026, 12:35:46 PM
class Solution {
public:
    int almostPalindromic(string s) {
        int n = (int) s.size();
        vector< vector< char>> dp0(n , vector<char>(n,0));
        vector< vector< char>> dp1(n , vector<char>(n,0));
        for(int i = 0 ; i < n ; i++){
            dp0[i][i] = dp1[i][i] =1;
        }
        int ans = 2 ;
        for(int len = 2 ; len <=n; len++){
            for( int l = 0 ; l+len-1<n; l++){
                 int r = l+len-1;
                if(s[l] ==s[r]){
                    dp0[l][r] = (len==2)?1: dp0[l+1][r-1];
                    dp1[l][r] = (len==2)?1: dp1[l+1][r-1];
                }
                else{
                    dp0[l][r] =0 ;
                    dp1[l][r] = dp0[l+1][r]||dp0[l][r-1];
                }
                if(dp1[l][r]) ans = max (ans , len);
            }
        }
        return ans;
    }
};