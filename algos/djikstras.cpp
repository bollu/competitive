#include "limits.h"
#include <iostream>
using namespace std;
#include <queue>
#include <set>
#define endl '\n'
#include <assert.h>

static const int V = 10000 + 1;

typedef int Ix;
typedef int Wt;

typedef vector<pair<Ix, Wt> > Adj;
void addedge(Adj adj[V], Ix source, Ix dest, Wt weight) {
    adj[source].push_back(std::make_pair(dest, weight));

}

struct SrcDist {
    Ix v;
    Wt dist;
    SrcDist(Ix v, Wt dist) : v(v), dist(dist) {
        assert(v >= 0 && v < V);
        assert(dist >= 0);
    }

    bool operator < (const SrcDist &b) const {
        //need to break tie for std::set since it compares using
        //!(a < b) && !(b < a)
        //so if two edges have the same weight, break tie
        //using vertex
        if (dist == b.dist) {
            return v < b.v;
        }
        return  dist < b.dist ;
    }
};



vector<Wt> djikstras(Adj adj[V], const int v, const int begin, const int end) {
   set<SrcDist> unexplored;
   vector<Wt> bestdist(v, INT_MAX);

   for(int i = 0; i < v; i++) {
        bestdist[i] = i == begin ? 0 : INT_MAX;
        unexplored.insert(SrcDist(i, bestdist[i]));
   }

   while(unexplored.size() > 0) {
       SrcDist smallest = *unexplored.begin();
       unexplored.erase(smallest);
       //cerr<<"smallest: "<<smallest.v<<" | wt: "<<smallest.dist<<"\n";

       if (smallest.dist == INT_MAX) {
            break;
       }

        //go through edges of smallest thing in set
       for(auto edge : adj[smallest.v]) {

           const int distfromsmallest = bestdist[smallest.v] + edge.second;
           if (bestdist[edge.first] > distfromsmallest) {

               unexplored.erase(SrcDist(edge.first, bestdist[edge.first]));
               //update distance to be better
               bestdist[edge.first] = distfromsmallest;
               unexplored.insert(SrcDist(edge.first, bestdist[edge.first]));
           }
       }
   }

   return bestdist;
};

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;

    while(t--)  {
        vector<pair<int, int> > adj[V];

        int v, e;
        cin>>v>>e;

        for(int i = 0; i < e; i++) {
            int src,dest,weight;
            cin>>src>>dest>>weight;
            addedge(adj, src, dest, weight);
        }

        int A, B;
        cin>>A>>B;
        vector<Wt>  shortest = djikstras(adj, v + 1, A, B);
        if (shortest[B] == INT_MAX) {
            cout<<"NO"<<"\n";
        } else {
            cout<<shortest[B]<<"\n";
        }
        
    }
    return 0;

}
