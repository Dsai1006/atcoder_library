//問題: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp

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
int main() {
   long long int n, q;
   cin >> n >> q;
   vector<long long int> a(n);

   long long int i;
   for(i = 0; i < n; i++){
       cin >> a[i];
   }

   long long int l = 0;
   long long int r = 0;
   long long int sum = 0;
   long long int count = 0;
   long long int s;

   for(i = 0; i < q; i++){
       cin >> s;
       l = 0;
       r = 0;
       sum = 0;
       count = 0;
       for(l = 0; l < n; l++){
           while(r < n && sum + a[r] <= s){
               sum += a[r];
               r++;
           }
           //rを固定してlが何個分動かせるか
           count += r - l;
           if(l == r){
               //lはrを追い越さない
               r++;
           }else{
               sum -= a[l];
           }
       }
       cout << count << endl;
   }
}