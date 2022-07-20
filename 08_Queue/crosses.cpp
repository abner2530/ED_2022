#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

void vencedor (queue<char>& times, int time1_go1, int time2_gol) {
    if (time1_go1 > time2_gol) {
            times.push(times.front());
            times.pop();
            times.pop();

    }

    else {
            times.pop();
            times.push(times.front());
            times.pop();
    }
}

int main() {
    queue<char> times;
    int time1_gols{0}, time2_gols{0};

    for (char c = 'A'; c < 'Q'; c++)
        times.push(c);

    while (times.size() != 1) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> time1_gols >> time2_gols;
        vencedor(times, time1_gols, time2_gols);
    }

    cout << times.front() << endl;
}