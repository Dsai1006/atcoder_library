//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja

//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>

#define INF 100000000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

pair<long long int, long long int> extGCD(long long int a, long long int b) {

  long long int s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;

  while (s % t != 0) {

    long long int temp = s / t;
    long long int u = s - t * temp;
    long long int ux = sx - tx * temp;
    long long int uy = sy - ty * temp;

    s = t;
    sx = tx;
    sy = ty;
    t = u;
    tx = ux;
    ty = uy;
  }

  return {tx, ty};
}
