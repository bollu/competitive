#include <iostream>
#include <string>

using namespace std;

typedef string K_t;
typedef int V_t;

int hashkey(K_t k, int mod) {
    int h = 7;
    for(auto c : k) {
        h = h * 37 + (int)c;
        h = h % (1 << 31);
    }
    h = h % (1 << 31);
    h = h % mod;
    return h;

};

template<typename K, typename T,int N>
class Map {
    public:
    class Node {
        public:
        K key;
        T value;
        
        Node *next;
        Node(K key, T value) : key(key), value(value), next(NULL) {};
    };

    Node* hashtable[N];

    Map() {
        for(int i = 0; i < N; i++) {
            hashtable[i] = NULL;
        }
    }

    void add(K key, T value) {
        const int idx = hashkey(key, N);
        if (hashtable[idx] == NULL) {
            hashtable[idx] = new Node(key, value);
        } else {
            Node *n = hashtable[idx];
            while(n->next != NULL) {
                n = n->next;
            }
            n->next = new Node(key, value);
        }
    };

    bool search(K key, T& value)  {
        const int idx = hashkey(key, N);

        for(Node *n = hashtable[idx]; n != NULL; n = n->next) {
            if(n->key == key) {
                value = n->value;
                return true;
            }
        }
        return false;
    };

};





int main() {
    Map<K_t, V_t, (int)1e4> map;
    while(1) {
        char command;
        cout<<"command: (i)nsert, (s)earch, (e)nd: ";
        cin>>command;
        if (command == 'e') {
            return 0;
        }
        else if (command == 'i') {
            string key;
            int value;
            cout<<"key: ";
            cin>>key;
            cout<<"value: ";
            cin>>value;

            map.add(key, value);
        }
        else if (command == 's') {
            string key;
            int value;
            cout<<"key: ";
            cin>>key;

            bool success = map.search(key, value);

            if (success) {
                cout<<"found: "<<key<<" => "<<value<<"\n";
            } else {
                cout<<"not found: "<<key<<" => "<<"[]\n";
            }

        }
        else {
            cout<<"incorrect option";
        }
        cout<<"\n--\n";
    }
    return 0;
}
