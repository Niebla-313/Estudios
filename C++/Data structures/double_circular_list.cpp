#include<iostream>

struct node {
    int data;
    node* next;
    node* prev;
};

class double_circular_list {
    private:
    node* temp;
    node* head;
    node* tail;
    node* aux;
    unsigned int size;

    public:
    double_circular_list();
    bool is_empty();
    void insert_at_front (int);
    void insert_at_end (int);
    void insert_at_position (int, unsigned int);
    void delete_from_front ();
    void delete_from_end ();
    void delete_from_position (unsigned int);
    void display ();
};

double_circular_list::double_circular_list () {
    head = NULL;
    tail = NULL;
    temp = NULL;
    aux = NULL;
    size = 0;
}

bool double_circular_list::is_empty() {
    return size == 0;
}

void double_circular_list::insert_at_front (int data) {
    temp = new node;
    temp -> data = data;
    if (is_empty()) {
        head = temp;
        tail = temp;
        temp -> next = head;
        temp -> prev = tail;
    } else {
        temp -> next = head;
        temp -> prev = tail;
        head -> prev = temp;
        head = temp;
        tail -> next = head;
    }
    size++;
}

void double_circular_list::insert_at_end (int data) {
    temp = new node;
    temp -> data = data;
    if (is_empty()) {
        insert_at_front(data);
    } else {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        temp -> next = head;
        head -> prev = tail;
    }
    size++;
}

void double_circular_list::insert_at_position (int data, unsigned int position) {
    temp = NULL;
    unsigned int i = 0;
    for (i = 0, temp = head; i < position && i < size; i++) {
        aux = temp;
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
        new_node -> prev = aux;
        aux -> next = new_node;
        temp -> prev = new_node;
        size++;
    }
}

void double_circular_list::delete_from_front () {
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
        temp -> prev = tail;
        delete head;
        head = temp;
        tail -> next = head;
    }
    size--;
}

void double_circular_list::delete_from_end () {
    if (is_empty()) {
        std::cout << "Error: the list is already empty.\n";
        return;
    }
    if (size == 1) {
        delete_from_front();
        return;
    } else {
        temp = tail -> prev;
        temp -> next = head;
        delete tail;
        tail = temp;
        head -> prev = tail;
    }
    size--;
}

void double_circular_list::delete_from_position (unsigned int position) {
    temp = NULL;
    unsigned int i = 0;
    for (i = 0, temp = head; i < position && i < size; i++) {
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
        aux = temp -> next;
        aux -> prev = temp -> prev;
        aux = temp -> prev;
        aux -> next = temp -> next;
        delete temp;
    }
    size--;
}
 
void double_circular_list::display () {
    temp = head;
    if (is_empty()) {
        std::cout << "List is empty" << '\n';
        return;
    }
    for (unsigned int i = 0; i < size; i++) {
        std::cout << temp -> data << " ";
        temp = temp -> nextd;
    }
    std::cout << '\n' << "The size of the list is: " << size << '.' << '\n';
}

int main (void) {
    double_circular_list test;
    test.insert_at_front(2);
    test.insert_at_front(1);
    test.insert_at_end(0);
    test.insert_at_position(2, 2);
    test.delete_from_end();
    test.display();
    return 0;
}