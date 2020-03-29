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
    int n;
    cin >> n;

    int prime[n+1];

    int i, j;
    for(i = 0; i <= n; i++){
        prime[i] = 0;
    }
    prime[0] = 0;
    prime[1] = 1;
    for(i = 2; i <= n; i++){
        if(prime[i] == 0){
            for(j = i; j <= n; j += i){
                prime[j] = i;
            }
        }
    }

    while(1){
        cout << prime[n] << endl;
        n /= prime[n];
        if(n == 1) break;
    }
}
