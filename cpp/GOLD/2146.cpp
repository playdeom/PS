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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;
void bfs(int num,int sx,int sy,vector<vector<int>>&arr,vector<vector<int>>&lands){
	queue<pair<int,int>>q;
	q.push({sx,sy});
	lands[sx][sy]=num;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
			if(arr[nx][ny]==0)continue;
			if(lands[nx][ny]!=-1)continue;
			q.push({nx,ny});
			lands[nx][ny]=num;
		}
	}
}
int checker(vector<vector<int>>&lands,int x,int y){
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
		if(lands[nx][ny]>0)return lands[nx][ny];
	}
	return -1;
}
int find_b(int num,int sx,int sy,vector<vector<int>>&check,vector<vector<int>>&lands){
	queue<pair<int,int>>q;
	q.push({sx,sy});
	check[sx][sy]=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0 or ny<0 or nx>=n or ny>=n)continue;
			if(check[nx][ny]!=-1)continue;
			if(lands[nx][ny]>0){
				if(lands[nx][ny]!=num)return check[x][y]+1;
				else continue;
			}
			check[nx][ny]=check[x][y]+1;
			q.push({nx,ny});
		}
	}
	return iinf;
}
int main(){
	fastio;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(n));
	for(auto&v:arr)for(auto&a:v)cin>>a;
	vector<vector<int>>lands(n,vector<int>(n,-1));
	int ln=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(lands[i][j]>0)continue;
			if(arr[i][j]==0)continue;
			bfs(ln,i,j,arr,lands);
			ln++;
		}
	}
	// for(auto&v:lands){
	// 	for(auto&a:v)cout<<a<<' ';
	// 	cout<<endl;
	// }
	int ans=iinf;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(lands[i][j]!=-1)continue;
			int c=checker(lands,i,j);
			if(c==-1)continue;
			else{
				vector<vector<int>>check(n,vector<int>(n,-1));
				ans=min(ans,find_b(c,i,j,check,lands)-1);
			}
		}
	}
	cout<<ans;
	return 0;
}