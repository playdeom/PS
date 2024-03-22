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
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int water[51][51],check[51][51];
vector<string>arr;
void bfs(int sx,int sy){
	queue<pair<int,int>>q;
	q.push({sx,sy});
	water[sx][sy]=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
			if(arr[nx][ny]=='X' or arr[nx][ny]=='D')continue;
			if(water[nx][ny]!=-1)continue;
			water[nx][ny]=water[x][y]+1;
			q.push({nx,ny});
		}
	}
}
void runbfs(int sx,int sy){
	queue<pair<int,int>>q;
	q.push({sx,sy});
	check[sx][sy]=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
			if(arr[nx][ny]=='X')continue;
			if(water[nx][ny]>=0 and water[nx][ny]<=check[x][y]+1)continue;
			if(check[nx][ny]!=-1)continue;
			q.push({nx,ny});
			check[nx][ny]=check[x][y]+1;
		}
	}
}
int main(){
	fastio;
	cin>>n>>m;
	arr.resize(n);
	memset(water,-1,sizeof(water));
    memset(check,-1,sizeof(check));
	for(auto&v:arr)cin>>v;
	int x=0,y=0,ex=0,ey=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]=='*'){
				bfs(i,j);
			}
			if(arr[i][j]=='S'){
				x=i,y=j;
			}
			if(arr[i][j]=='D'){
				ex=i,ey=j;
			}
		}
	}
	runbfs(x,y);
	if(check[ex][ey]==-1)cout<<"KAKTUS";
	else cout<<check[ex][ey];
	// cout<<endl;
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		cout<<check[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		cout<<water[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}