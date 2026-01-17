// Last updated: 1/17/2026, 6:54:34 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()) return false;
         string d = s+s;
          return d.find(goal)!= string::npos;;

    }
};