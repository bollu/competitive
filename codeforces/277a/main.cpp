//http://codeforces.com/problemset/problem/277/A

#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

const int V = 200;

//adjacency
vector<int> adj[100];
int visited[V];


void dfs(int v) {
    if (visited[v]) { return; }
    
    visited[v] = true;
    for(auto nv : adj[v]) {
        dfs(nv);

    }
}


void printadj(int n) {
    for(int i = 0; i < n; i++) {
        cerr<<i<<" => ";
        for(auto it : adj[i]) {
            cerr<<it<<" ";
        }
        cerr<<"\n";
    }
}
int main() {
    for(int i = 0; i < 100; i++) {
        visited[i] = false;
    }

    
    int ls, es;
    cin>>es>>ls;

    for(int e = 0; e <  es; e++) {
        int langs; cin>>langs;
        for(int j = 0; j < langs; j++) {
            int l; cin>>l; l -= 1;
            adj[e].push_back(es + l);
            adj[es + l].push_back(e);
        }
    }


    printadj(ls + es);

    cerr<<"computing numcc\n";

    
    int numcc = 0;
    for(int i = 0; i < es + ls; i++) {
        if (!visited[i])  {
            //it's a language - we don't need to care about empty languages
            if (i >= es && adj[i].empty()) {
                visited[i] = true;
                continue;
            
            } else {
                numcc++;
                dfs(i);
                cerr<<i<<" not visited\n";
            }
        }
    }

    cout<<numcc - 1;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;

}
