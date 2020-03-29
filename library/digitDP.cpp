//問題: https://abc007.contest.atcoder.jp/tasks/abc007_4

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

long long int digit(long long int A){
    long long int dp[20][2][2] = {};
    
    string s = to_string(A);
    
    int n = s.size();
    
    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){

                //次の位の数字がどこまでいけるか
                int lim;
                if(j == 1){
                    lim = 9;
                }else{
                    lim = s[i] - '0';
                }
                //次の位の数字を行ける範囲まで探索してdpを更新する
                for(int d = 0; d < lim+1; d++){
                    dp[i+1][j || d < lim][k || d == 4 || d == 9] += dp[i][j][k];
                }
            }
        }
    }
    
    return dp[n][0][1] + dp[n][1][1];
}

int main(){
    long long int A, B;
    cin >> A >> B;
    
    long long int ans = digit(B) - digit(A-1);
    
    cout << ans << endl;
}
