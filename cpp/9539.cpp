#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <ext/rope>
#include <cassert>
#include <x86intrin.h>
#include<stdio.h>
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
struct escape{
    int n;
    vector<ll>s;
    vector<vector<int>>arr;
    escape(int _n){
        n=_n;
        s.resize(2*n,0);
        arr.resize(2*n,vector<int>(0,0));
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>dfs(int x, int p){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        for(auto&v:arr[x]){
            if(v==p)continue;
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>save=dfs(v,x);
            if(save.size()>pq.size())swap(save,pq);
            while(!save.empty()){
                pair<ll,ll>now=save.top();
                pq.push(now);
                save.pop();
            }
        }
        ll a=max(-s[x],(ll)0),b=max(s[x],(ll)0);
        while(!pq.empty()){
            if(b>a and b<pq.top().first)break;
            pair<ll,ll>x=pq.top();
            ll now=b-a+x.second-x.first;
            a=max(a,a-b+x.first);
            b=now+a;
            pq.pop();
        }
        if(a<b)pq.push({a,b});
        return pq;
    }
    ll get(){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq=dfs(1,0);
        ll ans=0;
        while(!pq.empty()){
            pair<ll,ll>now=pq.top();
            if(ans<now.first)break;
            pq.pop();
            ans+=now.second-now.first;
        }
        return ans;
    }
};
int main() {
	fastio;
	int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        escape esc(n);
        esc.arr[x].push_back(n+1);
        esc.arr[n+1].push_back(x);
        esc.s[n+1]=2*linf;
        for(int i=1; i<=n; i++)cin>>esc.s[i];
        for(int i=0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            esc.arr[a].push_back(b);
            esc.arr[b].push_back(a);
        }
        if(esc.get()>linf)cout<<"escaped"<<endl;
        else cout<<"trapped"<<endl;
    }
	return 0;
}