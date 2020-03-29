//問題: https://arc017.contest.atcoder.jp/tasks/arc017_3


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


#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    long long int n, k;
   cin >> n >> k;

   vector<long long int> a(n);

   long long int i, j;
   for(i = 0; i < n; i++){
       cin >> a[i];
  }

  vector<long long int> x, y;

  for(i = 0; i < (1<<(n/2)); i++){
      int t = 0;
      for(j = 0; j < n/2; j++){
          if((i>>j)&1){
              t += a[j];
          }
      }
      x.push_back(t);
  }
 
  for(i = 0; i < (1<<(n-n/2)); i++){
      int t = 0;
      for(j = 0; j < n-n/2; j++){
          if((i>>j)&1){
              t += a[n/2+j];
          }
      }
      y.push_back(t);
  }

  sort(y.begin(), y.end());
 
  long long int ans = 0;
  for(i = 0; i < x.size(); i++){
      ans += upper_bound(y.begin(), y.end(), k-x[i]) - lower_bound(y.begin(), y.end(), k-x[i]);
  }

  cout << ans << endl;
}