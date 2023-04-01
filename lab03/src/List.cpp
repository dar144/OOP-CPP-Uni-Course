#include "List.h"
#include <iostream>

void List::insert(int i)
{
    this->list.push_back(i);
}


void List::print(std::string str) const
{
    std::cout << str << "[";
    for(int i: this->list)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

int& List::operator[] (int i)
{
    return this->list[i];
}

List List::filter(std::function <bool(int)> fun) const
{
    List result;

    for(int i: this->list)
        if(fun(i))
            result.insert(i);

    return result;
}