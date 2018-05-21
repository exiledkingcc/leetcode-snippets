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
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return {{"Q"}};
        } else if (n < 4) {
            return {};
        }
        vector<vector<string>> vv;
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
                    vv.push_back(std::move(make_layout(qq)));
                    k -= 2;
                } else {
                    qq[k] = -1;
                }
            }
        }
        return vv;
    }
private:
    vector<string> make_layout(const vector<int>& qq) {
        int n = qq.size();
        string s(n, '.');
        vector<string> v(n, s);
        for (int i = 0; i < n; ++i) {
            v[i][qq[i]] = 'Q';
        }
        return v;
    }
};

static void test() {
    Solution sol;
    vector<int> xx = {
        4, 5, 6, 7, 8
    };
    for (auto x : xx) {
        auto y = sol.solveNQueens(x);
        cout << x << " : " << y.size() << "\n";
        for (auto a: y) {
            for (auto b : a) {
                cout << b << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}