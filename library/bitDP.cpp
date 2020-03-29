//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=jp

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

#define INF 100000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
int main() {
  int n;
  int e;
 
  cin >> n >> e;
  int dist[n][n];
 
  int i, j, k;
  //隣接行列作成
  for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){   
          dist[i][j] = INF;
       }
   }

   int s, t, d;
   for(i = 0; i < e; i++){
       cin >> s >> t >> d;
       dist[s][t] = d;
   }
  
   int dp[1<<n][n];

  //dp初期化
  for(i = 0; i < (1<<n); i++){
      for(j = 0; j < n; j++){
          dp[i][j] = INF;
      }
  }
  dp[1][0] = 0;

  for(i = 0; i < (1<<n); i++){
      for(j = 0; j < n; j++){
          if(dp[i][j] == INF) continue;
          for(k = 0; k < n; k++){
              //もしkが訪問済みだったら何もしない
              if((i>>k)%2 == 1) continue;
              if(dist[j][k] == INF) continue;
              //集合の更新
              int nexti = i | (1<<k);
              //経路長を求める
              int nextd = dp[i][j] + dist[j][k];
              //現在の値より小さいなら更新する
              dp[nexti][k] = min(dp[nexti][k], nextd);
          }
      }
  }

  //全て訪問した時の状態
  int all = (1<<n) - 1;
  int ans = INF;
  int goal;
  for(i = 0; i < n; i++){
      if(dp[all][i] == INF) continue;
      int tmp = dp[all][i] + dist[i][0];
      ans = min(ans, tmp);
  }

  if(ans == INF){
      cout << -1 << endl;
  }else{
      cout << ans << endl;
  }
}