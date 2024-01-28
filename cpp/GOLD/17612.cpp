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
struct shopping{
	ll id,w,num;
	bool operator<(const shopping&d) const{
		if(w==d.w)return num>d.num;//시간 같다면 가장 작은 번호로
		return w>d.w;
	}
};
struct outshop{
	ll id,w,num;
	bool operator<(const outshop&d) const{
		if(w==d.w)return num<d.num;//시간 같다면 가장 높은 번호로
		return w>d.w;
	}
};
int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	vector<pair<ll,ll>>arr(n);
	for(auto&[a,b]:arr)cin>>a>>b;//id, w

	priority_queue<shopping>pq;
	for(int i=0; i<min(k,n); i++)pq.push({arr[i].first,arr[i].second,i+1});
	
	priority_queue<outshop>oq;
	for(int i=k; i<n; i++){
		shopping save=pq.top();
		pq.pop();
		oq.push({save.id,save.w,save.num});
		pq.push({arr[i].first,save.w+arr[i].second,save.num});
	}
	while(!pq.empty()){
		shopping save=pq.top();
		pq.pop();
		oq.push({save.id,save.w,save.num});
	}
	ll now=1,ans=0;
	while(!oq.empty()){
		ans+=oq.top().id*now;
		oq.pop();
		now++;
	}
	cout<<ans;
	return 0;
}