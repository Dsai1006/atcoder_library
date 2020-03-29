//問題: https://yukicoder.me/problems/no/807

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
typedef pair<int, int> P;

typedef struct edge{
  int to;
  long long int cost;
} edge;

vector<edge> graph[100010];
long long int d[2][100010];

void dijkstra(int s){
   typedef pair<long long int, P> T; //pair<頂点までの距離, チケット残り, 頂点>
   priority_queue<T, vector<T>, greater<T> > que;
   for(int i = 0; i < 100010; i++){
       d[0][i] = INF;
       d[1][i] = INF;
   }

   //スタート地点への距離は0
   d[1][s] = 0;
   d[0][s] = 0;
   que.push(T(0, P(1, s)));


   //ダイクストラ法
   while(!que.empty()){
       T t = que.top();
       que.pop();
       long long int dist = t.first;
       int state = t.second.first;
       int v = t.second.second;

       if(dist > d[state][v]) continue;

       for(int i = 0; i < graph[v].size(); i++){
           edge e = graph[v][i];
           if(d[state][e.to] > dist + e.cost){
               d[state][e.to] = dist + e.cost;
               que.push(T(d[state][e.to], P(state, e.to)));
           }
       }

       if(state == 1){
           for(int i = 0; i < graph[v].size(); i++){
               edge e = graph[v][i];
               if(d[0][e.to] > dist + 0){
                   d[0][e.to] = dist + 0;
                   que.push(T(d[0][e.to], P(0, e.to)));
               }
           }
       }
   }
}


int main() {
  int n, m;
  cin >> n >> m;

   for(int i = 0; i < m; i++){
       int s, t;
       long long int c;
       cin >> s >> t >> c;
       s--;
       t--;

       edge e;
       e.to = t; e.cost = c; graph[s].push_back(e);
       e.to = s; e.cost = c; graph[t].push_back(e);
   }

   dijkstra(0);

   for(int i = 0; i < n; i++){
       cout << d[0][i] + d[1][i] << endl;
   }
}