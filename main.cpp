#include <iostream>
#include "basicMaths.hpp"

int main()
{
    BasicMaths bm;
    bm.isArmstrong(2) ? cout << "Yes" : cout << "No";
    bm.isArmstrong(200) ? cout << "Yes" : cout << "No";
    bm.isArmstrong(153) ? cout << "Yes" : cout << "No";

    return 0;
}