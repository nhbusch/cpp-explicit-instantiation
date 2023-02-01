#include <iostream>

#include "array.h"

int
main(int argc, char** argv)
{
    my::array<int, 3> a;
    a[0] = 3;
    a[1] = 2;
    a[2] = 1;
    a.print();
    std::cout << '\n';

    my::array<double, 4> b = {1.2, 3.4, 5.6, 7.8};

    return 0;
}