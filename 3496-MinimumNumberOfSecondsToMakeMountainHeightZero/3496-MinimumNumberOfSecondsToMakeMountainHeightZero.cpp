// Last updated: 3/14/2026, 9:04:36 PM
class Solution {
public:

    long long units(long long T, long long t){
        long long l=0, r=1e6, ans=0;

        while(l<=r){
            long long mid=(l+r)/2;

            long long cost = t * mid * (mid+1) / 2;

            if(cost <= T){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }

    bool can(long long T, int mountainHeight, vector<int>& workerTimes){

        long long total=0;

        for(auto t: workerTimes){
            total += units(T, t);

            if(total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long l=1, r=1e18;
        long long ans=r;

        while(l<=r){

            long long mid=(l+r)/2;

            if(can(mid, mountainHeight, workerTimes)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};