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

///////////////////////////////////////////////
//segment tree (maxsum)
void update(vector<ll>&seg, int n, int s, int e, int i, int v){
    if(s>i or e<i)return;
    if(s==e){
        seg[n]=v;
        return;
    }
    update(seg,n*2,s,(s+e)/2,i,v);
    update(seg,n*2+1,(s+e)/2+1,e,i,v);
    seg[n]=seg[n*2]+seg[n*2+1];
}
ll query(vector<ll>&seg, int n, int s, int e, int l, int r){
    if(r<s or l>e)return 0;
    if(l<=s and e<=r)return seg[n];
    return query(seg,n*2,s,(s+e)/2,l,r)+query(seg, n*2+1,(s+e)/2+1,e,l,r);
}