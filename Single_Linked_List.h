#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <cstddef> // For size_t
#include <stdexcept> // For exceptions

template <typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    // Constructor for easy node creation
    Node(const Item_Type& item, Node* next_node = nullptr)
        : data(item), next(next_node) {}
};

template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head; // Pointer to the head of the list
    Node<Item_Type>* tail; // Pointer to the tail of the list
    size_t num_items; // Number of items in the list

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor
    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }

    // Check if list is empty
    bool empty() const {
        return head == nullptr;
    }

    // Push an item to the front
    void push_front(const Item_Type& item) {
        Node<Item_Type>* new_node = new Node<Item_Type>(item, head);
        head = new_node;
        if (tail == nullptr) tail = head;
        ++num_items;
    }

    // Push an item to the back
    void push_back(const Item_Type& item) {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        if (tail == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        ++num_items;
    }

    // Pop an item from the front
    void pop_front() {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }
        Node<Item_Type>* old_head = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete old_head;
        --num_items;
    }

    // Pop an item from the back
    void pop_back() {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<Item_Type>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            delete tail;
            tail = current;
        }
        --num_items;
    }

    // Return the item at the front of the list
    Item_Type front() const {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }
        return head->data;
    }

    // Return the item at the back of the list
    Item_Type back() const {
        if (empty()) {
            throw std::underflow_error("List is empty.");
        }
        return tail->data;
    }

    // Insert an item at a specific index
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
        }
        else if (index >= num_items) {
            push_back(item);
        }
        else {
            Node<Item_Type>* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node<Item_Type>* new_node = new Node<Item_Type>(item, current->next);
            current->next = new_node;
            ++num_items;
        }
    }

    // Remove an item at a specific index
    bool remove(size_t index) {
        if (index >= num_items) {
            return false;
        }
        if (index == 0) {
            pop_front();
        }
        else {
            Node<Item_Type>* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node<Item_Type>* to_delete = current->next;
            current->next = to_delete->next;
            if (to_delete == tail) {
                tail = current;
            }
            delete to_delete;
            --num_items;
        }
        return true;
    }

    // Find the position of the first occurrence of an item
    size_t find(const Item_Type& item) const {
        Node<Item_Type>* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return num_items; // If not found, return the size of the list
    }

    // Get the element at a specific index
    Item_Type get_element_at(size_t index) const {
        if (index >= num_items) {
            throw std::out_of_range("Index is out of range.");
        }
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
};

#endif
