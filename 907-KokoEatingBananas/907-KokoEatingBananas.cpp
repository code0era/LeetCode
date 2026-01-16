// Last updated: 1/16/2026, 8:20:50 PM
class Solution {
public:
    int findMax(vector<int>& piles){
        int m = INT_MIN;
        for(int i =  0; i < piles.size(); i++){
            m= max(m, piles[i]);
        }
        return m ;
    }
 long long findHours(vector<int>& piles, int r) {
        long long ans = 0;
        for (int x : piles) {
            ans += ((long long)x + r - 1) / r;  // safe ceil
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0 ;
        int l = 1 ;
        int hg = findMax(piles);
        while(l<=hg){
            int mid = l +(hg-l)/2;
            long long t = findHours(piles, mid);
            if(t<=h){
             hg = mid-1;
            }
            else{
                l=  mid+1;
            }
        } 
        return l ;
    }
}; 