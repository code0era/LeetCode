// Last updated: 2/15/2026, 9:23:06 AM
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        result.reserve(max(a.length(), b.length()) + 1);
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};