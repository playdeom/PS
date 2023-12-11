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
template<typename T>
void printarr(vector<T> arr) {
	for (auto v : arr) {
		cout << v << " ";
	}
    cout << endl;
}
//////////////////////////////////////////

int main(){
	fastio;
	string s;
	cin>>s;
	int m;
	cin>>m;
	rope<char>rp;
	int n=s.size();
	rp.append(s.c_str());
	while(m--){
		int q,x,y;
		cin>>q>>x;
		if(q==1){
			cin>>y;
			rope<char>save=rp.substr(x,y-x+1);
			rp.erase(x,y-x+1);
			rp.insert(0,save);
		}
		if(q==2){
			cin>>y;
			rope<char>save=rp.substr(x,y-x+1);
			rp.erase(x,y-x+1);
			rp.insert(n-y+x-1,save);
		}
		if(q==3){
			cout<<rp[x]<<endl;
		}
	}
	return 0;
}