#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <algorithm>

using namespace std;

static const int V = 10;

typedef int Ix;
typedef int Wt;

//djikstras 
typedef pair<Ix, Wt> Edge;
typedef vector<Edge> VertexEdges;

//debug print
void printpath(vector<Ix> path) {
    cerr<<"|";
    for(int i = 0; i < path.size(); i++) {
        cerr<<path[i]<<(i < path.size() -1 ? " -> " : "");
    }
    cerr<<"|\n";
}
void printedge(int source, Edge e) {
   cerr<<source<<"--("<<e.second<<")--"<<e.first<<"\n";
}

//edge stuff

void printgraph(VertexEdges edges[V], int v) {
    for(int i = 0; i < v; i++) {
        cerr<<"\nedges from "<<i<<":\n";
        for(auto e: edges[i]) {
            cerr<<"\n\t";
            printedge(i, e);
        }
    }
}

void addedge(VertexEdges edges[V], Ix source, Ix dest, Wt weight) {
    const Edge e = std::make_pair(dest, weight);
    cerr<<"adding edge: ";
    printedge(source, e);

    edges[source].push_back(e);

}

int getcap(const VertexEdges capacities[V], int source, int dest) {
    for(Edge e : capacities[source]) {
        if (e.first == dest) {
            return e.second;
        }
    }
    //edge does not exist, return 0
    return 0;
}


void deledge(VertexEdges edges[V], int source, int dest) {
    auto it = edges[source].begin();

    while(it != edges[source].end()) {
        if (it->first == dest) {
            break;
        }
        it++;
    }

    assert(it != edges[source].end());

    edges[source].erase(it);
}

void setcap(VertexEdges capacities[V], int source, int dest, Wt cap) {
    assert (cap >= 0);

    if (cap == 0) {
        deledge(capacities, source, dest);
    }
    else {
        for (auto it = capacities[source].begin();
                it != capacities[source].end(); ++it) {
            if (it->first == dest) {
                cerr<<"setting capacity to: "<<cap<<" for: ";
                printedge(source, (*it));
                it->second = cap;
                return;
            }
        }
        //no such edge exists, add said edge
        addedge(capacities, source, dest, cap);
    }
}


struct SrcDist {
    Ix v;
    Wt dist;
    SrcDist(Ix vertex, Wt dist) : v(vertex), dist(dist) {
        assert(v >= 0 && v < V);
        assert(dist >= 0);
    }


    bool operator < (const SrcDist &b) const {
        if (dist == b.dist) {
            return v < b.v;
        }
        return  dist < b.dist ;
    }
};



void print_unexplored(const int begin, 
                      const set<SrcDist> &unexplored) {
    cerr<<"** UNEXPLORED: **\n";
    for(auto it: unexplored) {
        cerr<<"\t"<<begin<<"===("<<it.dist<<")=="<<it.v<<"\n";
    }
    cerr<<"***\n";
}
vector<Wt> djikstras(const VertexEdges edges[V], const int v, const int begin, const int end, 
        vector<Ix> *shortest) {
    set<SrcDist> unexplored;
    vector<Wt> bestdist(v, INT_MAX);

    //send parents to -1
    vector<Ix> *parent;
    if (shortest != NULL) {
        parent = new vector<Ix>(v, -1);
    }

    for(int i = 0; i < v; i++) {
        bestdist[i] = i == begin ? 0 : INT_MAX;
        unexplored.insert(SrcDist(i, bestdist[i]));
        //print_unexplored(begin, unexplored);
    }


    while(unexplored.size() > 0) {
        SrcDist smallest = *unexplored.begin();

        if (smallest.dist == INT_MAX) {
            break;
        }

        unexplored.erase(smallest);

        //go through edges of smallest thing in set
        for(auto edge : edges[smallest.v]) {

            const int eweight = edge.second;
            const int distfromsmallest = smallest.dist + eweight;

            //cerr<<"\n\t new edge:\n";
            //cerr<<"\t"<<begin<<"--("<<bestdist[edge.first]<<")-->"<<edge.first<<"\n";
            //cerr<<"\t"<<begin<<"--("<<smallest.dist<<")-->"<<smallest.v<<"--("<<eweight<<")-->"<<edge.first<<"\n";

            if (bestdist[edge.first] > distfromsmallest) {
                //cerr<<"\tpicked new edge: ";
                //cerr<<" "<<begin<<"--("<<smallest.dist<<")-->"<<smallest.v<<"--("<<eweight<<")-->"<<edge.first<<"\n";

                unexplored.erase(SrcDist(edge.first, bestdist[edge.first]));
                //update distance to be better
                bestdist[edge.first] = distfromsmallest;
                if (parent != NULL) {
                    (*parent)[edge.first] = smallest.v;
                }


                unexplored.insert(SrcDist(edge.first, bestdist[edge.first]));
            }

            //print_unexplored(begin, unexplored);
        }
    }


    if (shortest != NULL) {
        /*
        for(int i = 0; i < parent->size(); i++) {
            cerr<<i<<"->parent = "<<(*parent)[i]<<"\n";
        }
        */

        shortest->clear();
        int i = end;
        while((*parent)[i] != -1) {
            shortest->push_back(i);
            i = (*parent)[i];
        }
        if (i == begin) {
            shortest->push_back(i);
        }


        reverse(shortest->begin(), shortest->end());
    }

    return bestdist;
};


