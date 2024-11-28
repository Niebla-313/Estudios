#include<iostream>

struct node {
    int data;
    node* next;
};

class circular_list {
    private:
    node* temp;
    node* head;
    node* tail;
    node* prev;
    unsigned int size;

    public:
    circular_list();
    bool is_empty();
    void insert_at_front (int);
    void insert_at_end (int);
    void insert_at_position (int, unsigned int);
    void delete_from_front ();
    void delete_from_end ();
    void delete_from_position (unsigned int);
    void display ();
};

circular_list::circular_list () {
    head = NULL;
    tail = NULL;
    temp = NULL;
    prev = NULL;
    size = 0;
}

bool circular_list::is_empty() {
    return size == 0;
}

void circular_list::insert_at_front (int data) {
    temp = new node;
    temp -> data = data;
    temp -> next = head;
    head = temp;
    if (is_empty()) { 
        tail = temp;
        tail -> next = head;
    }
    size++;
}

void circular_list::insert_at_end (int data) {
    temp = new node;
    temp -> data = data;
    temp -> next = NULL;
    if (is_empty()) {
        head = temp;
        tail = temp;
        tail -> next = head;
    } else {
        tail -> next = temp;
        tail = temp;
        tail -> next = head;
    }
    size++;
}

void circular_list::insert_at_position (int data, unsigned int position) {
    temp = NULL;
    unsigned int i = 0;
    for (i = 0, temp = head; i < position && i < size; i++) {
        prev = temp;
        temp = temp -> next;
    }
    if (i != position) {
        std::cout << "Error: Memory violation.\n";
        return;
    }
    if (temp == head) {
        insert_at_front(data);
        return;
    } else if(size == i) {
        insert_at_end(data);
        return;
    } else {
        node* new_node = new node;
        new_node -> data = data;
        new_node -> next = temp;
        prev -> next = new_node;
        size++;
    }
}

void circular_list::delete_from_front () {
    if (is_empty()) {
        std::cout << "Error: the list is already empty.\n";
        return;
    }
    if (size == 1) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        temp = head -> next;
        delete head;
        head = temp;
        tail -> next = head;
    }
    size--;
}

void circular_list::delete_from_end () {
    if (is_empty()) {
        std::cout << "Error: the list is already empty.\n";
        return;
    }
    temp = head;
    if (size == 1) {
        delete_from_front();
        return;
    } else {
        while (temp != tail) {
            prev = temp;
            temp = temp -> next;
        }
        delete temp;
        tail = prev;
        tail -> next = head;
    }
    size--;
}

void circular_list::delete_from_position (unsigned int position) {
    temp = NULL;
    unsigned int i = 0;
    for (i = 0, temp = head; i < position && i < size; i++) {
        prev = temp;
        temp = temp -> next;
    }
    if (i != position) {
        std::cout << "Error: Memory violation.\n";
        return;
    }
    if (temp == head) {
        delete_from_front();
        return;
    }else if (temp == tail) {
        delete_from_end();
        return;
    } else {
        prev -> next = temp -> next;
        delete temp;
    }
    size--;
}
 
void circular_list::display () {
    temp = head;
    if (size == 0) {
        std::cout << "List is empty" << '\n';
        return;
    }
    for (unsigned int i = 0; i < size; i++) {
        std::cout << temp -> data << " ";
        temp = temp->next;
    }
    std::cout << '\n' << "The size of the list is: " << size << '.' << '\n';
}

int main (void) {
    circular_list test;
    test.insert_at_front(10);
    test.insert_at_end(9);
    test.display();
    return 0;
}