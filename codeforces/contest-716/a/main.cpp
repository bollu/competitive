#include <iostream>
using namespace std;
#define endl '\n'

const int N = 10e6 + 1;

int main() {
    int n, c;
    cin>>n>>c;
    
    int times[N];

    for(int i = 0; i < n; i++) {
        cin>>times[i];
    }

    
    int total_count = 1;
    for(int i = 1; i < n; i++) {
        int delta = times[i] - times[i - 1];
        if (delta > c) {
            total_count = 1;
        } else {
            total_count++;
        }
    }

    cout<<total_count;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;

}
