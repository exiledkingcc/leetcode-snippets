#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::make_pair;
using std::map;
using std::vector;

class Solution {
  public:
    vector<int> twoSum(const vector<int> &numbers, int target) {
        map<int, int> m;
        vector<int> v{-1, -1};
        for (int i = 0; i < numbers.size(); ++i) {
            auto x = numbers[i];
            auto t = target - x;
            auto p = m.find(t);
            if (p != m.end()) {
                v[0] = p->second;
                v[1] = i;
                break;
            }
            m[x] = i;
        }
        return v;
    }
};

static void test() {
    Solution sol;
    {
        vector<int> x{2, 7, 11, 15};
        auto y = sol.twoSum(x, 18);
        cout << y[0] << " " << y[1] << "\n";
    }
    {
        vector<int> x{3, 3};
        auto y = sol.twoSum(x, 6);
        cout << y[0] << " " << y[1] << "\n";
    }
}