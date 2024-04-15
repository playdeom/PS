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
// builtin funcs
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl

//search for array
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
//////////////////////////////////////////
struct ds{
	vector<int>par;
	vector<set<int>>st;
	int n;
	ds(int N){
		n=N;
		par.resize(n);
		st.resize(n);
		iota(all(par),0);
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void uni(int x, int y){
		x=find(x);y=find(y);
		if(st[x].size()>st[y].size())swap(x,y);
		par[x]=y;
		for(auto&v:st[x])st[y].insert(v);
	}
};
int main(){
	fastio;
	int n,q;
	cin>>n>>q;
	vector<int>arr(n+1);
	vector<int>col(n+1);
	for(int i=2; i<=n; i++)cin>>arr[i];
	for(int i=1; i<=n; i++)cin>>col[i];
	ds dst(n+1);
	for(int i=1; i<=n; i++)dst.st[i].insert(col[i]);
	q+=n-1;
	vector<pair<int,int>>query;
	int a,b;
	while(q--){
		cin>>a>>b;
		query.push_back({a,b});
	}
	reverse(all(query));
	vector<int>ans;
	for(auto[a,b]:query){
		if(a==1)dst.uni(b,arr[b]);
		else ans.push_back(dst.st[dst.find(b)].size());
	}
	reverse(all(ans));
	for(auto&v:ans)cout<<v<<endl;
	return 0;
}