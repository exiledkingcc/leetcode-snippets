#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::pair;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i <= m - n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return i;
            }
        }
        return -1;
    }
};

static void test() {
    Solution sol;
    vector<pair<string, string>> xx = {
        {"", ""},
        {"a", ""},
        {"", "a"},
        {"sssd", "ssd"},
        {"aaaaa", "bba"},
    };
    for (auto x : xx) {
        auto y = sol.strStr(x.first, x.second);
        cout << x.first << " " << x.second << " " << y << "\n";
    }
}