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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int p = 0;
        int i = 1;
        while(i < n) {
            if (nums[i] != nums[p]) {
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
    vector<vector<int>> xx = {
        {1, 2, 3, 4, 5},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 2, 2},
        {1, 1, 2, 3, 3, 3, 4},
    };
    for (auto x : xx) {
        auto y = sol.removeDuplicates(x);
        cout << x.size() << " " << y << "\n";
    }
}