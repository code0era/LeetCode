// Last updated: 5/24/2026, 9:56:22 AM
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st(password.begin(), password.end());
        int ans = 0 ;

        for( char c : st){
            if(islower(c)) ans+=1;
            else if (isupper(c)) ans+=2;
            else if (isdigit(c)) ans+=3;
            else ans +=5;
        }
        return ans;
    }
};