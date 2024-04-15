#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define repair(x) x.erase(unique(all(x)),x.end())
using namespace std;
typedef long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
const int mod = 1e9 + 9; //prime number
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
void push(vector<int>&pre, vector<int>&arr, int sz){
    for(int i=0; i<sz; i++){
        int s=arr[i];
        pre.push_back(s);
        for(int j=i+1; j<sz; j++){
            s+=arr[j];
            pre.push_back(s);
        }
    }
}
void print(vector<int>pre){
    for(auto&v:pre)cout<<v<<" ";
    cout<<endl;
}
int main() {
	fastio;
    int t;
    cin>>t;
    int n,m;
    cin>>n;
    vector<int>aarr(n);
    for(auto&v:aarr)cin>>v;
    cin>>m;
    vector<int>barr(m);
    for(auto&v:barr)cin>>v;
    vector<int>apre,bpre;
    push(apre,aarr,n);push(bpre,barr,m);
    sort(all(bpre));
    ll ans=0;
    int save=0;
    for(int i=0; i<apre.size(); i++){
        save=t-apre[i];
        int l=lower_bound(all(bpre),save)-bpre.begin();
        int r=upper_bound(all(bpre),save)-bpre.begin();
        ans+=r-l;
    }
    cout<<ans;
    return 0;
}