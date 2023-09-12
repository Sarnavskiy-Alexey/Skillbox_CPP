#ifdef __MODULE_27__
/* Объявление класса Forest */

#pragma once
#include "Branch.hpp"

class Forest {
private:
    Branch* m_trees = nullptr;
    unsigned short m_countTrees = 0;
public:
    Forest();
    ~Forest();

    Branch* find_by_name(std::string name, Branch* branch = nullptr) const;
    void set_names(Branch* branch = nullptr);

    void print_forest() const;
};

#endif