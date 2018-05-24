#include <iostream>
#include <string>
#include <vector>

#include "common.h"

using std::cout;
using std::string;
using std::vector;
using std::pair;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(const vector<Interval>& ts, Interval t) {
        auto vv(ts);
        int n = vv.size();
        if (n == 0) {
            vv.push_back(t);
            return vv;
        }

        auto p1 = _find(vv, t.start);
        auto p2 = _find(vv, t.end);
        if (p1.first) {
            if (p2.first) {
                vv[p1.second].end = vv[p2.second].end;
                vv.erase(vv.begin() + p1.second + 1, vv.begin() + p2.second + 1);
            } else {
                // if (p2.second < n && t.end + 1 == vv[p2.second].start) {
                //     vv[p1.second].end = vv[p2.second].end;
                //     vv.erase(vv.begin() + p1.second + 1, vv.begin() + p2.second + 1);
                // } else {
                    vv[p1.second].end = t.end;
                    vv.erase(vv.begin() + p1.second + 1, vv.begin() + p2.second);
                // }
            }
        } else {
            if (p2.first) {
                // if (p1.second > 0 && vv[p1.second -1].end + 1 == t.start) {
                //     vv[p2.second].start = vv[p1.second -1].start;
                //     vv.erase(vv.begin() + p1.second - 1, vv.begin() + p2.second);
                // } else {
                    vv[p2.second].start = t.start;
                    vv.erase(vv.begin() + p1.second, vv.begin() + p2.second);
                // }
            } else {
                // if (p1.second > 0 && vv[p1.second -1].end + 1 == t.start) {
                //     if (p2.second < n && t.end + 1 == vv[p2.second].start) {
                //         vv[p1.second -1].end = vv[p2.second].end;
                //         vv.erase(vv.begin() + p1.second, vv.begin() + p2.second + 1);
                //     } else {
                //         vv[p1.second -1].end = t.end;
                //         vv.erase(vv.begin() + p1.second, vv.begin() + p2.second);
                //     }
                // } else {
                    // if (p2.second < n && t.end + 1 == vv[p2.second].start) {
                    //     vv[p2.second].start = t.start;
                    //     vv.erase(vv.begin() + p1.second, vv.begin() + p2.second);
                    // } else {
                        if (p1.second == p2.second) {
                            vv.insert(vv.begin() + p1.second, t);
                        } else {
                            vv[p2.second - 1] = t;
                            vv.erase(vv.begin() + p1.second, vv.begin() + p2.second - 1);
                        }
                    // }
                // }
            }
        }
        return vv;
    }
private:
    pair<bool, int> _find(const vector<Interval>& ts, int x) {
        int i = 0;
        int j = ts.size();
        bool found = false;
        while (i < j) {
            int k = (i + j) / 2;
            int c = _cmp(x, ts[k]);
            if (c < 0) {
                j = k;
            } else if (c > 0) {
                i = k + 1;
            } else {
                found = true;
                i = k;
                break;
            }
        }
        return {found, i};
    }

    int _cmp(int x, const Interval& t) {
        if (x < t.start) {
            return -1;
        } else if (x > t.end) {
            return 1;
        } else {
            return 0;
        }
    }
};

static std::ostream& operator<<(std::ostream& out, Interval t) {
    out << "<" << t.start << "," << t.end << ">";
    return out;
}

static void test() {
    Solution sol;
    vector<pair<vector<Interval>, Interval>> xx = {
        {{{1, 4}, {6, 9}}, {1, 2}},
        {{{1, 4}, {6, 9}}, {1, 5}},
        {{{1, 4}, {7, 9}}, {1, 5}},
        {{{1, 3}, {6, 9}}, {1, 5}},
        {{{1, 3}, {6, 9}}, {1, 7}},
        {{{1, 3}, {6, 9}}, {0, 10}},
        {{{1, 3}, {6, 9}}, {-1, 11}},
        {{{1, 3}, {6, 9}}, {4, 5}},
        {{{1, 2}, {7, 9}}, {4, 5}},
        {{{1, 2}, {7, 9}}, {-1, 0}},
        {{{1, 2}, {7, 9}}, {11, 12}},
        {{{1, 2}, {7, 9}}, {10, 12}},
        {{{1,2},{3,5},{6,7},{8,10},{12,16}}, {4, 8}},
        {{{1,4},{9,12},{19,22}}, {7, 13}},
    };
    for (auto x : xx) {
        auto y = sol.insert(x.first, x.second);
        cout << x.first << ", " << x.second << " => " << y << "\n";
    }
}