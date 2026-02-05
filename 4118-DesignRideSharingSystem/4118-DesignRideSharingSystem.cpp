// Last updated: 2/5/2026, 9:02:10 PM
class RideSharingSystem {

    queue<int> drivers;
    queue<pair<int, int>> riders;
    unordered_map<int ,int> active;
    int seq = 0 ;
    
public:
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        riders.push({riderId , ++seq});
        active[riderId] = seq;
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty()){
            if(active.count(riders.front().first)&& active[riders.front().first]== riders.front().second) break;
            riders.pop();
        }
        if(riders.empty() || drivers.empty())return {-1, -1};
        int r = riders.front().first;
        riders.pop();
        int d = drivers.front();
        drivers.pop();
        active.erase(r);
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        if(active.count(riderId)){
            active.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */