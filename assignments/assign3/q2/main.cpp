#include <iostream>
#include <assert.h>
using namespace std;
#define endl '\n'

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    
    int people[100000+1];

    while(t--) {
        int nstations, npeople;
        cin>>nstations>>npeople;
    
        for(int i = 0; i < nstations; i++) {
            cin>>people[i];
        }
        
        int maxsum = 0, maxstations = 0;

        int starti = 0;
        int cursum = 0;

        for(int i = 0; i < nstations; i++) {
            cursum += people[i];

            if (cursum > npeople) {
                //check if leaving a station from the begin
                //will help pick this one up
                while(cursum > npeople) {
                    cursum -= people[starti];
                    starti++;
                }
            } 

            const int curstations = i - starti + 1;
            if (curstations > maxstations ||
                (curstations == maxstations && maxsum > cursum)) {
                maxstations = curstations;
                maxsum = cursum;
            }
        }

        cout<<maxsum<<" "<<maxstations<<"\n";
    
    }
    
    return 0;

}
