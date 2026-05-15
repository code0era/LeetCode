// Last updated: 5/15/2026, 8:34:43 PM
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> result;
        for (int num : nums) {
            std::string s = std::to_string(num);
            for (char c : s) {
                result.push_back(c - '0'); // Convert char '1' to int 1
            }
        }
        return result;
    }
};