#pragma once

#include <vector>
#include <string>
#include <functional>

class List
{
public:
    void insert(int);
    void print(std::string str = "") const;
    int& operator[] (int);
    List filter(std::function <bool(int)> fun) const;

private:
    std::vector<int> list;
};