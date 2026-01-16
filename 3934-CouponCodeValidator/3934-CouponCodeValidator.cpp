// Last updated: 1/16/2026, 8:20:01 PM
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        // Order priority for business lines
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, int> priority;
        for (int i = 0; i < order.size(); i++) {
            priority[order[i]] = i;
        }

        // Store valid coupons as {priority, code}
        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < code.size(); i++) {

            // Condition 1: isActive must be true
            if (!isActive[i]) continue;

            // Condition 2: valid business line
            if (priority.find(businessLine[i]) == priority.end()) continue;

            // Condition 3: valid code (non-empty, alphanumeric or '_')
            if (code[i].empty()) continue;

            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;

            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by businessLine priority, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        // Extract only the codes
        vector<string> result;
        for (auto& p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};
