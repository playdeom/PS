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
///////////////////////////////////////////////
bool cmp(pair<int,int>a, pair<int,int>b){
	return a.second<b.second;
}
int main() {
	fastio;
	int n;
	cin>>n;
	vector<pair<int,int>>arr(n);
	for(auto&v:arr)cin>>v.first;
	for(auto&v:arr)cin>>v.second;
	sort(all(arr),cmp);
	priority_queue<int>pq;
	int ans=arr[0].first;
	for(int i=1; i<n-1; i+=2){
		pq.push(arr[i].first);
		pq.push(arr[i+1].first);
		ans+=pq.top();
		pq.pop();
	}
	cout<<ans;
	return 0;
}