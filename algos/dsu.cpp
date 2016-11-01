#include <iostream>
#include <algorithm>
using namespace std;

static const int N = 1000;

int dsuparent[N];
int dsurank[N];

void initdsu() {
    for(int i = 0; i < N; i++) {
        dsuparent[i] = i;
    }
    fill(dsurank, dsurank+N, 0);
}

int find(int value) {
    //we haven't reached the fixed point root
    if (dsuparent[value] != value) {
        //my parent is my parent's parent
        dsuparent[value] = find(dsuparent[value]);
    }
    return dsuparent[value];
}


void dsuunion(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    
    if (xroot == yroot) {
        return;
    }

    if (dsurank[xroot] > dsurank[yroot]) {
        dsuparent[yroot] = dsuparent[xroot];
    }
    else if (dsurank[xroot] < dsurank[yroot]) {
        dsuparent[xroot] = dsuparent[yroot];
    } else {
        //connect x's parent to y's parent
        dsuparent[xroot] = yroot;
        dsurank[xroot] += 1;
    }

}
int main() {
    initdsu();

    const int SETSIZE = 8;
    for(int n = 0; n < SETSIZE * 2; n++) {
        int i = rand() % SETSIZE;
        int j = rand() % SETSIZE;
        
        printf("unioning %d %d\n", i, j);
        dsuunion(i, j);

        int k = rand() % SETSIZE;
        int l = rand() % SETSIZE;

        printf("%d and %d are in the same set: %s\n", k, l, find(k) == find(l) ? "TRUE" : "FALSE" );
    }
    return 0;
}
