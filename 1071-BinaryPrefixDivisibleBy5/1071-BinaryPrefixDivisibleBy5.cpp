// Last updated: 1/16/2026, 8:20:43 PM
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> answer(n);
        
        int currentRemainder = 0;

        for (int i = 0; i < n; ++i) {
            
            currentRemainder = currentRemainder * 2;
            currentRemainder = currentRemainder + nums[i];
            currentRemainder = currentRemainder % 5;
            
            if (currentRemainder == 0) {
                answer[i] = true;
            } else {
                answer[i] = false;
            }
        }
        
        return answer;
    }
};