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
typedef pair<int, P> T;

struct UnionFind{
  vector<long long int> par; //par[i] : iの親の番号
  vector<long long int> rnk; //root[i] : iの木のランク

  //コンストラクタ
  UnionFind(long long int n): par(n), rnk(n){
      //木の初期化
      for(long long int i = 0; i < n; i++){
          par[i] = i;
          rnk[i] = 1;
      }
  }

  //データxが属する木の根を再帰で取得
  long long int root(long long int x){
      if(par[x] == x){
          return x;
      }else{
          return par[x] = root(par[x]);
      }
  }

  //xとyが同じ木に属しているかを判定
  bool same(long long int x, long long int y){
      return root(x) == root(y);
  }

  //xとyの木を併合
  void unite(long long int x, long long int y){
      long long int rx = root(x); //xの根
      long long int ry = root(y); //yの根
      if(rx == ry) return; //根が同じならそのまま

      if(rnk[rx] < rnk[ry]){
          par[rx] = ry;
      }else{
          par[ry] =rx;
          if(rnk[rx] == rnk[ry]) rnk[rx]++;
      }
  }
};

vector<T> edges; //cost, from, toの順

int kruskal(int V){
   //辺をコストでソート
  sort(edges.begin(), edges.end());
  UnionFind uf(V);
  int res = 0;

  //コストが小さい順に辺を追加できるか判定していく
  for(int i = 0; i < edges.size(); i++){
      T e = edges[i];
      if(!uf.same(e.second.first, e.second.second)){
          uf.unite(e.second.first, e.second.second);
          res += e.first;
      }
  }

  return res;
}

int main(){
  int V, E;
  cin >> V >> E;

  int i;
  for(i = 0; i < E; i++){
      int s, t, w;
      cin >> s >> t >> w;
      edges.push_back(make_pair(w, make_pair(s, t)));
  }

  cout << kruskal(V) << endl;
}