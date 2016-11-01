#include <iostream>
using namespace std;
#define endl '\n'

static const int NUM_A = 1e6 + 2;

int a[NUM_A];
int b[NUM_A];
int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }


    b[n] = a[n];
    for(int i = n - 1; i >= 0; i--) {
        b[i] = a[i] + a[i + 1];
    }
    

    for(int i = 1; i <= n; i++) {
        cout<<b[i]<<" ";
    }
    return 0;

}
