#define _CRT_SECURE_NO_WARNING
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
const int mod = 1e9 + 9; //prime number

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
int test[]={2,3,5,7,11,13,17,19,23,29,31};
ll multi(ll a, ll b, ll m){
    ll ans=0;
    a%=m;
    while(b){
        if(b&1)ans=(ans+a)%m;
        b>>=1;
        a=(a*2)%m;
    }
    return ans%m;
}
ll pow(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1)ans=multi(ans,a,m);
        b>>=1;
        a=multi(a,a,m);
    }
    return ans%m;
}
bool milr(ll n, ll a){
    if(a%n==0)return 1;
    ll d=n-1;
    while(d%2==0){
        if(pow(a,d,n)==n-1)return 1;
        d/=2;
    }
    ll save=pow(a,d,n);
    return save==1 or save==n-1;
}
bool check(ll t){
    if(t==9 or t==1)return 1;
    for(int i=0; i<11; i++){
        if(!milr(t,test[i]))return 0;
    }
    return 1;
}
int main() {
    fastio;
    ll a,b;
    cin>>a>>b;
    vector<ll>ans;
    for(ll t=a; t<=b; t++){
        if(check(t))cout<<t<<' ';
    }
    return 0;
}