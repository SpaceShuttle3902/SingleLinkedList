#include "single_linked_list.h"
#include <iostream>

int main() {
    Single_Linked_List<int> list;

    // Add elements to the list
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);

    // Insert element at index 2
    list.insert(2, 3);

    // Display all elements in the list
    std::cout << "List elements: ";
    for (size_t i = 0; i < 4; ++i) {
        std::cout << list.get_element_at(i) << " ";
    }
    std::cout << std::endl;

    // Remove element at index 1
    list.remove(1);

    // Display all elements after removal
    std::cout << "List after removal: ";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << list.get_element_at(i) << " ";
    }
    std::cout << std::endl;

    // Find the position of element 4
    size_t pos = list.find(4);
    std::cout << "Position of element 4: " << pos << std::endl;

    return 0;
}

