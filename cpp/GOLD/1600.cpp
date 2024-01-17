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

//////////////////////////////////////////
int k,n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int hdx[]={-1,-2,-2,-1,1,2,2,1};
int hdy[]={-2,-1,1,2,2,1,-1,-2};
struct jump{
	int x,y,t;
};
int check[202][202][33];
int bfs(vector<vector<int>>&arr){
	queue<jump>q;
	q.push({0,0,k});
	check[0][0][k]=0;
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		int t=q.front().t;
		q.pop();
		if(x+1==n and y+1==m)return check[x][y][t];
		if(t>0){
			for(int i=0; i<8; i++){
				int nx=x+hdx[i];
				int ny=y+hdy[i];
				if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
				if(arr[nx][ny] or check[nx][ny][t-1])continue;
				check[nx][ny][t-1]=check[x][y][t]+1;
				q.push({nx,ny,t-1});
			}
		}
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
			if(arr[nx][ny] or check[nx][ny][t])continue;
			check[nx][ny][t]=check[x][y][t]+1;
			q.push({nx,ny,t});
		}
	}
	return -1;

}
int main(){
	fastio;
	cin>>k>>m>>n;
	vector<vector<int>>arr(n,vector<int>(m));
	for(auto&v:arr)for(auto&a:v)cin>>a;
	cout<<bfs(arr);
	return 0;
}