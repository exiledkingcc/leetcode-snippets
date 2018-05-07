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
    string longestCommonPrefix(const vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        } else if (n == 1) {
            return strs[0];
        }
        int m = strs[0].size();
        for (int j = 1; j < n; ++j) {
            int x = strs[j].size();
            if (m < x) {
                m = x;
            }
        }
        if (m == 0) {
            return "";
        }

        string s;
        int i = 0;
        while (i < m) {
            auto c = strs[0][i];
            bool diff = false;
            for (int j = 1; j < n; ++j) {
                if (strs[j][i] != c) {
                    diff = true;
                    break;
                }
            }
            if (diff) {
                break;
            } else {
                s += c;
                ++i;
            }
        }
        return s;
    }
};

static void test() {
    Solution sol;
    vector<vector<string>> xx = {
        {"flower","flow","flight"},
        {"dog","racecar","car"},
        {"dog","do","done"},
        {"aa","","ab"},
    };
    for (auto x : xx) {
        auto y = sol.longestCommonPrefix(x);
        cout << y << "\n";
    }
}