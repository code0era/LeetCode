// Last updated: 4/25/2026, 12:59:13 AM
class Robot {
    int w, h;
    int x, y;
    int dir; 
    bool moved;
    string d_str[4] = {"East", "North", "West", "South"};
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        moved = false;
    }
    void step(int num) {
        moved = true;
        int loop = 2 * (w - 1) + 2 * (h - 1);
        num %= loop;
        if (num == 0) num = loop;
        while (num > 0) {
            if (dir == 0) { 
                int steps = min(num, w - 1 - x);
                x += steps;
                num -= steps;
                if (x == w - 1 && num > 0) dir = 1;
            } else if (dir == 1) { 
                int steps = min(num, h - 1 - y);
                y += steps;
                num -= steps;
                if (y == h - 1 && num > 0) dir = 2;
            } else if (dir == 2) { 
                int steps = min(num, x);
                x -= steps;
                num -= steps;
                if (x == 0 && num > 0) dir = 3;
            } else if (dir == 3) { 
                int steps = min(num, y);
                y -= steps;
                num -= steps;
                if (y == 0 && num > 0) dir = 0;
            }
        }
    }
    vector<int> getPos() {
        return {x, y};
    }
    string getDir() {
        if (!moved) return "East";
        return d_str[dir];
    }
};