// Last updated: 5/24/2026, 9:59:05 AM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> freq(n + 1, 0); 
        int common_count = 0;
        
        for (int i = 0; i < n; ++i) {
            // Increment frequency for the current element in A
            if (++freq[A[i]] == 2) {
                common_count++;
            }
            // Increment frequency for the current element in B
            if (++freq[B[i]] == 2) {
                common_count++;
            }
            // Store the running count of common elements
            C[i] = common_count;
        }
        
        return C;
    }
};