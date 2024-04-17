#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <cstring>
#define llong long long

using namespace std;

struct BigNum {
    int l[107];
    bool neg;
} a[11], S;

int n, x[11], aa[11];

BigNum to_arr(llong X) {
    BigNum c; memset(c.l, 0, sizeof(c.l));
    if (X < 0) c.neg = true; else c.neg = false;
    X = abs(X);
    if (X == 0) c.l[0] = 1;
    else {
        while (X != 0) {
            c.l[++c.l[0]] = X % 10;
            X /= 10;
        }
    }
    return c;
}

void operator += (BigNum &A, BigNum B) {
    A.l[0] = max(A.l[0], B.l[0]);
    int rem = 0;
    for(int i=1; i<=A.l[0]; ++i) {
        A.l[i] += B.l[i] + rem;
        rem = A.l[i] / 10;
        A.l[i] %= 10;
    }
    if (rem) A.l[++A.l[0]] = rem;
}

void operator *= (BigNum &A, BigNum B) {
    BigNum C;
    memset(C.l, 0, sizeof(C.l)); C.neg = A.neg;
    C.l[0] = A.l[0] + B.l[0] - 1;
    for(int i=1; i<=A.l[0]; ++i)
    for(int j=1; j<=B.l[0]; ++j) C.l[i+j-1] += A.l[i] * B.l[j];
    int rem = 0;
    for(int i=1; i<=C.l[0]; ++i) {
        C.l[i] += rem;
        rem = C.l[i] / 10;
        C.l[i] %= 10;
    }
    if (rem) C.l[++C.l[0]] = rem;
    A = C;
}

void operator -= (BigNum &A, BigNum B) {
    int rem = 0;
    for(int i=1; i <= A.l[0]; ++i) {
        A.l[i] -= (B.l[i] + rem);
        if (A.l[i] < 0) {
            A.l[i] += 10;
            rem = 1;
        } else  rem = 0;
    }
    while (A.l[0] > 1 && A.l[A.l[0]] == 0) A.l[0]--;
}

int cmp(BigNum A, BigNum B) {
    if (A.l[0] > B.l[0]) return -1;
    if (A.l[0] < B.l[0]) return 1;
    else {
        for(int i=A.l[0]; i; --i)
            if (A.l[i] > B.l[i]) return -1;
            else if (A.l[i] < B.l[i]) return 1;
        return 0;
    }
}

void Plus(BigNum &A, BigNum B) {
    if (A.neg == B.neg) A += B;
    else if (cmp(A, B) == 1) {
        B -= A; A = B;
    } else A -= B;
}

void Sub(BigNum &A, BigNum B) {
    if (A.neg == B.neg) {
        if (cmp(A, B) == 1) {
            B -= A; A = B;
            A.neg = !A.neg;
        } else A -= B;
    } else A += B;
}

void Mul(BigNum &A, BigNum B) {
    if (A.neg != B.neg) A.neg = true;
    else A.neg = false;
    A *= B;
}

void check() {
    BigNum S1 = to_arr(0);
    deque<pair<BigNum, char> > Q;
    Q.push_back(make_pair(a[1], '+'));
    for(int i=2; i<=n; ++i)
        if (x[i] == 0) {
            pair<BigNum, char> p = Q.back(); Q.pop_back();
            p.first *= a[i];
            Q.push_back(p);
        } else if (x[i] == 1) Q.push_back(make_pair(a[i], '+'));
        else Q.push_back(make_pair(a[i], '-'));
    while (!Q.empty()) {
        if (Q.front().second == '-') Sub(S1, Q.front().first);
        else Plus(S1, Q.front().first);
        Q.pop_front();
    }
    if (cmp(S1, S) == 0 && S1.neg == S.neg) {
        cout << aa[1];
        for(int i=2; i<=n; ++i) {
            if (x[i] == 0) cout << '*';
            else if (x[i] == 1) cout << '+';
            else cout << '-';
            cout << aa[i];
        }
        putchar('\n');
    }
}

void back_track(int cnt) {
    if (cnt == n+1){
        check();
        return;
    }
    for(int i=0; i<3; ++i) {
        x[cnt] = i;
        back_track(cnt+1);
    }
}

int main() {
    llong S1;
    scanf("%d%I64d", &n, &S1);
    S = to_arr(S1);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &aa[i]);
        a[i] = to_arr(1LL*aa[i]);
    }

    back_track(2);

    return 0;
}
    
