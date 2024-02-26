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
int da[]={1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int db[]={0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dc[]={0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int dd[]={0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int de[]={0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0};
int df[]={0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0};
int dg[]={0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0};
int dh[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0};
int di[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0};
int dj[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0};
int dk[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1};
struct tomato{
	int a,b,c,d,e,f,g,h,i,j,k,dis;
};
int m,n,o,p,q,r,s,t,u,v,w;
int a,b,c,d,e,f,g,h,i,j,k,na,nb,nc,nd,ne,nf,ng,nh,ni,nj,nk,dis;
queue<tomato>qu;
int main(){
	fastio;
	cin>>m>>n>>o>>p>>q>>r>>s>>t>>u>>v>>w;
	int arr[w][v][u][t][s][r][q][p][o][n][m];
	// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>>arr(w,
	// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>(v,
	// vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>(u,
	// vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(t,
	// vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(s,
	// vector<vector<vector<vector<vector<vector<int>>>>>>(r,
	// vector<vector<vector<vector<vector<int>>>>>(q,
	// vector<vector<vector<vector<int>>>>(p,
	// vector<vector<vector<int>>>(o,
	// vector<vector<int>>(n,
	// vector<int>(m)))))))))));
	int ssss=0;
	for(a=0; a<w; a++){
		for(b=0; b<v; b++){
			for(c=0; c<u; c++){
				for(d=0; d<t; d++){
					for(e=0; e<s; e++){
						for(f=0; f<r; f++){
							for(g=0; g<q; g++){
								for(h=0; h<p; h++){
									for(i=0; i<o; i++){
										for(j=0; j<n; j++){
											for(k=0; k<m; k++){
												cin>>arr[a][b][c][d][e][f][g][h][i][j][k];
												if(arr[a][b][c][d][e][f][g][h][i][j][k]==1){
													qu.push({a,b,c,d,e,f,g,h,i,j,k});
												}
												if(arr[a][b][c][d][e][f][g][h][i][j][k]==0)ssss++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	while(!qu.empty()){
		assert(qu.size()<=1000000);
		a=qu.front().a;
		b=qu.front().b;
		c=qu.front().c;
		d=qu.front().d;
		e=qu.front().e;
		f=qu.front().f;
		g=qu.front().g;
		h=qu.front().h;
		i=qu.front().i;
		j=qu.front().j;
		k=qu.front().k;
		dis=qu.front().dis;
		qu.pop();
		for(int nex=0; nex<22; nex++){
			na=a+da[nex];
			nb=b+db[nex];
			nc=c+dc[nex];
			nd=d+dd[nex];
			ne=e+de[nex];
			nf=f+df[nex];
			ng=g+dg[nex];
			nh=h+dh[nex];
			ni=i+di[nex];
			nj=j+dj[nex];
			nk=k+dk[nex];
			if(na<0 or nb<0 or nc<0 or nd<0 or ne<0 or nf<0 or ng<0 or nh<0 or ni<0 or nj<0 or nk<0)continue;
			if(na>=w or nb>=v or nc>=u or nd>=t or ne>=s or nf>=r or ng>=q or nh>=p or ni>=o or nj>=n or nk>=m)continue;
			if(arr[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk]==-1 or arr[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk])continue;
			arr[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk]=1;
			qu.push({na,nb,nc,nd,ne,nf,ng,nh,ni,nj,nk,dis+1});
			ans=max(ans,dis+1);
			ssss--;
		}
	}
	cout<<(ssss?-1:ans);
	return 0;
}