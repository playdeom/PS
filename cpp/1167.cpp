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
vector<pair<int,int>>arr[101010];
int check[101010];
int ansd=0,ansn=0;
void dfs(int n,int d){
    if(check[n])return;
    if(ansd<d)ansd=d,ansn=n;
    check[n]=1;
    for(int i=0; i<arr[n].size(); i++){
        dfs(arr[n][i].first,arr[n][i].second+d);
    }
}
int main() {
	fastio;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int s;
        cin>>s;
        while(1){
            int ne;
            cin>>ne;
            if(ne==-1)break;
            int dis;
            cin>>dis;
            arr[s].push_back({ne,dis});
            arr[ne].push_back({s,dis});
        }
    }
    dfs(1,0);
    memset(check,0,sizeof(check));
    ansd=0;
    dfs(ansn,0);
    cout<<ansd;
}