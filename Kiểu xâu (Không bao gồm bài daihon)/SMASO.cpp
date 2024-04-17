#include <iostream>
#include <cstring>

using namespace std;

int res = 0;
char s[10006];

int main() {
    scanf("%s", s+1); int n = strlen(s+1);
    for (int i=1; i<=n; ++i) res += (s[i] - '0');
    cout << res;    
  
    return 0;
}
    
