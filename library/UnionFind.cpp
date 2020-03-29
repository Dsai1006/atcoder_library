//問題: https://atcoder.jp/contests/abc075/tasks/abc075_c?lang=ja


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
   vector<long long int> rnk; //root[i] : iの木のサイズ

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

       //併合するときにサイズを足し合わせる
       if(rnk[rx] < rnk[ry]){
           par[rx] = ry;
           rnk[ry] += rnk[rx];
       }else{
           par[ry] = rx;
           rnk[rx] += rnk[ry];
       }
   }

   //属している木のサイズを取得
   long long int size(long long int x){
       return rnk[root(x)];
   }
};

int main(){
   int n, m;
   cin >> n >> m;

   vector<P> edges;
   int i;
   for(i = 0; i < m; i++){
       int a, b;
       cin >> a >> b;
       a--; b--;
       edges.push_back(make_pair(a, b));
   }

   int count = 0;
   int j;

   //iがなくす辺
   for(i = 0; i < m; i++){
       UnionFind uf(n);
       for(j = 0; j < m; j++){
           if(i == j) continue;
           uf.unite(edges[j].first, edges[j].second);
       }
       //サイズがnより小さいならそれは連結ではない
       if(uf.size(0) < n) count++;
   }
  
   cout << count << endl;
}