#include <iostream>
using namespace std;
#define endl '\n'

//const int MAX = 10e9 + 1;
const int SQRT_MAX = 31625;

bool prime[SQRT_MAX + 1];

void dosieve(int till) {
    for(int i = 2; i <= till; i++) {
        if (!prime[i]) {
            continue;
        }
        for(int j = i * 2; j <= till; j += i) {
            prime[j] = false;
        }
    
    }
}

const int RANGESIZE = 100000;
bool nm_isprime[RANGESIZE];

int smallest_larger_than_multiple(int lowerbound, int base) {
    if (lowerbound % base == 0) {
        return lowerbound;
    }

    int n = lowerbound + base;
    int rem = n % base;
    return n - rem;

}

int main() {
    //clear the thing to say that none of these are primes
    memset(prime, 1, SQRT_MAX * sizeof(bool));
    for(int i = 0; i < RANGESIZE; i++) {
        nm_isprime[i] = true;
    }


    prime[1] = false;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    //roughly sqrt(10^9)
    dosieve(SQRT_MAX + 1);
    
    int m, n;
    cin>>n>>m;


    if (n == 1) {
        nm_isprime[0] = false;
    }

    for(int i = 2; i < SQRT_MAX && i < m; i++) {
        if(prime[i]) {
                int start = -1;
                if (i < n) {
                     start = smallest_larger_than_multiple(n, i);
                }else {
                    start = i * 2;
                }


                for(int j = start;
                        j <= m;
                        j += i) {

                    nm_isprime[j - n] = false;
                }
        }
    }

    for(int i = n; i < m; i++) {
        if (nm_isprime[i - n]) {
            cout<<i<<" ";
        }
    }

    return 0;

}