// actual flow

void initflow(int v, VertexEdges edges[V], VertexEdges capacities[V]) {
    for(int i = 0; i < v; i++) {
        capacities[i].clear();
        for(auto e : edges[i]) {
            capacities[i].push_back(e);
        }
    }
}

int iterateflow(const int v, const int src, 
                const int sink,
                VertexEdges capacities[V]) {

    vector<Ix> augmentpath;
    int totalflow = 0;
    
    while(1) {
        printgraph(capacities, v);
        getchar();
    
        //find an augmenting path over the capacities
        djikstras(capacities, v, src, sink, &augmentpath);

        cerr<<"found augmenting path: ";
        printpath(augmentpath);
            
        //no shortest path found, quit
        if (augmentpath.size() == 0) {
            return totalflow;   
        }

        //have shortest path, find channel capacity
        int flow = INT_MAX;
        {
            auto augmentit = augmentpath.begin();
            while (augmentit + 1 != augmentpath.end()) {
                const int cur = *augmentit;
                const int next = *(augmentit + 1);

                const int cap = getcap(capacities, cur, next);
                flow = min(flow, cap);
                augmentit++;
            }
        }

        if (flow == 0) {
            return totalflow;
        }


        cerr<<"sending flow: "<<flow<<"\n";
        
        //adjust capacities
        {
            auto augmentit = augmentpath.begin();
            while(augmentit + 1 != augmentpath.end()) {
                const int cur = *augmentit;
                const int next = *(augmentit + 1);

                const int fwdcap = getcap(capacities, cur, next);
                setcap(capacities, cur, next, fwdcap - flow);

                const int backcap = getcap(capacities, next, cur);
                setcap(capacities, next, cur, backcap + flow);

                augmentit++;


            }
        }
        //PUSH FLOW
        totalflow += flow;

    }

    assert (false && "should never reach here!");

}


int main() {
    VertexEdges edges[V];

    /*
    /-(10)--->1--->(5)->3
    0                   ^
    \--(10)-->2-->(3)---/
    */
    addedge(edges, 0, 1, 10);
    addedge(edges, 0, 2, 10);
    addedge(edges, 2, 3, 3);
    addedge(edges, 1, 3, 5);


    const int v = 4;
    const int source = 0;
    const int sink = 3;

    vector<Ix> shortest;
    vector<Wt> dist = djikstras(edges, v, source, sink, &shortest);
    cout<<"DJIKSTRAS DISTANCES FROM |"<<source<<"|: \n";
    for(int i = 0; i < dist.size(); i++) {
        cout<<i<<" dist: "<<dist[i]<<"\n";
    }
    cout<<"\n";

    cout<<"SHORTEST PATH FROM |"<<source<<"| TO |"<<sink<<"| :\n";
    printpath(shortest);

    VertexEdges capacities[V];
    initflow(v, edges, capacities);
    int maxflow = iterateflow(v, source, sink, capacities);

    cout<<"MAX FLOW: "<<maxflow<<"\n";
    return 0;
}
