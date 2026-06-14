// Last updated: 6/14/2026, 9:37:46 AM
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) count[word]++;
        vector<string> res;
        for (auto const& [w, n] : count)
            if (n == 1) res.push_back(w);
        return res;
    }
};