#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <assert.h>

/*
ID: arun.ga1
LANG: C++
TASK: 
 */

using namespace std;

#define prime 1000000007
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
// static const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

/////////////////////////////////////////////////////////////////////

void quick_sort (int *a, int n,int *b) 
{
    int i,j,p,t;
    if(n<2)
    {
        return;
    }
    p=a[n/2];
    for(i=0,j=n-1;;i++,j--)
    {
        while(a[i]<p)
        {
            i++;
        }
        while(p<a[j])
        {
            j--;
        }
        if(i>=j)
        {
            break;
        }
        t=a[i];
        a[i]=a[j];
        a[j]=t;

        t=b[i];
        b[i]=b[j];
        b[j]=t;
    }
    quick_sort(a,i,b);
    quick_sort(a+i,n-i,b+i);
}


void run() {
    int n, m, d, D;
    cin>>n>>m>>d>>D;

    int adj[100][100];

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            adj[i][j] = 0;
        }
    }

    int nadjl[100];
    int nadjr[100];

    for(int i = 0; i < m; i++) {
        nadjl[i] = nadjr[i] = 0;
    }

    if (m < d * n || m > D * n) {
        cout<<-1<<"\n";
    }
    else {
        int curm = m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nadjl[i] < d && nadjr[j] < d && !adj[i][j]) {
                    curm--;
                    adj[i][j] = 1;
                    nadjl[i]++;
                    nadjr[j]++;
                }
            }
        }

        while(curm > 0) {
            for(int i = 0; i < n; i++)  {
                for(int j = 0; j < n; j++) {
                    if(nadjl[i] < D && nadjr[j] < D && !adj[i][j]) {
                        curm--;
                        adj[i][j] = 1;
                        nadjl[i]++;
                        nadjr[j]++;
                    }       

                    if (curm == 0) {
                        break;
                    }

                }
                if (curm == 0) {
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j]) {
                    cout<<i + 1<<" "<<j + 1<<"\n";
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);


    int t;
    cin>>t;
    while(t--) {
        run();
    }

    return 0;
}

