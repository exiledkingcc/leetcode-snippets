#include "common.h"
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
using std::to_string;

class Solution {
  public:
    Solution() {
        mm[1] = "1";
        mm[2] = "11";
        mm[3] = "21";
        mm[4] = "1211";
        mm[5] = "111221";
    }

    string countAndSay(int n) {
        int m = mm.size();
        if (m < n) {
            auto x = mm.rbegin()->first + 1;
            auto s = mm[x - 1];
            while (x <= n) {
                s = _countAndSay(s);
                mm[x] = s;
                ++x;
            }
        }
        return mm[n];
    }

  private:
    string _countAndSay(string ss) {
        string s;
        int n = ss.size();
        int i = 1, k = 1;
        char c = ss[0];
        while (i < n) {
            auto x = ss[i];
            if (x == c) {
                ++k;
            } else {
                s += to_string(k);
                s += c;
                c = x;
                k = 1;
            }
            ++i;
        }
        s += to_string(k);
        s += c;
        return s;
    }

    map<int, string> mm;

};

static void test() {
    Solution sol;
    for (int i = 1; i < 10; ++i) {
        auto y = sol.countAndSay(i);
        cout << i << " => " << y << "\n";
    }
}