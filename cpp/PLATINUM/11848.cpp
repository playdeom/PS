#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
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
void func(vector<ll>&mu, vector<pair<ll,ll>>&arr, vector<ll>&f, int n, int m, int w){
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll sum=0;
    if(w&1)reverse(all(arr));
    for(int i=0; i<n; i++){
        ll pos=arr[i].second;
        if(pq.size()<m){
            sum+=mu[pos];
            pq.push(mu[pos]);
        }
        else if(!pq.empty() and pq.top()<mu[pos]){
            sum-=pq.top();
            pq.pop();
            sum+=mu[pos];
            pq.push(mu[pos]);
        }
        f[w&1?n-1-i:i]=sum;
    }
}
int main(){
    fastio;
    int n,m,s;
    cin>>n>>m>>s;
    vector<pair<ll,ll>>arr(n);
    vector<ll>mu(n+10),sp(n+10);
    for(int i=0,a; i<n; i++){
        cin>>mu[i]>>sp[i];
        arr[i]={mu[i]-sp[i],i};
    }
    sort(all(arr),greater<pair<ll,ll>>());
    vector<ll>f(n+10), b(n+10);
    func(mu,arr,f,n,m,0);
    func(sp,arr,b,n,s,1);
    ll ans=b.front();
    for(int i=0; i<n; i++)ans=max(ans, f[i]+b[i+1]);
    cout<<ans;
    return 0;
}