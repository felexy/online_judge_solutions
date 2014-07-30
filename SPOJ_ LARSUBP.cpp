/*
 * Problem: http://www.spoj.com/problems/LARSUBP/
 * user: olimpo
 * D[d]: amount of subsequences ended in d.
 * for each new digit d D[d] = sum(D[dd]) with dd = (0,d) 
 */
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
long long A[10];
int t;
char C[10005];

int main() {
  scanf("%d",&t);
  int tt = 1;
  while (t--) {
    scanf("%s",C);
    int x = 0;
    long long s = 0;
    for (int i = 0; C[i]; i++) {
      s = 0;
      x = C[i] - '0';
      for (int j = 1; j < x; j++) {
        s += A[j];
      }
      A[x] = (A[x] + s + 1) % 1000000007;
    }
    s = 0;
    for (int i = 0; i < 10; i++) {
      s += A[i];
      A[i] = 0;
    }
    s %= 1000000007;
    printf("Case %d: %lld\n", tt++, s);
  }
  return 0;
}
