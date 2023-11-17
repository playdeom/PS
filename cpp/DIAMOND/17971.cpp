#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
using namespace std;

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
const int mod = 1e9 + 9; //prime number

// gcd, lcm, egcd funcs
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
// builtin funcs
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl
template<typename T>
void printarr(vector<T> arr) {
	for (auto v : arr) {
		cout << v << " ";
	}
    cout << endl;
}

struct ladder{
    int i,idx,x;
    bool operator<(const ladder &d) const{
        return x<d.x;
    }
};
int main() {
    fastio;
    int n;
    cin>>n;
    vector<ladder>arr;
    for(int i=1,a; i<n; i++){
        int c=1;
        while(cin>>a and a!=0)arr.push_back({i,c++,a});
    }
    sort(all(arr));
    vector<int>save(n+1);
    for(int i=0; i<=n; i++)save[i]=i;
    //printarr(save);
    for(auto[i,idx,n]:arr)swap(save[i],save[i+1]);
    reverse(all(arr));
    vector<pair<int,int>>ans;
    for(auto[i,idx,x]:arr){
        if(save[i]<=save[i+1])continue;
        swap(save[i],save[i+1]);
        ans.push_back({i,idx});
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v.first<<' '<<v.second<<endl;
    }
    return 0;
}