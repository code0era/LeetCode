// Last updated: 1/16/2026, 8:20:09 PM
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // 1. Custom Sorting
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) return timeA < timeB;
            // If timestamps equal, OFFLINE (Type 1) comes before MESSAGE (Type 2)
            // We can treat "OFFLINE" as priority 0 and "MESSAGE" as priority 1
            return a[0] == "OFFLINE" && b[0] == "MESSAGE";
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<int> onlineAt(numberOfUsers, 0); // Stores the time user becomes online

        for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);

            if (type == "OFFLINE") {
                int userId = stoi(event[2]);
                onlineAt[userId] = timestamp + 60;
            } 
            else { // MESSAGE Event
                string mentionsStr = event[2];
                if (mentionsStr == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) mentions[i]++;
                } 
                else if (mentionsStr == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (onlineAt[i] <= timestamp) mentions[i]++;
                    }
                } 
                else {
                    // Parse multiple IDs like "id0 id1 id2"
                    stringstream ss(mentionsStr);
                    string token;
                    while (ss >> token) {
                        // Extract number from "id<number>"
                        int userId = stoi(token.substr(2));
                        mentions[userId]++;
                    }
                }
            }
        }

        return mentions;
    }
};