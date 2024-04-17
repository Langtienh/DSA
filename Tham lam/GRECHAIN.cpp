#include<cstdio>
#include<algorithm>
using namespace std;
 
int n, a[555555];
 
int main() {
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < n; ++i) scanf("%d", a+i);
		sort(a, a+n);
		int lo = 0, hi = n-1, res = 0;
		while(lo != hi) {
			if(a[lo] + 1 <= hi - lo) {
				int l = a[lo]; res += a[lo];
				for(int i = hi-a[lo]; i <= hi; ++i) l += a[i];
				hi -= a[lo]; a[hi] = l; ++lo;
			} else {
				res += hi - lo;
				hi = lo;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
    
