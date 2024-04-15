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
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
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
int lcs(string a, string b){
	bitset<50000>d,x,s[26];
    for(int i=0; i<b.size(); i++){
        s[b[i]-'a'][i]=1;
    }
    for(int i=0; i<a.size(); i++){
        x=s[a[i]-'a']|d;
        d<<=1;
        d[0]=1;
        d=x&(x^(x-d));
    }
    return d.count();
}
vector<int>arr(50001);
void prime(){
	for(int i=2; i<=50000; i++)arr[i]=i;
	for(int i=2; i<=50000; i++){
		if(arr[i]==0)continue;
		for(int j=2*i; j<=50000; j+=i)arr[j]=0;
	}
}
int main() {
	fastio;
    string a,b;
    cin>>a>>b;
	char c,d;
	cin>>c>>d;
	a.erase(remove(all(a),d),a.end());
	b.erase(remove(all(b),d),b.end());
	int si1,si2;
	string saveaf="",saveab="";
	string savebf="",savebb="";
	bool ch=1;
	for(int i=0; i<a.size(); i++){
		if(ch)saveaf+=a[i];
		else saveab+=a[i];
		if(a[i]==c and ch){
			ch=!ch;
		}
	}
	ch=1;
	for(int i=0; i<b.size(); i++){
		if(ch)savebf+=b[i];
		else savebb+=b[i];
		if(b[i]==c and ch){
			ch=!ch;
		}
	}
	si1=lcs(saveaf,savebf);
	si2=lcs(saveab,savebb);
	//cout<<saveaf<<" "<<saveab<<endl;
	//cout<<savebf<<" "<<savebb<<endl;
	prime();
	for(int i=si1+si2; i>=0; i--){
		if(arr[i]>0)return cout<<i,0;
	}
	cout<<-1;
}