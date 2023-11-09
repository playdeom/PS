#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define repair(x) x.erase(unique(all(x)),x.end())
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 9; //prime number
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
int main(){
    fastio;
    int n;
    cin>>n;
    vector<vector<int>>dp(101,vector<int>(101,0)),c(101,vector<int>(101,0));
    while(n--){
        int a,b;
        cin>>a>>b;
        c[a][b]=1;
        c[b][a]=1;
    }
    for(int i=1; i<=100; i++){
        for(int j=i; j>=1; j--){
            for(int k=j; k<i; k++){
                dp[j][i]=max(dp[j][i],dp[j][k]+dp[k][i]+c[i][j]);
            }
        }
    }
    cout<<dp[1][100];
    return 0;
}