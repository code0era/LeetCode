// Last updated: 2/15/2026, 12:35:44 PM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int > freq(101,0);
        for(int x : bulbs) freq[x]++;
        vector<int > ans ;
        for(int i = 1 ; i <= 100; i++){
            if(freq[i]%2==1)
                ans.push_back(i);
        }
        return ans ;
    }
};