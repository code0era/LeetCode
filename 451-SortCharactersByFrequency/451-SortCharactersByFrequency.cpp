// Last updated: 1/21/2026, 3:21:00 PM
class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    priority_queue<pair<int, char>> pq;
    for (auto& it : freq)
        pq.push({it.second, it.first});

    string result;
    while (!pq.empty()) {
        auto [f, c] = pq.top();
        pq.pop();
        result.append(f, c);
    }
    return result;
}

};