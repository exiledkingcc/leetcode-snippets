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
    bool isValid(string s) {
        vector<char> v;
        for (auto c: s) {
            if (isleft(c)) {
                v.push_back(c);
            } else {
                if (v.size() > 0 && ispair(v.back(), c)) {
                    v.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (v.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    static bool isleft(char c) {
        if (c == '(' || c == '[' || c == '{') {
            return true;
        } else {
            return false;
        }
    }

    static bool ispair(char c1, char c2) {
        if (c1 == '(' && c2 == ')') {
            return true;
        } else if (c1 == '[' && c2 == ']') {
            return true;
        } else if (c1 == '{' && c2 == '}') {
            return true;
        } else {
            return false;
        }
    }
};

static void test() {
    Solution sol;
    vector<string> xx = {
        "()",
        "()[]{}",
        "([)]",
        "{[]}",
    };
    for (auto x : xx) {
        auto y = sol.isValid(x);
        cout << x << " " << y << "\n";
    }
}