// #ifdef __MODULE_27__
/* Определение класса Branch */

#include <iostream>

#include "Branch.hpp"

Branch::Branch() {
}

void Branch::create_tree(Branch* parent) {
    if (parent == nullptr) {
        /* в дереве */
        this->m_countBranches = std::rand() % 3 + 3;
        this->m_daughters = new Branch[this->m_countBranches];
        for (unsigned short i = 0; i < this->m_countBranches; i++) {
            this->m_daughters[i].set_parent(this);
            create_tree(&m_daughters[i]);
        }
    } else if (parent->m_parent->m_parent == nullptr) {
        /* в большой ветке */
        parent->m_countBranches = std::rand() % 2 + 2;
        parent->m_daughters = new Branch[parent->m_countBranches];
        for (unsigned short i = 0; i < parent->m_countBranches; i++) {
            parent->m_daughters[i].set_parent(parent);
            create_tree(&(parent->m_daughters[i]));
        }
    } else {
        /* в средней ветке */
        parent->m_countBranches = 0;
        parent->m_daughters = nullptr;
    }
}

Branch::~Branch() {
    if (m_daughters == nullptr) {
        /* в средней ветке маленькие ветки не создавались */
    } else if (m_daughters->m_daughters == nullptr) {
        /* в большой ветке создавался массив средних веток */
        delete[] m_daughters;
    } else {
        /* в дереве создавался массив больших веток */
        delete[] m_daughters;
    }
}

Branch* Branch::get_daughter(unsigned short index) {
    /* возвращается указатель на ветку по индексу */
    return (index < m_countBranches ? &m_daughters[index] : nullptr);
}

Branch* Branch::get_parent() {
    return m_parent;
}

void Branch::set_name(std::string name) {
    m_name = (name != "None" ? name : "");
    m_alive = !(name == "None");
}

void Branch::set_parent(Branch* parent) {
    m_parent = parent;
}

unsigned short Branch::get_countBranches() const {
    return m_countBranches;
}

bool Branch::get_alive() const {
    return m_alive;
}

std::string Branch::get_name() const {
    return m_name;
}

unsigned int Branch::count_neighbours() {
    if (m_daughters == nullptr) {
        return m_parent->count_neighbours();
    } else if (m_daughters->m_daughters == nullptr) {
        unsigned int result = 0;
        result += (m_alive ? 1 : 0);
        for (unsigned short i = 0; i < m_countBranches; i++) {
            result += (m_daughters[i].m_alive ? 1 : 0);
        }
        return result - 1;
    }
    return 0;
}

void Branch::print_tree() const {
    std::cout << "( ";
    for (unsigned short i = 0; i < m_countBranches; i++) {
        /* пробегаемся по большим веткам */
        std::cout << "\"" << m_daughters[i].m_name << "\" (";
        for (unsigned short j = 0; j < m_daughters[i].m_countBranches; j++) {
            std::cout << "\"" << m_daughters[i].m_daughters[j].m_name << "\", ";
        }
        std::cout << "), ";
    }
    std::cout << ")\n";
}
// #endif