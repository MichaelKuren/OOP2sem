#include "linkedlist.h"
#include <iostream>
#include <cmath>

int main()
{
    LinkedList<double> list;

    list.push_back(1.0);
    list.push_back(2.0);
    list.push_back(3.0);
    list.push_back(4.0);
    list.push_back(5.0);
    list.push_back(6.0);
    list.push_back(7.0);

    list.print();
    std::cout << std::endl;

    auto it = list.begin();
    while (it != list.end())
        ++it;

    list.print();
    std::cout << std::endl;

    return 0;
}