// Last updated: 5/23/2026, 10:04:44 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int  ans = 0 , j = nums.size()-1;
        for( int i =0 ; i < j ; i++){
            if(nums[i] ==0){
                while(i<j && nums[j] == 0) j--;
                if (i<j) ans++ , j--;
            }
        }
        return ans;
    }
};