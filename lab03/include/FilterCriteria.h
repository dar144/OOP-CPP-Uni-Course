#pragma once

#include <vector>

class FilterCriteria
{
    public:
    void add(std::function <bool(int)> fun) { criteria.push_back(fun); }
    int size() const { return criteria.size(); }
    std::function <bool(int)> get(int i) const { return criteria[i]; }

    private:
        std::vector<std::function <bool(int)>> criteria;
};