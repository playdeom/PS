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
int main() {
	fastio;
    int n,d,k,c;
    cin>>n>>d>>k>>c;
    vector<int>arr(n);
    vector<int>su(3030);
    for(auto&v:arr)cin>>v;
    deque<int>dq;
    int ans=0,cnt=0;
    for(int i=0; i<k; i++){
        dq.push_back(arr[i]);
        if(!su[dq.back()])ans++;
        su[dq.back()]++;
    }
    cnt=ans;
    for(int i=0; i<n; i++){
        int s=dq.front();
        dq.pop_front();
        su[s]--;
        if(!su[s])cnt--;
        dq.push_back(arr[(i+k)%n]);
        if(!su[arr[(i+k)%n]])cnt++;
        su[arr[(i+k)%n]]++;
        if(!su[c])ans=max(ans,cnt+1);
        else ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}