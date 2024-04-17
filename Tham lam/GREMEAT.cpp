#include <iostream>

using namespace std;

#define llong long long

llong sum = 0;
int a[100006], p[100006], n;

int main() {
    scanf("%d", &n); int mmin;
    for(int i=1; i<=n; ++i) {
    	scanf("%d%d", &a[i], &p[i]);
    	if (i == 1) sum += 1LL*a[i]*p[i], mmin = p[i];
    	else {
    	     mmin = min(mmin, p[i]);
    	     sum += 1LL*a[i] * mmin;
    	}
    }  
    cout << sum;
    
    return 0;
}
    
