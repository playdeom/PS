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
struct uf{
	vector<int>par,check,ar;
	vector<ll>cnt;
	vector<vector<int>>arr;
	int n;
	uf(int _n){
		n=_n;
		par.resize(n+1);
		cnt.resize(n+1,1);
		check.resize(n+1,0);
		arr.resize(n+1);
		ar.resize(n+1);
		iota(all(par),0);
	}
	void reset(vector<int>&s){
		for(auto&v:s){
			check[v]=0;
			par[v]=v;
			cnt[v]=1;
		}
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void uni(int x, int y){
		x=find(x),y=find(y);
		if(x==y)return;
		par[y]=x; //y의 부모를 x로
		cnt[x]+=cnt[y]; //부모 x에 y가 가진 정점의 개수 넘겨줌
	}
	void dfs(int i){
		for(auto&v:arr[i]){
			if(v==ar[i])continue;
			ar[v]=i;dfs(v);
		}
	}
};
int main() {
    fastio;
	int n;
	cin>>n;
	uf u(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		u.arr[a].push_back(b);
		u.arr[b].push_back(a);
	}
	u.dfs(1);
	int q;
	cin>>q;
	while(q--){
		int k;
		ll ans=0;
		cin>>k;
		vector<int>s(k);
		for(auto&v:s)cin>>v;
		for(auto&v:s)u.check[v]=1;
		for(auto&v:s)if(u.check[u.ar[v]])u.uni(v,u.ar[v]);
		for(auto&v:s){
			if(u.find(v)==v){
				ans+=u.cnt[v]*(u.cnt[v]-1)/2;
			}
		}
		u.reset(s);
		cout<<ans<<endl;
	}
    return 0;
}