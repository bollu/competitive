#include <iostream>
using namespace std;
#define endl '\n'

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;

    cin>>s;

    int leftover = 26;
    int counts[26];
    int spaces = 0;

    for(int i = 0; i < 26; i++) {
        counts[i] = 0;
    }


    if (s.length() < 26) {
        cout<<-1; return 0;
    }

    //initialize the counts;
    for(int i = 0; i < 26; i++) {
        if (s[i] == '?') {
            spaces++;
        } else {
            const int index = s[i] - 'A';
            //if 1, do nothing
            if (counts[index] == 0) {
                leftover--;
            }
            counts[index]++;
        }
    }

    
    int i = 26;
    //for(int i = 26; i < s.length(); i++) {
    do {
        if (leftover <= spaces) {
            for(int j = 0; j < i - 26; j++) {
                if (s[j] == '?') { cout<<'Z'; } else { cout<<s[j]; }
            }
            
            //print actual string
            for(int j = i - 26; j < i; j++) {
                if (s[j] == '?') {
                    for(int k = 0; k < 26; k++) {
                        if (counts[k] == 0) {
                            cout<<(char)('A' + k);
                            counts[k]++;
                            break;
                        }
                    }

                } else {
                    cout<<s[j];
                }
            }

            for(int j = i; j < s.length(); j++) {
                if (s[j] == '?') { cout<<'Z'; } else { cout<<s[j]; }
            }

            return 0;

        } else {
            //do not exec
            if (i == s.length()) { i++; break; }
            //drop last letter
            const int prev = i - 26;
            if (s[prev] == '?') { spaces--; }
            else {
                const int index = s[prev] - 'A';
                //we're losing a letter
                if (counts[index] == 1) {
                    leftover++;
                }
                counts[index]--;
            }

            //update current status
            if (s[i] == '?') { spaces++; }
            else {
                const int index = s[i] - 'A';
                if (counts[index] == 0) {
                    leftover--;
                }
                counts[index]++;
            }
            
        }
        i++;
    //}
    } while(i <= s.length());

    cout<<-1;



    
    return 0;

}
