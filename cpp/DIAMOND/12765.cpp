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
    int m,k;
    cin>>m>>k;
    vector<int>arr(m);
    int sum=0;
    for(auto&v:arr)cin>>v,sum+=v;
    vector<int>at(m);
    for(int i=0; i<k; i++){
        int a;
        cin>>a;
        at[a-1]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(int i=0; i<m; i++){
        pq.push({(arr[i]-1+(at[i]+1)*sum)/arr[i],i});
    }
    int i=0;
    for(i=k+1; i<=k+2*sum; i++){
        if(pq.top().first<i){
            if(pq.top().first>k+2*sum)cout<<"forever";
            else cout<<pq.top().first-k-1;
            return 0;
        }
        int s=pq.top().second;
        pq.pop();
        at[s]++;
        pq.push({(arr[s]-1+(at[s]+1)*sum)/arr[s],s});
    }
    cout<<"forever";
    return 0;
}