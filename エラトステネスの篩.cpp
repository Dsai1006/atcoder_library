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

    //素数リスト
    vector<int> prime;
    //is_prime[i]はiが素数かどうかの結果
    bool is_prime[n];

    int i, j;
    for(i = 0; i < n; i++){
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for(i =2; i*i < n; i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(j = 2*i; j < n; j += i){
                is_prime[j] = false;
            }
        }
    }

    cout << prime.size() << endl;
}

