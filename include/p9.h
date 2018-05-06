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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }
        int d[11];
        int i = 0;
        int64_t xx = x;
        while (xx != 0) {
            d[i] = xx % 10;
            xx /= 10;
            ++i;
        }
        --i;
        bool pal = true;
        for (int j = 0; j < i; ++j,--i) {
            if (d[j] != d[i]) {
                pal = false;
                break;
            }
        }
        return pal;
    }
};

static void test() {
    Solution sol;
    vector<int> xx = {5, 33, 121, 34566543, 76667, 1000000001, -11, 0};
    for (auto x : xx) {
        auto y = sol.isPalindrome(x);
        cout << x << " " << y << "\n";
    }
}