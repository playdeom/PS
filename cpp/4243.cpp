#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <ext/rope>
#include <cassert>
#include <x86intrin.h>
using namespace std;
using namespace __gnu_cxx;

// utils
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define repair(x) x.erase(unique(all(x)),x.end())
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 7; //prime number

// gcd, lcm, egcd funcs
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>tuple<T,T,T> egcd(T a, T b){
	if(b==0)return {a,1,0};
	auto[g,x,y]=egcd(b,a%b);
	return {g,y,x-(a/b)*y};
}
// builtin funcs
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl
//////////////////////////////////////////
int n;
ll dp[101][101][2];
ll run(int l, int r, int p,vector<int>&arr){
    ll&ret=dp[l][r][p];
    if(ret!=-1)return ret;
    if(l==1 and r==n)return ret=0;
    ret=linf;
    ll now;
    if(p)now=r;
    else now=l;
    ll rest=n-r+l-1;
    if(1<l)ret=min(ret,run(l-1,r,0,arr)+rest*(arr[now]-arr[l-1]));
    if(r<n)ret=min(ret,run(l,r+1,1,arr)+rest*(arr[r+1]-arr[now]));
    return ret;
}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>arr(n+1);
        memset(dp,-1,sizeof(dp));
        int s;
        cin>>s;
        for(int i=2; i<=n; i++){
            cin>>arr[i];
            arr[i]+=arr[i-1];
        }
        cout<<min(run(s,s,1,arr),run(s,s,0,arr))<<endl;
    }
    return 0;
}