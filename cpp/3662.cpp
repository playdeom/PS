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
//////////////////////////////////////////
struct who{
	int p,j;
	bool operator<(const who&d) const {
		if(p==d.p)return j<d.j;
		return p>d.p;
	}
};
struct pqwho{
	bool operator()(const who&a, const who&b){
		if(a.j==b.j)return a.p<b.p;
		return a.j>b.j;
	}
};
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;string s;
		cin>>n>>s;
		vector<who>arr(n);
		for(auto&[p,j]:arr)cin>>p>>j;
		int pans=0,jans=0;
		sort(all(arr));
		int c=0;
		if(s.front()=='P')pans+=arr[0].p,c=1;
		priority_queue<who,vector<who>,pqwho>pq;
		for(int i=c; i<n; i+=2){
			pq.push({arr[i].p,arr[i].j});
			if(i+1<n){
				pq.push({arr[i+1].p,arr[i+1].j});
				pans+=pq.top().p;
				pq.pop();
			}
		}
		//pq.push({arr.back().p,arr.back().j});
		while(!pq.empty())jans+=pq.top().j,pq.pop();
		cout<<pans<<' '<<jans<<endl;
	}
}