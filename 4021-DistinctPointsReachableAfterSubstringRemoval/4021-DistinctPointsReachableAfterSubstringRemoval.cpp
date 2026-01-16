// Last updated: 1/16/2026, 8:19:57 PM
class Solution {
public:
    pair <int , int> get_d( char c ){
            if( c == 'U' ) return {0,1};
            if( c == 'D' ) return {0,-1};
            if( c == 'L' ) return {-1,0};
            return {1, 0};
        }
    int distinctPoints(string s, int k) {
        int n = s.length();
        if( k == n ) return 1;
        vector <pair < int , int > > p ( n+1);
        p[0] = { 0, 0 };
        for ( int i = 0 ; i< n ; i++){
            pair < int , int > d = get_d ( s[i]);
            p[i+1].first = p[i] .first + d.first ;
            p[i+1].second = p[i] .second + d.second ;
        } 
        set<pair<int , int >> ans;
        int tdx  = p[ n].first;
        int tdy  = p[ n].second;
        for(int i = 0 ;i <= n -k ; i++){
            int rdx = p[i+k].first - p[i].first;
            int rdy = p[i+k].second - p[i].second;

            int fdx = tdx - rdx;
            int fdy = tdy - rdy;
            ans.insert({fdx, fdy});
        
        }
        return ans.size();
        
    }
};