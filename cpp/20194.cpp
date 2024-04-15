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
ll getans(ll n, ll r, ll x, ll c, vector<ll>&arr,vector<ll>&full,vector<ll>&pv,vector<ll>&sec,vector<ll>&ucov);
int main(){
	fastio;
	ll n,l,r;
	cin>>n>>l>>r;
	if(2*n*r<l)return cout<<-1,0;
	vector<ll>arr(n);
	for(auto&v:arr)cin>>v;

	vector<ll>full(n+1,-linf);
	full[n]=l;
	for(int i=n-1; i>=0; i--){
		if(full[i+1]<=arr[i]+r)full[i]=max(0ll,arr[i]-r);
		else break;
	}
	vector<ll>np(n+1,0),pv(n+1,0);
	vector<ll>ucov(n+1,0),sec(n+1,0);
	np.front()=r;pv.front()=-r;
	ll h=0;
	for(int i=1; i<=n; i++){
		ll savef=(2*i-1)*r,saves=arr[i-1];
		sec[i]=sec[i-1];ucov[i]=ucov[i-1];np[i]=(2*i+1)*r;

		if(savef<saves){
			savef=max(savef,h);
			ucov[i]+=saves-savef;
			h=max(h,saves);
			sec[i]=i;
		}
		pv[i]=min(pv[i-1],2*ucov[i]-np[i]);
	}

	ll ans=min(getans(n,r,l,-1,arr,full,pv,sec,ucov),getans(n,r,l-r,-1,arr,full,pv,sec,ucov));
	for(int i=0,j=0; i<n; i++){
		for(;j<n and arr[j]<=arr[i]-2*r;j++);
		ll s1=getans(n,r,arr[i],i+1,arr,full,pv,sec,ucov);
		ll s2=getans(n,r,arr[i]-2*r,j,arr,full,pv,sec,ucov);
		ans=min(ans,min(s1,s2));
		//deb(s1);deb(s2);
	}
	cout<<(ans==linf?-1:ans);
	return 0;
}
ll getans(ll n, ll r, ll x, ll c, vector<ll>&arr,vector<ll>&full,vector<ll>&pv,vector<ll>&sec,vector<ll>&ucov){
	x=max(x,0ll);
	if(c==-1){
		c=n;
		for(int i=0; i<n; i++){
			if(arr[i]>x){
				c=i;
				break;
			}
		}
	}
	if(full[c]<0 or min(x+r,2*c*r)<full[c])return linf;
	if(!sec[c])return x;
	return min(2*ucov[c],x+pv[sec[c]-1])+x;
}