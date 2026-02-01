// Last updated: 2/1/2026, 9:22:39 AM
1class RideSharingSystem {
2
3    queue<int> drivers;
4    queue<pair<int, int>> riders;
5    unordered_map<int ,int> active;
6    int seq = 0 ;
7    
8public:
9    RideSharingSystem() {}
10    
11    void addRider(int riderId) {
12        riders.push({riderId , ++seq});
13        active[riderId] = seq;
14    }
15    
16    void addDriver(int driverId) {
17        drivers.push(driverId);
18    }
19    
20    vector<int> matchDriverWithRider() {
21        while(!riders.empty()){
22            if(active.count(riders.front().first)&& active[riders.front().first]== riders.front().second) break;
23            riders.pop();
24        }
25        if(riders.empty() || drivers.empty())return {-1, -1};
26        int r = riders.front().first;
27        riders.pop();
28        int d = drivers.front();
29        drivers.pop();
30        active.erase(r);
31        return {d,r};
32    }
33    
34    void cancelRider(int riderId) {
35        if(active.count(riderId)){
36            active.erase(riderId);
37        }
38    }
39};
40
41/**
42 * Your RideSharingSystem object will be instantiated and called as such:
43 * RideSharingSystem* obj = new RideSharingSystem();
44 * obj->addRider(riderId);
45 * obj->addDriver(driverId);
46 * vector<int> param_3 = obj->matchDriverWithRider();
47 * obj->cancelRider(riderId);
48 */