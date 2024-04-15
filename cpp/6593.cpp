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
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};
int sx=0,sy=0,sz=0,ex=0,ey=0,ez=0;
int l,r,c;
struct xyz{
	int x,y,z;
};
int bfs(vector<vector<string>>&arr,vector<vector<vector<int>>>&check){
	queue<xyz>q;
	q.push({sx,sy,sz});
	check[sx][sy][sz]=0;
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		int z=q.front().z;
		q.pop();
		if(arr[x][y][z]=='E')return check[x][y][z];
		for(int i=0; i<6; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nz=z+dz[i];
			if(nx<0 or ny<0 or nz<0 or nx>=l or ny>=r or nz>=c)continue;
			if(arr[nx][ny][nz]=='#')continue;
			if(check[nx][ny][nz]!=-1)continue;
			check[nx][ny][nz]=check[x][y][z]+1;
			q.push({nx,ny,nz});
		}
	}
	return -1;
}
int main(){
	fastio;
	while(cin>>l>>r>>c and l!=0 and r!=0 and c!=0){
		vector<vector<string>>arr(l,vector<string>(r));
		for(auto&v:arr)for(auto&a:v)cin>>a;
		sx=0,sy=0,sz=0,ex=0,ey=0,ez=0;
		for(int layer=0; layer<l; layer++){
			for(int i=0; i<r; i++){
				for(int j=0; j<c; j++){
					if(arr[layer][i][j]=='S'){
						sx=layer,sy=i,sz=j;
					}
					if(arr[layer][i][j]=='E'){
						ex=layer,ey=i,ez=j;
					}
				}
			}
		}
		vector<vector<vector<int>>>check(l,vector<vector<int>>(r,vector<int>(c,-1)));
		int ans=bfs(arr,check);
		if(ans==-1)cout<<"Trapped!"<<endl;
		else cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
	}
	return 0;
}