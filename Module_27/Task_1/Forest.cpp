// #ifdef __MODULE_27__
/* Определение класса Forest */

#include <iostream>
#include "Forest.hpp"

Forest::Forest() {
    m_countTrees = 5;
    m_trees = new Branch[m_countTrees];
    for (unsigned short i = 0; i < m_countTrees; i++) {
        m_trees[i].create_tree(nullptr);
    }
}

Forest::~Forest() {
    delete[] m_trees;
}

Branch* Forest::find_by_name(std::string name, Branch* branch) const {
    if (branch == nullptr) {
        /* изучаем все деревья леса */
        for (unsigned short i = 0; i < m_countTrees; i++) {
            Branch* result = find_by_name(name, &m_trees[i]);
            if (result != nullptr) {
                return result;
            }
        }
    } else if (branch->get_parent() == nullptr) {
        /* изучаем каждое дерево */
        for (unsigned short i = 0; i < branch->get_countBranches(); i++) {
            /* на дереве никто не живет, идем на большие ветки */
            Branch* result = find_by_name(name, branch->get_daughter(i));
            if (result != nullptr) {
                return result;
            }
        }
    } else {
        /* если на ветке живет искомый эльф, то возвращаем ветку с жителем */
        if (branch->get_name() == name && branch->get_alive()) {
            return branch;
        }
        for (unsigned short i = 0; i < branch->get_countBranches(); i++) {
            /* если у ветки есть дочерняя, то ищем в дочерней ветке */
            if (branch->get_daughter(i) != nullptr) {
                Branch* result = find_by_name(name, branch->get_daughter(i));
                if (result != nullptr) {
                    return result;
                }
            }
        }
    }

    /* если ничего не было найдено, то возвращаем нулевой указатель */
    return nullptr;
}

void Forest::set_names(Branch* branch) {
    if (branch == nullptr) {
        for (unsigned short i = 0; i < m_countTrees; i++) {
            set_names(&m_trees[i]);
        }
    } else if (branch->get_parent() == nullptr) {
        for (unsigned short i = 0; i < branch->get_countBranches(); i++) {
            set_names(branch->get_daughter(i));
        }
    } else {
        std::string name;
        if (branch->get_parent()->get_parent() == nullptr) {
            std::cout << "Введите имя эльфа, живущего на большой ветке: ";
            std::cin >> name;
            branch->set_name(name);
            
            for (unsigned short i = 0; i < branch->get_countBranches(); i++) {
                set_names(branch->get_daughter(i));
            }
        } else {
            std::cout << "    Введите имя эльфа, живущего на средней ветке: ";
            std::cin >> name;
            branch->set_name(name);
        }
    }
}

void Forest::print_forest() const {
    std::cout << "\n        В лесу живут следующие эльфы:\n";
    for (unsigned short i = 0; i < m_countTrees; i++) {
        std::cout << "    Дерево №" << i + 1 << ":\n";
        m_trees[i].print_tree();
    }
}

// #endif