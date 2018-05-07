#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::make_pair;
using std::map;
using std::vector;

#include "common.h"
typedef single_list_node ListNode;

class Solution {
  public:
    ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2) {
        ListNode *h = nullptr;
        ListNode **p = &h;
        int c = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                c += l2->val;
                l2 = l2->next;
            }
            *p = new ListNode(c % 10);
            p = &((*p)->next);
            c = c >= 10 ? 1 : 0;
        }
        if (c > 0) {
            *p = new ListNode(c);
        }
        return h;
    }
};


static void test() {
    Solution sol;
    {
        vector<int> x1{5, 3, 4, 3, 4, 6, 7};
        vector<int> x2{7, 5, 6, 7, 5, 3, 3, 9};
        auto l1 = build_single_list(x1);
        auto l2 = build_single_list(x2);
        auto y = sol.addTwoNumbers(l1, l2);
        print_single_list(y);
    }
}