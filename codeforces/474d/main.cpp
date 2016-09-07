//http://codeforces.com/problemset/problem/474/D
//Flowers

#include <iostream>
using namespace std;
#define endl '\n'

typedef long long num;

static const num MODULO = 1000000007;
static const num MAX_I = 100000 + 1;


num lens[MAX_I];
num accum[MAX_I];

void fill_dp(num k) {
    for (num i = 0; i <= k; i++) {
        lens[i] = 1;
    }
    for(num i = k; i < MAX_I; i++) {
        lens[i] = (lens[i - 1] + lens[i - k]) % MODULO;
    }

    accum[0] = 0;
    for(num i = 1; i < MAX_I; i++) {
        accum[i] = (accum[i - 1] + lens[i]) % MODULO;
    }
}

void test(num k, num a, num b) {
    num total = (MODULO + accum[b] - accum[a - 1]) % MODULO;
    cout<<total<<endl;
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    num t, k; cin>>t>>k;
    fill_dp(k);
    num a, b;

    while(t--) {
        cin>>a>>b;
        test(k, a, b);
    }
    return 0;

}
