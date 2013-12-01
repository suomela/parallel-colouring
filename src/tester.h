#ifndef TESTER_H
#define TESTER_H

#include <memory>
#include "colour.h"

constexpr unsigned BITS_MAX {31};
constexpr unsigned BITS_MIN {10};

class Tester {
public:
    Tester(unsigned bits_);
    void gen_input();
    void do_colour();
    bool verify() const;
    void stat() const;

private:
    const unsigned n;
    const unsigned mask;
    std::unique_ptr<unsigned[]> p;
    std::unique_ptr<col_t[]> c;
};

#endif
