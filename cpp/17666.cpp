#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
using namespace std;

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
template<typename T>
void printarr(vector<T> arr) {
	for (auto v : arr) {
		cout << v << " ";
	}
    cout << endl;
}
/////////////////////////////////////////////
int main(){
	fastio;
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(int i=0; i<n; i++)cin>>a[i]>>b[i];
	for(int c=1;c;){
		c=0;
		for(int i=0; i<n; i++){
			if(a[i]<2 or a[i]<=b[i])continue;
			int save=max(1,(a[i]-b[i])/2);
			a[i]-=save*2;
			a[(i+1)%n]+=save;
			c=1;
		}
	}
	for(int i=0; i<n; i++)if(a[i]!=b[i])return cout<<"No",0;
	cout<<"Yes";
	return 0;
}