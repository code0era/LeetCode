// Last updated: 3/1/2026, 9:33:53 AM
class Solution {
public:
    string trimTrailingVowels(string s) {
        string vowels = "aeiou";
        int i = s.length()-1;
        while( i >= 0 && vowels.find(s[i]) != string :: npos) {
            i--;
        }
        return s.substr(0 , i+1);
    }
};