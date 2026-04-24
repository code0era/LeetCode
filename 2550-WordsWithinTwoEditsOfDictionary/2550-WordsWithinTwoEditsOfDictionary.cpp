// Last updated: 4/25/2026, 12:59:08 AM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for(const string& q : queries) {
            for(const string& d : dictionary) {
                int diff = 0;
                // Since all words are the same length, we compare index by index
                for(int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        diff++;
                    }
                    // Optimization: if diff exceeds 2, this dictionary word fails
                    if (diff > 2) break;
                }
                
                if(diff <= 2) {
                    result.push_back(q);
                    break; // Move to the next query word
                }
            }
        }
        
        return result;
    }
};