#include <iostream>
#include <assert.h>
using namespace std;
//REFERENCE IMPL: https://crypto.stanford.edu/pbc/notes/numbertheory/millerrabin.html

template<typename T>
void decompose_even_odd(T n, T &even, T &odd) {
    even = 0;
    while(n % 2 == 0) {
        even += 1;
        n = n / 2;
    }
    odd = n;
}


/*
template<typename T>
T powmod(T base, const T exp, const T mod) {
    //cout<<base<<"^"<<exp<<" (mod"<<mod<<")\n";
    T val = 1;
    base %= mod;
    for(int i = 0; i < exp; i++) {
        val = val * base;
        val = val % mod;
        //cout<<"\te: "<<val<<"\n";
    }

    return val;
}
*/


template<typename T>
T powmod(T base, const T exp, const T mod) {
    base = base % mod;
    
    if (exp == 0) {
        return 1;
    }
    else if (exp == 1) {
        return base;
    }

    T basesq = (base * base) % mod;

    if (exp % 2 == 0) {
        return powmod(basesq, exp / 2, mod) % mod;
    }
    else {
        //exp = 2e + 1;
        //base^(2e + 1) = (base^2e).base = (base^2)^e.base
        return (powmod(basesq, exp / 2, mod) * base) % mod;
    }
}

// implementation of milner-rabin
template<typename T>
bool rabin(T n, T x) {
    if (n == 1) { return false; }
    if (n == 2) { return true; }

    if (n % 2 == 0) { return false; }

    //get largest power of 2 that divides it
    //(n - 1) =  2^e * o
    T e, o;
    decompose_even_odd(n - 1, e, o);
    //cerr<<n - 1<<" has even: "<<e<<" | odd: "<<o<<"\n";

    //let x \in [1, n - 1]
    //T x = 1 + (rand() % (n - 1));
    assert(x >= 1 && x <= n - 1);

    //cerr<<"random:"<<x<<"\n";

    // n - 1 = 2^e.o
    // check all 2^(e - 1)o, 2^(e - 2)o, ... till o
    // we have already check 2^e.o which was (n - 1)
    T xpow = powmod(x, o, n);
    //cerr<<x<<"^"<<o<<" % "<<n<<" = "<<xpow<<"\n";
    
    //we know that the nth root came out to be 1,
    //so we must have started with 1
    if (xpow == 1) {
        return true;
    }
    else {
        //x^(2^i.t) % n == -1 for some i in [i , e]
        //i = 1 : x^t
        //i = 2 : x^2t
        //i = 4 : x^4t
        for(int i = 0; i <= e - 1 ; i++) {
            //v this works fo sho
            //xpow = powmod(x, (1 << i) * o, n);
            
            //cerr<<x<<"^(2^"<<i<<"."<<o<<")"<<" = "<<xpow<<"\n";

            if (xpow == n - 1) { //n - 1 <==> -1 (mod n)
                return true; //is a prime
            }

            xpow = (xpow * xpow) % n;
        }
        return false;
    }
    assert (false && "never reach here");

}

template<typename T>
bool isprime(T n) {
    if (n == 2) return true;
    if (n == 1) return false;


    //4 works till 3,215,031,751 > 10^9
    static const int NPRIMES = 4;
    T primes[7] = {2, 3, 5, 7, 11, 13, 17};
    
    for(T i = 0; i < NPRIMES; i++) {
        if (n > primes[i]) {
            if (!rabin(n, primes[i])) {
                return false;
            }
        } else {
            break;
        }
    }

    return true;
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    for(long long i = 1; i <= 1e9; i++) {
        if (isprime(i)) {
            cout<<i<<"\n";
        }
    }
}
