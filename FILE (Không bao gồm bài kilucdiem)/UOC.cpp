#include <iostream>
#include <algorithm>

using namespace std;

long long n, g = 0;
long long G[2000001];

void check_num() {
   for (int i=1; 1LL*i*i<=n; ++i)
      if (n % i == 0) {
      	 g++;
      	 if (1LL* i * i < n) g++;
      }
   cout << "Cac uoc so cua " << n << "\n";
}

void print() {
   int l = 1, r = g;
   for (int i=1; 1LL*i*i<=n; ++i)
      if (n % i == 0) {
      	 G[l++] = i;
      	 if (1LL* i * i < n) G[r--] = n / i;
      }
   for (int i=1; i<=g; ++i) cout << G[i] << '\n';
}

int main() {
   scanf("%I64d", &n);
   check_num();
   print();
}
    
