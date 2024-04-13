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
void update(vector<ll>&seg, int node, int s, int e, int i){
	if(i<s or e<i)return;
	seg[node]+=1;
	if(s==e)return;
	update(seg,node*2,s,s+e>>1,i);
	update(seg,node*2+1,(s+e>>1)+1,e,i);
}
ll query(vector<ll>&seg, int node, int s, int e, int val){
	if(val>e)return seg[node];
	if(s>val or s==e)return 0;
	return query(seg,node*2,s,s+e>>1,val)+query(seg,node*2+1,(s+e>>1)+1,e,val);
}
int main() {
    fastio;
	int n;
	cin>>n;
	vector<pair<ll,ll>>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i].first;
		arr[i].second=i;
	}
	sort(all(arr));
	for(int i=0; i<n; i++)arr[i].first=i;
	sort(all(arr),[](pair<ll,ll>a, pair<ll,ll>b){
		return a.second<b.second;
	});
	int h=ceil(log2(n));
	h=1<<(h+1);
	vector<ll>seg(h);
	for(int i=0; i<n; i++){
		cout<<i-query(seg,1,0,n-1,arr[i].first)+1<<endl;
		update(seg,1,0,n-1,arr[i].first);
	}
    return 0;
}