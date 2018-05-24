#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution {
public:
    int myAtoi(const string& str) {
        auto p = str.c_str();
        auto end = p + str.size();
        while (p < end && (*p == ' ' || *p == '\t')) {
            ++p;
        }
        bool neg = false;
        if (*p == '-') {
            neg = true;
            ++p;
        } else if (*p == '+') {
            ++p;
        }
        int64_t k = 0;
        while (p < end && *p >= '0' && *p <= '9') {
            k *= 10;
            k += *p - '0';
            if (k >= INT32_MAX) {
                if (!neg) {
                    return INT32_MAX;
                } else if (k - 1 >= INT32_MAX) {
                    return INT32_MIN;
                }
            }
            ++p;
        }
        if (!neg) {
            return k;
        } else {
            return -k;
        }
        return 0;
    }
};

static void test() {
    Solution sol;
    vector<string> xx = {
        "",
        "  ",
        " 42",
        "-42",
        "  -4232abc",
        " 23423 haha ",
        " haah 234 ",
        " -haah 234 ",
        "2147483647",
        "-2147483647",
        "2147483648",
        "-2147483648",
        "-2147483649",
    };
    for (auto x : xx) {
        auto y = sol.myAtoi(x);
        cout << "\"" << x << "\" => " << y << "\n";
    }
}