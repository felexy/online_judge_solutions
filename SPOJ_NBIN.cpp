/*
 *  User: olimpo
 *  Problem: http://www.spoj.com/problems/NBIN/
 *  Solution: Dynamic Programing
 *    D1[n] the number of sequences using the n-digits and the first one is 1
 *    D0[n] the number of sequences using the n-digits and the first one is 0
 *    D1[n] = D0[n-1]
 *    D0[n] = D0[i-1] + D1[i-1];
 *    Given this we can calculate how many bit we need to get the n-simo number and with the bit we 
 *  can print the digit in the function show().
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

long long D0[100] = {1}, D1[100] = {1}, n;

void pre_build() {
  REPP(i, 1, 100) {
    D0[i] = D0[i-1] + D1[i-1];
    D1[i] = D0[i-1];
  }
}

void show(long long x, int b) {
  //cout << x << b <<endl;
  if (b == -1) return;
  if (D0[b] > x) {
    printf("0");
    show(x, b-1);
  } else {
    printf("1");
    show(x - D0[b], b-1);
  }
}

int main() {
  pre_build();
  GI(testCases);
  while (testCases--) {
    GL(n);
    int c = 0;
    while (D1[c] + D0[c] - 1 < n) c++;
    show(n, c);
    printf("\n");
  }
  return 0;
}
