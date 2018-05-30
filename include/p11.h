#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "common.h"

using std::cout;
using std::string;
using std::vector;
using std::multimap;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        auto vv(height);
        int n = height.size();
        multimap<int, int> mm;
        for (int i = 0; i < n; ++i) {
            mm.insert(std::make_pair(height[i], i));
        }
        int first = 0;
        int last = n - 1;
        int mk = 0;
        for (const auto& m: mm) {
            auto h = m.first;
            auto i = m.second;
            auto x = std::max(i - first, last - i) * h;
            if (x > mk) {
                mk = x;
            }
            if (i == first) {
                ++first;
                while (vv[first] == 0) {
                    ++first;
                }
            } else if (i == last) {
                --last;
                while (vv[last] == 0) {
                    --last;
                }
            } else {
                vv[i] = 0;
            }
        }
        return mk;
    }
};

static void test() {
    Solution sol;
    vector<vector<int>> xx = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 2, 4, 4, 3},
        {3, 1, 4, 4, 3},
        {1, 3, 2, 5, 25, 24, 5},
    };
    for (auto x : xx) {
        auto y = sol.maxArea(x);
        cout << x << " => " << y << "\n";
    }
}