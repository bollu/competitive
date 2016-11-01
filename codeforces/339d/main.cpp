#include <iostream>
using namespace std;
#define endl '\n'
const int N = 10e5 + 1;
int n;
int t[2  * N];

void build() {
    for(int i = n - 1; i > 0; i--) {
        t[i] = t[i<<1] + t[i<<1|1];
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;

}
