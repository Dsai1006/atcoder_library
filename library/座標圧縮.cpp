//問題: https://abc036.contest.atcoder.jp/tasks/abc036_c

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

int main(){
    int n;
    cin >> n;

    vector<int> a(n), v(n);
    int i;
    for(i = 0; i < n; i++){
        int p;
        cin >> p;
        a[i] = p;
        v[i] = p;
    }
    //ソートする
    sort(v.begin(), v.end());

    //ダブりを消す
    v.erase(unique(v.begin(), v.end()), v.end());

    for(i = 0; i < n; i++){
        int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        cout << id << endl;
    }
}
