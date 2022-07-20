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

    ~BTree() {
        __destroy(this->root);
    }

    void __destroy(Node * node) {
        if(node == nullptr)
            return;

        __destroy(node->left);
        __destroy(node->right);

        delete node;
    }
    
    void bshow() {
        __bshow(this->root);
    }

    void __bshow(Node * node, string heranca = "") {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left , heranca + "l");

        for(int i = 0; i < (int) heranca.size() - 1; i++)
            cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");

        if(heranca != "")
            cout << (heranca.back() == 'l' ? "┌───" : "└───");

        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;

        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heranca + "r");
    }

    void show_in_order() {
        cout << "[ ";
        __show_in_order(root);
        cout << "]\n";
    }

    void __show_in_order(Node * node) {
        if(node == nullptr)
            return;

        __show_in_order(node->left);
        cout << node->value << " ";
        __show_in_order(node->right);
    }

};

int main(){
    string line;
    getline(cin, line);

    BTree bt(line);
    bt.show_in_order();
}