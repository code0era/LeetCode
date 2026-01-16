// Last updated: 1/16/2026, 8:21:58 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto it: intervals){
            if(ans.empty() || it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            else{
                ans.back()[1] = max(it[1], ans.back()[1]);
            }
        }
        return ans;
    }
}; 