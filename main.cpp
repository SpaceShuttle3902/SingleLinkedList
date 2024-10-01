#include "Single_Linked_List.h"
#include <iostream>

// Function to display the menu
void displayMenu() {
    std::cout << "\nSingle Linked List Operations Menu:\n";
    std::cout << "1. Push front\n";
    std::cout << "2. Push back\n";
    std::cout << "3. Pop front\n";
    std::cout << "4. Pop back\n";
    std::cout << "5. Display front element\n";
    std::cout << "6. Display back element\n";
    std::cout << "7. Insert element at index\n";
    std::cout << "8. Remove element at index\n";
    std::cout << "9. Display element at index\n";
    std::cout << "10. Find position of element\n";
    std::cout << "11. Check if list is empty\n";
    std::cout << "12. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Single_Linked_List<int> list;
    int choice; // User's menu choice

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Push an element to the front
            int value;
            std::cout << "Enter value to push to front: ";
            std::cin >> value;
            list.push_front(value);
            std::cout << value << " pushed to front of list.\n";
            break;
        }
        case 2: {
            // Push an element to the back
            int value;
            std::cout << "Enter value to push to back: ";
            std::cin >> value;
            list.push_back(value);
            std::cout << value << " pushed to back of list.\n";
            break;
        }
        case 3: {
            // Pop an element from the front
            try {
                list.pop_front();
                std::cout << "Front element popped from list.\n";
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            // Pop an element from the back
            try {
                list.pop_back();
                std::cout << "Back element popped from list.\n";
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            // Display the front element
            try {
                std::cout << "Front element: " << list.front() << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 6: {
            // Display the back element
            try {
                std::cout << "Back element: " << list.back() << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 7: {
            // Insert an element at a specific index
            int value, index;
            std::cout << "Enter index to insert at: ";
            std::cin >> index;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list.insert(index, value);
            std::cout << value << " inserted at index " << index << ".\n";
            break;
        }
        case 8: {
            // Remove an element at a specific index
            int index;
            std::cout << "Enter index to remove element from: ";
            std::cin >> index;
            if (list.remove(index)) {
                std::cout << "Element at index " << index << " removed.\n";
            }
            else {
                std::cout << "Invalid index. Unable to remove element.\n";
            }
            break;
        }
        case 9: {
            // Display element at a specific index
            int index;
            std::cout << "Enter index to display: ";
            std::cin >> index;
            try {
                std::cout << "Element at index " << index << ": " << list.get_element_at(index) << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 10: {
            // Find the position of a specific element
            int value;
            std::cout << "Enter value to find: ";
            std::cin >> value;
            size_t pos = list.find(value);

            // No size method; display based on validity of pos
            if (pos != list.find(value)) { // Check if pos is valid
                std::cout << "Element " << value << " found at index " << pos << ".\n";
            }
            else {
                std::cout << "Element " << value << " not found in list.\n";
            }
            break;
        }
        case 11: {
            // Check if the list is empty
            if (list.empty()) {
                std::cout << "The list is empty.\n";
            }
            else {
                std::cout << "The list is not empty.\n";
            }
            break;
        }
        case 12: {
            // Exit the program
            std::cout << "Exiting program.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}
