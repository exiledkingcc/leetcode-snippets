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
    int lengthOfLongestSubstring(const string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        map<char, int> m;
        int a = 0;
        int k = 0;
        for (int i = 0; i < len; ++i) {
            auto c = s[i];
            auto p = m.find(c);
            if (p != m.end()) {
                auto j = p->second;
                if (j >= a) {
                    auto x = i - a;
                    if (k < x) {
                        k = x;
                    }
                    a = j + 1;
                }
            }
            m[c] = i;
        }
        if (k < len - a) {
            k = len - a;
        }
        return k;
    }
};

static void test() {
    Solution sol;
    vector<string> ss = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
    };
    for (auto s : ss) {
        auto x = sol.lengthOfLongestSubstring(s);
        cout << s << " " << x << "\n";
    }
}