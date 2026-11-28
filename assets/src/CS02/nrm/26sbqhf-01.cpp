#include <iostream>

struct element {
    int val;
    element* ptr;
};

int main() {
    element* HEAD = new element();
    HEAD->val = 0;

    element* temp = HEAD;
    for (int i = 1; i < 10; i++) {
        element* current = new element;
        current->val = i;
        current->ptr = nullptr;

        temp->ptr = current;
        temp = current;
    }

    element* search = HEAD;
    while ((*search).ptr != nullptr) {
        std::cout << (*search).val << " ";
        search = search->ptr;
    }
    std::cout << (*search).val << "\n";

    return 0;
}


