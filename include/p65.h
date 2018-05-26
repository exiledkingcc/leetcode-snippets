#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution {
public:
    bool isNumber(const string& s) {
        if (s.empty()) {
            return false;
        }
        auto p = s.begin();
        auto e = s.end();
        int stat = 0;
        bool has_num = false;
        while (p != e) {
            switch (*p) {
                case '\t':                
                case ' ': {
                    if (stat == 1) {
                        return false;
                    } else if (stat == 2 || stat == 3 || stat == 4 || stat == 7) {
                        stat = 8;
                    } else if (stat == 5 || stat == 6) {
                        return false;
                    }
                } break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9': {
                    if (stat == 0 || stat == 1) {
                        has_num = true;                        
                        stat = 2;
                    } else if (stat == 3) {
                        has_num = true;
                        stat = 4;
                    } else if (stat == 5 || stat == 6) {
                        stat = 7;
                    } else if (stat == 8) {
                        return false;
                    }
                } break;
                case '.': {
                    if (stat == 0 || stat == 1 || stat == 2) {
                        stat = 3;
                    } else {
                        return false;
                    }
                } break;
                case 'E': 
                case 'e': {
                    if (!has_num) {
                        return false;
                    }
                    if (stat == 2 || stat == 3 || stat == 4) {
                        stat = 5;
                    } else {
                        return false;
                    }
                } break;
                case '+':
                case '-': {
                    if (stat == 0) {
                        stat = 1;
                    } else if (stat == 5) {
                        stat = 6;
                    } else {
                        return false;
                    }
                } break;
                default:
                    return false;
            }
            ++p;
        }
        if (stat == 5 || stat == 6) {
            return false;
        }
        return has_num;
    }
};

static void test() {
    Solution sol;
    vector<string> xx = {
        "  ",
        " . ",
        "0",
        "1e ",
        ".e1",
        "+",
        "+.",
        "+5.",
        " 0.1",
        "abc",
        "1 a",
        "2e10",
        "  -1.2e+10 ",
    };
    for (auto x : xx) {
        auto y = sol.isNumber(x);
        cout << '"' << x << '"' << " => " << std::boolalpha << y << "\n";
    }
}