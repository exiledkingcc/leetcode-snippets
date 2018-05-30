#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::pair;

#include "common.h"
typedef single_list_node<int> ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head;
        auto q = head;
        while (n-- > 0) {
            q = q->next;
        }
        if (q == nullptr) {
            p = p->next;
            delete head;
            return p;
        }
        while (q->next != nullptr) {
            q = q->next;
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};

static void test() {
    Solution sol;
    vector<pair<vector<int>, int>> xx = {
        {{1, 2, 3, 7, 9}, 1},
        {{1, 2, 3, 7, 9}, 2},
        {{1, 2, 3, 7, 9}, 3},
        {{1, 2, 3, 7, 9}, 4},
        {{1, 2, 3, 7, 9}, 5},
    };
    for (auto x : xx) {
        auto l1 = ListNode::build(x.first);
        cout << ListNode::to_string(l1) << " " << x.second << " ";
        auto y = sol.removeNthFromEnd(l1, x.second);
        cout << ListNode::to_string(y) << "\n";
    }
}