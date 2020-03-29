//問題: https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f


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


#define INF 10e9
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
using P = pair<int, int>;

typedef struct edge{
   int to;
   int cost;
} edge;

vector<edge> graph[100];
long long int d[100];

void dijkstra(int s){
   priority_queue<P, vector<P>, greater<P> > que;
   for(int i = 0; i < 100; i++){
       d[i] = INF;
   }
   d[s] = 0;
   que.push(P(s, 0));

   while (!que.empty()) {
       P p = que.top();
       que.pop();
       int v = p.first;
       if (d[v] < p.second) continue;

       for (int i=0; i<graph[v].size(); ++i) {
           edge e = graph[v][i];
           if (d[e.to] > d[v] + e.cost) {
               d[e.to] = d[v] + e.cost;
               que.push(P(e.to, d[e.to]));
           }
       }
   }
}

int main() {
   int n, k;
   cin >> n >> k;

   for(int i = 0; i < k; i++){
       int u;
       cin >> u;
       if(u == 0){
           int a, b;
           cin >> a >> b;
           dijkstra(a-1);
           if(d[b-1] == INF){
               cout << -1 << endl;
           }else{
               cout << d[b-1] << endl;
           }
       }else{
           int c, d, e;
           cin >> c >> d >> e;
           edge E;
           E.to = d-1;
           E.cost = e;
           graph[c-1].push_back(E);

           E.to = c-1;
           E.cost = e;
           graph[d-1].push_back(E);
       }
   }

}