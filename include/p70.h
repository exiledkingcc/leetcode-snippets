#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }
        int a = 2, b = 3;
        int k = 4;
        while (k <= n) {
            auto c = a + b;
            a = b;
            b = c;
            ++k;
        }
        return b;
    }
};

static void test() {
    Solution sol;
    vector<int> xx = {
        1, 2, 3, 4, 9, 10
    };
    for (auto x : xx) {
        auto y = sol.climbStairs(x);
        cout << x << " => " << y << "\n";
    }
}