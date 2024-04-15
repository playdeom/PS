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
struct mst{
    int c,l,r;
    bool operator<(const mst& a){
        return c<a.c;
    }
};

int find(int x, vector<int>&par){
	if(par[x]==x)return x;
	par[x]=find(par[x],par);
	return par[x];
}
void uni(int x, int y, vector<int>&par){
	x=find(x,par);
	y=find(y,par);
	if(x==y)return;
	par[y]=x;
}
int check(int x, int y, vector<int>&par){
    x=find(x,par);y=find(y,par);
    if(x==y)return 1;
    return 0;
}
int main(){
    fastio;
    while(1){
        int n,m,k;
        cin>>n>>m>>k;
        if(n==0 and m==0 and k==0)return 0;
        vector<mst>minarr(m),maxarr(m);
        for(int i=0; i<m; i++){
            char c;
            int f,t;
            cin>>c>>f>>t;
            if(c=='B'){
                minarr[i]={1,f,t};
                maxarr[i]={0,f,t};
            }
            else{
                minarr[i]={0,f,t};
                maxarr[i]={1,f,t};
            }
        }
        sort(all(minarr));sort(all(maxarr));
        vector<int>par(n+1);
        for(int i=1; i<=n; i++)par[i]=i;
        int minans=0;
        for(auto&v:minarr){
            if(check(v.l,v.r,par))continue;
            uni(v.l,v.r,par);
            minans+=v.c;
        }
        for(int i=1; i<=n; i++)par[i]=i;
        int maxans=0;
        for(auto&v:maxarr){
            if(check(v.l,v.r,par))continue;
            uni(v.l,v.r,par);
            maxans+=v.c;
        }
        maxans=n-1-maxans;
        if(minans<=k and k<=maxans)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}