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
int fibo[1010101]={0,};
struct dst{
	vector<int>par;
	int n;
	dst(int N){
		n=N;
		par.resize(n+2);
		iota(all(par),0);
	}
	int find(int x){
		if(x==par[x])return x;
		return par[x]=find(par[x]);
	}
	void uni(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return;
		par[x]=y;
	}
};
int main(){
	fastio;
	fibo[1]=1;fibo[2]=2;
	for(int i=3; i<1010101; i++){
		fibo[i]=fibo[i-1]%mod+fibo[i-2]%mod;
		fibo[i]%=mod;
	}
	int n,q;
	cin>>n>>q;
	vector<pair<int,int>>arr(q);
	vector<int>ans(n+2,0);
	for(auto&[a,b]:arr)cin>>a>>b;
	reverse(all(arr));
	dst ds(n);
	for(auto&[a,b]:arr){
		int s=a,e=b;
		int l=s;
		while(s<=e){
			if(ds.find(s)!=s)s=ds.find(s);
			else{
				ans[s]=fibo[s-l+1];
				ds.uni(s,s+1);s++;
			}
		}
	}
	for(int i=1; i<=n; i++)cout<<ans[i]<<' ';
    return 0;
}