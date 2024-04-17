#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n;

bool check(int A, int B, int C) {
    if (A+B>C && C+B>A && A+C>B) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    if (n < 3) {
        cout << "NO";
        return 0;
    }
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=3; i<=n; ++i)
       if (check(a[i], a[i-1], a[i-2])) {
            cout << "YES";
            return 0;
       }
   cout << "NO";
   return 0;
}
    
