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
vector<pair<int,int>>arr;
ll ccw(pair<ll, ll>a, pair<ll, ll>b, pair<ll, ll>c) {
	ll s = a.first * b.second + b.first * c.second + c.first * a.second;
	s -= b.first * a.second + c.first * b.second + a.first * c.second;
    return s;
}
bool cmp_t(pair<ll,ll>a,pair<ll,ll>b){
    ll s=ccw(arr[0],a,b);
    if(s!=0)return s>0;
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}
int main(){
    fastio;
    int n;
    cin>>n;
    arr.resize(n);
    for(auto&v:arr)cin>>v.first>>v.second;
    for(int i=1; i<n; i++){
        if(arr[i].second<arr[0].second or 
        (arr[i].second==arr[0].second and arr[i].first<arr[0].first)){
            swap(arr[0],arr[i]);
        }
    }
    sort(arr.begin()+1,arr.end(),cmp_t);
    stack<pair<ll,ll>>st;
    st.push(arr[0]);st.push(arr[1]);
    for(int i=2; i<n; i++){
        while(st.size()>=2){
            pair<ll,ll> save=st.top();
            st.pop();
            pair<ll,ll> save2=st.top();
            if(ccw(save2,save,arr[i])>0){
                st.push(save);
                break;
            }
        }
        st.push(arr[i]);
    }
    cout<<st.size();
    return 0;
}