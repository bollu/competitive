//http://codeforces.com/problemset/problem/489/C
//Given Length and Sum of Digits

/*
   You have a positive integer m and a non-negative integer s. Your task is to
   find the smallest and the largest of the numbers that have length m and sum of
   digits s. The required numbers should be non-negative integers written in the
   decimal base without leading zeroes.

   Input The single line of the input contains a pair of integers m, s
   (1 ≤ m ≤ 100, 0 ≤ s ≤ 900) — the length and the sum of the digits of the
   required numbers.

   Output In the output print the pair of the required non-negative integer
   numbers — first the minimum possible number, then — the maximum possible
   number. If no numbers satisfying conditions required exist, print the pair of
   numbers "-1 -1" (without the quotes).
   */



#include <iostream>
#include <assert.h>
using namespace std;
#define endl '\n'

typedef int* ans_t;
static const int MAX_NUMLEN = 100;
static const int MAX_SUM = 900;

void print_ans(ans_t ans) {
    if (ans[0] == -1) {
        cout<<(-1);
    } else {
        for (int i = 0; i < MAX_NUMLEN && ans[i] != -1; i++) {
            cout<<(char)('0' + ans[i]);
        }
    }

} 
int get_largest_num(int index, int len, int sum, ans_t ans) {
    if (len < 1) {
        return -1;
    }
    if (len == 1) {
        if (sum >= 10) {
            return -1;
        }
        else {
            ans[index] = sum;
        }
    } 
    else {
        if (sum < 0) {
            return -1;
        }
        else {

            const int start_place = index == 0 ? 1 : 0;
            if (sum < start_place) {
                return -1;
            }

            for (int i = 9; i >= start_place; i--) {
                int max_digit_possible = min(i, sum);
                int amt_left = sum - max_digit_possible;

                if (amt_left < 0) {
                    continue;
                }
                ans[index] = max_digit_possible;
                int result = get_largest_num(index + 1, len - 1, amt_left, ans);
                if (result != -1) {
                    return 1;
                }
            }
            return -1;
        }
    }
    return 1;
}





int dp[MAX_NUMLEN][MAX_SUM];

void init_dp() {
    for(int i = 0; i < MAX_NUMLEN; i++) {
        for(int j = 0; j < MAX_SUM; j++) {
            dp[i][j] = -1;
        }
    }
}
int get_smallest_num(int index, int len, int sum, ans_t ans) {
    assert(index >= 0 && index <= MAX_NUMLEN);
    int dp_digit = dp[index][sum];
        
    if (len < 1) {
        goto fail;
    }

    if (sum < 0) {
        goto fail;
    }

    if (len == 1 && sum > 9) {
        goto fail;
    }

    if (dp_digit != -1) {
        ans[index] = dp_digit;
        goto success;
    }

    if (len == 1) {
        ans[index] = sum;
        goto success;
    } else {

        const int min_digit = index == 0 ? 1 : 0;

        for (int i = min_digit; i <= 9; i++) {
            const int leftover_sum = sum - i;
            const int result = get_smallest_num(index + 1, len - 1, leftover_sum, ans);

            if (result != -1) {
                dp[index][sum] = i;
                ans[index] = i;
                goto success;
            }
            
        }
        goto fail;
    }
  
success:
    return 1;

fail:
    return -1;
}


int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s; cin>>m>>s;

    int ans[MAX_NUMLEN];
    for (int i = 0; i < MAX_NUMLEN; i++) {
        ans[i]= -1;
    }
    
    init_dp();
    get_smallest_num(0, m, s, ans);
    print_ans(ans);

    cout<<" ";
    

    /*
    for (int i = 0; i < MAX_NUMLEN; i++) {
        ans[i]= -1;
    }
    get_largest_num(0, m, s, ans);
    print_ans(ans);
    */

    return 0;

}
