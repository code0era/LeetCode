// Last updated: 2/17/2026, 11:21:02 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> freq;
        freq[0] = 1;
        long long sum = 0;
        int ans = 0;

        for (int x : nums) {
            sum += x;
            auto it = freq.find(sum - k);
            if (it != freq.end()) ans += it->second;
            freq[sum]++;
        }
        return ans;
    }
};