#include <assert.h>
#include <iostream>
using namespace std;
#define endl '\n'

typedef unsigned long long ull;
int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;


    ull x = 2;
    for(ull k = 1; k <= n; k++) {
        //cout<<"x: "<<x<<" | k: "<<k <<" | ";
        ull target = k * k * (k + 1) * (k + 1);

        //ull nadds = (target - x) / k;
        ull nadds = k * (k + 1) * (k + 1) - x / k;

        //cout<<"x: "<<x<<" | nadds: "<<nadds<<" k : "<<k<<" | target: "<<target;
        assert(x + nadds * k == target);

        x = k * (k + 1);
        //cout<<"x': "<<x * x<<" | ";
        cout<<nadds<<"\n";
    
    }
    
    return 0;
}
