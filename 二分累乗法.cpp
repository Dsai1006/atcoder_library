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

long long int modpow(long long int a, long long int n, long long mod){
    long long int ans = 1;
    while(n != 0){
        if(n%2 == 1){
            ans = ans * a % mod;
            n -= 1;
        }else{
            a = a * a % mod;
            n /= 2;
        }
    }

    return ans;
}