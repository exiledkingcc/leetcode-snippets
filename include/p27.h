#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::pair;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int p = -1;
        int i = 0;
        while(i < n) {
            if (nums[i] != val) {
                ++p;
                if (p != i) {
                    nums[p] = nums[i];
                }
            }
            ++i;
        }
        ++p;
        nums.resize(p);
        return p;
    }
};

static void test() {
    Solution sol;
    vector<pair<vector<int>, int>> xx = {
        { {3, 2, 2, 3}, 3},
        { {1, 1, 1, 1, 1}, 1},
        { {0, 1, 2, 2, 3, 0, 4, 2}, 2},
        { {1, 1, 2, 3, 3, 3, 4}, 3},
    };
    for (auto x : xx) {
        auto v = x.first;
        auto y = sol.removeElement(v, x.second);
        cout << v.size() << " " << y << "\n";
    }
}