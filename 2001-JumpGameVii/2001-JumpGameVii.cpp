// Last updated: 6/14/2026, 9:37:03 AM
class Solution {
public:

    bool canReach(string s,
                  int minJump,
                  int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<int> vis(n, 0);
        vis[0] = 1;

        int farthest = 0;

        while(!q.empty()) {

            int i = q.front();
            q.pop();

            if(i == n-1)
                return true;

            int start =
                max(i + minJump,
                    farthest + 1);

            int end =
                min(n-1,
                    i + maxJump);

            for(int j = start;
                j <= end;
                j++) {

                if(s[j] == '0' &&
                   !vis[j]) {

                    vis[j] = 1;
                    q.push(j);
                }
            }

            farthest = end;
        }

        return false;
    }
};