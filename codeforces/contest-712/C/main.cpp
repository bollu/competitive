#include <iostream>
#include <assert.h>
using namespace std;
#define endl '\n'

typedef struct Tri {
    int side[3];
} Tri;


Tri inc_sides_to(Tri t, int target) {
    int newsides[3];

    for(int i = 0; i < 3; i++) {
        newsides[i] = t.side[(i + 1) % 3] + t.side[(i + 2) % 3] - 1;
    }


    int maxi = -1; int maxside = -1;
    for(int i = 0; i < 3; i++) {
        if (t.side[i] != target) {
            maxi = newsides[i] > maxside ? i : maxi;
            maxside = newsides[i] > maxside  ? newsides[i] : maxside;
        }
    }

    assert(maxi != -1);

    maxside = maxside > target ?  target : maxside;

    t.side[maxi] = maxside;
    return t;
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i, f;
    cin>>i>>f;


    Tri t;
    t.side[0] = t.side[1] = t.side[2] = f;

    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 3; j++) {
            if(t.side[i] < t.side[j])  {
                int temp = t.side[i];
                t.side[i] = t.side[j];
                t.side[j] = temp;
            }
        }
    }


    int count = 0;
    while(true) {
        //cout<<"\n("<<t.side[0]<<" "<<t.side[1]<<" "<<t.side[2]<<")"<<endl;
        t = inc_sides_to(t, i);
 
        count++;
        if (t.side[0] == i && 
            t.side[1] == i &&
            t.side[2] == i) {
           break; 
        }
    }
    cout<<count;
    
    return 0;
}
