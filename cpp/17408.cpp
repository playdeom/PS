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
void update(vector<pair<ll,ll>>&seg,int node,int s,int e,int i,ll v){
	if(s>i or i>e)return;
	if(s==e){
		seg[node]={v,i};
		return;
	}
	int m=s+e>>1;
	update(seg,node*2,s,m,i,v);
	update(seg,node*2+1,m+1,e,i,v);
	if(seg[node*2].first>seg[node*2+1].first)seg[node]=seg[node*2];
	else seg[node]=seg[node*2+1];
}
pair<ll,ll> query(vector<pair<ll,ll>>&seg,int node,int s,int e,int l,int r){
	if(s>r or e<l)return {0,-1};
	if(l<=s and e<=r)return seg[node];
	int m=s+e>>1;
	pair<ll,ll> a=query(seg,node*2,s,m,l,r);
	pair<ll,ll> b=query(seg,node*2+1,m+1,e,l,r);
	if(a.first>b.first)return a;
	else return b;
}
int main(){
	fastio;
	int n;
	cin>>n;
	vector<pair<ll,ll>>seg(n*3);
	for(int i=0,a; i<n; i++){
		cin>>a;
		update(seg,1,0,n-1,i,a);
	}
	int m;
	cin>>m;
	while(m--){
		int q,a,b;
		cin>>q>>a>>b;
		if(q==1){
			update(seg,1,0,n-1,a-1,b);
		}
		else{
			pair<ll,ll> an1=query(seg,1,0,n-1,a-1,b-1);
			pair<ll,ll> an2=query(seg,1,0,n-1,a-1,an1.second-1);
			pair<ll,ll> an3=query(seg,1,0,n-1,an1.second+1,b-1);
			cout<<an1.first+max(an2.first,an3.first)<<endl;
		}
	}
	return 0;
}