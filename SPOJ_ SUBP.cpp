/*
 *  User: olimpo
 *  Problem: http://www.spoj.com/problems/SUBP/
 *  Solution: Dynamic Programing
 *    D[n][d] the number of sequences using the n-first number and the last number is equal to d.
 *    D[n][d] = D[n-1][d] + (D[n-1][0...d-1] iff d == N[n])
 *  Implementation: Dont use a 2-dimensional array we can use only a array and update it.
 */
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; i++)
#define REPP(i,k,n) for(int i = k ; i < n ; i++)
#define GI(x) scanf("%d",&x)
#define GII(x,y) scanf("%d%d",&x,&y)
#define GIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define GL(x) cin >> x
#define GLL(x,y) cin >> x >> y
#define GLLL(x,y,z) cin >> x >> y >> z
#define MOD 1000000007

int testCases, testCase = 1;
char seq[105];
int D[10];

int main() {
  GI(testCases);
  while (testCases--) {
    scanf("%s", seq);
    memset(D, 0, sizeof(D));
    
    for (int i = 0; seq[i]; i++) {
      int d = seq[i] - '0';
      for (int j = 0; j < d; j++) {
        D[d] += D[j];
      }
      D[d] += 1;
    }
    
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      sum += D[i];
    }
    printf("Case %d: %d\n", testCase++, sum);
  }
  return 0;
}
