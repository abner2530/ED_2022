#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int value;
    Node * next;

    Node(int value = 0, Node * next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

struct LinkedList {
    Node * head {nullptr};

    LinkedList() {}

    ~LinkedList() {
        destroy(head);
    }

    void destroy(Node * node) {
        if(node == nullptr)
            return;
        else {
            destroy(node->next);
            delete(node);
        }
    }

    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }

        auto node = head;
        while (node->next != nullptr) {
            node = node->next;    
        }
        node->next = new Node(value); 
    }

    void push_front(int value) {
        auto node = new Node(value);

        node->next = head;
        head = node;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            pop_front();
            return;
        }

        auto node = head;
        while (node->next->next != nullptr) {
            node = node->next;
        }
        delete node->next;
        node->next = nullptr;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }

        auto backup = head;
        head = head->next;
        delete backup;
    }
    
    int size() {
        Node * node = head;
        int cont = 0;
        while(node != nullptr) {
            cont += 1;
            node = node->next;
        }
        return cont;
    }

    friend ostream& operator<<(ostream& os, LinkedList& lista) {
        os << "[ ";
        Node * node = lista.head;
        while(node != nullptr) {
            os << node->value << " ";
            node = node->next;
        }
        os << "]";
        return os;
    }
};

int main() {
    LinkedList ll;
    while(true) {
        string line, cmd;
        int value;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end") {
            break;
        }else if(cmd == "show") {
            cout << ll << endl;
        }else if(cmd == "push_back") {
            while(ss >> value)
                ll.push_back(value);
        }else if(cmd == "push_front") {
            while(ss >> value)
                ll.push_front(value);
        }else if(cmd == "pop_back") {
            ll.pop_back();
        }else if(cmd == "pop_front") {
            ll.pop_back();
        }else if(cmd == "size") {
            cout << ll.size() << endl;
        }
    }
}