// Last updated: 1/17/2026, 6:54:12 PM
class Solution {
public:
    string largestOddNumber(string nums) {
         for( int i = nums.size()-1; i >=0; i--){
             int d =  nums[i] - '0';
             if(d%2==1) {
                return nums.substr(0, i+1);
             }

         }
         return "";
    }
};