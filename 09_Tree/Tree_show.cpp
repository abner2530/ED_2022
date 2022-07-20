#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;

    Node(int value = 0, Node * left = nullptr, Node * right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree {
    Node * root {nullptr};

    BTree() {}

    Node* __create(stringstream& ss) {
        string dado;
        int value{};

        ss >> dado;

        if (dado == "#")
            return nullptr;

        stringstream(dado) >> value;

        Node * node = new Node(value);
        node->left = __create(ss);
        node->right = __create(ss);
        return node;
    }

    BTree(string serial) {
        stringstream ss(serial);
        root = __create(ss);
    }

    void __destroy(Node * node) {
        if(node == nullptr)
            return;

        __destroy(node->left);
        __destroy(node->right);

        delete node;
    }

    ~BTree() {
        __destroy(this->root);
    }

    void __bshow(Node * node, int tab) {
        if(node == nullptr) {
            cout << string(tab * 5, '.') << "#\n";
            return;
        }

        if(node->left != nullptr || node->right != nullptr) {
            __bshow(node->left, tab + 1);

            cout << string(tab * 5, '.') << node->value << "\n";
        
            if(node->left != nullptr || node->right != nullptr)
            __bshow(node->right, tab + 1);

            return;
        }

        cout << string(tab * 5, '.') << node->value << "\n";
    }

    void show() {
        __bshow(root, 0);
    }

};

int main() {
    string line;
    getline(cin, line);

    BTree bt(line);
    bt.show();
}