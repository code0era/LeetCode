// Last updated: 3/14/2026, 9:06:00 PM
class Solution {
    


public:
    int fun(int n)
    {
        int res =  0 ;
        while(n){
            int d = n%2;
            if(d)res++;

            n/=2;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i =  0 ; i <= n; i++ ){
            int bit = fun(i);
            ans.push_back(bit);
        }
        return ans;
    }
};