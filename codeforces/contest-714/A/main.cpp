#include <iostream>
using namespace std;
#define endl '\n'

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long l1, r1, l2, r2, k;
    cin>>l1>>r1>>l2>>r2>>k;

    long long begin_spend = max(l1, l2);
    long long end_spend = min(r1, r2);


    long long duration = end_spend - begin_spend + 1;

    if (k >= begin_spend && k <= end_spend) {
        duration -= 1;
    }

    if (duration <= 0) {
        cout<<0;
    } else {
        cout<<duration;
    }

    
    return 0;

}
