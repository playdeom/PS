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
    vector<ll>c;
    vector<int>par;
    vector<vector<int>>arr;
    vector<priority_queue<pair<ll,ll>>>pq;
    escape(int _n){
        n=_n;
        c.resize(2*n,0);
        arr.resize(2*n,vector<int>(0,0));
        par.resize(2*n);
        iota(all(par),0);
        pq.resize(2*n);
    }
    int find(int x){
        if(x==par[x])return x;
        return par[x]=find(par[x]);
    }
    void uni(int x, int y){
        x=find(x); y=find(y);
        if(pq[x].size()>pq[y].size())swap(x,y);
        while(pq[x].size()){
            pq[y].push(pq[x].top());
            pq[x].pop();
        }
        par[x]=y;
    }
    void dfs(int a, int p){
        for(auto&v:arr[a]){
            if(v==p)continue;
            dfs(v,a);
            uni(v,a);
        }
        int s=find(a);
        if(c[a]>=0)pq[s].push({0,c[a]});
        else{
            ll a=c[a], b=c[a];
            while(!pq[s].empty()){
                pair<ll,ll>save=pq[s].top();
                pq[s].pop();
                if(save.first<=a and b>=0)break;
                a=min(a,save.first+b);
                b+=save.second;
            }
            if(b>=0)pq[s].push({a,b});
        }
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
        esc.c[n+1]=2*linf;
        esc.arr[x].push_back(n+1);
        esc.arr[n+1].push_back(x);
        for(int i=1; i<=n; i++)cin>>esc.c[i];
        for(int i=0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            esc.arr[a].push_back(b);
            esc.arr[b].push_back(a);
        }
        esc.dfs(1,-1);
        int no=esc.find(1);
        ll ans=0;
        while(!esc.pq[no].empty()){
            pair<ll,ll>save=esc.pq[no].top();
            esc.pq[no].pop();
            if(ans+save.first>=0)ans+=save.second;
            else break;
        }
        if(ans>linf)cout<<"escaped"<<endl;
        else cout<<"trapped"<<endl;
    }
	return 0;
}