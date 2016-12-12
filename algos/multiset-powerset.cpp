#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>
#include <assert.h>

using namespace std;

template<typename T>
using multiset = vector<pair<T, int>>;

template<typename T>
ostream& operator<< (ostream &out, const multiset<T> ms) {
    out<<"{";
    for(const pair<T, int> elem : ms) {
        for(int i = 0; i < elem.second; i++) {
            out<<elem.first<<" ";
        }
    }
    out<<"}\n";

    return out;
}

template<typename T>
vector<multiset<T> > _powerset(vector<multiset<T>> accum, const multiset<T> multi, const int cur_index) {
    assert(cur_index >= 0 && cur_index <= multi.size());

    if (cur_index == multi.size()) {
        return accum;
    }

    //we have multisets of size cur_index - 1. we need to add multisets of 
    //cur_index.
    const T cur_elem = multi[cur_index].first;
    const int cur_count = multi[cur_index].second;

    cout<<"cur elem: "<<cur_elem<<" | cur count: "<<cur_count<<"\n";
    vector<multiset<T> > new_subsets;
    for(auto subsets : accum) {
        for(int c = 1; c <= cur_count; c++) {
            auto new_subset = subsets;
            new_subset.push_back(make_pair(cur_elem, c));

            new_subsets.push_back(new_subset);
        }
    }

    accum.insert(accum.end(), new_subsets.begin(), new_subsets.end()); 

    cout<<"accum ("<<cur_index<<"):\n";
    for(auto a : accum)
        cout<<a;

    return _powerset(accum, multi, cur_index + 1);
}


template<typename T>
vector<multiset<T> > powerset(multiset<T> multi) {
    vector<multiset<T> >accum;
    accum.push_back(multiset<T>());

    return _powerset(accum, multi, 0);
}
int main() {
    multiset<char> s;
    s.push_back(make_pair('a', 1));
    s.push_back(make_pair('b', 2));
    s.push_back(make_pair('c', 2));

    cout<<s;

    auto ps = powerset(s);
    cout<<"--powerset:-- \n";
    for(auto subset : ps)  {
        cout<<subset;
    }
    return 0;
}
