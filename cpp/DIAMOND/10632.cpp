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
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll>arr(n);
	for(auto&v:arr)cin>>v;
	ll ans=0;
	if(a==b){
		for(auto&v:arr){
			v%=(a+1);
			ans^=v;
		}
	}
	else if(a>b){
		for(auto&v:arr){
			if(v>b){
				ans=1;
				break;
			}
			ans^=v;
		}
	}
	else if(a<b){
		vector<ll>c;
		for(auto&v:arr){
			if(v>a)c.push_back(v);
			else ans^=v;
		}
		if(c.size()>=2)return cout<<"Jiro",0;
		if(c.size()==1){
			return cout<<(ans<=a and ans>0 and c.front()<=a+ans?"Hanako":"Jiro"),0;
		}
	}
	return cout<<(ans?"Hanako":"Jiro"),0;
}