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
struct mp{
	int a,b,t;
	bool operator<(const mp& a){
        return t<a.t;
    }
};
struct uf{
	vector<int>par;
	uf(int _n){
		par.resize(_n+1);
		iota(all(par),0);
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void uni(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return;
		par[y]=x;
	}
};
int main(){
    fastio;
	int n,m;
	cin>>n>>m;
	vector<mp>arr(m);
	for(auto&[a,b,c]:arr)cin>>a>>b>>c;
	sort(all(arr));
	uf un(n);
	int day=1;
	for(auto&[a,b,c]:arr){
		if(c!=day)break;
		if(un.find(a)!=un.find(b)){
			un.uni(a,b);
			day++;
		}
	}
	cout<<day;
	return 0;
}