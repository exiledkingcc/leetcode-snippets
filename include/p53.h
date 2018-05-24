#include "common.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::pair;
using std::to_string;

class Solution {
  public:
    int maxSubArray(const vector<int> &nums) {
        int n = nums.size();
        int m = INT32_MIN, t = 0;
        for (int i = 0; i < n; ++i) {
            t += nums[i];
            if (t > m) {
                m = t;
            }
            if (t < 0) {
                t = 0;
            }
        }
        return m;
    }
};

static void test() {
    Solution sol;
    vector<vector<int>> xx = {
        {1, 1, 1},
        {1, 0, 1},
        {1, -1, 1},
        {-1, -1, -1},
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},
    };
    for (auto x: xx) {
        auto y = sol.maxSubArray(x);
        cout << x << " => " << y << "\n";
    }
}