// Last updated: 1/16/2026, 8:20:29 PM
class Solution {
public:
    bool isPos(vector<int>& bloomDay, int d, int m, int k) {

        int c = 0;
        int b = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= d) {
                c++;
            }
            else{
                b += c/k;
                c= 0 ;
            }
        }
        b += c/ k;
        return  b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val  = m *1LL* k *1LL;
        if(val > bloomDay.size())return -1;

        int mn = INT_MAX;
        int mx = INT_MIN;
    
        for(int i = 0 ; i <bloomDay.size() ; i ++){
            mn = min(mn, bloomDay[i]); 
            mx = max(mx, bloomDay[i]); 
        }

       int l = mn ; 
       int h = mx;
       while(l <= h){
        int  mid = l + (h-l)/2;
        if(isPos(bloomDay, mid , m , k )){
            h = mid-1;

        }
        else{
            l = mid+1;
        }
       }
       return l;
    }
};