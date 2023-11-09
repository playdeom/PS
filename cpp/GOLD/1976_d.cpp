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
struct uni{
    vector<int>arr;
    uni(int n){arr.resize(n+1);}
    int find(int v){
        if(v==arr[v])return v;
        arr[v]=find(arr[v]);
        return arr[v];
    }
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a<b)arr[b]=a;
        else arr[a]=b;
    }
};
int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    uni arr(n);
    for(int i=1; i<=n; i++)arr.arr[i]=i;
    vector<vector<int>>tr(n, vector<int>(n,0));
    vector<int>s(m+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tr[i][j]==1 and arr.arr[i]!=arr.arr[j])arr.merge(i,j);
        }
    }
    for(int i=0; i<m; i++){
        cin>>s[i];
    }
    int save=arr.arr[s[0]];
    int c=0;
    for(int i=1; i<m; i++){
        if(save==arr.arr[s[i]]){
            if(i==m-1)c=1;
        }
        else{
            c=0;
            break;
        }
    }
    if(!c)cout<<"NO";
    else cout<<"YES";
    return 0;
}