// Last updated: 1/21/2026, 3:20:23 PM
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int target : nums) {
            bool found = false;
            // Brute force check from 0 up to the target
            for (int x = 0; x < target; ++x) {
                if ((x | (x + 1)) == target) {
                    ans.push_back(x);
                    found = true;
                    break; // Found the minimum, so stop
                }
            }
            if (!found) ans.push_back(-1);
        }
        
        return ans;
    }
};