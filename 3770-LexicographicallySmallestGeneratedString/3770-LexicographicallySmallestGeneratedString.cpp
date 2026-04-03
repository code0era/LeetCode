// Last updated: 4/3/2026, 7:58:55 AM
class Solution{
public:
    string generateString(string str1,string str2){
        int n=str1.length(),m=str2.length();
        int sz=n+m-1;
        string ans(sz,'\0');
        vector<bool> modifiable(sz,true);

        // Handle 'T'
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    int pos=i+j;
                    if(ans[pos] && ans[pos]!=str2[j]) return "";
                    ans[pos]=str2[j];
                    modifiable[pos]=false;
                }
            }
        }

        // Fill remaining
        for(int i=0;i<sz;i++){
            if(ans[i]=='\0') ans[i]='a';
        }

        // Handle 'F'
        for(int i=0;i<n;i++){
            if(str1[i]=='F' && match(ans,i,str2)){
                int pos=lastModifiablePosition(i,m,modifiable);
                if(pos==-1) return "";
                ans[pos]='b';
                modifiable[pos]=false;
            }
        }

        return ans;
    }

private:
    bool match(string& ans,int i,string& s){
        for(int j=0;j<s.length();j++){
            if(ans[i+j]!=s[j]) return false;
        }
        return true;
    }

    int lastModifiablePosition(int i,int m,vector<bool>& modifiable){
        int pos=-1;
        for(int j=0;j<m;j++){
            if(modifiable[i+j]) pos=i+j;
        }
        return pos;
    }
};