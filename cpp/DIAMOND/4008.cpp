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
const ll linf = 1e18; //long long maximum
const int mod = 1e9 + 9; //prime number
const ld pi = 3.14159265358979; // piiiiiii
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
struct cht{
    int n,a,b,c;
    int now=0, save=1;
    vector<ll>arr,dp,s,pos,t;
    cht(int N, int A, int B, int C){
        arr.resize(1010101,0);
        dp.resize(1010101,0);
        s.resize(1010101,0);
        pos.resize(1010101,0);
        t.resize(1010101,0);
        n=N,a=A,b=B,c=C;
    }
    ll func(ll x){
        return (ll)a*x*x+(ll)b*x+c;
    }
    ll k(ll x){
        return -2*a*s[x];
    }
    ll m(ll x){
        return a*s[x]*s[x]-b*s[x]+dp[x];
    }
    ld ch(int i,int j){
        return 1.0*(m(i)-m(j))/(k(j)-k(i));
    }
    void input(){
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            s[i]=s[i-1]+arr[i];
        }
    }
    void query(int i){
        dp[i]=func(s[i]);
        if(now){
            while(save<now and pos[save+1]<s[i])save++;
            dp[i]=max(dp[i],dp[t[save]]+func(s[i]-s[t[save]]));
            while(now>1 and pos[now]>ch(t[now],i))--now;
            t[now+1]=i;
            pos[now+1]=ch(t[now],i);
            now+=1;
            if(save>now)save=now;
        }
        else{
            now++;
            t[now]=i;
            pos[now]=-iinf;
        }
    }
};
int main(){
    fastio;
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cht arr(n,a,b,c);
    arr.input();
    for(int i=1; i<=n; i++){
        arr.query(i);
    }
    int ans=arr.dp[n];
    cout<<ans;
    return 0;
}
//reference https://justicehui.github.io/apio/2018/08/20/BOJ4008/