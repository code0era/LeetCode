// Last updated: 6/14/2026, 9:33:53 AM
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>res;
        auto  dfs =[&](auto self, string s  ,int cost , bool lastone )-> void{
            if (s.size() == n ){
                if(cost <=k) res.push_back(s);
                return;
            }
            self(self , s+ '0' , cost , false);
            if(!lastone && cost + s.size()<=k){
                self(self, s+'1', cost + s.size(),true);
                
            }
        };
        dfs(dfs ,"", 0 , false);
        return res;
    }
};