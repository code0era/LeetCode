// Last updated: 6/14/2026, 9:36:25 AM
class Solution {
 public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    ranges::sort(asteroids);

    long m = mass;

    for (const int asteroid : asteroids)
      if (m >= asteroid)
        m += asteroid;
      else
        return false;

    return true;
  }
};