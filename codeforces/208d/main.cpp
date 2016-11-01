//http://codeforces.com/problemset/problem/208/D
//D. Prizes, Prizes, more Prizes


#include <iostream>
using namespace std;
#define endl '\n'


static const int MAX_POINTS = 51;


int points[MAX_POINTS];

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;


    for(int i = 0; i < n; i++) {
        cin>>points[i];
    }
    int costs[5];

    for(int i = 0; i < 5; i++) {
        cin>>costs[i];
    }

    long long counts[5] = {0,0,0,0,0};

    
    long long cur = 0;
    for(int i = 0;  i < n; i++) {
        cur += points[i];

        for(int j = 4; j >=0; j--) {
            int num = cur / costs[j];
            counts[j] += num;

            cur -= num * costs[j];
        }
    
    }


    for(int i = 0; i < 5; i++) {
        cout<<counts[i]<<" ";
    }
    cout<<"\n"<<cur;


    
    return 0;

}
