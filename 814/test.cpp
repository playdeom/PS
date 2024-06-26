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
int arr[8][14];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct num{

};
int checker(int n){
    for(int i=0; i<8; i++){
        for(int j=0; j<14; j++){
            int now=arr[i][j],len=1;
            queue<pair<int,int>>q;
            q.push({i,j});
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(len>4)continue;
                if(now==n)return 1;
                for(int k=0; k<4; k++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 or ny<0 or nx>=8 or ny>=14)continue;
                    q.push({nx,ny});
                    now=now*10+arr[nx][ny];
                }
            }
        }
    }
    return 0;
}
int main() {
	fastio;

	return 0;
}