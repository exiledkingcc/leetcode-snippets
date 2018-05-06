
#define _(x) __(x)
#define __(x) #x

#ifndef PROB_HDR
    #define PROB_HDR p0.h
#endif // !PROB_HDR

#include _(PROB_HDR)

int main() {
    test();
}