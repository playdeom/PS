#define _CRT_SECURE_NO_WARNINGS
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
const int mod = 1e9 + 7; //prime number

// gcd, lcm, egcd funcs
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>tuple<T,T,T> egcd(T a, T b){
	if(b==0)return {a,1,0};
	auto[g,x,y]=egcd(b,a%b);
	return {g,y,x-(a/b)*y};
}
// builtin funcs
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl
//////////////////////////////////////////
int n,k;
int stack_dfs(vector<vector<int>>&arr){
    stack<int>st;
    vector<int>check(n+1,0),dp(n+1,-1);
    int ans=0;
    st.push(1);
    while(!st.empty()){
        int x=st.top();
        if(!check[x]){
            check[x]=1;
            for(auto&v:arr[x]){
                if(check[v])continue;
                st.push(v);
            }
            continue;
        }
        st.pop();
        int d1=0,d2=0;
        for(auto&v:arr[x]){
            int nx=dp[v]+1;
            if(d1<=nx)d2=d1,d1=nx;
            else if(d2<=nx)d2=nx;
        }
        if(k<=d1+d2)ans++,dp[x]=-1;
        else dp[x]=d1;
    }
    return ans;
}
int main(){
    fastio;
    cin>>n>>k;
    vector<vector<int>>arr(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    cout<<stack_dfs(arr);
    return 0;
}