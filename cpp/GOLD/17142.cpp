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
int n,m,is;
int ans=iinf;
int bfs(vector<vector<int>>&arr,vector<int>&check,vector<pair<int,int>>&vir){
	queue<pair<int,int>>q;
	vector<vector<int>>dist(n,vector<int>(n,-1));
	for(int i=0; i<vir.size(); i++){
		if(check[i]){
			q.push({vir[i].first,vir[i].second});
			dist[vir[i].first][vir[i].second]=0;
		}
	}
	int where=1,cnt=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
			if(arr[nx][ny]==1 or dist[nx][ny]!=-1)continue;
			dist[nx][ny]=dist[x][y]+1;
			q.push({nx,ny});
			if(arr[nx][ny]==0)cnt++,where=dist[nx][ny];
		}
	}
	if(cnt==is)ans=min(ans,where);
	return ans;
}
void make(int idx,int c,vector<vector<int>>&arr,vector<pair<int,int>>&vir,vector<int>&check){
	if(c==m){
		ans=bfs(arr,check,vir);
		return;
	}
	for(int i=idx; i<vir.size(); i++){
		if(check[i])continue;
		check[i]=1;
		make(i+1,c+1,arr,vir,check);
		check[i]=0;
	}
}
int main(){
	fastio;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(n));
	for(auto&v:arr)for(auto&a:v)cin>>a;
	vector<pair<int,int>>vir;
	for(int i=0; i<n; i++)for(int j=0; j<n; j++){
		if(arr[i][j]==2)vir.push_back({i,j});
		if(arr[i][j]==0)is++;
	}
	vector<int>check(vir.size(),0);
	make(0,0,arr,vir,check);
	cout<<(ans==iinf?-1:ans);
	return 0;
}