#include <iostream>

using namespace std;

struct Amt {
    int percake;
    int cur;
};


int main() {
    Amt as[4];

    while(1) {
        for(int i = 0; i < 4; i++) {
            cin>>as[i].cur;
        }
    
        //break
        if (as[0].cur == -1) {
            return 0;
        }

        for(int i = 0;i < 4; i++) {
            cin>>as[i].percake;
        }

        int canmake[4];
        for(int i = 0; i < 4; i++) {
            canmake[i] = as[i].cur / as[i].percake;
        }

        int maxcanmake = canmake[0];
        for(int i = 1; i < 4; i++) {
            maxcanmake = max(maxcanmake, canmake[i]);
        }

        int needed[4];
        for(int i = 0; i < 4; i++) {
            needed[i] = as[i].percake * maxcanmake - as[i].cur;
        }

        for(int i = 0; i < 4; i++) {
            cout<<needed[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
