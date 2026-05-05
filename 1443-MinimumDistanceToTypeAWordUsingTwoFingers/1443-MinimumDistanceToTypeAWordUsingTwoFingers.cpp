// Last updated: 5/5/2026, 9:14:03 PM
class Solution{
public:
    int minimumDistance(string word){
        int n=word.size();
        const int INF=1<<30;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(26,vector<int>(26,INF)));
        
        for(int j=0;j<26;++j){
            dp[0][word[0]-'A'][j]=0;
            dp[0][j][word[0]-'A']=0;
        }
        
        for(int i=1;i<n;++i){
            int prev=word[i-1]-'A';
            int curr=word[i]-'A';
            int d=dist(prev,curr);
            
            for(int j=0;j<26;++j){
                dp[i][curr][j]=min(dp[i][curr][j],dp[i-1][prev][j]+d);
                dp[i][j][curr]=min(dp[i][j][curr],dp[i-1][j][prev]+d);
                
                if(j==prev){
                    for(int k=0;k<26;++k){
                        int d2=dist(k,curr);
                        dp[i][curr][j]=min(dp[i][curr][j],dp[i-1][k][prev]+d2);
                        dp[i][j][curr]=min(dp[i][j][curr],dp[i-1][prev][k]+d2);
                    }
                }
            }
        }
        
        int ans=INF;
        int last=word[n-1]-'A';
        
        for(int j=0;j<26;++j){
            ans=min(ans,dp[n-1][last][j]);
            ans=min(ans,dp[n-1][j][last]);
        }
        
        return ans;
    }
    
    int dist(int a,int b){
        return abs(a/6-b/6)+abs(a%6-b%6);
    }
};