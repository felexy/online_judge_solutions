/*
 *  Problem: http://www.spoj.com/problems/AMR10I/
 *  user: olimpo
 *  Calculate (x < 1000) recursively.
 */
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 1000

int R[MAX];

int digitSquareSum(int x) {
  if (x < 10) {
    return x * x;
  }
  int c = x % 10;
  return digitSquareSum(x/10) + c*c;
}

int HNCicle(int x) {
  if (x == 1)
    return 0;
  if (R[x] == 0) {
    R[x] = -1;
    R[x] = HNCicle(digitSquareSum(x));
    if (R[x] != -1) R[x]++;
  }
  return R[x];
}

int main() {
  int x;
  cin >> x;
  if (x < MAX)
    cout << HNCicle(x) << endl;
  else {
    x = digitSquareSum(x);
    x = HNCicle(x);
    if (x != -1) x++;
    cout << x << endl;
  }

}
