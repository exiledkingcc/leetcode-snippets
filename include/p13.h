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
    int romanToInt(string s) {
        int k = 0;
        int x = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            auto c = s[i];
            auto y = mm.at(c);
            if (y < x) {
                k -= y;
            } else {
                k += y;
            }
            x = y;
        }
        return k;
    }

    static const map<char, int> mm;
};

const map<char, int> Solution::mm = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

static void test() {
    Solution sol;
    vector<string> xx = {
        "III", "IV", "IX", "LVIII", "MCMXCIV",
    };
    for (auto x : xx) {
        auto y = sol.romanToInt(x);
        cout << x << " " << y << "\n";
    }
}