//問題: https://atc001.contest.atcoder.jp/tasks/dfs_a


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <unordered_map>
using namespace std;

int h, w;
bool ans = false;
bool visited[600][600];
char field[600][600];

void dfs(int x, int y){
    if(x < 0 || w <= x || y < 0 || h <= y){
        return;
    }
    if(visited[y][x] == true){
        return;
    }
    if(field[y][x] == '#'){
        return;
    }
    
    visited[y][x] = true;
    if(field[y][x] == 'g'){
        ans = true;
        return;
    }
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

int main(){
    cin >> h >> w;
    int x, y;
    int i, j;
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            char tmp;
            cin >> tmp;
            field[i][j] = tmp;
            visited[i][j] = false;
            if(tmp == 's'){
                y = i;
                x = j;
            }
        }
    }
    
    dfs(x, y);
    
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}