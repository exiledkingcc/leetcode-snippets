#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "common.h"

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::pair;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int p = 0, q = n;
        while (p < q) {
            int c = (p + q) / 2;
            int x = nums[c];
            if (target == x) {
                return c;
            } else if (target < x) {
                q = c;
            } else {
                p = c + 1;
            }
        }
        return p;
    }
};

static void test() {
    Solution sol;
    vector<pair<vector<int>, int>> xx = {
        { {}, 0},
        { {1, 2, 3}, 0},
        { {1, 2, 3}, 4},
        { {1, 2, 3}, 2},
        { {1, 3, 5, 6}, 5},
        { {1, 3, 5, 6}, 2},
        { {1, 3, 5, 6}, 7},
        { {1, 3, 5, 6}, 0},
    };
    for (auto x : xx) {
        auto y = sol.searchInsert(x.first, x.second);
        cout << x.first << ", " << x.second << " => " << y << "\n";
    }
}