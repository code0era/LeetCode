// Last updated: 1/16/2026, 8:20:06 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        double y;
        double x1, x2;
        int delta; // +1 add, -1 remove
        bool operator<(Event const& o) const {
            return y < o.y;
        }
    };

    vector<double> xs;
    vector<int> cnt;
    vector<double> covered; // covered length at node
    int Xn;

    void build(int node, int l, int r) {
        cnt[node] = 0;
        covered[node] = 0.0;
        if (l + 1 == r) return;
        int mid = (l + r) >> 1;
        build(node<<1, l, mid);
        build(node<<1|1, mid, r);
    }

    void pull(int node, int l, int r) {
        if (cnt[node] > 0) {
            // whole segment covered
            covered[node] = xs[r] - xs[l];
        } else {
            if (l + 1 == r) covered[node] = 0.0;
            else covered[node] = covered[node<<1] + covered[node<<1|1];
        }
    }

    void update(int node, int l, int r, int ql, int qr, int delta) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[node] += delta;
            pull(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(node<<1, l, mid, ql, qr, delta);
        update(node<<1|1, mid, r, ql, qr, delta);
        pull(node, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = (int)squares.size();
        if (n == 0) return 0.0;

        vector<Event> events;
        xs.clear(); xs.reserve(2*n);

        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(events.begin(), events.end());
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        Xn = (int)xs.size();

        // Segment tree arrays size (4 * Xn) is safe
        cnt.assign(4 * max(1, Xn), 0);
        covered.assign(4 * max(1, Xn), 0.0);
        build(1, 0, Xn - 1 + 1); // build covering [0, Xn-1+1) => intervals between xs[i]

        // Sweep events, compute covered length L_k for each y-interval
        // We'll store unique Y (event y's), L for each interval, dy for each interval.
        vector<double> Y; // unique y coordinates of events in order
        for (auto &e : events) {
            if (Y.empty() || fabs(e.y - Y.back()) > 1e-12) Y.push_back(e.y);
        }
        // We'll create mapping from event y to index in Y
        int m = (int)Y.size();
        // But easiest: process events in order and for each distinct y compute covered length for interval to next y.
        vector<double> L; L.reserve(max(0,m));
        vector<double> dy; dy.reserve(max(0,m));

        int i = 0;
        while (i < (int)events.size()) {
            double curY = events[i].y;
            // process all events at this y
            while (i < (int)events.size() && fabs(events[i].y - curY) < 1e-12) {
                // update x interval [x1, x2)
                int lidx = int(lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin());
                int ridx = int(lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin());
                if (lidx < ridx) update(1, 0, Xn-1+1, lidx, ridx, events[i].delta);
                ++i;
            }
            double nextY = (i < (int)events.size() ? events[i].y : curY);
            if (i < (int)events.size()) {
                double len = covered[1]; // covered length after processing events at curY
                double gap = nextY - curY;
                // store only if gap > 0
                L.push_back(len);
                dy.push_back(gap);
            }
        }

        // Compute total area and suffix areas f(Yk)
        int intervals = (int)L.size();
        double totalArea = 0.0;
        for (int k = 0; k < intervals; ++k) totalArea += L[k] * dy[k];

        double target = totalArea / 2.0;

        // Build suffix sums f_k = area from interval k to end.
        vector<double> suffix(intervals + 1, 0.0); // suffix[k] area starting at interval k (k=0 first interval)
        for (int k = intervals - 1; k >= 0; --k) suffix[k] = suffix[k+1] + L[k] * dy[k];

        // We need the list of Y event coordinates corresponding to each interval start.
        // Reconstruct Y_starts: we can re-scan events to produce ordered unique Ys that started intervals.
        vector<double> Ystart; Ystart.reserve(max(0,m));
        i = 0;
        while (i < (int)events.size()) {
            double curY = events[i].y;
            // process all events at this y (but we only need curY as start)
            while (i < (int)events.size() && fabs(events[i].y - curY) < 1e-12) ++i;
            if (i < (int)events.size()) Ystart.push_back(curY);
        }
        // Edge: if there were no intervals (e.g., empty), return something
        if (intervals == 0) {
            // No vertical span => totalArea == 0
            return 0.0;
        }

        // Now find interval k such that suffix[k] >= target > suffix[k+1]
        for (int k = 0; k < intervals; ++k) {
            double areaAtStart = suffix[k];
            double areaAfter = suffix[k+1];
            if (fabs(areaAtStart - target) < 1e-12) {
                // exact at start of interval -> answer is Ystart[k]
                return Ystart[k];
            }
            if (areaAtStart > target && areaAfter < target + 1e-12) {
                // target lies inside interval k, f(h) = areaAtStart - L[k] * (h - Ystart[k])
                double Lk = L[k];
                if (Lk <= 0) {
                    // covered length zero across this interval but areaAtStart != areaAfter -> numerical fragility
                    // If Lk == 0 and areaAtStart==areaAfter then area constant; if target equals that constant, choose start.
                    if (fabs(areaAtStart - target) < 1e-9) return Ystart[k];
                    continue;
                }
                double need = areaAtStart - target; // = Lk * (h - Yk)
                double h = Ystart[k] + need / Lk;
                return h;
            }
        }

        // If not found in loop due numerical tolerances, check edge cases
        // If target equal to 0, return highest top y
        if (fabs(target) < 1e-12) {
            // highest y among tops
            double maxTop = -1e300;
            for (auto &s : squares) maxTop = max(maxTop, (double)s[1] + s[2]);
            return maxTop;
        }

        // If target equals totalArea, return smallest y (lowest bottom)
        if (fabs(target - totalArea) < 1e-12) {
            double minBot = 1e300;
            for (auto &s : squares) minBot = min(minBot, (double)s[1]);
            return minBot;
        }

        // As fallback (shouldn't happen), binary search using computed L/dy segments:
        // find smallest y such that f(y) <= target
        double cur = Ystart.front();
        double fcur = suffix[0];
        for (int k = 0; k < intervals; ++k) {
            if (fcur - L[k] * dy[k] <= target + 1e-12) {
                // inside interval k
                double need = fcur - target;
                if (L[k] <= 0) return Ystart[k];
                return Ystart[k] + need / L[k];
            }
            fcur -= L[k] * dy[k];
        }
        // fallback return last start
        return Ystart.back();
    }
};
