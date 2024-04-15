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
int main(){
    fastio;
    int n;
    cin>>n;
    n--;
    if(n%4==1 or n%4==2)return cout<<"No",0;
    if(n==0)return cout<<"Yes"<<endl<<0<<" "<<0,0;
    int save=(n+3)/4;
    int a=2*save-1, b=4*save-2;
    int c=4*save-1, d=4*save;
    vector<int>p,q;
    for(int i=1; i<a; i+=2)p.push_back(i);
    for(int i=2; i<a; i+=2)q.push_back(i);
    vector<int>r,s;
    for(int i=a+2; i<b; i+=2)r.push_back(i);
    for(int i=a+1; i<b; i+=2)s.push_back(i);
    vector<int>arr;
    for(int i=s.size()-1; i>=0; i--)arr.push_back(s[i]);
    for(int i=p.size()-1; i>=0; i--)arr.push_back(p[i]);
    arr.push_back(b);
    for(auto&v:p)arr.push_back(v);
    arr.push_back(c);
    for(auto&v:s)arr.push_back(v);
    if(n%4==0){
        cout<<"Yes"<<endl;
        for(auto&v:arr)cout<<v<<" ";
        cout<<d<<" ";
        reverse(all(r));reverse(all(q));
        for(auto&v:r)cout<<v<<" ";
        for(auto&v:q)cout<<v<<" ";
        reverse(all(r));reverse(all(q));
        cout<<b<<" "<<a<<" ";
        for(auto&v:q)cout<<v<<" ";
        cout<<c<<" ";
        for(auto&v:r)cout<<v<<" ";
        cout<<a<<" "<<d<<" ";
        cout<<0<<" "<<0<<" ";
    }
    else{
        cout<<"Yes"<<endl;
        for(auto&v:arr)cout<<v<<" ";
        cout<<a<<" ";
        reverse(all(r));reverse(all(q));
        for(auto&v:r)cout<<v<<" ";
        for(auto&v:q)cout<<v<<" ";
        cout<<b<<" "<<a<<" ";
        reverse(all(r));reverse(all(q));
        for(auto&v:q)cout<<v<<" ";
        cout<<c<<" ";
        for(auto&v:r)cout<<v<<" ";
        cout<<0<<" "<<0<<" ";
    }
    return 0;
}