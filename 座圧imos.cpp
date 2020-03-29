//問題: https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e

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

//#define INF 100000000
//#define MOD (int) (1e9+7)
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    int i, j;
    vector<int> x1(n), x2(n), y1(n), y2(n);
    vector<int> xs, ys; //座圧用
    xs.push_back(0); xs.push_back(w);
    ys.push_back(0); ys.push_back(h);
    for(i = 0; i < n; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xs.push_back(x1[i]);
        xs.push_back(x2[i]);
        ys.push_back(y1[i]);
        ys.push_back(y2[i]);
    }

    //ソートする
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    //ダブりを消す
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    //1番上と1番右がはみ出るので，その分の長さを引く
    int H = ys.size()-1;
    int W = xs.size()-1;

    //圧縮した二次元空間を初期化
    int imos[H][W];
    for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            imos[i][j] = 0;
        }
    }

    //二次元空間に対してimos法
    for(i = 0; i < n; i++){
        int a, b, c, d;
        a = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
        b = lower_bound(ys.begin(), ys.end(), y1[i]) - ys.begin();
        c = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
        d = lower_bound(ys.begin(), ys.end(), y2[i]) - ys.begin();
        
        //はみ出たものまでxs, ysに格納している可能性があるので，その分は除去する
        if(b < H && a < W) imos[b][a]++;
        if(d < H && a < W) imos[d][a]--;
        if(b < H && c < W) imos[b][c]--;
        if(d < H && c < W) imos[d][c]++;
    }

    for(i = 0; i < H; i++){
        for(j = 1; j < W; j++){
            imos[i][j] += imos[i][j-1];
        }
    }

    for(i = 1; i < H; i++){
        for(j = 0; j < W; j++){
            imos[i][j] += imos[i-1][j];
        }
    }

    int ans = 0;
    //幅優先探索で連結部分をカウントする
    for(i = 0; i < H; i++){
        for(j = 0; j < W; j++){
            if(imos[i][j] != 0) continue;
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if(imos[y][x] != 0) continue;
                imos[y][x] = 1;

                if(0 <= y-1 && y-1 < H && 0 <= x && x < W) q.push(make_pair(y-1, x));
                if(0 <= y+1 && y+1 < H && 0 <= x && x < W) q.push(make_pair(y+1, x));
                if(0 <= y && y < H && 0 <= x-1 && x-1 < W) q.push(make_pair(y, x-1));
                if(0 <= y && y < H && 0 <= x+1 && x+1 < W) q.push(make_pair(y, x+1));
            }

            ans++;
        }
    }

    cout << ans << endl;
}



