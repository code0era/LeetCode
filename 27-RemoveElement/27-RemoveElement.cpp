// Last updated: 1/16/2026, 8:22:11 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // The write pointer
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is NOT the value we want to remove
            if (nums[i] != val) {
                // Move it to the 'k-th' position
                nums[k] = nums[i];
                // Move the write pointer forward
                k++;
            }
        }
        
        // k is the count of elements not equal to val
        return k;
    }
};