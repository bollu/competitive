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


int withindist(int i, int j, int n, int m, int d, int D) {
    return (abs(i - j) % n) < d;
}

void printedge(int i, int j) {
    cout<<i + 1<<" "<<j + 1<<"\n";
}

bool ispaired(int i, int j, int n, int m, int d, int D) {
    int pairs_per_node = (D - d) / n;
    int pairsleftover = (D - d) - pairs_per_node * n;

    int mintill = n * d;
    int pairedtill = 0;

    cout<<"i: "<<i<<"j: "<<j<<" | ppn: "<<pairs_per_node<<" | plo: "<<pairsleftover<<"\n";
    if (!withindist(i, j, n, m, d, D)) {
        pairedtill = i * pairs_per_node;
    }

    // cerr<<"i:"<<i<<" | j:"<<j<<" | mintill:"<<mintill<<" | pairedtill:"<<pairedtill<<"\n";
    if (mintill + pairedtill >= m) {
        return false;
    }
    return true;
}

void run() {
    int n, m, d, D;
    cin>>n>>m>>d>>D;

   
    if (m < n * d || m > n * D) {
        cout<<-1<<"\n";
    }
    else {
        int curm = m;
        //add all the usual edges i <-> [i, (i + d) % n)
        curm -= d * n;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < d; j++) {
                printedge(i, (i + j) % n);
                
            }
        }

        int connects[100];
        for(int i = 0; i < n; i++) {
            connects[i] = (i + d) % n;
        }
        
        //6 27 3 5
        //leftover: 27 - 3 * 6 = 9
        //pernode = 
        
        const int leftover  = m - n * d;
        const int pernode = leftover / n;
        const int extra = leftover - pernode * n;
       // cout<<"EXTRA: "<<extra<<"\n";

        
        for(int i = 0; i < n; i++) {
            const int leftover_begin_index = (i + d) % n;
            
            //per node leftover distribution
            for(int e = 0; e < pernode; e++) {
                printedge(i, (leftover_begin_index + e) % n);
            }
        }
        
        //give extra edges         
        for(int i = 0; i < extra; i++) {
            const int leftover_begin_index = (i + d) % n;
          
            printedge(i, (leftover_begin_index + pernode + 1) % n);
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