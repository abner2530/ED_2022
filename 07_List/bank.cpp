#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

struct Client {
    string name {""};
    int docs {0};
    int patience { 0 };

    Client(string name, int docs, int patience): 
        name(name), docs(docs), patience(patience) {}

    string str() {
        return name + ":" + to_string(docs) + ":" + to_string(patience); 
    }
};

string formato(auto dado, string abre = "[", string fecha = "]", string sep = ", ") {
    ostringstream ss;
    ss << abre;
    for (auto it = dado.begin(); it != dado.end(); ++it)
        ss << (it != dado.begin() ? sep : "") << *it;
    ss << fecha;
    return ss.str();
}

ostream& operator<<(ostream& os, Client* client) {
    return os << client->str();
}

struct Bank {
    vector<Client*> tellers;
    list<Client*> queue_in;
    list<Client*> queue_out;
    int docs_gain {0};     
    int docs_lost {0};
    int tics {0};           

    void tic() {
        tics++;
        empty_queue_out();
        for (int i = 0; i < (int) tellers.size(); i++)
            process_teller(i);
        decrease_patience();
    }

    Bank(int teller_size) { 
        tellers = vector<Client*>(teller_size);
     }

    ~Bank() { 
        for (auto client : queue_in)
            delete client;
        for (auto client : tellers)
            delete client;
        for (auto client : queue_out)
            delete client;
    }

    void insere(string name, int docs, int patience) { 
        queue_in.push_back(new Client(name, docs, patience));
     }

    //Confere se não tem gente no banco
    bool empty() { 
        if(queue_in.empty()) {
            return true;
        }    

        return false;
     }

    void empty_queue_out() { 
        for (auto * client : queue_out) {
            this->docs_lost += client->docs;
            delete client;
        }

        queue_out.clear();
     }

    void process_teller(int index) { 
        auto& teller = tellers[index];
        if (teller != nullptr) {
            if (teller->docs > 0) {
                teller->docs -= 1;
                this->docs_gain += 1;
            } else {
                queue_out.push_back(teller);
                teller = nullptr;
            }
        } else {
            if (queue_in.size() > 0) {
                teller = queue_in.front(); 
                queue_in.pop_front();
            }
        }
    }

    void decrease_patience() { 
        for (auto it = queue_in.begin(); it != queue_in.end(); ) {
            if ((*it)->patience > 0) {
                (*it)->patience -= 1;
                it++;
            } else {
                queue_out.push_back(*it);
                it = queue_in.erase(it);
            }
        }
    }

    void finish() {
        while (!this->empty())
            tic();
     }

    string str() {
        stringstream ss;
        for (auto client : tellers)
            ss << "[" << (client == nullptr ? "" : client->str()) << "]";
        ss << "\nfila_in  :" << formato(queue_in, "{", "}", " ");
        ss << "\nfila_exit :" << formato(queue_out,  "{", "}", " ");
        ss << "\ndoc_gain:" << docs_gain << " doc_lost:" << docs_lost;
        return ss.str();
     }
};

ostream& operator<<(ostream& os, Bank& bank) {
    return os << bank.str();
}

int main() {
    Bank banco(3);

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end") {
            break;
        }else if (cmd == "show") {
            cout << banco.str() << "\n";
        } else if (cmd == "in") {
            string name { };
            int docs { }, patience { };
            ss >> name >> docs >> patience;
            banco.insere(name, docs, patience);
        } else if (cmd == "init") {
            int size { };
            ss >> size;
            banco = Bank(size);
        } else if (cmd == "tic") {
            banco.tic();
        } else if (cmd == "finish") {
            banco.finish();
        } else {
            cout << "fail: command not found\n";
        }
    }
}