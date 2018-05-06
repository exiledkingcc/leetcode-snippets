#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::map;
using std::string;
using std::vector;

class Solution {
  public:
    int reverse(int x) {
        int64_t xx = x;
        int64_t k = 0;
        while (xx != 0) {
            k *= 10;
            k += xx % 10;
            xx /= 10;
        }
        if (k > INT32_MAX || k < INT32_MIN) {
            return 0;
        }
        return k;
    }
};

static void test() {
    Solution sol;
    vector<int> xx = {121, 234, -567, -11, 1534236469};
    for (auto x : xx) {
        auto y = sol.reverse(x);
        cout << x << " " << y << "\n";
    }
}