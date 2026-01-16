// Last updated: 1/16/2026, 8:20:32 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // lastPos stores the index of the most recent '1' found
        int lastPos = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                // If we've seen a '1' before, check the distance
                if (lastPos != -1) {
                    if (i - lastPos - 1 < k) {
                        return false;
                    }
                }
                // Update the position of the latest '1'
                lastPos = i;
            }
        }
        
        return true;
    }
};