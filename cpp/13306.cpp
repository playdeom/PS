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
struct ds{
	vector<int>par;
	int n;
	ds(int N){
		n=N;
		par.resize(n);
		iota(all(par),0);
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void uni(int x, int y){
		x=find(x);y=find(y);
		par[x]=y;
	}
};
int main(){
	fastio;
	int n,q;
	cin>>n>>q;
	vector<int>arr(n+1);
	for(int i=2; i<=n; i++)cin>>arr[i];
	ds dst(n+1);
	q+=n-1;
	vector<tuple<int,int,int>>query;
	int a,b,c=-1;
	while(q--){
		cin>>a;
		if(a==0)cin>>b;
		else cin>>b>>c;
		query.push_back({a,b,c});
		c=-1;
	}
	reverse(all(query));
	vector<string>ans;
	for(auto[a,b,c]:query){
		if(a==0)dst.uni(b,arr[b]);
		else{
			if(dst.find(b)==dst.find(c))ans.push_back("YES");
			else ans.push_back("NO");
		}
	}
	reverse(all(ans));
	for(auto&v:ans)cout<<v<<endl;
	return 0;
}