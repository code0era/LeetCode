// Last updated: 1/16/2026, 8:21:05 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> res;

        // Step 2: Traverse both arrays with two pointers
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                // Only add if not already added to avoid duplicates
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }

        return res;
    }
};

/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> map;
        vector<int> result;

        for(int nums : nums1){
            map[nums] = true;
        }
        for(int nums : nums2){
            if(map[nums]){
                result.push_back(nums);
                map[nums] = false;
            }
        }
    return result;
    }
};
*/