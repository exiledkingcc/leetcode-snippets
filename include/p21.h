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
    ListNode* mergeTwoLists(const ListNode* l1, const ListNode* l2) {
        ListNode *h = nullptr;
        ListNode **p = &h;
        while (true) {
            if (l1 != nullptr) {
                if (l2 != nullptr) {
                    auto x = l1->val;
                    auto y = l2->val;
                    if (x < y) {
                        *p = new ListNode(x);
                        l1 = l1->next;
                    } else if (x > y) {
                        *p = new ListNode(y);
                        l2 = l2->next;
                    } else {
                        *p = new ListNode(x);
                        p = &((*p)->next);
                        *p = new ListNode(x);
                        l1 = l1->next;
                        l2 = l2->next;
                    }
                    p = &((*p)->next);
                } else {
                    while (l1 != nullptr) {
                        *p = new ListNode(l1->val);
                        p = &((*p)->next);
                        l1 = l1->next;
                    }
                    break;
                }
            } else {
                if (l2 != nullptr) {
                    while (l2 != nullptr) {
                        *p = new ListNode(l2->val);
                        p = &((*p)->next);
                        l2 = l2->next;
                    }
                    break;
                }
                break;
            }
        }
        return h;
    }
};

static void test() {
    Solution sol;
    vector<pair<vector<int>, vector<int>>> xx = {
        {{1, 2, 3, 7, 9}, {1, 3, 4, 5, 6, 8, 10}},
        {{1, 1, 2, 3}, {5, 8, 13}},
    };
    for (auto x : xx) {
        auto l1 = ListNode::build(x.first);
        auto l2 = ListNode::build(x.second);
        auto y = sol.mergeTwoLists(l1, l2);
        cout << ListNode::to_string(y) << "\n";
    }
}