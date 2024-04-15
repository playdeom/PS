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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll m=0,c=0;
        int bef=0;//0=. 1=W 2=B
        for(int i=s.size()-1; i>=0; i--){
            if(bef==0){
                if(s[i]=='.')continue;
                else if(s[i]=='W')bef=1;
                else bef=2;
            }
            if(s[i]=='.'){
                if(bef==1)m+=c;
                else m-=c;
            }
            else if((s[i]=='W'?1:s[i]=='B'?2:0)==bef)c++;
            else {
                c=0;
                bef=0;
            }
        }
        if(m>0)cout<<"WHITE";
        else cout<<"BLACK";
        cout<<endl;
    }
    return 0;
}