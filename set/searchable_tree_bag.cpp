#include "searchable_tree_bag.hpp"

bool searchable_bag::search(int num) {
    node *current = tree;
    while (current != nullptr) {
        if (num == current->value)
            return true;
        else if (current->value > num)
            current = current->l;
        else
            current = current->r;
    }
    return false;
}