// Last updated: 6/14/2026, 9:34:39 AM
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    // memoCount[idx][tight][isZero][prev + 1][trend]
    // trend: 0 = neutral, 1 = up (increasing), 2 = down (decreasing)
    long long memoCount[20][2][2][12][3];
    long long memoWave[20][2][2][12][3];

    // Helper struct to return pair data cleanly
    struct DPResult {
        long long count;
        long long waviness;
    };

    DPResult dfs(int idx, int tight, int isZero, int prev, int trend, const string& s) {
        // Base case: successfully formed a valid number
        if (idx == s.length()) {
            return {1, 0};
        }

        int prevIdx = prev + 1; // offset -1 to 0 for array mapping
        if (memoCount[idx][tight][isZero][prevIdx][trend] != -1) {
            return {
                memoCount[idx][tight][isZero][prevIdx][trend],
                memoWave[idx][tight][isZero][prevIdx][trend]
            };
        }

        int limit = tight ? (s[idx] - '0') : 9;
        long long totalCount = 0;
        long long totalWave = 0;

        for (int d = 0; d <= limit; d++) {
            int nextTight = (tight && (d == limit)) ? 1 : 0;
            int nextIsZero = (isZero && (d == 0)) ? 1 : 0;
            
            int nextTrend = 0;
            int waveAdded = 0;

            if (!nextIsZero) { 
                if (isZero) {
                    // Placing the first non-zero digit of the number
                    nextTrend = 0; 
                } else {
                    if (d > prev) {
                        nextTrend = 1; // Transition goes Up
                        if (trend == 2) waveAdded = 1; // 'prev' is a local Valley!
                    } else if (d < prev) {
                        nextTrend = 2; // Transition goes Down
                        if (trend == 1) waveAdded = 1; // 'prev' is a local Peak!
                    } else {
                        nextTrend = 0; // Flat line resets trend
                    }
                }
            }

            // Recursive step
            DPResult nextRes = dfs(idx + 1, nextTight, nextIsZero, (nextIsZero ? -1 : d), nextTrend, s);
            
            totalCount += nextRes.count;
            // Total waviness = deeper waviness sum + (local waves * number of combinations that use it)
            totalWave += nextRes.waviness + (waveAdded * nextRes.count);
        }

        memoCount[idx][tight][isZero][prevIdx][trend] = totalCount;
        memoWave[idx][tight][isZero][prevIdx][trend] = totalWave;

        return {totalCount, totalWave};
    }

    long long getWavinessSum(long long num) {
        if (num < 100) return 0; // Numbers under 3 digits have 0 waviness
        
        string s = to_string(num);
        memset(memoCount, -1, sizeof(memoCount));
        memset(memoWave, -1, sizeof(memoWave));

        // Start from index 0, tight=true, isZero=true, prev=-1, trend=0
        DPResult res = dfs(0, 1, 1, -1, 0, s);
        return res.waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return getWavinessSum(num2) - getWavinessSum(num1 - 1);
    }
};
