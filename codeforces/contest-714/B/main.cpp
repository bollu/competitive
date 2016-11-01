//http://codeforces.com/contest/714/problem/B
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define endl '\n'

static const int N = 10e6 + 1;
typedef long long ll;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n; cin>>n;

    int xs[N];
    
    for(int i = 0; i < n; i++) {
        cin>>xs[i];
    }

    int n1 = -1, n2 = -1, n3 = -1;

    bool success = true;
    for(int i = 0; i < n; i++) {
        int cur = xs[i];

        if (n1 == -1) {
            n1 = cur;
        } else if (n2 == -1 && n1 != cur) {
            n2 = cur;
        } else if (n3 == -1 && n1 != cur && n2 != cur) {
            n3 = cur;   
        } else {
            if (n1 != cur && n2 != cur && n3 != cur)  {
                success  = false;
                break;
            }
        }
    }

    if (n1 == -1 || n2 == -1 || n3 == -1) {
        success = true;
    } else {
        int maxn = max(max(n1, n2), n3);
        int minn = min(min(n1, n2), n3);
        int midn = n1 + n2 - maxn + n3 - minn;

        if (abs(minn - midn) != abs(midn - maxn)) {
            success = false;
        }
    
    }

    if (success) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;

}
