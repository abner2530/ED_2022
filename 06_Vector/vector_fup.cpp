#include <iostream>
#include <sstream>

using namespace std;

struct Vector {
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int size) {
    Vector * v = new Vector();
    v->data = new int[size];
    v->capacity = size;
    v->size = 0;
    return v;
}

void vector_destroy(Vector * vector) {
    delete [] vector->data;
    delete vector;
}

void vector_add(Vector * vector, int value) {
    if(vector->size < vector->capacity) {
        vector->data[vector->size] = value;
        vector->size++;
    }
}

string vector_show(Vector * vector) {
    stringstream ss;
    ss << "[ ";
    for(int i = 0; i < vector->size; i++)
        ss << vector->data[i] << " ";
    ss << "]";
    return ss.str();
}

int main(){
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status"){
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show"){
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}