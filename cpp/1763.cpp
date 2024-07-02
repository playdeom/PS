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

//counter clock wise
template<class T> T ccw(pair<T,T> a, pair<T,T> b, pair<T,T> c){
    return a.first*b.second+b.first*c.second+c.first*a.second-
    a.second*b.frist-b.second*c.first-c.second*a.first;
}
// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl
//////////////////////////////////////////
struct tree_painting{
    int n,r;
    vector<int>par;
    vector<ld>cost,cnt;
    vector<int>check;
    vector<vector<int>>arr;
    tree_painting(int _n,int _r){
        n=_n;r=_r;
        par.resize(n+1,0);
        iota(all(par),0);
        check.resize(n+1,0);
        cnt.resize(n+1,1);
        cost.resize(n+1,0);
        arr.resize(n+1,vector<int>());
    }
    void input(){
        for(int i=1; i<=n; i++)cin>>cost[i];
        for(int i=0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            par[b]=a;
        }
    }
    int find(int x){
        if(check[x])return par[x]=find(par[x]);
        return x;
    }
    void upd(int a, int b){
        cnt[b]+=cnt[a];
        cost[b]+=cost[a];
        par[a]=b;
    }
    int get(){
        int idx=-1;
        ld res=-iinf;
        for(int i=1; i<=n; i++){
            ld save=cost[i]/cnt[i];
            if(check[i] or i==r or res>=save)continue;
            res=save;
            idx=i;
        }
        return idx;
    }
    int getans(){
        int u,idx,ans=0;
        for(int i=0; i<n-1; i++){
            idx=get();
            u=find(par[idx]);
            check[idx]=1;
            ans+=cost[idx]*cnt[u];
            upd(idx,u);
        }
        return ans+cost[r];
    }
};
int main(){
    fastio;
    int n,r;
    cin>>n>>r;
    tree_painting t(n,r);
    t.input();
    cout<<t.getans();
    return 0;
}