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

vector<priority_queue<pair<int,int>>>pq(202020);
void check(priority_queue<pair<int,int>>&p,int x){
	pair<int,int>save={x,x};
	while(p.size() and (save.second<=0 or p.top().first>=save.first)){
		pair<int,int>t=p.top();
		p.pop();
		save={min(save.first,save.second+t.first),save.second+t.second};
	}
	if(save.second>0)p.push(save);
}
void merge(priority_queue<pair<int,int>>&a,priority_queue<pair<int,int>>&b){
	if(a.size()<b.size())swap(a,b);
	while(!b.empty()){
		a.push(b.top());
		b.pop();
	}
}
void make(int x, int y, vector<vector<pair<int,int>>>&arr, vector<int>&val){
	for(auto&v:arr[x]){
		if(v.first!=y){
			make(v.first,x,arr,val);
			check(pq[v.first],-v.second);
		}
	}
	pq[x].push({val[x],val[x]});
	for(auto&v:arr[x]){
		if(v.first!=y){
			merge(pq[x],pq[v.first]);
		}
	}
}
ll worst=0;
int start=0;
int cc_f[202020];
int cc_l[202020];
int ss[202020];
int cost[202020];
int dfs(int i,vector<int>&val){
	int ans=cost[i]-val[i];
	for(int j=cc_f[i]; j; j=ss[j])ans+=max(cost[j]-1,dfs(j,val));
	return ans;
}
int main() {
	fastio;
	int n;
	cin>>n;
	vector<vector<pair<int,int>>>arr(n+1);
	vector<int>val(n+1,0),check(n+1,0);
	for(int i=1; i<n; i++){
		int a,b;
		cin>>a>>val[i]>>b;
		cost[i]=b;
		if(val[i]==-1)start=i;
		if(cc_f[a])ss[cc_l[a]]=i;
		else cc_f[a]=i;
		cc_l[a]=i;
		arr[a].push_back({i,b});
		arr[i].push_back({a,b});
	}
	val[start]=iinf;
	cout<<dfs(0,val)+1<<' ';
	make(0,-1,arr,val);
	int ans=0,now=0;
	while(!pq[0].empty() and ans<500000000){
		ans=max(ans,-now-pq[0].top().first);
		now+=pq[0].top().second;
		pq[0].pop();
	}
	cout<<ans;
	return 0;
}