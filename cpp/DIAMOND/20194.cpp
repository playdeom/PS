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

int main() {
	fastio;
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>arr(n);
    for(auto&v:arr)cin>>v;
    arr.push_back(l+r);
    if(2*n*r<l)return cout<<-1,0;

    int bef_safe=0, safe=0, pos=0, bef_pos=0, not_move_pos=0;
    int bef_pos_length=-1, now_pos_length=0, have_to_move=0;
    int ans=0;

    for(int i=0; i<n; i++){
        if(arr[i]-r>bef_safe){//안전범위 밖에 있다면
            


            
            // now_pos_length=2*(arr[i]-bef_safe-r);
            // if(bef_pos_length==-1){
            //     bef_pos_length=now_pos_length;
            //     bef_pos=safe+r;
            //     bef_safe=bef_pos+r;
            // }
            // else{
            //     if(2*(arr[i]-bef_pos)>now_pos_length+bef_pos_length){
            //         safe;
            //     }
            // }
        }
        else if(arr[i]-r<safe){
            if(arr[i]+r>arr[i+1]-r){//뒤 범위와 겹치면
                have_to_move+=2*r;
                
            }
            else{
                if(safe+have_to_move<arr[i+1]-r){
                    safe+=have_to_move;
                    pos=safe-r;
                }
                else{

                }
            }
        }
    }
    return 0;
}