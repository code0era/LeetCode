// Last updated: 3/29/2026, 4:08:15 PM
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Solution {
    typedef unsigned long long ull;
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> target = nums;
        sort(target.begin(), target.end());

        static ull val_hash[100005];
        static bool initialized = false;
        if(!initialized) {
            mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
            for(int i = 0; i < 100005; ++i) {
                val_hash[i] = rng();
            }
            initialized = true;
        }

        vector<ull> pref_nums(n + 1, 0);
        vector<ull> pref_target(n + 1, 0);
        vector<int> pref_drops(n + 1, 0);

        for(int i = 0; i < n; ++i) {
            pref_nums[i + 1] = pref_nums[i] + val_hash[nums[i]];
            pref_target[i + 1] = pref_target[i] + val_hash[target[i]];
            if(i < n - 1) {
                pref_drops[i + 1] = pref_drops[i] + (nums[i] > nums[i + 1] ? 1 : 0);
            }
        }

        long long total_k_sum = 0;

        for(int k = 1; k <= n; ++k) {
            if(n % k != 0) continue;

            bool possible = true;
            for(int start = 0; start < n; start += k) {
                int end = start + k - 1;

                if(pref_nums[end + 1] - pref_nums[start] != pref_target[end + 1] - pref_target[start]) {
                    possible = false;
                    break;
                }

                int block_internal_drops = pref_drops[end] - pref_drops[start];
                if(block_internal_drops > 1) {
                    possible = false;
                    break;
                }
                if(block_internal_drops == 1) {
                    if(nums[end] > nums[start]) {
                        possible = false;
                        break;
                    }
                }
            }
            if(possible) {
                total_k_sum += k;
            }
        }
        return (int)total_k_sum;
    }
};
