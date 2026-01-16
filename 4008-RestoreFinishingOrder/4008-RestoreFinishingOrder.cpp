// Last updated: 1/16/2026, 8:19:59 PM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int>pos;
        for (int i = 0 ; i < order.size(); i++){
            pos[order[i]] = i;
        }
        sort(friends.begin(), friends.end(), [&](int a , int b){
            return pos[a]<pos[b];
        });
        return friends;
    }
};