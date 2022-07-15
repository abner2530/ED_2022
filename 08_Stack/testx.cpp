#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef pair<size_t, size_t> Pos;

vector <Pos> get_neib (Pos pos) {
    vector <Pos> neib;
    neib.push_back(Pos(pos.first, pos.second - 1));
    neib.push_back(Pos(pos.first, pos.second + 1));
    neib.push_back(Pos(pos.first - 1, pos.second));
    neib.push_back(Pos(pos.first + 1, pos.second));
    return neib;
}

bool inside (vector <string> &matrix, Pos pos) {
    return (pos.first >= 0 && pos.first < matrix.size() && pos.second >= 0 && pos.second < matrix[0].size());
}

void queimar(vector<string> &mat, size_t l, size_t c){
	list<Pos> pilha;
	if(mat[l][c] != '#')
		return;
	mat[l][c] = 'o';
	pilha.push_back(make_pair(l, c));
	while(!pilha.empty()){
		auto top = pilha.back();
		vector<Pos> toburn;
		for(auto neib : get_neib(top)){
			if(inside(mat, neib) && (mat[neib.first][neib.second] == '#')){
				toburn.push_back(neib);
				break;
			}
		}
		if(!toburn.empty()){
			auto neib = toburn.front();
			mat[neib.first][neib.second] = 'o';
			pilha.push_back(neib);
		}else{
			pilha.pop_back();
		}
	}
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector <string> mat(n);
    for (size_t i = 0; i < n; i++) {
        cin >> mat[i];
    }
    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        size_t l, c;
        cin >> l >> c;
        queimar(mat, l, c);
    }
    size_t s;
    cin >> s;
    size_t cont = 0;
    for (size_t i = 0; i < s; i++) {
        size_t l, c;
        cin >> l >> c;
        if(mat[l][c] == 'o')
            cont++;
    }
    cout << cont << endl;
    return 0;
}