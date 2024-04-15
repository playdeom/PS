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
struct receives{
    int get,price,max_sell;
};
struct cmp{
    bool operator()(const receives&a, const receives&b){
        return a.price>b.price;
    }
};
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<receives>arr(n);
        for(auto&v:arr)cin>>v.get>>v.price>>v.max_sell;
        priority_queue<receives,vector<receives>,cmp>pq;
        int ans=0, stock=0;
        for(int i=0; i<n; i++){
            if(pq.empty()){
                int used=min(arr[i].max_sell,arr[i].get+stock);
                ans+=arr[i].price*used;
                pq.push({arr[i].get,arr[i].price,used});
                stock=stock+arr[i].get-used;
            }
            else if(stock+arr[i].get<arr[i].max_sell){
                int used=0;
                stock+=arr[i].get;
                used+=stock;
                ans+=stock*arr[i].price;
                arr[i].max_sell-=stock;
                stock=0;
                while(!pq.empty()){
                    if(pq.top().price>=arr[i].price or arr[i].max_sell<=0)break;
                    receives save=pq.top();
                    pq.pop();
                    int usin=min(save.max_sell,arr[i].max_sell);
                    ans-=save.price*usin;
                    ans+=arr[i].price*usin;
                    used+=usin;
                    arr[i].max_sell-=usin;
                    if(save.max_sell-usin>0)pq.push({save.get,save.price,save.max_sell-usin});
                }
                pq.push({arr[i].get,arr[i].price,used});
            }
            else{
                int used=min(arr[i].max_sell,arr[i].get+stock);
                ans+=arr[i].price*used;
                pq.push({arr[i].get,arr[i].price,used});
                stock=stock+arr[i].get-used;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}