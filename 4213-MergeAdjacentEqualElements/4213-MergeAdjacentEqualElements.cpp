// Last updated: 2/11/2026, 12:52:49 AM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector <long long > st;
        for(long long x: nums){
            st.push_back(x);
            while(st.size()>=2){
                int n = st.size();
                if(st[n-1] == st[n-2]){
                    long long v = st[n-1]+ st[n-2];
                    st.pop_back();
                    st.pop_back();
                    st.push_back(v);
                }
                else break;
            }
        }
        return st;
    }
};