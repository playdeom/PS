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
    int n,m;
    cin>>n>>m;
    if(n==1){
        int s=0,u=1;
        for(int i=0; i<m; i++){
            cout<<s+u<<" ";
            s=s+u-1;u++;
        }
    }
    else if(m==1){
        int s=0,u=1;
        for(int i=0; i<n; i++){
            cout<<s+u<<endl;
            s=s+u-1;u++;
        }
    }
    else{
        vector<vector<int>>arr(n,vector<int>(m,0));
        arr[0][0]=1;
        arr[1][0]=2;
        arr[0][1]=3;
        int i=0,j=1;
        int turn=1;
        int cnt=3;
        int i=0,j=0,c=1;
        int num=1;
        while(i!=n-1 or j!=m-1){
            while(i>=0 and j>=0 and i<n and j<m){
                if(c){
                    if(i+1<n){
                        arr[i+1][j]=arr[i][j]+num;
                        num++;
                    }
                    if(j+1<m){
                        arr[i][j+1]=arr[i][j]+num;
                        num++;
                    }
                    if(i-1<0 or j+1>=m){
                        if(j+1<m)j++;
                        else if(i+1<n)i++;
                        break;
                    }
                    i--;j++;
                }
                else{
                    if(j+1<m){
                        arr[i][j+1]=arr[i][j]+num;
                        num++;
                    }
                    if(i+1<n){
                        arr[i+1][j]=arr[i][j]+num;
                        num++;
                    }
                    if(i+1>=n or j-1<0){
                        if(i+1<n)i++;
                        else if(j+1<m)j++;
                        break;
                    }
                    i++;j--;
                }
            }
            c=c?0:1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}