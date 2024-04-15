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
const int mod = 1e9 + 7; //prime number
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
void lazy_update(vector<ll>&seg, vector<ll>&lazy, int node, int s, int e){
    if(!lazy[node])return;
    seg[node]+=lazy[node]*(e-s+1);
    if(s!=e){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}
void update(vector<ll>&seg, vector<ll>&lazy, int node, int s, int e, int l, int r, ll v){
    lazy_update(seg,lazy,node,s,e);
    if(e<l or s>r)return;
    if(l<=s and e<=r){
        lazy[node]+=v;
        lazy_update(seg,lazy,node,s,e);
        return;
    }
    update(seg,lazy,node*2,s,s+e>>1,l,r,v);
    update(seg,lazy,node*2+1,(s+e>>1)+1,e,l,r,v);
    seg[node]=seg[node*2]+seg[node*2+1];
}
ll query(vector<ll>&seg, vector<ll>&lazy, int node, int s, int e, int l, int r){
    lazy_update(seg,lazy,node,s,e);
    if(s>r or e<l)return 0;
    if(l<=s and e<=r)return seg[node];
    return query(seg,lazy,node*2,s,s+e>>1,l,r)+
    query(seg,lazy,node*2+1,(s+e>>1)+1,e,l,r);
}
int main(){
    fastio;
    int n;
    cin>>n;
    vector<ll>arr(n+1,0);
    int h=ceil(log2(n))+1;
    h=1<<(h+1);
    vector<ll>seg(h),lazy(h);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        update(seg,lazy,1,0,n-1,i-1,i-1,arr[i]-arr[i-1]);
    }
    int m;
    cin>>m;
    while(m--){
        int q;
        cin>>q;
        if(q&1){
            int l,r;
            cin>>l>>r;
            update(seg,lazy,1,0,n-1,l-1,r-1,1);
            update(seg,lazy,1,0,n-1,r,r,-(r-l+1));
        }
        else{
            int x;
            cin>>x;
            cout<<query(seg,lazy,1,0,n-1,0,x-1)<<endl;
        }
    }
    return 0;
}