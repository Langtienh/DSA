#include <iostream>
#include <algorithm>
#include <map>
#define llong long long
#define fname "SPIRALPRIM"

using namespace std;

const int N = 40005;
const llong M = 100000000007;
int np[N];
int p[N], pp=0;

void eratos() {
    for(int i=2; i<=N; ++i) {
        if (!np[i]) np[i] = p[++pp] = i;
        int j = 1;
        while (j <= pp && p[j] <= np[i] && p[j]*i <= N) {
            np[p[j]*i] = p[j];
            ++j;
        }
    }
}

llong power(llong a, llong k) {
    llong P = 1;
    while (k) {
        if (k&1) P=P*a;
        k >>= 1; a=a*a;
    }
    return P;
}

llong power(llong a, llong k, llong M) {
    llong P=1;
    for (a=a%M; k; k >>= 1)
    { if (k&1) P=P*a%M; a=a*a%M; }
    return P;
}

llong root(llong n, llong k) {
    llong x = pow(n, 1.0/k);
    while (power(x, k)%M==power(x, k, M) && power(x, k)<n) x++;
    while (power(x, k)%M!=power(x, k, M) || power(x, k)>n) x--;
    return x;
}

map<llong, llong> Phi[N];

llong phi(llong x, int a) {
    if (Phi[a].count(x)) return Phi[a][x];
    if (a==1) return (x+1)/2;
    llong res = phi(x, a-1) - phi(x/p[a], a-1);
    return Phi[a][x] = res;
}

llong pi(llong x) {
    if (x<N)
        return upper_bound(p+1, p+pp+1, x) - (p+1);
    llong a = pi(root(x, 4));
    llong b = pi(root(x, 2));
    llong c = pi(root(x, 3));
    llong Sum = phi(x, a) + (b+a-2)*(b-a+1)/2;
    for (int i=a+1; i<=b; i++)
        Sum -= pi(x/p[i]);
    for (int i=a+1; i<=c; i++) {
        llong bi = pi(root(x/p[i], 2));
        for (int j=i; j<=bi; j++)
        Sum -= pi(x/p[i]/p[j]) - (j-1);
    }
    return Sum;
}

int n;

void process() {
    eratos();
    int pos = (int) pi(1LL*n); --pos;
    int x = 0, y = 0, h = 1, s = 0, i = 1;
    while (s <= pos) {
        for(int j=1; j<=2; ++j) {
            if (s + i >= pos) {
                i = pos - s;
                switch (h) {
                    case 1 : x += i; break;
                    case 2 : y += i; break;
                    case 3 : x -= i; break;
                    case 4 : y -= i; break;
                }
                cout << x << " " << y;
                return;
            } else {
                s += i;
                switch (h) {
                    case 1 : x += i, h = 2; break;
                    case 2 : y += i, h = 3; break;
                    case 3 : x -= i, h = 4; break;
                    case 4 : y -= i, h = 1; break;
                }
            }
        }
        ++i;
    }
}

int main() {

    scanf("%d", &n);
    process();

    return 0;
}
    
