#include <iostream>
using namespace std;
#define endl '\n'

int posmod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret += b;
   return ret;
}



void copymat(int out[2][2], const int in[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            out[i][j] = in[i][j];
        }
    }
}

void printmat(const int mat[2][2]) {
    cout<<"\n";
    cout<<mat[0][0]<<" "<<mat[0][1]<<"\n"<<mat[1][0]<<" "<<mat[1][1];
}

void vecmatmul(int out[2], const int v[2], const int a[2][2], const int m) {
    /*
       [a00 a01][v0] = [v0 a00 + v1 a01]
       [a10 a11][v1] = [v0 a10 + v1a11]
    */

    out[0] = posmod(posmod(v[0] * a[0][0], m) + posmod(v[1] * a[0][1], m), m);
    out[1] = posmod(posmod(v[0] * a[1][0], m) + posmod(v[1] * a[1][1], m), m);

    return;
}



void matmatmul(int out[2][2], const int a[2][2], const int b[2][2], const unsigned int m) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            out[i][j] = 0;
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int  j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                const int result = posmod(posmod(a[i][k], m) * posmod(b[k][j], m), m);
                out[i][j] = posmod(out[i][j] + result, m);
            }
        }
    }
}


void matn(int out[2][2], const int in[2][2], int n, int m) {

    int ans[2][2] = {{1, 0}, {0, 1}};

    for(int i = 0; i < n; i++) {
        int new_ans[2][2];
        matmatmul(new_ans, ans, in, m);    
        copymat(ans, new_ans);
    }

    copymat(out, ans);

}

void fastmatn(int nmat[2][2], int mat[2][2], int n, int m) {
    if (n == 1 || n == 0) {
        matn(nmat, mat, n, m);
        return;
    }

    int matsq[2][2];
    matn(matsq, mat, 2, m);

    if (n % 2 == 0) {
        fastmatn(nmat, matsq, n/2, m);    
    }
    else {
        int n_minus_onemat[2][2];
        fastmatn(n_minus_onemat, matsq, (n - 1) / 2, m);
        matmatmul(nmat, mat, n_minus_onemat, m);
    }
    
}

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        if (n == 0) {
            cout<<0 % m<<" ";
        }
        else {
            //I solved the reucurrence starting from one.
            //don't want to do the whole CF + PI again
            //with those initial conditions!
            n--;

            const int initialvec[2] = {4, 2};

            int mat[2][2];
            mat[0][0] = 1; mat[0][1] = 1;
            mat[1][0] = 1; mat[1][1] = 0;

            int nmat[2][2];

            fastmatn(nmat, mat, n, m);

            int ansvec[2];
            vecmatmul(ansvec, initialvec, nmat, m);
            
            int ans = posmod(ansvec[0] - (n + 3), m);
            cout<<ans<<" ";
        }


    }
    
    return 0;

}
