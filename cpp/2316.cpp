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
int n,p;
int c[808][808],f[808][808];
vector<int>arr[808];
int nwf(int s, int e){
	int ans = 0;
	while(1){
		vector<int> par(808,-1);
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i=0; i<arr[x].size(); i++){
				int v=arr[x][i];
				if(c[x][v]-f[x][v]>0 and par[v]==-1){
					par[v]=x;
					q.push(v);
					if(v==e)break;
				}
			}
		}
		if(par[e]==-1)break;
		int flow=iinf;
		for(int i=e;i!=s;i=par[i]){
			flow=min(flow,c[par[i]][i]-f[par[i]][i]);
		}
		for(int i=e;i!=s;i=par[i]){
			f[par[i]][i]+=flow;
			f[i][par[i]]-=flow;
		}
		ans+=flow;
	}
	return ans;
}

int main(){
    fastio;
	cin>>n>>p;
	int out=401;
	for(int i=1; i<=n; i++){
		arr[i].push_back(i+out);
		arr[i+out].push_back(i);
		c[i][i+out]=1;
	}
	for(int i=0; i<p; i++){
		int a,b;
		cin>>a>>b;
		arr[a+out].push_back(b);
		arr[b].push_back(a+out);
		c[a+out][b]=1;
		arr[b+out].push_back(a);
		arr[a].push_back(b+out);
		c[b+out][a]=1;
	}
	cout<<nwf(out+1,2);
	return 0;
}