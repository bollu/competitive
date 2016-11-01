#include <assert.h>
#include <utility>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <bitset>
using namespace std;
#define endl '\n'

typedef unsigned long  long ll;
typedef unsigned long long P;
static const int MAX_PARITY_LEN = 20;

unordered_map<P, int> counts;

void add_parities(P p) {
    P prev = p;
    counts[prev]++;

    for(int i = 0; i < MAX_PARITY_LEN - 1; i++) {
        p ^= 1 << (MAX_PARITY_LEN - 1 - i);
        if (p != prev) {
            counts[p]++;
            prev = p;
        }
    }
}


void remove_parities(P p) {
    P prev = p;
    counts[prev]--;
    for(int i = 0; i < MAX_PARITY_LEN - 1; i++) {
        //remove the bit at the MAX_PARITY_LEN position
        p ^= 1 << (MAX_PARITY_LEN - 1 - i);
        if (p != prev) {
            counts[p]--;
            prev = p;
        }
    }
}
P num_to_parity(ll n) {
    P p = 0;
    int pos = 0;
    while(n != 0) {
        int digit = n % 10;
        p |= ((digit % 2) << pos);

        pos++;
        n = n / 10;
    }

    return p;
}

/*
   void num_to_parity_str(int parity[PARITY_LEN], ll num) {
   for(int i = 0; i < PARITY_LEN; i++) {
   parity[i] = 0; 
   }

   for(int i = PARITY_LEN - 1; i >= 0 && num != 0; i--) {
   parity[i] = (num % 10) % 2;
   num = num / 10;
   }
   }

   void string_to_parity_arr(int parity[PARITY_LEN], string str) {
   for(int i = 0; i < PARITY_LEN; i++) {
   parity[i] = 0; 
   }

   for(int i = PARITY_LEN - 1, j = str.length() - 1; j >= 0; j--, i--) {
   parity[i] = str[j] - '0';
   }
   }
   */

    /*
       bool parity_equal(int p1[PARITY_LEN], int p2[PARITY_LEN]) {
       for(int i = 0; i < PARITY_LEN; i++) {
       if (p1[i] != p2[i]) {
       return false;
       }
       }
       return true;
       }*/

        template<typename T>
        void print_arr(T*arr, int len) {
            cout<<"[";
            for(int i = 0; i < len; i++) {
                cout<<arr[i]<<(i > 0 ? " " : "");
            }
            cout<<"]";
        }


int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    string n_str;
    getline(cin, n_str);
    n = atoi(n_str.c_str());

    while(n--) {
        string query;
        getline(cin, query);


        if (query[0] == '+') {

            long long number = atoll(query.c_str() + 2);
            add_parities(num_to_parity(number));


        } 
        else if (query[0] == '-') {
            long long number = atoll(query.c_str() + 2);
            remove_parities(num_to_parity(number));
        }
        else if (query[0] == '?') {
            long long number = atoll(query.c_str() + 2);

            P wantedp = num_to_parity(number);
            int total = 0;

            auto it = counts.find(wantedp);

            if (it == counts.end()) {
                total = 0;
            } else {
                total = it->second;
            }

            cout<<total<<endl;

        } else {
            assert(false && "should not reach here");
        }
    }


    return 0;

}
