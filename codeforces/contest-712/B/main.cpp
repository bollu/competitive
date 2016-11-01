#include <iostream>
using namespace std;
#define endl '\n'

static const int SLEN = 10e5 + 1;
char s[SLEN];


int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    
    int ups = 0, lefts = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'U') {
            ups++;
        }
        else if (s[i] == 'D') {
            ups--;
        }
        else if (s[i] == 'L') {
            lefts++;
        }
        else if (s[i] == 'R') {
            lefts--;
        }
    }
    ups = abs(ups);
    lefts = abs(lefts);

    if ((ups + lefts) % 2 != 0) {
        cout<<-1;
    } else {
        cout<<(ups + lefts) / 2;
    }
    
    return 0;

}
