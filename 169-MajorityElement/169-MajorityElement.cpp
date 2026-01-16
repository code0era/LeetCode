// Last updated: 1/16/2026, 8:21:20 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0 ; 
        int el=0;
        for(auto it : nums){
            if(c==0){
                el = it;
                c++;
            }
            else if(it == el){
                c++;
            }
            else {
                c--;
            }
        }
        return el;
    }
};