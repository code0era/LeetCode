// Last updated: 6/14/2026, 9:36:04 AM
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // Vector-based Trie structure for memory efficiency and speed
    struct TrieNode {
        int children[26];
        int bestIndex;
        TrieNode(int idx) : bestIndex(idx) {
            fill(begin(children), end(children), -1);
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Step 1: Find the global best index for an empty suffix match
        int bestGlobalIndex = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[bestGlobalIndex].length()) {
                bestGlobalIndex = i;
            }
        }

        // Step 2: Initialize the Trie
        vector<TrieNode> trie;
        trie.emplace_back(bestGlobalIndex); // Root node at index 0

        // Step 3: Insert reversed container words into the Trie
        for (int i = 0; i < wordsContainer.size(); ++i) {
            int curr = 0;
            const string& w = wordsContainer[i];
            
            // Traverse the string backwards
            for (int j = w.length() - 1; j >= 0; --j) {
                int charIdx = w[j] - 'a';
                
                // Create a new node if path doesn't exist
                if (trie[curr].children[charIdx] == -1) {
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back(i);
                }
                
                curr = trie[curr].children[charIdx];
                
                // Update the best index at the current node
                int currBest = trie[curr].bestIndex;
                if (w.length() < wordsContainer[currBest].length() || 
                   (w.length() == wordsContainer[currBest].length() && i < currBest)) {
                    trie[curr].bestIndex = i;
                }
            }
        }

        // Step 4: Process the queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            
            // Traverse the query string backwards
            for (int j = q.length() - 1; j >= 0; --j) {
                int charIdx = q[j] - 'a';
                
                // Stop if the character path doesn't exist in the Trie
                if (trie[curr].children[charIdx] == -1) {
                    break;
                }
                curr = trie[curr].children[charIdx];
            }
            // The answer is pre-computed at the node where we stopped
            ans.push_back(trie[curr].bestIndex);
        }

        return ans;
    }
};