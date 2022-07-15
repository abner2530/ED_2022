#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

template <class T>
string fmt(T data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

template <class T>
vector<T> range(T _beg, T _end) {
    std::vector<T> output;
    for (char c = _beg; c < _end; c++)
        output.push_back(c);
    return output;
}

template <class T>
vector<T> shuffle(std::vector<T> vet) {
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

struct Problem {
    string data;
    int lim;
    vector<int> holes;

    Problem(string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < (int) data.size(); i++)
            if (data[i] == '.')
                this->holes.push_back(i);
    }

    bool fit(int index, char value) {
        int size = data.size();
        int inicio = max(index - lim    , 0);
        int final  = min(index + lim + 1, size);
        for(int i = inicio; i < final; i++)
            if(data[i] == value)
                return false;
        return true;
    }

    bool solve(int hindex) {
        if (hindex == (int) holes.size())
            return true;
        
        auto index = holes[hindex];
        
        auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                if (this->solve(hindex + 1))
                    return true;
            }
        }
        data[index] = '.';
        return false;
    }

    int count_solutions(int hindex) {
        if (hindex == (int) this->holes.size())
            return true;
        
        auto index = holes[hindex];
        
        int solutions = 0;
        auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                solutions += count_solutions(hindex + 1);
            }
        }
        data[index] = '.';
        return solutions;
    }

    bool can_remove(int index) {
        auto data_backup = this->data;
        data_backup[index] = '.';
        Problem prob(data_backup, lim);
        int solutions = prob.count_solutions(0);
        
        return solutions == 1;
    }

    void fill_holes() {
        auto avaliable = shuffle(range<int>(0, data.size()));
        for (int index : avaliable)
            if (can_remove(index))
                data[index] = '.';
    }
};

int main(int argc, char * argv[]) {
    srand(time(0));
    int size { 5 }, lim { 3 };
    if (argc < 3) {
        cout << "./solver size limite.\n";
        return 1;
    }
    istringstream(argv[1]) >> size;
    istringstream(argv[2]) >> lim;
    cout << size << ' ' << lim << '\n';

    Problem prob(string(size, '.'), lim);
    prob.solve(0);
    cout << prob.data << "\n";
    prob.fill_holes();
    cout << prob.data << '\n';
}