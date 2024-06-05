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
ll dp[1010][1010][2];
int n,m;
vector<ll>pos,arr,pre;
ll run(int l, int r, int p){
    ll&ret=dp[l][r][p];
    if(l==1 and r==n)return 0;
    if(ret!=-1)return ret;
    ret=linf;
    int now=p?r:l;
    ll rest=pre[n]-pre[r]+pre[l-1];
    if(1<l){
        ll save=run(l-1,r,0)+rest*(pos[now]-pos[l-1]);
        ret=min(ret,save);
    }
    if(r<n){
        ll save=run(l,r+1,1)+rest*(pos[r+1]-pos[now]);
        ret=min(ret,save);
    }
    return ret;
}
int main(){
    fastio;
    cin>>n>>m;
    pos.resize(n+1),arr.resize(n+1),pre.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>pos[i]>>arr[i];
        pre[i]=pre[i-1]+arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<run(m,m,0);
    return 0;
}