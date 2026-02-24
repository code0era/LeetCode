// Last updated: 2/24/2026, 10:55:43 AM
class Solution {
public:
    string maximumXor(string s, string t) {
        int c1= 0 ;
        for(char ch : t)c1 +=(ch == '1');
        int c0 = (int)t.size() -c1;
        string ans ;
        ans.reserve(s.size());
         for(char ch :s){
             char want = (ch =='0')? '1': '0';
             char pick;
              if(want == '1'){
                  pick = (c1?(c1--,'1'): (c0--, '0'));
              }else{
                  pick = (c0?(c0-- , '0'): (c1-- , '1'));
              }
             ans.push_back((ch == pick)? '0' :'1');
         }
        return ans;
    }
    
};