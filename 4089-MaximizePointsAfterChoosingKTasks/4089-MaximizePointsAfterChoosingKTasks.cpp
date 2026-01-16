// Last updated: 1/16/2026, 8:19:51 PM
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<long long > gain(n);
        long long total = 0 ;
        for( int i = 0 ; i < n ; i++){
            total +=technique2[i];
            gain[i] = (long long ) technique1[i] - technique2[i];
        }
        sort (gain.begin() , gain.end(), greater<long long>());
        for(int i = 0 ; i <n ; i++){
            if(i < k ) total+=gain[i];
            else if (gain[i]>0) total+=gain[i];
        }
        return total;
    }
};