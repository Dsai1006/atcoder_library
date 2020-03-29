//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp

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

#define INF 10e15
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
 long long int dist[100][100];
 long long int V, E;
 cin >> V >> E;

 long long int s, t, d;
 long long int i, j, k;
 for(i = 0; i < V; i++){
     for(j = 0; j < V; j++){
         if(i == j){
             dist[i][j] = 0;
         }else{
             dist[i][j] = INF;
         }
      }
 }
 for(i = 0; i < E; i++){
     cin >> s >> t >> d;
     dist[s][t] = d;
 }

 for(k = 0; k < V; k++){
     for(i = 0; i < V; i++){
         for(j = 0; j < V; j++){
             if(dist[i][k] != INF && dist[k][j] != INF){
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
             }
             if(i == j && dist[i][j] < 0){
                 cout << "NEGATIVE CYCLE" << endl;
                 return 0;
             }
         }
     }
 }

 for(i = 0; i < V; i++){
      for(j = 0; j < V; j++){
         if(j) cout<<" ";
         if(dist[i][j] == INF) cout<<"INF";
         else cout << dist[i][j];
      }
      cout<<endl;
  }
}