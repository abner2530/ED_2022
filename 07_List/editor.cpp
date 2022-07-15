#include <iostream>
#include <list>
#include <sstream>

using namespace std;

struct Status {
    list<char> text;
    list<char>::iterator cursor;
    
    Status() { 
        cursor = text.end(); }

    Status(string str) {
        for(auto m : str)
            this->text.push_back(m);

        cursor = text.end();
    }

    Status(const Status& value): text(value.text) {
        this->cursor = this->text.begin();
        for(auto it = value.text.begin(); it != value.cursor; it++)
            this->cursor++;
    }

    string getText() {
        stringstream ss;
        for(auto it = text.begin(); it != text.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << *it;
        }

        if(cursor == text.end())
            ss << "|";

        return ss.str();
    }
};

struct Bloco_Notas {
    list<Status> estado;
    list<Status>::iterator itt;

    Bloco_Notas(string in_Text = "") {
        estado.push_back(Status(in_Text));
        itt = estado.begin();
    }

    void insert_C(char C) {
        auto prox = itt;
        estado.erase(++prox, estado.end());
        estado.push_back(*itt);
        itt = --estado.end();

        itt->text.insert(itt->cursor, C);
    }
    
    void espaco() {
        if(itt->cursor != itt->text.begin())
            itt->cursor = itt->text.erase(--itt->cursor);
    }

    void delet() {
        if(itt->cursor != itt->text.end())
            itt->cursor = itt->text.erase(itt->cursor);
    }

    void right() {
        if(itt->cursor != itt->text.end())
            itt->cursor++;
    }

    void left() {
        if(itt->cursor != itt->text.begin())
            itt->cursor--;
    }

};

void teclado(Bloco_Notas& bloco, char tecla) {
    if(tecla == 'R')
        bloco.insert_C('\n');
    else if(tecla == 'B')
        bloco.espaco();
    else if(tecla == 'D')
        bloco.delet();
    else if(tecla == '>')
        bloco.right();
    else if(tecla == '<')
        bloco.left();
    else
        bloco.insert_C(tecla);
}

int main() {
    string line;
    getline(cin, line);
    Bloco_Notas bloco;
    
    for(auto c : line)
        teclado(bloco, c);

    cout << bloco.itt->getText() << endl;

}