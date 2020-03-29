//問題: https://abc007.contest.atcoder.jp/tasks/abc007_3


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
int main() {
   int r, c;
   int sy, sx;
   int gy, gx;
   char field[51][51];
   int ans[51][51];

   int dx[4] = {1, 0, -1, 0};
   int dy[4] = {0, 1, 0, -1};

   cin >> r >> c >> sy >> sx >> gy >> gx;

   int i, j;
   for(i = 0; i < r; i++){
       for(j = 0; j < c; j++){
           cin >> field[i][j];
           ans[i][j] = 1000000;
       }
   }

   queue<pair<int, int>> q;
   q.push(make_pair(sy, sx));
   ans[sy-1][sx-1] = 0;
   while(!q.empty()){
       pair<int, int> p = q.front();
       q.pop();
       if(p.first == gy && p.second == gx){
            cout << ans[p.first-1][p.second-1] << endl;
       }
       for(i = 0; i < 4; i++){
           int ny = p.first + dy[i];
           int nx = p.second + dx[i];
           if(nx >= 0 && nx < c && ny >= 0 && ny < r && field[ny-1][nx-1] != '#' && ans[ny-1][nx-1] == 1000000){
               q.push(make_pair(ny, nx));
               ans[ny-1][nx-1] = ans[p.first-1][p.second-1] + 1;
           }
       }
   }
}