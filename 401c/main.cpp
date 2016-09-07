//http://codeforces.com/problemset/problem/401/C
#include <iostream>
#include <assert.h>
#include <map>
using namespace std;
#define endl '\n'

//number of zeroes and ones

template<typename T>
void print_arr(T *arr, size_t len, const char *name="") {
    cout<<"\n"<<name<<"[";
    for(int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}

void print(int n0, int n1, int cons0, int cons1) {
    //cout<<"\nn0: "<<n0<<" |n1: "<<n1;
    assert(n1 <= (n0 + 1) * 2);
    assert(n0 <= n1 + 1);

    if (n0 == 0 &&  n1 == 0) {
        return;
    }

    if (n0 > n1) {
        cout<<0;
        print(n0 - 1, n1, 1, 0);
    } else if (n0 == n1) {
        if (cons0 == 1) {
            cout<<1<<0;
            print(n0 - 1, n1 - 1, 1, 0);
        }
        else {
            //assert(cons1 <= 1);
            cout<<0<<1;
            print(n0 - 1, n1 - 1, 0, 1);
        }
    } 
    else {
        if (cons1 == 2) {
            assert(n0 > 0);
            cout<<0;
            print(n0 - 1, n1, 1, 0);
        } else {
            cout<<1;
            print(n0, n1 - 1, 0, cons1 + 1);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n0, n1;
    cin>>n0>>n1;


    if(n1 > (n0 + 1) * 2 || (n0 > n1 + 1)) {
        cout<<-1;
        return 0;
    };
    
    print(n0, n1, 0, 0);
    return 0;
}
