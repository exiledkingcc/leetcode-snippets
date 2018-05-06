#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::make_pair;
using std::map;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2) {
        ListNode *h = new ListNode(0);
        ListNode *p = h;
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
            p->next = new ListNode(c % 10);
            p = p->next;
            c = c >= 10 ? 1 : 0;
        }
        if (c > 0) {
            p->next = new ListNode(c);
        }
        p = h->next;
        delete h;
        return p;
    }
};

static ListNode *build_list(const vector<int> xx) {
    ListNode *h = new ListNode(0);
    ListNode *p = h;
    for (auto x : xx) {
        p->next = new ListNode(x);
        p = p->next;
    }
    p = h->next;
    delete h;
    return p;
}

static void print_list(ListNode *p) {
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "\n";
}

static void test() {
    Solution sol;
    {
        vector<int> x1{5, 3, 4};
        vector<int> x2{7, 5, 6};
        auto l1 = build_list(x1);
        auto l2 = build_list(x2);
        auto y = sol.addTwoNumbers(l1, l2);
        print_list(y);
    }
}