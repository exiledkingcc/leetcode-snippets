#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "common.h"

using std::cout;
using std::string;
using std::vector;
using std::find;

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 1) {
            return 1;
        } else if (n < 4) {
            return 0;
        }
        int sum = 0;
        vector<int> qq(n, -1);
        qq[0] = 0;
        int k = 1;
        while (qq[0] < n) {
            if (k == 0) {
                ++qq[0];
                ++k;
                qq[k] = -1;
                continue;
            }
            int x = qq[k - 1];
            if (qq[k] == x) {
                --k;
                continue;
            }
            qq[k] = qq[k] == -1 ? (x + 1) % n : (qq[k] + 1) % n;
            bool ok = true;
            for (int j = 0; j < k; ++j) {
                int d = abs(qq[j] - qq[k]);
                if (d == 0 || d == k - j) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++k;
                if (k == n) {
                    sum += 1;
                    k -= 2;
                } else {
                    qq[k] = -1;
                }
            }
        }
        return sum;
    }
};

static void test() {
    Solution sol;
    vector<int> xx = {
        4, 5, 6, 7, 8, 9, 10
    };
    for (auto x : xx) {
        auto y = sol.totalNQueens(x);
        cout << x << " : " << y << "\n";
    }
}