#include<bits/stdc++.h>
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
const int INF = 1<<29;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    return 0;
}

