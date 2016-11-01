#include <iostream>
using namespace std;
#define endl '\n'

static const int T = 100;
static const int K = 1000;
//const int MODULO = 10e9 + 7;

static const total_max_score = 2 * K * T;

//dp[i][t] = number of ways to get i score in t'th turn
int dp[total_max_score + 1][T + 1];

void partitiongs(){

}



int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, l,k,t;
    cin>>m>>l>>k>>t;
        
    partitions();
    

    cout<<"lower: " <<l - m<<"upper: "<<2 * k * t<<" | t: "<<t<<endl;

    int total = 0;

    int lower = max(m - l + 1, -2 * k * t);
    int upper = 2 * k * t;
    for(int i = lower; i <= upper; i++) {
        total += total_count[i];
    }
    cout<<"total: "<<total;


    return 0;

}
