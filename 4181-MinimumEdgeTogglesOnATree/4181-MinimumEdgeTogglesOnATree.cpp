// Last updated: 1/18/2026, 2:20:32 PM
class Solution {
public:

    vector<int> r , d ;
    vector<vector<pair<int,int>>> g;
    void f(int u , int p){
        for(auto& [v,i]:g[u])
            if(v!=p){
                f(v,u);
                if(d[v]) r.push_back(i), d[u]^=1;
            }
    }
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        g.resize(n);
        d.resize(n);
        for(int i = 0; i< n ; ++i )d[i] = start[i]!= target[i];
        for(int i = 0 ; i < n-1; ++i){
            g[edges[i][0]].push_back({edges[i][1],i});
            g[edges[i][1]].push_back({edges[i][0],i});
        }
        f(0,-1);
        if(d[0]) return {-1};
         sort(r.begin() , r.end());
        return r;
    }
};