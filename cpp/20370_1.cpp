#define _CRT_SECURE_NO_WARNINGS
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
const int mod = 1e9 + 7; //prime number

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
bool cmp(pair<ll,ll>a, pair<ll,ll>b){
	if(a.second==b.second)return a.first>b.first;
	return a.second>b.second;
}
int main(){
    fastio;
    int n,k;
	cin>>n>>k;
	vector<pair<ll,ll>>arr(n,{0,0});
	for(auto&[a,b]:arr)cin>>a;
	for(auto&[a,b]:arr)cin>>b;
	sort(all(arr),cmp);
	vector<ll>pbt(n+1,0);
	pbt[0]=arr[0].second;
	for(int i=1; i<n; i++)pbt[i]=pbt[i-1]+arr[i].second;
	priority_queue<ll>pq;
	vector<ll>rfbt(n+1,0);
	for(int i=0; i<n; i++){
		ll a=arr[i].first;
		ll b=arr[i].second;
		pq.push(a+b);
		if(i<k)continue;
		rfbt[i]=rfbt[i-1]+pq.top();
		pq.pop();
	}
	while(!pq.empty())pq.pop();
	vector<ll>sfbt(n+1,0);
	for(int i=n-1; i>=0; i--){
		pq.push(arr[i].first);
		if(i>=k+k)continue;
		sfbt[i]=sfbt[i+1]+pq.top();
		pq.pop();
	}
	ll ans=-linf;
	for(int i=k-1; i<k+k; i++)ans=max(ans,rfbt[i]+sfbt[i+1]-pbt[i]);
	cout<<ans;
    return 0;
}