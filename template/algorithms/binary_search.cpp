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

int binary_search(vector<int>&arr, int start, int end,int value) {
	sort(all(arr));
    while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == value) {
			return mid;
		}
		else if (arr[mid] > value) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}
