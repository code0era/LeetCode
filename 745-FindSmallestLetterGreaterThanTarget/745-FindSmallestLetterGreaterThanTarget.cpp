// Last updated: 2/6/2026, 5:19:07 PM
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        
        // If target is greater than or equal to the last element,
        // we must wrap around to the first element.
        if (target >= letters.back()) {
            return letters[0];
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If mid is greater than target, it's a candidate, but we try to find a smaller one to the left
            if (letters[mid] > target) {
                right = mid - 1;
            } else {
                // If mid is <= target, we need to look to the right
                left = mid + 1;
            }
        }
        
        // 'left' will point to the smallest element greater than target
        return letters[left];
    }
};