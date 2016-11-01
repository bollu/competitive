#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
#define endl '\n'

unordered_map<string, string> parents;
int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int newnames = 0;
    while(n--) {
        string olds, news;
        cin>>olds>>news;

        auto it = parents.find(olds);
        if (it != parents.end()) {
            parents[news] = parents[olds];
            parents.erase(olds);
        } else {
            newnames++;
            parents[news] = olds;
        }

    }

    cout<<newnames<<"\n";
    for(auto it : parents) {
        cout<<it.second<<" "<<it.first<<"\n";
    }



    return 0;

}
