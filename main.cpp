#include "linkedlist.h"
#include <iostream>

int main()
{
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    LinkedList<int> list2 = list1;
    list2.push_back(4);

    LinkedList<int> list3;
    list3 = std::move(list2);

    for (int val : list3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}