// Last updated: 3/10/2026, 10:23:49 PM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";

        for(int i = 0; i < n; i++){
            if(nums[i][i] == '0')
                ans.push_back('1');
            else
                ans.push_back('0');
        }

        return ans;
    }
};