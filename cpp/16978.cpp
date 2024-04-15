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
struct quq{
	int idx,k,i,j;
};
bool cmp(quq a, quq b){
	if(a.k==b.k)return a.idx<b.idx;
	return a.k<b.k;
}
bool cmp2(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
void update(vector<ll>&seg,int node,int s,int e,int idx,ll v){
	if(e<idx or idx<s)return;
	if(s==e){
		seg[node]=v;
		return;
	}
	update(seg,node*2,s,s+e>>1,idx,v);
	update(seg,node*2+1,(s+e>>1)+1,e,idx,v);
	seg[node]=seg[node*2]+seg[node*2+1];
}
ll query(vector<ll>&seg,int node,int s,int e,int l,int r){
	if(e<l or r<s)return 0;
	if(l<=s and e<=r)return seg[node];
	int m=(s+e)>>1;
	return query(seg,node*2,s,m,l,r)+query(seg,node*2+1,m+1,e,l,r);
}
int main(){
	fastio;
	int n;
	cin>>n;
	vector<ll>seg(4*n);
	for(int i=0,a; i<n; i++){
		cin>>a;
		update(seg,1,0,n-1,i,a);
	}
	int m;
	cin>>m;
	vector<pair<int,int>>oneq;
	vector<quq>twoq;
	int c=0;
	while(m--){
		int q;
		cin>>q;
		if(q==1){
			int i,v;
			cin>>i>>v;
			oneq.push_back({i-1,v});
		}
		else{
			int k,i,j;
			cin>>k>>i>>j;
			twoq.push_back({c,k,i-1,j-1});
			c++;
		}
	}
	sort(all(twoq),cmp);
	vector<pair<int,ll>>ans;
	c=0;
	for(auto&[idx,k,l,r]:twoq){
		//deb(idx);deb(k);deb(c);
		while(k>c){
			update(seg,1,0,n-1,oneq[c].first,oneq[c].second);
			c++;
		}
		ans.push_back({idx,query(seg,1,0,n-1,l,r)});
	}
	sort(all(ans));
	for(auto&v:ans)cout<<v.second<<endl;
    return 0;
}