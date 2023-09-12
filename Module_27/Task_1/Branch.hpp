#ifdef __MODULE_27__
/* Объявление класса Branch */

#pragma once
#include <string>

class Branch {
private:
    Branch* m_parent = nullptr;
    Branch* m_daughters = nullptr;
    std::string m_name = "";
    unsigned short m_countBranches = 0;
    bool m_alive = false;
public:
    Branch();
    ~Branch();

    void create_tree(Branch* parent);
    
    Branch* get_daughter(unsigned short index);
    Branch* get_parent();
    unsigned short get_countBranches() const;
    bool get_alive() const;
    std::string get_name() const;
    
    void set_name(std::string name);
    void set_parent(Branch* parent);

    unsigned int count_neighbours();
    void print_tree() const;
};

#endif