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
void update(vector<ll>&seg, int n, int s, int e, int i, int v){
    if(s>i or e<i)return;
    if(s==e){
        seg[n]=v;
        return;
    }
    update(seg,n*2,s,(s+e)/2,i,v);
    update(seg,n*2+1,(s+e)/2+1,e,i,v);
    seg[n]=seg[n*2]+seg[n*2+1];
}
ll query(vector<ll>&seg, int n, int s, int e, int l, int r){
    if(r<s or l>e)return 0;
    if(l<=s and e<=r)return seg[n];
    return query(seg,n*2,s,(s+e)/2,l,r)+query(seg, n*2+1,(s+e)/2+1,e,l,r);
}
int main() {
	fastio;
    int n;
    cin>>n;
    int h=ceil(log2(n));
    h=1<<(h+1);
    vector<ll>seg(h);
    vector<pair<int,int>>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        update(seg,1,0,n-1,i,1);
        arr[i].second=i;
    }
    sort(all(arr));
    ll ans=0;
    for(int i=0; i<n; i++){
        ans+=query(seg,1,0,n-1,0,arr[i].second)-1;
        update(seg,1,0,n-1,arr[i].second,0);
    }
    cout<<ans;
    return 0;
}