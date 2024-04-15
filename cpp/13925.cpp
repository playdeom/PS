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
void update_lazy(vector<ll>&seg, vector<vector<ll>>&lazy, int node, int s, int e){
    if(lazy[node][0]==1 and lazy[node][1]==0)return;
    seg[node]=lazy[node][0]*seg[node]+(e-s+1)*lazy[node][1];
    seg[node]%=mod;
    if(s!=e){
        lazy[node*2][0]=lazy[node][0]*lazy[node*2][0];
        lazy[node*2][0]%=mod;
        lazy[node*2][1]=lazy[node][0]*lazy[node*2][1]+lazy[node][1];
        lazy[node*2][1]%=mod;
        lazy[node*2+1][0]=lazy[node][0]*lazy[node*2+1][0];
        lazy[node*2+1][0]%=mod;
        lazy[node*2+1][1]=lazy[node][0]*lazy[node*2+1][1]+lazy[node][1];
        lazy[node*2+1][1]%=mod;
    }
    lazy[node][0]=1;
    lazy[node][1]=0;
}
void update(vector<ll>&seg, vector<vector<ll>>&lazy, int node, int s, int e, int l, int r, ll m, ll a){
    update_lazy(seg,lazy,node,s,e);
    if(e<l or s>r)return;
    if(l<=s and e<=r){
        lazy[node][0]*=m;
        lazy[node][0]%=mod;
        lazy[node][1]*=m;
        lazy[node][1]%=mod;
        lazy[node][1]+=a;
        lazy[node][1]%=mod;
        update_lazy(seg,lazy,node,s,e);
        return;
    }
    update(seg,lazy,node*2,s,s+e>>1,l,r,m,a);
    update(seg,lazy,node*2+1,(s+e>>1)+1,e,l,r,m,a);
    seg[node]=seg[node*2]+seg[node*2+1];
    seg[node]%=mod;
}
ll query(vector<ll>&seg, vector<vector<ll>>&lazy, int node, int s, int e, int l, int r){
    update_lazy(seg,lazy,node,s,e);
    if(e<l or s>r)return 0;
    if(l<=s and e<=r)return seg[node]%mod;
    return (query(seg,lazy,node*2,s,s+e>>1,l,r)+query(seg,lazy,node*2+1,(s+e>>1)+1,e,l,r))%mod;
}
int main(){
    fastio;
    int n;
    cin>>n;
    int h=ceil(log2(n))+1;
    h=1<<(h+1);
    vector<vector<ll>>lazy(h,vector<ll>(2));
    for(int i=0; i<h; i++)lazy[i][0]=1,lazy[i][1]=0;
    vector<ll>seg(h);
    for(int i=0,a; i<n; i++){
        cin>>a;
        update(seg,lazy,1,0,n-1,i,i,1,a);
    }
    int m;
    cin>>m;
    while(m--){
        int q,x,y,v;
        cin>>q>>x>>y;
        if(q<4)cin>>v;
        if(q==1){
            update(seg,lazy,1,0,n-1,x-1,y-1,1,v);
        }
        if(q==2){
            update(seg,lazy,1,0,n-1,x-1,y-1,v,0);
        }
        if(q==3){
            update(seg,lazy,1,0,n-1,x-1,y-1,0,v);
        }
        if(q==4){
            cout<<query(seg,lazy,1,0,n-1,x-1,y-1)<<endl;
        }
    }
    return 0;
}