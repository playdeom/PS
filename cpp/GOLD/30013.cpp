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
int main(){
    fastio;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=iinf;
    for(int k=1; k<=n; k++){
        vector<int>check(k+1,0);
        int c=0;
        for(int i=0; i<n; i++){
            if(s[i]=='.'){
                check[i%k]=max(0,check[i%k]-1);
            }
            else if(!check[i%k]){
                c++;
                check[i%k]=1;
            }
        }
        ans=min(ans,c);
    }
    cout<<ans;
    return 0;
}