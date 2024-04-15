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
	int k;
	cin>>k;

	//mobius func
	vector<int>arr(10101010,0);
	arr[1]=1;
	for(int i=1,j; i<10101010; i++){
		for(int j=2*i; j<10101010; j+=i){
			arr[j]-=arr[i];
		}
	}

	//binary search
	ll s=0,e=iinf*2;
	while(s<e-1){
		ll m=s+e>>1;
		ll c=0;
		for(ll i=1; i<(ll)(sqrt(m)+1); i++){
			ll j=i*i;
			c+=arr[i]*(m/j);
		}
		if(c<k)s=m;
		else e=m;
	}
	cout<<e;
	return 0;
}
