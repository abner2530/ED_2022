#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

template <class T>
vector<T> range(T begin, T end) {
    vector<T> output;
    for (T i = begin; i < end; i++)
        output.push_back(i);
    return output;
}

template <class T>
T shuffle(T dado) {
    std::shuffle(dado.begin(), dado.end());
    return dado;
}

struct Problem {
    vector<string> data;
    int size { 9 };
    int dim { 3 };
    vector<pair<int, int>> holes;

    Problem(vector<string> data) {
        this->data = data;
        this->size = data.size();
        this->dim = sqrt(this->size);

        for (int l = 0; l < size; l++)
            for (int c = 0; c < size; c++)
                if (data[l][c] == '.')
                    holes.push_back(make_pair(l, c));
    }

    bool procurar(int hindex, char value) {
        auto [pl, pc] = holes[hindex];
        
        for (int l = 0; l < size; l++)
            if (data[l][pc] == value) 
                return false;
        
        for (int c = 0; c < size; c++)
            if (data[pl][c] == value)
                return false;
        
        int lh = pl - pl % dim;
        int ch = pc - pc % dim;
        for (int l = lh; l < lh + dim; l++)
            for (int c = ch; c < ch + dim; c++)
                if (data[l][c] == value)
                    return false;
        return true;
    }

    void colocar(int hindex, char value) {
        auto [pl, pc] = holes[hindex];
        data[pl][pc] = value;
    }

    bool resolver(int hindex) {
        if (hindex == (int) holes.size())
            return true;
        
        auto values = range<char>('1', '0' + size + 1);
        for (char v : values) {
            if (procurar(hindex, v)) {
                colocar(hindex, v);
                if (resolver(hindex + 1))
                    return true;
            }
        }
        colocar(hindex, '.');
        return false;
    }

    string str() {
        std::stringstream ss;
        for (auto line : data)
            ss << line << endl;
        return ss.str();
    }
};

int main() {
    auto& input = cin;

    int size { };
    input >> size;
    vector<string> data(size);
    for (int i = 0; i < size; i++)
        input >> data[i];
    
    Problem prob(data);
    prob.resolver(0);
    cout << prob.str();
}