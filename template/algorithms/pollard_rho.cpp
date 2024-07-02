#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <ext/rope>
#include <cassert>
#include <x86intrin.h>
#include<stdio.h>
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
const int mod = 1e9 + 9; //prime number

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

namespace miller_rabin{
    ll mul(ll a, ll b, ll m){
        ll ans=0;
        a%=m;
        while(b){
            if(b&1)ans=(ans+a)%m;
            a=(a*2)%m;
            b>>=1;
        }
        return ans%m;
    }
    ll pow(ll a, ll b, ll m){
        ll ans=1;
        while(b){
            if(b&1)ans=mul(ans,a,m);
            b>>=1;
            a=mul(a,a,m);
        }
        return ans%m;
    }
    bool milr(ll n, ll a){
        if(a%n==0)return 1;
        ll d=n-1;
        while(d%2==0){
            if(pow(a,d,n)==n-1)return 1;
            d>>=1;
        }
        ll save=pow(a,d,n);
        return save==1 or save==n-1;
    }
    bool isit(ll n){
        for(auto&v:{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }){
            if(!milr(n,v))return 0;
        }
        return 1;
    }
}

namespace pollard_rho{
    ll f(ll c, ll n, ll x){
        return (c+miller_rabin::mul(x,x,n))%n;
    }
    void rec(ll n, vector<ll>&arr){
        if(n==1)return;
        if(~n&1){
            arr.push_back(2);
            rec(n/2,arr);
            return;
        }
        if(miller_rabin::isit(n)){
            arr.push_back(n);
            return;
        }
        ll a,b,c,g=n;
        while(1){
            if(g==n){
                a=b=rand()%(n-2)+2;
                c=rand()%20+1;
            }
            a=f(c,n,a);
            b=f(c,n,f(c,n,b));
            g=gcd(abs(a-b),n);
			if(g!=1)break;
        }
        rec(g,arr);
        rec(n/g,arr);
    }
    vector<ll>fact(ll n){
        vector<ll>res;
        rec(n,res);
        sort(all(res));
        return res;
    }
}
