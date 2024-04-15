#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
using namespace std;

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
template<typename T>
void printarr(vector<T> arr) {
	for (auto v : arr) {
		cout << v << " ";
	}
    cout << endl;
}
/////////////////////////////////////////////
//scc 연습
stack<int>st;
vector<int>arr[101010],en[101010];
vector<int>ans[101010];
bool visited[101010]={0,};
void dfs(int i){
	visited[i]=1;
	for(auto v:arr[i])if(!visited[v])dfs(v);
	st.push(i);
}
void backtrack(int i, int t){
	visited[i]=1;
	ans[t].push_back(i);
	for(auto v:en[i])if(!visited[v])backtrack(v,t);
}
int main(){
	fastio;
	int n, m;
	cin>>n>>m;
	for(int i=0,a,b; i<m; i++){
		cin>>a>>b;
		arr[a].push_back(b);
		en[b].push_back(a);
	}
	for(int i=1; i<=n; i++)if(!visited[i])dfs(i);
	memset(visited,0,sizeof(visited));
	int res=0;
	while(!st.empty()){
		int s=st.top();
		st.pop();
		if(visited[s])continue;
		backtrack(s,res);
		res++;
	}
	cout<<res<<endl;
	vector<pair<int,int>>print;
	for(int i=0; i<res; i++){
		sort(all(ans[i]));
		print.push_back({ans[i][0],i});
	}
	sort(all(print));
	for(auto&v:print){
		for(auto&a:ans[v.second])cout<<a<<' ';
		cout<<-1<<endl;
	}
	return 0;
}