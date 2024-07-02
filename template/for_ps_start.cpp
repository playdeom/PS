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

//counter clock wise
template<class T>T ccw(pair<T,T> a, pair<T,T> b, pair<T,T> c){
    return a.first*b.second+b.first*c.second+c.first*a.second-
    a.second*b.first-b.second*c.first-c.second*a.first;
}
//bool type ccw
template<class T>T ccwb(pair<T,T>a, pair<T,T> b, pair<T,T> c){
	ll s=ccw(a,b,c);
	if(s>0)return 1;
	if(s<0)return -1;
	return 0;
}
template<class T>T linecheck(pair<T,T>a, pair<T,T>b, pair<T,T>c, pair<T,T>d){
	ll s1=ccw(a,b,c)*ccw(a,b,d);
	ll s2=ccw(c,d,a)*ccw(c,d,b);
	if(s1==0 and s2==0){
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		if(a<=c and b>=c)return 1;
		return 0;
	}
	if(s1<=0 and s2<=0)return 1;
	return 0;
}

// debuging funcs
#define deb(x) cout<<#x<<": "<<(x)<<endl
//////////////////////////////////////////

int main() {
	fastio;
	return 0;
}