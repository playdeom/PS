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
template<typename T>
void printarr(vector<T> arr) {
	for (auto v : arr) {
		cout << v << " ";
	}
    cout << endl;
}
//////////////////////////////////////////
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
void bfs(int a,int b,vector<vector<int>>&arr,vector<vector<int>>&check){
	queue<pair<int,int>>q;
	check[a][b]=1;
	q.push({a,b});
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
			if(check[nx][ny])continue;
			if(arr[nx][ny]<=0)continue;
			check[nx][ny]=1;
			q.push({nx,ny});
		}
	}
}
int main(){
	fastio;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m));
	for(auto&v:arr)for(auto&a:v)cin>>a;
	for(int c=0;;c++){
		vector<vector<int>>check(n,vector<int>(m,0));
		int cnt=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(check[i][j])continue;
				if(arr[i][j])bfs(i,j,arr,check),cnt++;
			}
		}
		if(cnt==0)return cout<<0,0;
		if(cnt>1)return cout<<c,0;
		vector<vector<int>>c_arr(n,vector<int>(m,0));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int side=0;
				if(arr[i][j]==0)continue;
				if(i-1>=0)if(arr[i-1][j]==0)side++;
				if(j-1>=0)if(arr[i][j-1]==0)side++;
				if(i+1<n)if(arr[i+1][j]==0)side++;
				if(j+1<m)if(arr[i][j+1]==0)side++;
				c_arr[i][j]=arr[i][j]-side<0?0:arr[i][j]-side;
			}
		}
		arr=c_arr;
	}
	return 0;
}