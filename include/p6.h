#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;
using std::pair;

class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int n = s.size();
        int k = numRows + (numRows - 2);
        string ss;
        ss.reserve(n);
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            while (j < n) {
                ss.push_back(s[j]);
                if (i > 0 && i < numRows - 1) {
                    auto jj = j -  (j % k) + k - i;
                    if (jj < n) {
                        ss.push_back(s[jj]);
                    }
                }
                j += k;
            }
        }
        return ss;
    }
};

static void test() {
    Solution sol;
    vector<pair<string, int>> xx = {
        {"PAYPALISHIRING", 1},
        {"PAYPALISHIRING", 2},
        {"PAYPALISHIRING", 3},
        {"PAYPALISHIRING", 4},
    };
    for (auto x : xx) {
        auto y = sol.convert(x.first, x.second);
        cout << "\"" << x.first << "\"," << x.second << " => " << y << "\n";
    }
}