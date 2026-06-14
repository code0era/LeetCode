// Last updated: 6/14/2026, 9:34:17 AM
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (const string& word : words) {
            int total_weight = 0;
            for (char ch : word) {
                total_weight += weights[ch - 'a'];
            }
            // Map 0 -> 'z', 1 -> 'y', ... 25 -> 'a'
            result += ('z' - (total_weight % 26));
        }
        return result;
    }
};
