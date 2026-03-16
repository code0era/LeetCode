// Last updated: 3/16/2026, 11:10:39 PM
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size();
        unordered_map<int , int> tc , count1 ;
        for(int i = 0; i < n ; i++){
            tc[nums1[i]]++;
            tc[nums2[i]]++;
            count1[nums1[i]]++; 
        }
        long long tsn = 0 ;
        for(auto const& [val, total]:tc){
            if(total%2 != 0) return -1;
            int target = total/2;
            if(count1[val] > target){
                tsn +=(count1[val] - target);
            }
        }
        return (int )tsn;
    }
};