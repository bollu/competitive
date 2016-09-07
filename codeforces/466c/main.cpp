//http://codeforces.com/problemset/problem/466/C
#include <iostream>
#include <assert.h>
#include <map>
using namespace std;
#define endl '\n'

// ~10^8 operations allowed for TLE

static const int MAX_LEN = 5 * 100000;

int n;
long as[MAX_LEN + 1];
long partial_sums[MAX_LEN + 1];
long reverse_partial_sums[MAX_LEN + 1];

long sum_23_ahead[MAX_LEN + 1];

long sum(int a, int b) {
    assert (a >= 0 && b >= 0);
    assert(a <= n && b <= n);
    assert(b >= a);

    return partial_sums[b] - partial_sums[a - 1];
}


template<typename T>
void print_arr(T *arr, size_t len, const char *name="") {
    cout<<"\n"<<name<<"[";
    for(int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i = 1; i <= n; i++) {
        cin>>as[i];
        partial_sums[i] = partial_sums[i - 1] + as[i];
    }
    partial_sums[n] = partial_sums[n - 1] + as[n];
    const long total = partial_sums[n];
    //cout<<"\ntotal: "<<total;

    reverse_partial_sums[n] = as[n];
    for(int i = n - 1; i >= 1; i--) {
        reverse_partial_sums[i] = reverse_partial_sums[i + 1] + as[i];
    }

    //print_arr(partial_sums, n + 1, "partial sums");

    sum_23_ahead[n] = 0;
    for(int i = n - 1; i >= 1; i--) {
        bool is_23 = partial_sums[i] * 3 == (total * 2);
        //cout<<"\nis_23: "<<partial_sums[i]<<" : "<<is_23;
        sum_23_ahead[i] = sum_23_ahead[i + 1] + (is_23 ? 1 : 0);
    }

    //print_arr(sum_23_ahead, n + 1, "sum 2/3 ahead");



    long long count = 0;
    for(int i = 1; i <= n - 2; i++) {
        if (partial_sums[i] * 3 == total) {
            count += sum_23_ahead[i + 1];
        }
    }
    cout<<count;
    return 0;
}
