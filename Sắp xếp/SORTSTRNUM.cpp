#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char S1[100006];
string S[100006], N[100006];
int cnt_S=0, cnt_N=0;

int main() {
    scanf("%s", S1);
    int n = strlen(S1);
    string tmp_S = "", tmp_N = "";
    bool number = ('0' <= S1[0] && S1[0] <= '9');
    if (number) tmp_N = tmp_N + S1[0];
    else tmp_S = tmp_S + S1[0];
    for(int i=1; i<n; ++i) {
        if (number && (S1[i] > '9' || S1[i] < '0')) {
            N[cnt_N++] = tmp_N; tmp_N.erase();
            number = false;
        } else if (!number && ('0' <= S1[i] && S1[i] <= '9')) {
            S[cnt_S++] = tmp_S; tmp_S.erase();
            number = true;
        }
        if (number) tmp_N = tmp_N + S1[i];
        else tmp_S = tmp_S + S1[i];
    }
    if(number) N[cnt_N++] = tmp_N; else S[cnt_S++] = tmp_S;


    sort(N, N+cnt_N, [] (const string &A, const string &B) {
        if (A.length() > B.length()) return false;
        if (A.length() < B.length()) return true;
        for(int i=0; i<(int) A.length(); ++i)
            if (A[i] < B[i]) return true;
            else if (A[i] > B[i]) return false;
        return false;
    });
    int i = 0, j = 0;
    if ('0' <= S1[0] && S1[0] <= '9') {
        while(i < cnt_N || j < cnt_S) {
            if (i < cnt_N) {
                cout << N[i];
                ++i;
            }
            if (j < cnt_S) {
                cout << S[j];
                ++j;
            }
        }
    } else {
        while(i < cnt_N || j < cnt_S) {
            if (j < cnt_S) {
                cout << S[j];
                ++j;
            }
            if (i < cnt_N) {
                cout << N[i];
                ++i;
            }
        }
    }

    return 0;
}
    
