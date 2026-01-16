// Last updated: 1/16/2026, 8:19:55 PM
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector < int> v ;
        long long  p = 1; 
        while(n>0){
            if(n%10!= 0) v.push_back((n%10)*p);
            n/=10;
            p*=10;
        }
        reverse(v.begin() , v.end());
        return  v ;
    }
};