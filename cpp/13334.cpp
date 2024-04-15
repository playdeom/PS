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

int main(){
	fastio;
	int n;
	cin>>n;
	vector<pair<int,int>>arr(n);
	for(auto&[a,b]:arr){
		cin>>a>>b;
		if(a>b)swap(a,b);
	}
	sort(all(arr),[](pair<int,int>a,pair<int,int>b){
		if(a.second==b.second)return a.first<b.first;
		return a.second<b.second;
	});
	priority_queue<int,vector<int>,greater<int>>pq;
	int d;
	cin>>d;
	int ans=0,cnt=0;
	for(auto&[a,b]:arr){
		int s=b-d,e=b;
		while(!pq.empty() and pq.top()<s)cnt--,pq.pop();
		if(a>=s)cnt++,pq.push(a);
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}