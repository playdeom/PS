#define private public
#include <bitset>
#undef private
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
//https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9?fbclid=IwAR0N3Woe8GwzAsxMapbEE9b7rrE_XArl50BRdQ9ZOTCxk-2X5BRrm-HBVpo
template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++){
		c=_subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
    }
}
template<> void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
	A._M_w-=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) {
    _M_do_sub(A, B);
	return A;
}
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	return C-=B;
}
template<size_t _Nw> void _M_do_add(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for(int i=0, c=0; i<_Nw; i++){
		c=_addcarry_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
    }
}
template<> void _M_do_add(_Base_bitset<1> &A, const _Base_bitset<1> &B) {
	A._M_w+=B._M_w;
}
template<size_t _Nb> bitset<_Nb>& operator+=(bitset<_Nb> &A, const bitset<_Nb> &B) {
	_M_do_add(A, B);
	return A;
}
template<size_t _Nb> inline bitset<_Nb> operator+(const bitset<_Nb> &A, const bitset<_Nb> &B) {
	bitset<_Nb> C(A);
	return C+=B;
}
//참고자료: https://m.blog.naver.com/jinhan814/222545486610
int main() {
	fastio;
    string a,b;
    cin>>a>>b;
    bitset<50000>d,x,s[26];
    for(int i=0; i<b.size(); i++){
        s[b[i]-'A'][i]=1;
    }
    for(int i=0; i<a.size(); i++){
        x=s[a[i]-'A']|d;
        d<<=1;
        d[0]=1;
        d=x&(x^(x-d));
    }
    cout<<d.count();
}