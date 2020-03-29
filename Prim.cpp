//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp

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

vector<P> graph[100000]; //first: コスト, second: 行き先
int used[100000];

int prim(){
   priority_queue<P, vector<P>, greater<P> > q;
   int i;
   for(i = 0; i < 100000; i++){
       used[i] = 0;
   }

   //適当な頂点を追加
   q.push(make_pair(0, 0));
   int ret = 0;

   //キューの中身がなくなるまで続ける
   while(!q.empty()){
       int cost = q.top().first;
       int to = q.top().second;
       q.pop();
       if(used[to]) continue;
       used[to] = 1;
       ret += cost;
       //隣接した辺を追加
       for(i = 0; i < graph[to].size(); i++){
           q.push(make_pair(graph[to][i].first, graph[to][i].second));
       }
   }
   return ret;
}

int main(){
   int V, E;
   cin >> V >> E;

   int s, t, w;
   int i;
   for(i = 0; i < E; i++){
       cin >> s >> t >> w;
       graph[s].push_back(make_pair(w, t));
       graph[t].push_back(make_pair(w, s));
   }

   cout << prim() << endl;
}