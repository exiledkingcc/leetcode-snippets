#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {
            if (s[i] != ' ') {
                break;
            }
            --i;
        }
        int x = i;
        while (i >= 0) {
            if (s[i] == ' ') {
                break;
            }
            --i;
        }
        return x - i;
    }
};

static void test() {
    Solution sol;
    vector<string> xx = {
        "",
        " ",
        "ab",
        "ab ",
        "  ab  ",
        "  ab   abc  ",
        "Hello World",
    };
    for (auto x : xx) {
        auto y = sol.lengthOfLastWord(x);
        cout << '"' << x << '"' << " => " << y << "\n";
    }
}