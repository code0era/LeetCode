// Last updated: 6/14/2026, 9:38:10 AM
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0)
      return true;

    for (int i = 0; i < flowerbed.size(); ++i)
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
          (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        if (--n == 0)
          return true;
      }

    return false;
  }
};