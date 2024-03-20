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
/////////////////////////////////////////////////

int main() {
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		string s;
		cin>>n>>m>>s;
		vector<int>a,b,arr,k,t;
		a.resize(n+m+1);b.resize(n+m+1);
		k.resize(n+m+1);t.resize(n+m+1);
		for(int i=1; i<=n+m; i++){
			if(s[i-1]=='0'){
				a[i]=a[i-1]+1;
				b[i]=b[i-1];
			}
			else{
				a[i]=a[i-1];
				b[i]=b[i-1]+1;
			}
			if(s[i-1]=='1')arr.push_back(i-1);
			k[i]=t[i]=0;
		}
		int l=n,r=m;
		for(int i=1; i<=n+m; i++){
			if(l>r){
				swap(l,r);
				swap(k,t);
				swap(n,m);
			}
			if(s[i-1]=='0'){
				if(l)k[l]=0,l--;
				else t[r]=0,r--;
			}
			else{
				int save=b[i]+r-l+1;
				int pos=arr[save-1]+1;
				if(save<=b[n+m] and a[pos]-a[i]<l){
					k[l]=1,l--;
				}
				else t[r]=1,r--;
			}
		}
		int c=0;
		vector<int>ans(n+m+1);
		for(int i=0; i<=max(n,m); i++){
			ans[i]=k[i]+t[i]+c;
			c=ans[i]>>1;
			ans[i]&=1;
		}
		if(c)ans[max(n,m)+1]=c;
		int sk=max(n,m)+1;
		while(sk>1 and !ans[sk])sk--;
		for(int i=sk; i>0; i--)cout<<ans[i];
		cout<<endl;
	}
	return 0;
}