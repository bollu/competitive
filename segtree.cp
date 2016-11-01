//min segtree
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000
#define pb push_back
#define endl '\n'

//Make it long long int instead of node if you are using Range Query point update instead of range query range update
struct node
{
	ll pre, lazy;
};

node segtree[400004];
int N = 100000, n;

//Point update
void setv(int pos, int val, int node = 1, int x = 0, int y = N)
{
	if(pos >= y || pos < x) return;
	if(y-1 == x)
	{
		segtree[node].pre = val;
		return;
	}
	setv(pos, val, 2*node, x, (x+y)/2);
	setv(pos, val, 2*node+1, (x+y)/2, y);
	segtree[node].pre = min(segtree[2*node].pre, segtree[2*node+1].pre);
}

//Range Update (lazy)
void update(int l, int val, int r = n, int node = 1, int x = 0, int y = N)
{
	if(l >= y || r <= x) return;
	if(l <= x && r >= y) 
	{
		segtree[node].lazy += val;
		return;
	}
	update(l, val, r, 2*node, x, (x+y)/2);
	update(l, val, r, 2*node+1, (x+y)/2, y);
	segtree[node].pre = min(segtree[2*node].pre + segtree[2*node].lazy, segtree[2*node+1].pre + segtree[2*node+1].lazy);
}

//Range Query with Point update
int query(int l, int r, int node = 1, int x = 0, int y = N)
{
	if(l >=y || r <= x) return INF;
	if(l <= x && r >= y) return segtree[node].pre;
	return min(query(l,r,2*node, x, (x+y)/2), query(l,r,2*node+1, (x+y)/2, y));
}

//Range Query with Range update
int query(int l, int r, int node = 1, int x = 0, int y = N)
{
	if(l >=y || r <= x) return INF;
	if(l <= x && r >= y) return segtree[node].pre + segtree[node].lazy;
	segtree[2*node].lazy += segtree[node].lazy;
	segtree[2*node+1].lazy += segtree[node].lazy;
	segtree[node].pre += segtree[node].lazy;
	segtree[node].lazy = 0;
	return min(query(l,r,2*node, x, (x+y)/2), query(l,r,2*node+1, (x+y)/2, y));
}

int main()
{
	ios_base::sync_with_stdio(false);

	return 0;
}
