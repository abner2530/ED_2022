#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void show(vector<int> vet) {
    cout << "[";
    for(auto line : vet)
        cout << " " << line;
    cout << " ]\n";
}

void soma_par(vector<int> v) {
    if(v.size() == 1)
        return;

    vector<int> vet;

    for(auto i = 0; i < v.size() - 1; i++) {
       vet.push_back(v[i] + v[i + 1]);
    }

    soma_par(vet);
    show(vet);
}

int main() {
    string line;
    getline(cin, line);

    stringstream ln(line);
    vector<int> vet;
    int base;

    while(ln >> base)
        vet.push_back(base);

    soma_par(vet);
    show(vet);
}