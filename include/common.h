#ifndef _COMMON_H_
#define _COMMON_H_ 1

#include <iostream>
#include <vector>

struct single_list_node {
    int val;
    single_list_node *next;
    single_list_node(int x) : val(x), next(nullptr) {}
};

static single_list_node* build_single_list(const std::vector<int> xx) {
    single_list_node *h = nullptr;
    single_list_node **p = &h;
    for (auto x : xx) {
        *p = new single_list_node(x);
        p = &((*p)->next);
    }
    return h;
}

static void print_single_list(single_list_node *p) {
    while (p != nullptr) {
        std::cout << p->val << " -> ";
        p = p->next;
    }
    std::cout << "null\n";
}

#endif // !_COMMON_H_