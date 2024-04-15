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
string bfs(int n,vector<int>&check){
	queue<pair<int,string>>q;
	q.push({1,"1"});
	check[1]=1;
	while(!q.empty()){
		int x=q.front().first;
		string s=q.front().second;
		q.pop();
		if(!x)return s;
		if(!check[(x*10)%n]){
			check[(x*10)%n]=1;
			q.push({(x*10)%n,s+"0"});
		}
		if(!check[(x*10+1)%n]){
			check[(x*10+1)%n]=1;
			q.push({(x*10+1)%n,s+"1"});
		}
	}
	return "BRAK";
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		vector<int>check(202020,0);
		cout<<bfs(n,check)<<endl;
	}
	return 0;
}