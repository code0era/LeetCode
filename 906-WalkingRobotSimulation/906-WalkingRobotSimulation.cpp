// Last updated: 4/6/2026, 7:49:08 AM
class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<long long> obs;

        // Encode obstacles
        for (auto &o : obstacles) {
            long long key = (long long)o[0] * 1000000 + o[1];
            obs.insert(key);
        }
        int dir =0;
        int x=0,y=0;
        int sqDis=0;
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};

        for(int cmd: commands){
            if(cmd == -1){// right turn 
                dir = (dir+1) % 4;
            }
            else if( cmd == -2){
                dir = (dir+3)% 4;
            }
            else{
                for( int i = 0 ; i < cmd; i++){
                    int nx = x+ dx[dir];
                    int ny = y+ dy[dir];
                    
                    long long key = (long long)nx * 1000000 + ny;

                    if (obs.count(key)) break;
                    x= nx;
                    y= ny;
                    sqDis = max(sqDis, x*x+ y*y);
                }
            }
        }
        return sqDis;

    }
};