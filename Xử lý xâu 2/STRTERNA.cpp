#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];
int num[4], n, num1[4];

int main() {
    scanf("%d", &n);
    scanf("%s", S+1);
    for(int i=1; i<=n; ++i) ++num[S[i]-'0'];
    int sum = num[0] + num[1] + num[2];
    sum /= 3;
    num[0] -= sum, num[1] -= sum, num[2] -= sum;
    int i = n;
    while (num[0] > 0 && i > 0) {
        if (S[i] == '0') {
            if (num[2] < 0) S[i] = '2', --num[0], ++num[2];
            else S[i] = '1', --num[0], ++num[1];
        }
        --i;
    }
    i = 1;
    while (num[1] > 0 && num[0] < 0 && i <= n) {
        if (S[i] == '1') S[i] = '0', ++num[0], --num[1];
        ++i;
    }
    i = n;
    while (num[1] > 0 && num[2] < 0 && i > 0) {
        if (S[i] == '1') S[i] = '2', ++num[2], --num[1];
        --i;
    }
    i = 1;
    while (num[2] > 0 && i <= n) {
        if (S[i] == '2') {
            if (num[0] < 0) S[i] = '0', ++num[0], --num[2];
            else S[i] = '1', ++num[1], --num[2];
        }
        ++i;
    }
    cout << S+1;
    return 0;
}
    
