#ifndef _COMMON_H_
#define _COMMON_H_ 1

#include <sstream>
#include <vector>

template <typename T> struct single_list_node {
    T val;
    single_list_node *next;
    single_list_node(T x) : val(x), next(nullptr) {}

    static single_list_node* build(const std::vector<T> xx) {
        single_list_node *h = nullptr;
        single_list_node **p = &h;
        for (auto x : xx) {
            *p = new single_list_node(x);
            p = &((*p)->next);
        }
        return h;
    }

    static std::string to_string(single_list_node *p) {
        std::stringstream ss;
        ss << "{ ";
        while (p != nullptr) {
            ss << p->val << "->";
            p = p->next;
        }
        ss << "null }";
        return ss.str();
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> vv) {
    int n = vv.size();
    if (n == 0) {
        out << "[]";
        return out;
    }
    out << "[";
    for (int i = 0; i <= n - 2; ++i) {
        out << vv[i] << ", ";
    }
    out << vv.back() << "]";
    return out;
}


#endif // !_COMMON_H_