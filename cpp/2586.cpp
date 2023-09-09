#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
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
vector<pair<int,int>>ss[404040];
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr(n+m+1);
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second=0;
    }
    for(int i=n; i<m+n; i++){
        cin>>arr[i].first;
        arr[i].second=1;
    }
    sort(arr.begin(),arr.begin()+n+m);
    int pnow=n+m;
    for(int i=0; i<n+m; i++){
        if(!arr[i].second){
            ss[pnow++].push_back(arr[i]);
        }
        else{
            ss[--pnow].push_back(arr[i]);
        }
    }
    int save=0;
    int mm=0;
    int ans=0;
    for(int i=0; i<404040; i++){
        save=0;

        for(int j=1; j<ss[i].size(); j+=2){
            save+=abs(ss[i][j].first-ss[i][j-1].first);
        }
        if(ss[i].size()&1){
            mm=save;
            for(int j=ss[i].size()-1; j>1; j-=2){
                save+=abs(ss[i][j].first-ss[i][j-1].first)-
                abs(ss[i][j-1].first-ss[i][j-2].first);
                mm=min(mm,save);
            }
        }
        else{
            ans+=save;
            continue;
        }
        ans+=mm;
    }
    cout<<ans;
    return 0;
}