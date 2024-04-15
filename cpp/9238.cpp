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
int main(){
	fastio;
	ld t,s=linf;
	int n;
	cin>>t>>n;
	vector<ld>arr(n);
	priority_queue<pair<ld,int>>pq;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		pq.push({arr[i],i});
		s=min(s,arr[i]);
	}
	int ans=0;
	vector<int>whc(n,1);
	while(1){
		ld w=pq.top().first;
		int idx=pq.top().second;
		pq.pop();
		if(s/w>=t)break;
		whc[idx]++;
		pq.push({arr[idx]/whc[idx],idx});
		s=min(s,arr[idx]/whc[idx]);
		ans++;
	}
	cout<<ans;
	return 0;
}