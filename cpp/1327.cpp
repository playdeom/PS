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
set<vector<int>>st;
int n,k;
int bfs(vector<int>&arr,vector<int>&so){
	queue<pair<vector<int>,int>>q;
	q.push({arr,0});
	st.insert(arr);
	while(!q.empty()){
		vector<int>x=q.front().first;
		int d=q.front().second;
		q.pop();
		if(x==so)return d;
		for(int i=0; i+k-1<n; i++){
			vector<int>save=x;
			reverse(save.begin()+i,save.begin()+i+k);
			if(st.find(save)!=st.end())continue;
			st.insert(save);
			q.push({save,d+1});
		}
	}
	return -1;
}
int main() {
    fastio;
	cin>>n>>k;
	vector<int>arr(n),so(n);
	for(auto&v:arr)cin>>v;
	for(int i=0; i<n; i++)so[i]=i+1;
	cout<<bfs(arr,so);
    return 0;
}