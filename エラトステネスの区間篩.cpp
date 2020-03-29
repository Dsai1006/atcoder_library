//問題: 与えられた整数a, bに対して、a以上b以下の素数を列挙してください。


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

#define INF 100000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
int main() {
   int l, r;
   cin >> l >> r;
   int n = sqrt(r);

   //素数リスト(indexがiのときl+iを表す)
   bool is_prime_ans[r-l+1];
   //sqrt(r)以下の素数表
   bool is_prime[n];

   int i, j;
   for(i = 0; i <= r-l; i++){
       is_prime_ans[i] = true;
   }
   for(i = 0; i < n; i++){
       is_prime[i] = true;
   }
   is_prime[0] = false;
   is_prime[1] = false;

   for(i = 2; i <= n; i++){
       if(is_prime[i]){
           for(j = 2*i; j <= n; j += i){
               is_prime[j] = false;
           }

           if(l%i == 0){
               j = l;
           }else{
               j = (l/i + 1)*i;
           }
           while(j <= r){
               if(j != i) is_prime_ans[j-l] = false;
               j += i;
           }
       }
   }

   for(i = 0; i <= r-l; i++){
       if(is_prime_ans[i]) cout << i+l << endl;
   }
}