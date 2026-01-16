// Last updated: 1/16/2026, 8:19:50 PM
class Solution {
public:
    string toB(int n ){
        string s = "";
        while(n>0){
            s+=char('0' + (n&1));
            n>>=1;
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
    bool  isPal(int n ){
        string s = toB(n);
        int  i = 0 , j = s.size()-1;
        while(i<j){
            if(s[i] !=s[j]) return false;
            i++;
            j--;
            
        }
        return true;
        
    }
    vector<int> minOperations(vector<int>& nums) {
        vector  <int > ans;
        for( int x: nums){
            int ops = 0 ;
            int lf = x , rg = x;
            while(true){
                if(isPal(lf)){
                    ops =abs(x-lf);
                    break;
                }
                if(isPal(rg)){
                    ops =abs(x-rg);
                    break;
                }
                lf--;
                rg++;
            }
            ans.push_back(ops);
        }
        return ans;
    }
};